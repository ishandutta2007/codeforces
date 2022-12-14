use std::io::{self, prelude::*};
use std::collections::BTreeMap;
use std::cmp::min;

/* I could not get away with making some local variables and write closure for them
 * like I did in C++...
 *
 * let mut x=1;
 * let mut f1=|| x+=1;
 * let mut f2=|| x+=2;
 *
 * because each closure tries to take a mutable reference to `x`.
 */

#[derive(Default)]
struct Multiset{
    pub cnt:BTreeMap<i32,usize>,
    pub size:usize,
    pub sum:i64,
}

impl Multiset{
    /*
    fn new()->Self{
        Self{
            cnt:BTreeMap::new(),
            size:0usize,
            sum:0i64,
        }
    }
    */

    fn insert(&mut self,x:i32){
        if let Some(x_cnt)=self.cnt.get_mut(&x) {
            *x_cnt+=1; // I don't understand how explicit `&` and `*` could make program clearer.........
        }else{
            self.cnt.insert(x,1);
        }
        self.size+=1;
        self.sum+=x as i64;
    }
    fn remove(&mut self,x:i32){
        let x_cnt=self.cnt.get_mut(&x).unwrap();
        *x_cnt-=1;
        if *x_cnt==0{
            self.cnt.remove(&x);
        }
        self.size-=1;
        self.sum-=x as i64;
    }
    fn min(&self)->Option<&i32>{
        self.cnt.iter().next().map(|(key,_value)| key)
    }
    fn max(&self)->Option<&i32>{
        self.cnt.iter().next_back().map(|(key,_value)| key)
    }
}

// Should I implement `new()` for those structs?
#[derive(Default)]
struct MultisetPair{
    left:Multiset,
    right:Multiset
    // There's no way to not repeat the type name here?...
}
impl MultisetPair{
    fn insert(&mut self,x:i32){
        (if let Some(&left_max)=self.left.max(){
            if x<=left_max{ &mut self.left }else{ &mut self.right }
        }else{
            &mut self.right
        }).insert(x)
    }
    fn remove(&mut self,x:i32){
        (if let Some(&left_max)=self.left.max(){
            if x<=left_max{ &mut self.left }else{ &mut self.right }
        }else{
            &mut self.right
        }).remove(x)
    }

    fn balance(&mut self,expected_size:usize){
        // NOTE slightly inefficient when there's any key with multiple occurrences
        // Complexity: roughly log(self.left.size+self.right.size) * abs(self.left.size - expected_size)

        debug_assert!(self.left.size+self.right.size>=expected_size);
        if let Some(x)=self.left.max(){
            if let Some(y)=self.right.min(){
                debug_assert!(x<=y);
            }
        } // TODO Can the check be optimized away in release build?...

        while self.left.size<expected_size{
            let &x=self.right.min().unwrap();
            self.left.insert(x);
            self.right.remove(x);
        }
        while self.left.size>expected_size{
            let &x=self.left.max().unwrap();
            self.left.remove(x);
            self.right.insert(x);
        }
        
        debug_assert!(self.left.size==expected_size);
    }
}

// * Also Rust forces separate struct declaration and implementation.

fn solve<R: BufRead, W: Write>(mut input: FastInput<R>, mut w: W) {
    let nlevel:usize=input.token();
    let nstar:usize=input.token();
    struct Level{
        a:i32,
        b:i32,
        idx:usize,
    };

    let mut levels:Vec<_>=(0..nlevel)
        .map(|idx| Level{a:input.token(),b:input.token(),idx})
        .collect();
    levels.sort_unstable_by(|x,y| x.b.cmp(&y.b));
    // Remark:
    // * A value expression cannot be automatically converted to a place expression.
    // * There's no way to immutable sort?
    // * Rust doesn't have multiset...

    let mut set=MultisetPair::default();

    for level in levels.iter() {
        set.insert(level.a);
    }
    let mut result=if nstar<=nlevel {
        set.balance(nstar);
        (set.left.sum,0usize)
    } else {
        (i64::max_value(),0usize)
    };

    let mut sum_added_a=0i64;
    for (index,level) in levels.iter().enumerate() {
        set.remove(level.a);
        sum_added_a+=level.a as i64;
        set.insert(level.b-level.a);

        if nstar<(index+1){ break }
        if nstar-(index+1)<=nlevel {
            set.balance(nstar-(index+1));
            result=min(result,(sum_added_a+set.left.sum,index+1));
        }
    }

    let mut state=vec!['0' as u8;nlevel];
    let (mintime,n12_first)=result;
    for level in &mut levels[..n12_first]{
        state[level.idx]+=1;
        level.a=level.b-level.a;
    } // NOTE meaning of 'a' changed

    levels.sort_unstable_by(|x,y| x.a.cmp(&y.a));
    for level in &levels[..nstar-n12_first]{
        state[level.idx]+=1;
    }

    unsafe{
        write!(w,"{}\n{}\n",mintime,String::from_utf8_unchecked(state)).unwrap();
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