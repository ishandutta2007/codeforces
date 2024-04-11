import java.util.*;
import java.io.*;
import java.lang.*;


public class A {

    static int INF = -2_000_000_000;
    static long MOD = 1_000_000_007;
    static int MAX_PRIME = 1_000_000_000;
    static int MAX_LOG = 20;
    static boolean on[];
    public static void main(String args[]) throws Exception {
        FastScanner fs=new FastScanner();
        PrintWriter out=new PrintWriter(System.out);
        int tt=fs.nextInt();
        for(int tc=0; tc < tt; ++tc) {
        	int n=fs.nextInt();
        	ArrayList<Integer> ar=new ArrayList<>();
        	ar.add(0);
        	for(int i = 0; i < n; ++i) {
        		ar.add(fs.nextInt());
        	}
        	ar.add(0);
        	long cnt=0;
        	for(int i = 1; i < n + 1; ++i) {
        		if(ar.get(i)>ar.get(i-1)&&ar.get(i)>ar.get(i+1)) {
        			cnt+=ar.get(i)-Math.max(ar.get(i-1), ar.get(i+1));
        			ar.set(i, Math.max(ar.get(i-1), ar.get(i+1)));
        		}
        	}
        	for(int i = 0; i < n + 1; ++i) {
        		cnt+=Math.abs(ar.get(i)-ar.get(i+1));
        	}
        	out.println(cnt);
        }
        
        out.close();
    }

    static class coordinate_compress {
        HashMap<Integer, Integer> position;
        public coordinate_compress(int a[]) {
            position = new HashMap<>();
            Pair points[]=new Pair[a.length];
            randomShuffleSort(a);
            for(int i = 0; i < a.length; i++) points[i] = new Pair(a[i], i);
            for(int i = 0; i < a.length; i++) if(!position.containsKey(a[i])) position.put(a[i], i);
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
        public int getIdx(int val) {
            return position.get(val);
        }
    }



    static boolean isprime(long X) {
        return miller_rabin(X);
    }

    static long modmul(long a, long b, long M) {
        long ret = a * b - M * (long)(1.0 / M * a * b);
        return ret + M * (ret < 0 ? 1 : 0) - M * (ret >= M ? 1 : 0);
    }
    static boolean miller_rabin(long n) {
        if(n < 2 || n % 6 % 4 != 1 ) return (n | 1) == 3;

        long nums[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
        long s = Long.numberOfTrailingZeros(n - 1), d = n >> s;
        for(long a : nums) {
            long p = modpow(a%n, d, n), i = s;
            while(p != 1 && p != n - 1 && (a%n!=0) && (i-- != 0)) {
                p = modmul(p, p, n);
            }

            if(p != n-1 && i != s) return false;
        }
        return true;
    }






    static class bit {
        long tree[];
        int l;
        public bit(int x) {
            l = x;
            tree = new long[l + 1];
        }

        public void add(int idx, long val) {
            for(++idx; idx <= l; idx += idx & -idx) {
                tree[idx] += val;
            }
        }

        public long query(int idx) {
            long s =0;
            for(++idx; idx > 0; idx -= idx & -idx)
                s += tree[idx];
            return s;
        }

        public long rangeQuery(int l, int r) {
            if(l == 0)
                return query(r);
            else
                return query(r) - query(l - 1);
        }

        public void upd(int l, int r, long val) {
            add(l, val);
            add(r + 1, -val);
        }

    }
    static long modpow(long x, long y, long MOD) {
        if(y == 0)
            return 1;

        long mid = modpow(x, y/2, MOD);
        if((y&1)==1) {
            return (((mid*mid)%MOD)*x)%MOD;
        } else {
            return (mid*mid)%MOD;
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
                return this.second<x.second?-1:(this.second==x.second?0:1);
            return 1;
        }
    }



    static class RangeMin {
        long logs[], st[][];
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