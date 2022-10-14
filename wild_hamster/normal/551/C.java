import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    static int i,j,n,m,x[] = new int[2505],y[] = new int[2505];
    static int a[] = new int[4100005]; 
    static Map<Long, Integer> hashmap = new HashMap<Long, Integer>();
    static int gcd(int a, int b)
    {
        if (b == 0) return a;
        return gcd(b,a%b);
    }
    static int Abs(int x)
    {
        if (x > 0)
            return x;
        return -x;
    }
    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);//new File("input.txt"));
        PrintWriter pw = new PrintWriter(System.out);//new File("output.txt"));
       n = sc.nextInt(); m = sc.nextInt();
       for (i = 0; i < n; i++)
           a[i] = sc.nextInt();
       while (a[n-1] == 0)
           n--;
       long l = 0, r = (long)1e+15;
       while (l < r)
       {
           long mid = (l+r-1)/2;
           int b[] = new int[n];
           for (i = 0; i < n; i++)
               b[i] = a[i];
           int nn = n-1;
           for (i = 0; i < m; i++)
           {
               long tim = mid - nn - 1;
               if (nn == -1)
                   break;
               while (nn >= 0 && b[nn] <= tim)
               {
                   tim -= b[nn];
                   b[nn] = 0;
                   nn--;
               }
               if (tim > 0 && nn >= 0)
                   b[nn] -= tim;
           }
           if (nn == -1)
               r = mid;
           else
               l = mid+1;
       }
       pw.println(l);
       pw.close();
    }
}