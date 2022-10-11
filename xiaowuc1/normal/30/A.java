import java.io.*;
import java.math.*;
import java.util.*;
public class A30 {
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BigInteger a = new BigInteger(st.nextToken());
        BigInteger b = new BigInteger(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        for(int xx = -1000; xx <= 1000; xx++)       {
            BigInteger x = BigInteger.valueOf(xx);
            if(a.multiply(x.pow(n)).equals(b))  {
                System.out.println(xx);
                return;
            }
        }
        System.out.println("No solution");
    }
}