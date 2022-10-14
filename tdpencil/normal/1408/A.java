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
             int a = s.nextInt();
             ArrayList<Integer> A = new ArrayList<>();
             ArrayList<Integer> B = new ArrayList<>();
             ArrayList<Integer> C = new ArrayList<>();
             for(int i =0; i < a; i++) A.add(s.nextInt());
             for(int i = 0; i < a; i++) B.add(s.nextInt());
             for(int i =0; i < a; i++) C.add(s.nextInt());
             ArrayList<Integer> D = new ArrayList<>();
             int last = -5;
             for(int i =0; i < a; i++){
                 if(i==a-1) {
                     if(D.get(0)!=A.get(i)&&A.get(i)!=last) {
                         D.add(A.get(i));
                         continue;
                     }
                     if(D.get(0)!=B.get(i)&&B.get(i)!=last) {
                         D.add(B.get(i));
                         continue;
                     }
                     if(D.get(0)!=C.get(i)&&C.get(i)!=last) {
                         D.add(C.get(i));
                         continue;
                     }
                 }
                 if(A.get(i)!=last) {
                     D.add(A.get(i));
                     last = A.get(i);
                     continue;
                 }
                 if(B.get(i)!=last) {
                     D.add(B.get(i));
                     last = B.get(i);
                     continue;
                 }
                 if(C.get(i)!=last) {
                     D.add(C.get(i));
                     last = C.get(i);
                     continue;
                 }
             }
            for(int i : D) {
                System.out.print(i + " ");
            }
            if(x-1!=n) {
                System.out.println();
            }



        }



    }
}