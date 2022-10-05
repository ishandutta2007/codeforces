//JDope
import java.util.*;
import java.io.*;
import java.math.*;
public class F{
public static void main(String[] omkar) throws Exception
{
   BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
   StringTokenizer st = new StringTokenizer(in.readLine());
   StringBuilder sb = new StringBuilder();
   int n = Integer.parseInt(st.nextToken());
   long sum = 0;
   int k = Integer.parseInt(st.nextToken());
   boolean ones = true;
   long a;
   long b;
   long modSum = 0;
   for(int i = 0; i < k; i++)
   {
      st = new StringTokenizer(in.readLine());
      a = Integer.parseInt(st.nextToken());
      b = Integer.parseInt(st.nextToken());
      sum += b;
      modSum += (b % (long)(n))*(a % (long)(n)) % (long)(n);
      modSum = modSum % (long)(n);
   }  
   if(sum > n)
   {
      System.out.println("-1");
      return;
   }
   if(sum == n)
   {
     if(n % 2 == 0 && modSum % n == n/2)
     {
         System.out.println("1");
      return;
     } 
     if(n % 2 == 1 && modSum % n == 0)
     {
         System.out.println("1");
      return;
     }
     System.out.println("-1");
      return;
   }
   System.out.println("1");
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