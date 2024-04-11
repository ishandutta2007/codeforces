import java.io.*;
import java.util.*;

public class F implements Runnable {
	public static void main (String[] args) {new Thread(null, new F(), "_cf", 1 << 28).start();}
	
	public void run() {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		System.err.println("");

		int n = fs.nextInt();
		int[] a = fs.nextIntArray(n);
		TreeSet<Integer>[] locs = new TreeSet[n];
		for(int i = 0; i < n; i++) locs[i] = new TreeSet<Integer>();
		for(int i = 0; i < n; i++) {
			a[i]--;
			locs[a[i]].add(i);
		}
		int[] next = new int[n];
		for(int i = 0; i < n; i++) {
			Integer nxt = locs[a[i]].higher(i);
			if(nxt == null) nxt = n;
			next[i] = nxt;
		}
		RMQ rmq = new RMQ(a, false);
		RMQ rmq2 = new RMQ(next, true);
		int res = 0;
		for(int i = 0; i < n; i++) {
			int L = i, R = i;
			while(R < n) {
				int size = rmq.query(L, R)+1;
				if(size > R-L+1) {
					R = L+size-1;
					continue;
				}
				int dup = rmq2.query(L, R);
				if(dup <= R) break;
				res++;
				R++;
			}
		}
		out.println(res);
		
		out.close();
	}
	
	class RMQ {
		int[] vs;
		int[][] lift;
		boolean min;
		
		public RMQ(int[] vs, boolean min) {
			this.vs = vs;
			this.min = min;
			int n = vs.length;
			int maxlog = Integer.numberOfTrailingZeros(Integer.highestOneBit(n)) + 2;
			lift = new int[maxlog][n];
			for (int i = 0; i < n; i++) {
				lift[0][i] = vs[i];
			}
			int lastRange = 1;
			for (int lg = 1; lg < maxlog; lg++) {
				for (int i = 0; i < n; i++) {
					int v1 = lift[lg - 1][i];
					int v2 = lift[lg - 1][Math.min(i + lastRange, n - 1)];
					if(min) {
						lift[lg][i] = Math.min(v1, v2);
					}
					else {
						lift[lg][i] = Math.max(v1, v2);
					}
				}
				lastRange *= 2;
			}
		}

		public int query(int low, int hi) {
			int range = hi - low + 1;
			int exp = Integer.highestOneBit(range);
			int lg = Integer.numberOfTrailingZeros(exp);
			if(min) {
				return Math.min(lift[lg][low] , lift[lg][hi-exp+1]);
			}
			else {
				return Math.max(lift[lg][low] , lift[lg][hi-exp+1]);
			}
		}
	}
	

	class FastScanner {
		public int BS = 1<<16;
		public char NC = (char)0;
		byte[] buf = new byte[BS];
		int bId = 0, size = 0;
		char c = NC;
		double num = 1;
		BufferedInputStream in;

		public FastScanner() {
			in = new BufferedInputStream(System.in, BS);
		}

		public FastScanner(String s) throws FileNotFoundException {
			in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
		}

		public char nextChar(){
			while(bId==size) {
				try {
					size = in.read(buf);
				}catch(Exception e) {
					return NC;
				}                
				if(size==-1)return NC;
				bId=0;
			}
			return (char)buf[bId++];
		}

		public int nextInt() {
			return (int)nextLong();
		}

		public long nextLong() {
			num=1;
			boolean neg = false;
			if(c==NC)c=nextChar();
			for(;(c<'0' || c>'9'); c = nextChar()) {
				if(c=='-')neg=true;
			}
			long res = 0;
			for(; c>='0' && c <='9'; c=nextChar()) {
				res = (res<<3)+(res<<1)+c-'0';
				num*=10;
			}
			return neg?-res:res;
		}

		public double nextDouble() {
			double cur = nextLong();
			return c!='.' ? cur:cur+nextLong()/num;
		}

		public String next() {
			StringBuilder res = new StringBuilder();
			while(c<=32)c=nextChar();
			while(c>32) {
				res.append(c);
				c=nextChar();
			}
			return res.toString();
		}

		public String nextLine() {
			StringBuilder res = new StringBuilder();
			while(c<=32)c=nextChar();
			while(c!='\n') {
				res.append(c);
				c=nextChar();
			}
			return res.toString();
		}

		public boolean hasNext() {
			if(c>32)return true;
			while(true) {
				c=nextChar();
				if(c==NC)return false;
				else if(c>32)return true;
			}
		}
		
		public int[] nextIntArray(int n) {
			int[] res = new int[n];
			for(int i = 0; i < n; i++) res[i] = nextInt();
			return res;
		}
		
	}

	
}