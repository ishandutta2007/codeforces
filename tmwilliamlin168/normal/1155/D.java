import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws IOException{
        Reader.init(System.in);
        //
        int n=Reader.nextInt();
        long k=Reader.nextLong();
        long a[]=new long[n+10];
        long dp[][]=new long[n+10][5];
        for(int i=1;i<=n;i++) a[i]=Reader.nextLong();
        //
        final long ze=0L;

        for(int i=1;i<=n;i++){
            dp[i][0]=Math.max(dp[i-1][0]+a[i],ze);
            dp[i][1]=Math.max(Math.max(dp[i-1][0]+a[i]*k,dp[i-1][1]+a[i]*k),ze);
            dp[i][2]=Math.max(Math.max(dp[i-1][1]+a[i],dp[i-1][2]+a[i]),ze);
            dp[i][3]=Math.max(Math.max(dp[i][0],dp[i][1]),Math.max(dp[i-1][3],dp[i][2]));
        }
        System.out.println(dp[n][3]);
    }

}
//
class Reader{
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init(InputStream input){
        reader=new BufferedReader(new InputStreamReader(input));
        tokenizer=new StringTokenizer("");
    }
    //
    static String next()throws IOException{
        while(!tokenizer.hasMoreTokens()){
            tokenizer=new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
    //
    static int nextInt() throws IOException {return Integer.parseInt(next());}
    static double nextDouble()throws IOException{return Double.parseDouble(next());}
    static long nextLong()throws IOException{return Long.parseLong(next());}
}