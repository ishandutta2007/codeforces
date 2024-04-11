import java.io.*;
import java.util.*;
public class A13 {
    static int sum;
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        for(int i = 2; i < n; i++)
            convert(n,i);
        n -= 2;
        int gcd = gcd(sum,n);
        sum /= gcd;
        n /= gcd;
        System.out.println(sum + "/" + n);
    }
    public static int gcd(int a, int b)     {
        return a%b==0 ? b : gcd(b,a%b);
    }
    public static void convert(int n, int a)        {
        while(n > 0)        {
            int ret = n%a;
            sum += ret;     
            n /= a;
        }
    }
}