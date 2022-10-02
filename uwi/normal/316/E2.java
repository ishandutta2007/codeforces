//package abbyy3;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	static long[] f;
	static long[] fcum;
	static int mod = 1000000000;
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = na(n);
		int N = 200002;
		f = new long[N];
		f[0] = f[1] = 1;
		for(int i = 2;i < N;i++){
			f[i] = f[i-1] + f[i-2];
			if(f[i] >= mod){
				f[i] -= mod;
			}
		}
		fcum = new long[N+1];
		for(int i = 1;i <= N;i++){
			fcum[i] = fcum[i-1] + f[i-1];
			if(fcum[i] >= mod){
				fcum[i] -= mod;
			}
		}
		SegmentTreeNode st = new SegmentTreeNode(a);
		for(int i = 0;i < m;i++){
			int t = ni();
			if(t == 1){
				int x = ni()-1, v = ni();
				long plus = v + mod - st.sum(x, x+1);
				if(plus >= mod)plus -= mod;
				st.add(x, x+1, (int)plus);
			}else if(t == 2){
				int l = ni()-1, r = ni()-1;
				out.println(st.sum(l, r+1));
			}else{
				int l = ni()-1, r = ni()-1, d = ni();
				st.add(l, r+1, d);
			}
		}
	}
	
	public static class SegmentTreeNode {
		public int M, H, N;
		public Node[] node;
		public int[] plus;
		
		private static class Node
		{
			public long up;
			public long lo;
			public int size;
			
			public Node() {
				size = 1;
			}
		}
		
		public SegmentTreeNode(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new Node[M];
			plus = new int[H];
			for(int i = 0;i < N;i++){
				node[H+i] = new Node();
				node[H+i].up = a[i];
				node[H+i].lo = a[i];
			}
			for(int i = (M>>1)-1;i >= 1;i--){
				propagate(i);
			}
		}
//		private void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
		
		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], plus[cur], node[cur]);
		}
		
		private Node prop2(Node L, Node R, int plus, Node C)
		{
			if(L != null && R != null){
				if(C != null){
				}else{
					C = new Node();
				}
				
				long a = f[L.size];
				long b = f[L.size-1];
				long c = L.size-2 >= 0 ? f[L.size-2] : 0;
				
				C.size = L.size + R.size;
				C.up = (int)((L.up + (a*R.up+b*R.lo) + plus*fcum[C.size+1])%mod);
				C.lo = (int)((L.lo + (b*R.up+c*R.lo) + plus*fcum[C.size])%mod);
				
//				tr(L.up, L.lo, R.up, R.lo, plus, C.up, C.lo);
				return C;
			}else if(L != null){
				return prop1(L, plus, C);
			}else if(R != null){
				return prop1(R, plus, C);
			}else{
				return null;
			}
		}
		
		private Node prop1(Node L, int plus, Node C)
		{
			if(C != null){
			}else{
				C = new Node();
			}
			C.size = L.size;
			C.up = (int)((L.up + plus*fcum[C.size+1])%mod);
			C.lo = (int)((L.lo + plus*fcum[C.size])%mod);
			return C;
		}
		
		public void add(int l, int r, int v) { if(l < r)add(l, r, v, 0, H, 1); }
		
		protected void add(int l, int r, int v, int cl, int cr, int cur)
		{
			if(cur >= H){
				node[cur].up += v;
				if(node[cur].up >= mod){
					node[cur].up -= mod;
				}
				node[cur].lo = node[cur].up;
			}else if(l <= cl && cr <= r){
				plus[cur] += v;
				if(plus[cur] >= mod){
					plus[cur] -= mod;
				}
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				if(Math.max(l, cl) < Math.min(r, mid)){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(Math.max(l, mid) < Math.min(r, cr)){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public long sum(int l, int r) {
			Node S = sum(l, r, 0, H, 1);
			if(S == null)return 0;
			return S.lo;
		}
		
		protected Node sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return node[cur];
			}else{
				Node L = null, R = null;
				int mid = cl+cr>>>1;
				if(Math.max(l, cl) < Math.min(r, mid)){
					L = sum(l, r, cl, mid, 2*cur);
				}
				if(Math.max(l, mid) < Math.min(r, cr)){
					R = sum(l, r, mid, cr, 2*cur+1);
				}
				return prop2(L, R, plus[cur], null);
			}
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
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