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
    static boolean maxOccursTwice(int a, int b, int c){
        int d = Math.max(a, Math.max(b, c));
        int oc=0;
        if(a==d) ++oc;
        if(b==d) ++oc;
        if(c==d) ++oc;
        return (oc>=2);
    }

    public static void main(String args[]) {
        fr s = new fr();
        int n = s.nextInt();
        for(int x = 0; x < n; x++) {
             int a = s.nextInt();
             int b = s.nextInt();
             int c = s.nextInt();
             boolean ret = maxOccursTwice(a, b, c);
             int max = Math.max(Math.max(a, b), c);
             int min = Math.min(Math.min(a, b), c);
             if(!ret) {
                 System.out.println("NO");
             } else {
                 System.out.println("YES");
                 System.out.print(min+" "+min+" "+max);
                 System.out.println();
             }

        }
    }
}