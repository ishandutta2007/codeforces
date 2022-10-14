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
    static int lcm(int a, int b) {
        int temp = Math.max(a, b);
        int step = temp;
        while(a!=0) {
            if(temp%a==0&&temp%b==0) {
                return temp;
            }
            temp+=step;
        }
        return temp;
    }

    public static void main(String args[]) {
        fr s = new fr();
        int n = s.nextInt();
        for(int x = 0; x < n; x++) {
             int b = s.nextInt();
             int c = s.nextInt();
             if(2*b>c) {
                 System.out.println("-1 -1");
             } else {
                 System.out.print(b + " "+ 2*b);
             }
             if(x==n-1) continue;
             else System.out.println();



        }



    }
}