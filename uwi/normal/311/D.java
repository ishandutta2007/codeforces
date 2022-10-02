//package round185;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static int mod = 95542721;
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		for(int i = 0;i < n;i++){
			a[i] %= mod;
		}
		
		SegmentTreeRSQ st = new SegmentTreeRSQ(a);
		int q = ni();
		for(int i = 0;i < q;i++){
			int t = ni();
			if(t == 1){
				out.println(st.sum(ni()-1, ni()));
			}else{
				st.add(ni()-1, ni());
			}
//			tr(t);
//			tr(st.plus);
		}
	}
	
	public static class SegmentTreeRSQ {
		public int M, H, N;
		public Node[] ns;
		public int[] plus;
		
		private static class Node
		{
			public int[] st;
			public int ptr;
			
			public Node() {
				st = new int[48];
			}
		}
		
		public SegmentTreeRSQ(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			ns = new Node[M];
			plus = new int[H];
			for(int i = 0;i < N;i++){
				ns[H+i] = new Node();
				ns[H+i].st[0] = a[i];
				long cur = a[i];
				for(int j = 1;j < 48;j++){
					cur = cur*cur%mod*cur%mod;
					ns[H+i].st[j] = (int)cur;
				}
			}
			for(int i = (M>>1)-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void propagate(int cur)
		{
			ns[cur] = prop2(ns[2*cur], ns[2*cur+1], plus[cur], ns[cur]);
		}
		
		private Node prop2(Node L, Node R, int plus, Node C)
		{
			if(L != null && R != null){
				if(C != null){
				}else{
					C = new Node();
				}
				for(int j = 0, lp = L.ptr, rp = R.ptr;j < 48;j++, lp++, rp++){
					if(lp == 48)lp = 0;
					if(rp == 48)rp = 0;
					int a = L.st[lp]+R.st[rp];
					if(a >= mod)a -= mod;
					C.st[j] = a;
				}
				C.ptr = plus;
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
			for(int j = 0, lp = L.ptr;j < 48;j++, lp++){
				if(lp == 48)lp = 0;
				C.st[j] = L.st[lp];
			}
			C.ptr = plus;
			return C;
		}
		
		public void add(int l, int r) { add(l, r, 0, H, 1); }
		
		protected void add(int l, int r, int cl, int cr, int cur)
		{
			if(cur >= H){
				if(++ns[cur].ptr == 48)ns[cur].ptr = 0;
			}else if(l <= cl && cr <= r){
				if(++plus[cur] == 48)plus[cur] = 0;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				if(Math.max(l, cl) < Math.min(r, mid)){
					add(l, r, cl, mid, 2*cur);
				}
				if(Math.max(l, mid) < Math.min(r, cr)){
					add(l, r, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public int sum(int l, int r) {
			Node N = sum(l, r, 0, H, 1);
			return N.st[N.ptr];
		}
		
		protected Node sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return ns[cur];
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
	
	public static void main(String[] args) throws Exception { new D4().run(); }
	
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