//JDope
import java.util.*;
import java.io.*;
import java.math.*;
public class J{
public static void main(String[] omkar) throws Exception
{
   BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
   StringTokenizer st = new StringTokenizer(in.readLine());
   StringBuilder sb = new StringBuilder();
   long mod = 1000000007;
   int cases = Integer.parseInt(st.nextToken());
   long x;
   long a, b;
   st = new StringTokenizer(in.readLine());
   for(int i = 0; i < cases; i++)
   {
      x = Long.parseLong(st.nextToken());
      a = x/2+1;
      if(a % 2 == 0)
      {
         b = ((a/2 % mod))*((a/2 % mod)+1);
         b = b % mod;
         sb.append(b + "\n");
      }
      else
      {
         b = ((a/2 % mod)+1)*((a/2 % mod)+1);
         b = b % mod;
         sb.append(b + "\n");
      }
   }  
   System.out.println(sb);
        }
 public static int[] readArr(int N, BufferedReader in, StringTokenizer st) throws Exception
      {
         int[] arr = new int[N];
         st = new StringTokenizer(in.readLine());
         for(int i=0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());
         return arr;
      }


}