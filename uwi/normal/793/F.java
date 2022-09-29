//package tinkoff2017.e;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] rs = new int[m][];
		for(int i = 0;i < m;i++){
			rs[i] = na(2);
		}
		int Q = ni();
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = new int[]{ni(), ni(), i};
		}
		Arrays.sort(qs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		Arrays.sort(rs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		// [l,r]
		// x <= ly >= ly = r
		
		int[] u = new int[n+1];
		for(int i= 0;i < n+1;i++)u[i] = i;
		SegmentTreeNodeSimple st = new SegmentTreeNodeSimple(u);
		int rp = 0, qp = 0;
		int[] anss = new int[Q];
		for(int x = 0;x < n+1;x++){
			while(rp < m && rs[rp][1] <= x){
				int[] r = rs[rp++];
				st.add(0, r[0]+1, r[0], r[1]);
			}
//			for(int i = 1;i < st.H+st.N;i++){
//				tr(i, st.node[i].a);
//			}
			while(qp < Q && qs[qp][1] <= x){
				int[] q = qs[qp++];
				anss[q[2]] = st.attack(q[0]);
			}
		}
		for(int ans : anss){
			out.println(ans);
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

	
	public static class SegmentTreeNodeSimple {
		public int M, H, N;
		public Node[] node;
		
		private static class Node
		{
			L a;
			
			public Node() {
				a = new L(2);
			}
		}
		
		public SegmentTreeNodeSimple(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new Node[M];
			for(int i = 1;i < H+N;i++){
				node[i] = new Node();
			}
		}
		
		void merge(Node n, int a, int b)
		{
			while(n.a.size() > 0 && a <= n.a.a[n.a.p-1]){
				a = Math.min(a, n.a.a[n.a.p-2]);
				n.a.p -= 2;
			}
			n.a.add(a).add(b);
		}
		
		void fall(int cur)
		{
			for(int i = 0;i < 2;i++){
				for(int j = 0;j < node[cur].a.p;j+=2){
					merge(node[2*cur+i], node[cur].a.a[j], node[cur].a.a[j+1]);
				}
			}
			node[cur].a.clear();
		}
		
		public void add(int l, int r, int q0, int q1) { if(l < r)add(l, r, 0, H, 1, q0, q1); }
		
		protected void add(int l, int r, int cl, int cr, int cur, int q0, int q1)
		{
			if(cur >= H){
				merge(node[cur], q0, q1);
			}else if(l <= cl && cr <= r){
				merge(node[cur], q0, q1);
			}else{
				fall(cur);
				
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					add(l, r, cl, mid, 2*cur, q0, q1);
				}
				if(mid < r && l < cr){
					add(l, r, mid, cr, 2*cur+1, q0, q1);
				}
			}
		}
		
		public int attack(int x)
		{
			int ret = x;
			for(int i = H+x;i >= 1;i>>>=1){
				int ind = Arrays.binarySearch(node[i].a.a, 0, node[i].a.p, ret);
				if(ind < 0)ind = -ind-2;
				if((ind&1) == 0){
					ret = node[i].a.a[ind+1];
				}
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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