import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args){
        try {
            new Main().solve();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    private void solve() throws Exception{
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        long n=in.nextLong(),b=in.nextLong();
        long ans=Long.MAX_VALUE;
        for(long i=2;i*i<=b;i++){
            int cnt=0;
            while(b%i==0){
                cnt++;
                b/=i;
            }
            if(cnt>0){
                ans=Math.min(get(n,i)/cnt,ans);
            }
        }
        if(b!=1){
            ans=Math.min(get(n,b),ans);
        }
        out.println(ans);
        out.flush();
    }
    long get(long n,long x){
        long ans=0;
        while(n>0){
            n/=x;
            ans+=n;
        }
        return ans;
    }
}
class InputReader{
    StreamTokenizer tokenizer;
    public InputReader(InputStream stream){
        tokenizer=new StreamTokenizer(new BufferedReader(new InputStreamReader(stream)));
        tokenizer.ordinaryChars(33,126);
        tokenizer.wordChars(33,126);
    }
    public String next() throws IOException {
        tokenizer.nextToken();
        return tokenizer.sval;
    }
    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }
    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
    public boolean hasNext() throws IOException {
        int res=tokenizer.nextToken();
        tokenizer.pushBack();
        return res!=tokenizer.TT_EOF;
    }
}