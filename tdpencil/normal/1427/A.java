import java.math.BigInteger;
import java.util.*;
import java.io.*;
import java.lang.Math;
public class run {
    static class fr
    {
        BufferedReader br;
        StringTokenizer st;

        public fr()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
        int[] readArr(int n) {
            int a[] = new int[n];
            for(int i = 0; i < n; i++) {
                a[i] = this.nextInt();
            }
            return a;
        }
    }
    static int sum(int[] a) {
        int s=0;
        for(int i : a) s+=i;
        return s;
    }


    public static void main(String args[]) {
        fr s = new fr();
        int n = s.nextInt();
        for(int x = 0; x < n; x++) {
             int a = s.nextInt();
             int b[] = s.readArr(a);
             if(sum(b)==0) {
                 System.out.println("NO");
             } else {
                 System.out.println("YES");
                 if(sum(b)>0) {


                     Arrays.sort(b);
                     for(int i =0 ; i < a/2;i++) {
                         int t = b[i];
                         b[i] = b[a-1-i];
                         b[a-1-i]=t;
                     }
                     for(int i =0; i < a; i++) {
                         if(b[i]>0) {
                             int temp = b[i];
                             b[i] = b[0];
                             b[0] = temp;
                             break;
                         }
                     }
                     for(int i : b) {
                         System.out.print(i + " ");
                     }
                     System.out.println();
                 } else {
                     Arrays.sort(b);
                     for(int i : b) {
                         System.out.print(i + " ");

                     }
                     System.out.println();
                 }
             }

        }



    }
}