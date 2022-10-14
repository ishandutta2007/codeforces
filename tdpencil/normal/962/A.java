import java.util.*;
import java.io.*;
import java.lang.Math;


public class A {
	
	static int INF = -2_000_000_000;
	static long MOD = 1_000_000_007;
	static int MAX_PRIME = 1_000_000_000;
	public static void main(String args[]) {
		FastScanner fs=new FastScanner();
		int t =1;
outer: for(int tt=0; tt < t; tt++) {
            int N = fs.nextInt();
            int A[] = new int[N];
            for(int i = 0; i < N; i++) {
                A[i] = fs.nextInt();
            }

            int prefix[] = new int[N];
            int S = 0;
            for(int i : A) S += i;
            prefix[0] = A[0];
            for(int i = 1; i < N; i++) {
                prefix[i] = prefix[i - 1] + A[i];
            }
            S = S / 2 + S % 2;
            for(int i =0; i < N; i++) {
                if(prefix[i] >= S) {
                    System.out.println(i + 1);
                    continue outer;
                }
            }
		}
	}

    static boolean isprime(long X) {
        return miller_rabin(X);
    }
	
	static long modmul(long a, long b, long M) {
		long ret = a * b - M * (long)(1.0 / M * a * b);
		return ret + M * (ret < 0 ? 1 : 0) - M * (ret >= (long)M ? 1 : 0);
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
	
	static boolean perfectSquare(int x) {
		return (int)Math.sqrt(x) * (int)Math.sqrt(x) == x;
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
            this.fine_sort(a);
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
	static class SegTree {
		int SIZE;
		// change to longs sirs
		int array[];
		int vals[];
		int lazy[];
		SegTree(int a[]) {
			int S = a.length;
			SIZE = 1;
			while(SIZE < S) SIZE *= 2;
			array = new int[2 * SIZE];
		}
		
		void build(int rt, int v1, int v2) {
			
		}
	}
	static class SegmentTree {
    	int leftmost, rightmost;
    	SegmentTree lChild, rChild;
    	int sum;
    	long lz_val;
    	
    	public SegmentTree(int l, int r, int a[]) {
    		leftmost = l;
    		rightmost = r;
    		lz_val=0;
    		if(l == r)
    			sum = a[l];
    		else {
    			int mid = (l + r) / 2;
    			lChild = new SegmentTree(l, mid, a);
    			rChild = new SegmentTree(mid+1, r, a);
    			update();
    		}
    	}
    	public void update() {
    		sum = lChild.sum + rChild.sum + (int)lChild.lz_val + (int)rChild.lz_val;
    	}
    	public void pointUpdate(int pos, int val) {
    		if(leftmost == rightmost) {
    			sum = val;
    		} else {
    			int mid = (leftmost + rightmost) / 2;
    			if(pos <= lChild.rightmost) lChild.pointUpdate(pos, val);
    			else rChild.pointUpdate(pos, val);
    			update();
    		}
    	}
    	public void rangeUpdate(int l, int r, int val) {
    		// first check if it's within the range
    		if(l <= leftmost && r >= rightmost) {
    			lz_val += val;
    		} else {
    			// its not within the range so lets update the left if we have to and update the right if we have to
    			if(lChild.rightmost >= l) lChild.rangeUpdate(l, r, val);
    			if(rChild.leftmost <= r) rChild.rangeUpdate(l, r, val);
    			update();
    		}
    	}
    	public long query(int l, int r) {
    		if(l > rightmost || r < leftmost) return 0;
    		else if(l <= leftmost && r >= rightmost) return sum + lz_val;
    		
    		return (long) lChild.query(l, r) + (long) rChild.query(l, r);
    	}
    }
}