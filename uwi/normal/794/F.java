//package round414;
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
		int n = ni(), Q = ni();
		int[] a = na(n);
		SegmentTreeArrayL st = new SegmentTreeArrayL(a);
//		for(long[] no : st.node)tr(no);
//		for(int[] ff : st.fs)tr(ff);
//		tr();
		for(int z = 0;z < Q;z++){
			int type = ni();
			if(type == 1){
				int l = ni()-1, r = ni()-1;
				int x = ni(), y = ni();
				st.trans(l, r+1, x, y);
//				for(long[] no : st.node)tr(no);
//				for(int[] ff : st.fs)tr(ff);
//				tr();
			}else{
				int l = ni()-1, r = ni()-1;
				out.println(st.sum(l, r+1));
			}
		}
	}
	
	public static class SegmentTreeArrayL {
		public int M, H, N;
		public long[][] node;
		public int[][] fs;
		public int K = 10;
		
		public SegmentTreeArrayL(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new long[M][];
			for(int i = 0;i < N;i++){
				long[] item = new long[K];
				int v = a[i];
				int d = 1;
				while(v > 0){
					item[v % 10] += d;
					v /= 10;
					d *= 10;
				}
				node[H+i] = item;
			}
			fs = new int[H][];
			for(int i = 0;i < H;i++){
				fs[i] = new int[K];
				for(int j = 0;j < K;j++)fs[i][j] = j;
			}
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int cur)
		{
			if(cur >= H)return;
			node[cur] = prop2(node[2*cur], node[2*cur+1], node[cur], fs[cur]);
		}
		
		private long[] prop2(long[] L, long[] R, long[] C, int[] f)
		{
			if(L != null && R != null){
				if(C == null)C = new long[K];
				Arrays.fill(C, 0);
				for(int i = 0;i < K;i++){
					C[f[i]] += L[i];
				}
				for(int i = 0;i < K;i++){
					C[f[i]] += R[i];
				}
				return C;
			}else if(L != null){
				return prop1(L, C, f);
			}else if(R != null){
				return prop1(R, C, f);
			}else{
				return null;
			}
		}
		
		private long[] prop1(long[] L, long[] C, int[] f)
		{
			if(C == null)C = new long[K];
			for(int i = 0;i < K;i++){
				C[f[i]] += L[i];
			}
			return C;
		}
		
		public void trans(int l, int r, int x, int y)
		{
			trans(l, r, 0, H, 1, x, y);
		}
		
		long[] temp = new long[K];
		
		private void fall(int cur)
		{
			if(cur*2 >= H){
				for(int i = 2*cur;i < 2*cur+2;i++){
					if(node[i] == null)continue;
					Arrays.fill(temp, 0);
					for(int j = 0;j < K;j++){
						temp[fs[cur][j]] += node[i][j];
					}
					for(int j = 0;j < K;j++){
						node[i][j] = temp[j];
					}
				}
			}else{
				for(int i = 2*cur;i < 2*cur+2;i++){
					Arrays.fill(temp, 0);
					for(int j = 0;j < K;j++){
						fs[i][j] = fs[cur][fs[i][j]];
					}
				}
			}
			for(int j = 0;j < K;j++){
				fs[cur][j] = j;
			}
		}
		
		private void trans(int l, int r, int cl, int cr, int cur, int x, int y)
		{
			if(l <= cl && cr <= r){
				if(cur >= H){
					if(y != x){
						node[cur][y] += node[cur][x];
						node[cur][x] = 0;
					}
				}else{
					for(int i = 0;i < K;i++){
						if(fs[cur][i] == x)fs[cur][i] = y;
					}
					propagate(cur);
				}
			}else{
				fall(cur);
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					trans(l, r, cl, mid, 2*cur, x, y);
				}
				if(mid < r && l < cr){
					trans(l, r, mid, cr, 2*cur+1, x, y);
				}
				propagate(2*cur);
				propagate(2*cur+1);
				propagate(cur);
			}
		}
		
		public long sum(int l, int r) {
			long[] N = sum(l, r, 0, H, 1);
			long s = 0;
			for(int i = 1;i < K;i++){
				s += N[i] * i;
			}
			return s;
		}
		
		protected long[] sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return node[cur];
			}else{
				long[] L = null, R = null;
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					L = sum(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					R = sum(l, r, mid, cr, 2*cur+1);
				}
				return prop2(L, R, null, fs[cur]);
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
	private static void trz(Object... o) { System.out.println(Arrays.deepToString(o)); }
}