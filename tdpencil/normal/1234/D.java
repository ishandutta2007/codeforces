import java.util.*;
import java.io.*;
import java.math.*;


public class A {
	
	static int INF = -2_000_000_000;
	static long MOD = 1_000_000_007;
	static int MAX_PRIME = 1_000_000_000;
	static int MAX_LOG = 20;
	static boolean on[];
	public static void main(String args[]) throws Exception {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		char line[]=fs.next().toCharArray();
		int qq=fs.nextInt();
		int n=line.length;
		TreeSet<Integer> sets[]=new TreeSet[26];
		for(int i = 0; i < 26; i++) sets[i]=new TreeSet<Integer>();
		for(int i = 0; i < n; i++) {
			sets[line[i] - 'a'].add(i);
		}
		for(int q = 0; q < qq; q++) {
			int t=fs.nextInt();
			if(t==1) {
				int pos=fs.nextInt();
				char c=fs.next().toCharArray()[0];
//				out.println(c);
				--pos;
				sets[line[pos]-'a'].remove(pos);
				line[pos]=c;
//				out.println(line[pos]);
				sets[line[pos]-'a'].add(pos);
			} else {
				int l=fs.nextInt(),r=fs.nextInt();
				--l;--r;
				int ans=0;
				for(int i = 0; i < 26; i++) {
					if(sets[i].ceiling(l)!=null&&sets[i].ceiling(l)<=r) {
						++ans;
					}
				}
				out.println(ans);
			}
		}
		out.close();
	}
	
	
	
	
	
	
	
	static boolean isPrime(long x) {
		return miller_rabin(x);
	}
	static boolean miller_rabin(long n) {
		if(n < 2)
			return false;

		for(int pr : new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
			if(n % pr == 0)
				return n == pr;


		Long r = (long) Long.numberOfTrailingZeros(n);
		Long d = (n-1) >> r;

		for(int pr : new int[]{2, 3, 61}) {
			long res = modpow(pr % n, d, n);
			if(res == 1 || res == n - 1) continue;

			while(d != n - 1) {
				res *= res;
				res %= n;
				d >>= 1;

				if(res == 1)
					return false;
				else if(res == n-1)
					break;
			}

			if(res != n - 1)
				return false;
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