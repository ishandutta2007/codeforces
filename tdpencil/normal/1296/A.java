import java.math.BigInteger;
import java.util.*;
import java.io.*;
import java.lang.Math;
public class run {
    static class fr {
        BufferedReader br;
        StringTokenizer st;

        public fr() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        int[] readArr(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = this.nextInt();
            }
            return a;
        }
    }

    static int sum(int[] a) {
        int s = 0;
        for (int i : a) s += i;
        return s;
    }

    static boolean unique(int n[]) {
        HashSet<Integer> s = new HashSet<>();
        for (int i : n) s.add(i);
        return s.size() > 1;
    }
    static class Vector{
        ArrayList<Integer> N;
        public Vector(){
            ArrayList<Integer> N = new ArrayList<>();
        }
        public int get(int d) {
            return N.get(d);
        }
        public void add(int d) {
            N.add(d);
        }
        public void erase(int d) {
            N.remove(d);
        }
        public int size() {
            return N.size();
        }
        public int sum() {
            int s=0;
            for(int i : N) s+=i;
            return s;
        }
        public int max() {
            int mx = Integer.MIN_VALUE;
            for(int i : N) mx=Math.max(i, mx);
            return mx;
        }
        public int min() {
            if(N.size()<1) return 0;
            int mn = Integer.MAX_VALUE;
            for(int i: N) mn=Math.min(i, mn);
            return mn;
        }
        public int search(int val) {
            for(int i =0; i < N.size(); i++) {
                if(N.get(i)==val) return i;
            }
            return -1;
        }
        public void sort() {
            Collections.sort(N);
        }

    }

    public static void main(String args[]) {
        fr s = new fr();
        int n = s.nextInt();
        for (int x = 0; x < n; x++) {
            int t= s.nextInt();
            int dp[] = new int[t];
            for(int i =0; i < t; i++) {
                dp[i] = s.nextInt();
            }
            if(sum(dp)%2==1) System.out.println("YES");
            else {
                int oc=0;
                int ec=0;
                for(int i =0; i < t; i++) {
                    if(dp[i]%2==0) ec++;
                    if(dp[i]%2==1) oc++;
                }
                if(ec>0&&oc>0) {
                    System.out.println("YES");
                } else System.out.println("NO");
            }
        }
    }
}