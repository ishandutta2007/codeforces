//package educational.round22;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = new int[]{ni()-1, ni()-1};
		}
		
		Map<Long, Integer> exs = new HashMap<>();
		QuerySegmentTree qst = new QuerySegmentTree(Q+1);
		for(int i = 0;i < Q;i++){
			int[] q = qs[i];
			long code = (long)q[0]<<32|q[1];
			if(!exs.containsKey(code)){
				exs.put(code, i);
			}else{
				int f = exs.remove(code);
				// [f,i]
				qst.put(f, i, f);
			}
		}
		
		for(int f : exs.values()){
			qst.put(f, Q, f);
		}
		
		// process
		RestorableDisjointSet2 rds = new RestorableDisjointSet2(n*2, Q*2);
		int[] stack = new int[30];
		boolean[] isbip = new boolean[31];
		isbip[0] = true;
		int sp = 0;
		
		for(int i = 0;i < Q;i++){
			int upd = Integer.bitCount((i^i-1)&(qst.M-1));
			if(i > 0){
				for(int j = 0;j < upd;j++){
					// pop
					rds.revert(stack[--sp]);
				}
			}
			for(int j = upd-1;j >= 0;j--){
				// push
				boolean base = isbip[sp];
				L node = qst.st[qst.H+i>>>j];
				stack[sp++] = rds.hp;
				if(node != null){
					for(int k = 0;k < node.size();k++){
						int[] q = qs[node.a[k]];
						rds.union(q[0], q[1]+n);
						rds.union(q[0]+n, q[1]);
						base &= !rds.equiv(q[0], q[0]+n);
					}
				}
				isbip[sp] = base;
			}
			
			out.println(isbip[sp] ? "YES" : "NO");
		}
	}
	
	public static class L {
		public int[] a;
		public int p = 0;
		
		public L(int n) { a = new int[n]; }
		public L add(int n)
		{
			if(p >= a.length)a = Arrays.copyOf(a, a.length*3/2+1);
			a[p++] = n;
			return this;
		}
		public int size() { return p; }
		public L clear() { p = 0; return this; }
		public int[] toArray() { return Arrays.copyOf(a, p); }
		@Override
		public String toString() {return Arrays.toString(toArray());}
	}

	
	public class QuerySegmentTree
	{
		public int M, H, N;
		public L[] st;
		
		public QuerySegmentTree(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new L[M];
		}
		
		public void put(int l, int r, int qid){
			if(l >= r)return;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				L q = st[(H+l)/f];
				if(q == null)q = st[(H+l)/f] = new L(1);
				q.add(qid);
				l += f;
			}
			
			while(l < r){
				int f = r&-r;
				L q = st[(H+r)/f-1];
				if(q == null)q = st[(H+r)/f-1] = new L(1);
				q.add(qid);
				r -= f;
			}
		}
		
		//////////////////////////// end
	}
	
	public static class RestorableDisjointSet2 {
		public int[] upper; // minus:num_element(root) plus:root(normal)
		private int[] targets;
		private int[] histupper;
		public int hp = 0;
		
		public RestorableDisjointSet2(int n, int m)
		{
			upper = new int[n];
			Arrays.fill(upper, -1);
			
			targets = new int[2*m];
			histupper = new int[2*m];
			// 
//				w = new int[n];
		}
		
		public RestorableDisjointSet2(RestorableDisjointSet2 ds)
		{
			this.upper = Arrays.copyOf(ds.upper, ds.upper.length);
			this.histupper = Arrays.copyOf(ds.histupper, ds.histupper.length);
			// 
			this.hp = ds.hp;
		}
		
		public int root(int x)
		{
			return upper[x] < 0 ? x : root(upper[x]);
		}
		
		public boolean equiv(int x, int y)
		{
			return root(x) == root(y);
		}
		
		public boolean union(int x, int y)
		{
			x = root(x);
			y = root(y);
			if(x != y) {
				if(upper[y] < upper[x]) {
					int d = x; x = y; y = d;
				}
//					w[x] += w[y];
				record(x); record(y);
				upper[x] += upper[y];
				// 
				upper[y] = x;
			}
			return x == y;
		}
		
		public int time() { return hp; }
		
		private void record(int x)
		{
			targets[hp] = x;
			histupper[hp] = upper[x];
			// 
			hp++;
		}
		
		public void revert(int to)
		{
			while(hp > to){
				upper[targets[hp-1]] = histupper[hp-1];
				// 
				hp--;
			}
		}
		
		public int count()
		{
			int ct = 0;
			for(int u : upper){
				if(u < 0)ct++;
			}
			return ct;
		}
		
		public int[][] makeUp()
		{
			int n = upper.length;
			int[][] ret = new int[n][];
			int[] rp = new int[n];
			for(int i = 0;i < n;i++){
				if(upper[i] < 0)ret[i] = new int[-upper[i]];
			}
			for(int i = 0;i < n;i++){
				int r = root(i);
				ret[r][rp[r]++] = i;
			}
			return ret;
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
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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