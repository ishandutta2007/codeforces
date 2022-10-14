// package com.company;

// import com.sun.source.tree.Tree;

import java.io.*;
import java.util.*;
import java.lang.*;
public class Main {
    static long M = 998244353;
    public static void main(String[] args) {
        FastScanner fs=new FastScanner();
        int T = 1;
        PrintWriter out=new PrintWriter(System.out);

        loop: for(int test_case = 1; test_case <= T; test_case++) {
            int n = fs.nextInt(), m =fs.nextInt();
            long a[] = new long[n];
            long b[] = new long[m];

            for(int i = 0; i < n; i++)
                a[i] = fs.nextLong();
            for(int i = 0; i < m; i++)
                b[i] = fs.nextLong();

            long w = 0;
            for(int i = 1; i < n; i++) {
                w = gcd(w, a[i] - a[i - 1]);
            }

            for(int i = 0; i < m; i++) {
                if(w % b[i] == 0) {
                    out.println("YES");
                    out.println(a[0] + " " + (i + 1));
                    continue loop;
                }
            }

            out.println("NO");
        }

        out.close();
    }

    static long gcd(long x, long y) {
        return y==0?x:gcd(y, x%y);
    }
    static class RangeMin {
        long logs[], st[][];
        // sparse table?
        int N, K;
        public RangeMin(int n) {
            N=n;
            K = (int)((double) (Math.log10((double)n) /(double) Math.log10((double)2) ));
            st = new long [N+2][K+2];
            logs = new long[N+2];
        }
        void init(ArrayList<Integer> A) {

            for(int i = 0; i < N; i++) {
                Arrays.fill(st[i], (long)1e18);
                st[i][0]=(long)A.get(i);
            }
            // NLOGN
            for(int j = 1; j <= K; j++) {
                for(int i = 0; i + (1<<j) <= N; i++) {
                    st[i][j]=Math.min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
                }
            }
            logs[1]=0;
            for(int i = 2; i <= N; i++) {
                logs[i]=logs[i/2]+1;
            }
        }
        void init(int [] A) {

            for(int i = 0; i < N; i++) {
                Arrays.fill(st[i], (long)1e18);
                st[i][0]=(long)A[i];
            }
            // NLOGN
            for(int j = 1; j <= K; j++) {
                for(int i = 0; i + (1<<j) <= N; i++) {
                    st[i][j]=Math.min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
                }
            }
            logs[1]=0;
            for(int i = 2; i <= N; i++) {
                logs[i]=logs[i/2]+1;
            }
        }

        long query(int L, int R) {
            int j = (int)logs[R-L+1];
            return Math.min(st[L][j], st[R - (1 << j) + 1][j]);
        }
    }

    static class Pair implements Comparable<Pair>{
        long first, second;
        public Pair(long l, long i) {
            first=l;second=i;
        }
        public Pair() {
            first=0;second=0;
        }
        public int compareTo(Pair x) {
            if(this.first<x.first)
                return -1;
            if(this.first==x.first)
                return Long.compare(this.second, x.second);
            return 1;
        }
    }

    static class FastScanner
    {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner()
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
        public int[] nextArray(int n) {
            int a[] = new int[n];
            for(int i =0; i < n; i++) a[i]=this.nextInt();
            return a;
        }
        public int max(int a[]) {
            int mx = Integer.MIN_VALUE;
            for(int i : a)
                mx = Math.max(i, mx);
            return mx;
        }
        public int count(int a[], int val) {
            int ans =0;
            for(int i : a)
                ans += val == i ? 1 : 0;
            return ans;
        }
        public int min(int a[]) {
            int mn = Integer.MAX_VALUE;
            for(int i : a)
                mn = Math.min(i, mn);
            return mn;
        }
        public void randomShuffleSort(int []a) {
            Random r = new Random();
            for(int i =0; i < (a.length)/2; i++) {
                int temp=a[i],p=r.nextInt(a.length);
                a[i]=a[p];
                a[p]=temp;
            }
            Arrays.sort(a);
        }
        public void fine_sort(int a[]) {
            ArrayList<Integer> A = new ArrayList<>();
            for(int i : a) A.add(i);
            Collections.sort(A);
            for(int i=0; i < a.length; i++) {
                a[i]=A.get(i);
            }
        }
    }


}