use std::io::{self, prelude::*};
use std::cmp::min;

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
    let num_test:usize=input.token();
    for _ in 0..num_test{
        let len:usize=input.token();
        let s:Vec<u8>=input.token();
        let t:Vec<u8>=input.token();
        let mut result=vec![vec![std::u16::MAX; len+1]; len+1]; // [i][j] = s[i:] -> t[j:]
        result[len][len]=0;

        let mut min_inside=vec![len; len+1];
        {
            let mut counts=[0; 128];
            for i in (0..len).rev(){
                counts[s[i] as usize]+=1;
                let mut countt=[0; 128];
                while min_inside[i]>0&&
                    countt[t[min_inside[i]-1] as usize]!=counts[t[min_inside[i]-1] as usize]{
                    min_inside[i]-=1;
                    countt[t[min_inside[i]] as usize]+=1
                }
            }
        }

                

        for i in (0..=len).rev(){
        for j in (0..=len).rev(){
            let cur=result[i][j];
            if cur==std::u16::MAX{continue}
            if j>=min_inside[i]+1{
                result[i][j-1]=min(result[i][j-1], cur)
            }
            if i!=0{
                result[i-1][j]=min(result[i-1][j], cur+1);
                if j!=0&&s[i-1]==t[j-1]{
                    result[i-1][j-1]=min(result[i-1][j-1], cur)
                }
            }
        }
        }

        if result[0][0]==std::u16::MAX{
            write!(w, "-1\n")
        }else{
            write!(w, "{}\n", result[0][0])
        }.unwrap();

    }
}

fn main() {
    let stdin = io::stdin();
    let stdout = io::stdout();
    let input = FastInput::from(stdin.lock());
    let writer = io::BufWriter::new(stdout.lock());
    solve(input, writer);
}

trait TokenStream<T> {
    fn token(&mut self) -> T;
}

struct FastInput<R> {
    stdin: R,
    pos: usize,
}

impl<R: BufRead> From<R> for FastInput<R> {
    fn from(r: R) -> Self {
        FastInput { stdin: r, pos: 0 }
    }
}

impl<R: BufRead> TokenStream<u8> for FastInput<R> {
    fn token(&mut self) -> u8 {
        loop {
            if let Ok(buf) = self.stdin.fill_buf() {
                while self.pos < buf.len() {
                    self.pos += 1;
                    if buf[self.pos - 1] > 32 {
                        return buf[self.pos - 1];
                    }
                }
                if self.pos == 0 {
                    return 0;
                }
            } else {
                return 0;
            }
            self.stdin.consume(self.pos);
            self.pos = 0;
        }
    }
}

impl<R: BufRead> TokenStream<Vec<u8>> for FastInput<R> {
    fn token(&mut self) -> Vec<u8> {
        let mut ans = Vec::new();
        let mut parse_token = false;
        loop {
            if let Ok(buf) = self.stdin.fill_buf() {
                if !parse_token {
                    while self.pos < buf.len() && buf[self.pos] <= 32 {
                        self.pos += 1;
                    }
                }
                while self.pos < buf.len() && buf[self.pos] > 32 {
                    parse_token = true;
                    ans.push(buf[self.pos]);
                    self.pos += 1;
                }
                if self.pos != buf.len() || self.pos == 0 {
                    return ans;
                }
            }
            self.stdin.consume(self.pos);
            self.pos = 0;
        }
    }
}

macro_rules! impl_token_stream_u {
    ($($t:ident),+) => {$(
        impl<R: BufRead> TokenStream<$t> for FastInput<R> {
           fn token(&mut self) -> $t {
                let mut ans = 0;
                let mut parse_token = false;
                loop {
                    if let Ok(buf) = self.stdin.fill_buf() {
                        if !parse_token {
                            while self.pos < buf.len() && buf[self.pos] <= 32 {
                                self.pos += 1;
                            }
                        }
                        while self.pos < buf.len() && buf[self.pos] > 32 {
                            parse_token = true;
                            ans = ans * 10 + (buf[self.pos] - b'0') as $t;
                            self.pos += 1;
                        }
                        if self.pos != buf.len() || self.pos == 0 {
                            return ans;
                        }
                    }
                    self.stdin.consume(self.pos);
                    self.pos = 0;
                }
           }
        }
    )+}
}
macro_rules! impl_token_stream_i {
    ($($t:ident),+) => {$(
        impl<R: BufRead> TokenStream<$t> for FastInput<R> {
           fn token(&mut self) -> $t {
                let mut ans = 0;
                let mut minus = false;
                let mut parse_token = false;
                loop {
                    if let Ok(buf) = self.stdin.fill_buf() {
                        if !parse_token {
                            while self.pos < buf.len() && buf[self.pos] <= 32 {
                                self.pos += 1;
                            }
                        }
                        while self.pos < buf.len() && buf[self.pos] > 32 {
                            parse_token = true;
                            if buf[self.pos] == b'-' {
                                minus = true;
                            } else {
                                ans = ans * 10 + (buf[self.pos] - b'0') as $t;
                            }
                            self.pos += 1;
                        }
                        if self.pos != buf.len() || self.pos == 0 {
                            return if minus { -ans } else { ans };
                        }
                    }
                    self.stdin.consume(self.pos);
                    self.pos = 0;
                }
           }
        }
    )+}
}

impl_token_stream_u!(usize);
impl_token_stream_i!(i32);
impl_token_stream_i!(i64);