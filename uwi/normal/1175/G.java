//package prac;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;


public class ECR66G2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int[] a;
	
	/*
[[0, 9777, 29196, 45342, 70884, 89350, 107220, 132692, 151648, 170604, 189560]]
[[0, 9777, 24375, 40005, 62940, 81082, 97682, 121166, 140122, 159078, 178034]]
[[0, 9777, 24375, 39489, 57726, 75745, 89414, 115829, 133894, 153741, 169269]]
	 */
	void solve()
	{
		int n = ni(), K = ni();
		a = na(n);
		
		long[] dp = new long[n+1];
		Arrays.fill(dp, Long.MAX_VALUE / 100000);
		dp[0] = 0;
		for(int i = 1;i <= K;i++) {
			dp = go(dp);
		}
		out.println(dp[n]);
	}
	
	long[] go(long[] dp)
	{
		int n = dp.length-1;
		long[] ret = new long[n+1];
		int[] stack = new int[n+1];
		int[] times = new int[n+1];
		LiChaoTreeWithNode[] lcts = new LiChaoTreeWithNode[n+1];
		PersistentLiChaoTree plct = new PersistentLiChaoTree(n+1, 0, 17);
		int sp = 0;
		
		// max * (i-j) + dp[j]
		// max * i + max*(-j) + dp[j]
		for(int i = 0;i < n;i++) {
			lcts[i] = new LiChaoTreeWithNode(0, 17);
			lcts[i].add(new LiChaoTreeWithNode.Node(-i, dp[i]));
			
			while(sp > 0 && a[i] > a[stack[sp-1]]){
				lcts[i] = merge(lcts[i], lcts[stack[sp-1]]);
				lcts[stack[sp-1]] = null;
				sp--;
			}
			// x+4
			
			plct.add(sp == 0 ? 0 : times[sp-1], a[i], lcts[i].f(a[i]));
			stack[sp] = i;
			times[sp] = plct.last();
			sp++;
			ret[i+1] = plct.f(plct.last(), i+1);
		}
		return ret;
	}
	
	LiChaoTreeWithNode merge(LiChaoTreeWithNode a, LiChaoTreeWithNode b)
	{
		if(b.num > a.num) {
			LiChaoTreeWithNode d = a; a = b; b = d;
		}
		adds(b.root, a);
		return a;
	}
	
	void adds(LiChaoTreeWithNode.Node x, LiChaoTreeWithNode a)
	{
		if(x == null)return;
		a.add(new LiChaoTreeWithNode.Node(x.a, x.b));
		adds(x.left, a);
		adds(x.right, a);
	}
	
	public static class LiChaoTreeWithNode {
		
		public static class Node
		{
			public long a, b;
			public Node left, right;
			
			public long f(long x)
			{
				return a*x+b;
			}

			public Node(long a, long b) {
				this.a = a;
				this.b = b;
			}

			@Override
			public String toString() {
				return "Node [a=" + a + ", b=" + b + ", " + (left != null ? "left=" + left + ", " : "")
						+ (right != null ? "right=" + right : "") + "]";
			}
		}
		
		public long L, D;
		public Node root;
		public int num;
		
		// [L, L+(1<<D))
		public LiChaoTreeWithNode(long L, int D)
		{
			root = null;
			this.L = L;
			this.D = D;
			num = 0;
		}
		
		// params
		public boolean add(Node x)
		{
			num++;
			long l = L, r = L+(1L<<D);
			Node cur = root;
			Node par = null;
			boolean ret = false;
			int lr = 0;
			// [l,r)
			while(cur != null){
				boolean lessl = x.f(l) < cur.f(l);
				boolean lessr = x.f(r-1) < cur.f(r-1);
				if(!lessl && !lessr){
					// not need to append
					return ret;
				}
				if(lessl && lessr){
					// replace
					if(par != null){
						if(par.left == cur){
							par.left = x;
						}else{
							par.right = x;
						}
					}
					x.left = cur.left;
					x.right = cur.right;
					cur.left = cur.right = null;
					if(root == cur)root = x;
					return true;
				}
//				U.tr("come", l, r, x, cur);
				long m = l + (r-l)/2;
				boolean lessm = x.f(m) < cur.f(m);
				if(lessm){
					// swap
					if(par != null){
						if(par.left == cur){
							par.left = x;
						}else{
							par.right = x;
						}
					}
					x.left = cur.left;
					x.right = cur.right;
					cur.left = cur.right = null;
					if(root == cur)root = x;
					Node d = cur; cur = x; x = d;
					ret = true;
					lessl = !lessl;
					lessr = !lessr;
				}
//				U.tr("come2", l, r, x, cur);
				if(lessl){
					r = m;
					par = cur;
					lr = 0;
					cur = cur.left;
				}else{
					l = m;
					par = cur;
					lr = 1;
					cur = cur.right;
				}
			}
			if(par != null){
				if(lr == 0){
					par.left = x;
				}else{
					par.right = x;
				}
			}else{
				root = x;
			}
			return ret;
		}
		
		public long f(long x)
		{
			assert L <= x;
			assert x < L+(1L<<D);
			long min = Long.MAX_VALUE;
			Node cur = root;
			for(long m = D-1;m >= 0 && cur != null;m--){
				min = Math.min(min, cur.f(x));
				if(x-L<<~m<0){
					cur = cur.right;
				}else{
					cur = cur.left;
				}
			}
			return min;
		}
	}
	
	public static int lowerBound(int[] a, int v){ return lowerBound(a, 0, a.length, v); }
	public static int lowerBound(int[] a, int l, int r, int v)
	{
		if(l > r || l < 0 || r > a.length)throw new IllegalArgumentException();
		int low = l-1, high = r;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h] >= v){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
	}
	
	public static class PersistentLiChaoTree {
		
		// parameters of function
		public long[] as;
		public long[] bs;
		
		public int gen;
		public long L, D;
		public int[] lefts, rights;
		
		public int[] entries;
		public int egen;
		
		// [L, L+(1<<D))
		public PersistentLiChaoTree(int Q, long L, int D)
		{
			as = new long[Q*(D+1)*2+1];
			bs = new long[Q*(D+1)*2+1];
			lefts = new int[Q*(D+1)*2+1];
			rights = new int[Q*(D+1)*2+1];
			Arrays.fill(lefts, -1);
			Arrays.fill(rights, -1);
			
			entries = new int[Q+1];
			Arrays.fill(entries, -1);
			egen = 0;
			
			this.L = L;
			this.D = D;
			
			gen = 0;
			as[gen] = 0; bs[gen] = Long.MAX_VALUE; // dummy
			gen++;
			entries[egen++] = 0;
		}
		
		public int last() { return egen-1; }
		
		public int clone(int id)
		{
			if(id == -1)return -1;
			as[gen] = as[id];
			bs[gen] = bs[id];
			lefts[gen] = lefts[id];
			rights[gen] = rights[id];
			return gen++;
		}
		
		// add ax+b
		public void add(int eid, long a, long b)
		{
			assert 0 <= eid && eid < egen;
			long l = L, r = L+(1L<<D);
			int cur = entries[eid], par = -1, lr = -1;
			// [l,r)
			entries[egen++] = cur = clone(cur);
			
			while(cur != -1){
				boolean lessl = f(l, a, b) < f(l, as[cur], bs[cur]);
				boolean lessr = f(r-1, a, b) < f(r-1, as[cur], bs[cur]);
				if(!lessl && !lessr){
					// not need to append
					return;
				}
				if(lessl && lessr){
					// replace
					as[cur] = a; bs[cur] = b; return;
				}
				long m = l + (r-l)/2;
				boolean lessm = f(m, a, b) < f(m, as[cur], bs[cur]);
				if(lessm){
					// swap
					long da = as[cur], db = bs[cur];
					as[cur] = a; bs[cur] = b;
					a = da; b = db;
					lessl = !lessl;
					lessr = !lessr;
				}
				if(lessl){
					r = m;
					par = cur;
					lr = 0;
					lefts[cur] = clone(lefts[cur]);
					cur = lefts[cur];
				}else{
					l = m;
					par = cur;
					lr = 1;
					rights[cur] = clone(rights[cur]);
					cur = rights[cur];
				}
			}
			if(par != -1){
				if(lr == 0){
					lefts[par] = gen;
				}else{
					rights[par] = gen;
				}
			}
			as[gen] = a; bs[gen] = b;
			gen++;
		}
		
		public long f(int eid, long x)
		{
			assert 0 <= eid && eid < egen;
			assert L <= x;
			assert x < L+(1L<<D);
			int cur = entries[eid];
			long min = Long.MAX_VALUE;
			for(long m = D;m >= 0 && cur != -1;m--){
				min = Math.min(min, f(x, as[cur], bs[cur]));
				if(m == 0)break;
				if(x-L<<~(m-1)<0){
					cur = rights[cur];
				}else{
					cur = lefts[cur];
				}
			}
			return min;
		}
		
		public static long f(long x, long a, long b)
		{
			return a*x+b;
		}
	}


	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new ECR66G2().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}