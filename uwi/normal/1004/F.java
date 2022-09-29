//package round495;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), X = ni();
		int[] a = na(n);
		SegmentTreeNode st = new SegmentTreeNode(a, X);
		for(int z = 0;z < m;z++){
			int type = ni();
			if(type == 1){
				int pos = ni()-1;
				int y = ni();
				st.update(pos, y);
			}else{
//				for(int i = 1;i < st.M;i++){
//					tr(i, st.node[i].pre, st.node[i].suf, st.node[i].count);
//				}
				int l = ni()-1;
				int r = ni()-1;
				out.println(st.sum(l, r+1));
			}
		}
	}
	
	public static class SegmentTreeNode {
		public int M, H, N;
		public Node[] node;
		public int X;
		
		private static class Node
		{
			public long count;
			public long[] pre;
			public long[] suf;
			
			public Node() {
			}
		}
		
		public long[] merge(long[] p1, long[] p2)
		{
			long[] ret = Arrays.copyOf(p1, p1.length+p2.length);
			int p = p1.length;
			for(long u : p2){
				if(p == 0 || (ret[p-1]>>>32 | u>>>32) != ret[p-1]>>>32){
					ret[p] = u|ret[p-1]>>>32<<32;
					p++;
				}else{
					ret[p-1] += (int)u;
				}
			}
			return Arrays.copyOf(ret, p);
		}
		
		public long countup(long[] suf, long[] pre)
		{
			int numpre = 0;
			for(int i = 0;i < pre.length;i++)numpre += (int)pre[i];
			
			long ret = 0;
			int p = 0;
			for(int i = suf.length-1;i >= 0;i--){
				while(p < pre.length && (suf[i]>>>32|pre[p]>>>32) < X){
					numpre -= (int)pre[p];
					p++;
				}
				ret += (long)((int)suf[i]) * numpre;
			}
			return ret;
		}
		
		public void set(int pos, int v)
		{
			node[pos] = new Node();
			node[pos].count = v >= X ? 1 : 0;
			node[pos].pre = node[pos].suf = new long[]{(long)v<<32|1};
		}
		
		public SegmentTreeNode(int[] a, int X)
		{
			this.X = X;
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new Node[M];
			for(int i = 0;i < N;i++){
				set(H+i, a[i]);
			}
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], node[cur]);
		}
		
		private Node prop2(Node L, Node R, Node C)
		{
			if(L != null && R != null){
				if(C == null)C = new Node();
				C.count = countup(L.suf, R.pre) + L.count + R.count;
				C.pre = merge(L.pre, R.pre);
				C.suf = merge(R.suf, L.suf);
				return C;
			}else if(L != null){
				return prop1(L, C);
			}else if(R != null){
				return prop1(R, C);
			}else{
				return null;
			}
		}
		
		private Node prop1(Node L, Node C)
		{
			if(C == null)C = new Node();
			C.count = L.count;
			C.pre = L.pre;
			C.suf = L.suf;
			return C;
		}
		
		public void update(int pos, int v) {
			set(H+pos, v);
			for(int i = H+pos>>>1;i >= 1;i>>>=1)propagate(i);
		}
		
		public long sum(int l, int r) {
			Node N = sum(l, r, 0, H, 1);
			return N == null ? 0 : N.count;
		}
		
		protected Node sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return node[cur];
			}else{
				Node L = null, R = null;
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					L = sum(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = sum(l, r, mid, cr, 2*cur+1);
				}
				return prop2(L, R, null);
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