//package grakn2020;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = na(n);
		}

		int[] rs = new int[n*(n-1)/2+1];
		int[] cs = new int[n*(n-1)/2+1];
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				rs[a[i][j]] = i;
				cs[a[i][j]] = j;
			}
		}

		long[][] ps = new long[n][];
		for(int i = 0;i < n;i++){
			ps[i] = new long[]{1};
		}
		DJSet ds = new DJSet(n);

		int[] hits = new int[n];
		outer:
		for(int i = 1;i <= n*(n-1)/2;i++){
//			tr(i, rs[i], cs[i]);
			ds.union(rs[i], cs[i]);
			hits[rs[i]]++;
			hits[cs[i]]++;
			int z = -ds.upper[ds.root(rs[i])];
//			tr("nes", ds.nes, hits);
			if(ds.nes[ds.root(rs[i])] == z*(z-1)/2){
//				for(int j = 0;j < n;j++){
//					if(ds.equiv(rs[i], j)){
//						tr(i, j, hits[j], z);
//					}
//				}
				for(int j = 0;j < n;j++){
					if(ds.equiv(rs[i], j) && hits[j] != z-1){
						continue outer;
					}
				}
				long[] P = ds.ps[ds.root(rs[i])];
				P = Arrays.copyOf(P, z);
				P[z-1]++;
				ds.ps[ds.root(rs[i])] = P;
//				tr(i, P);
			}
		}
		long[] V = ds.ps[ds.root(0)];
//		tr(ds.ps[ds.root(0)]);
		for(int i = V.length-1;i >= 0;i--){
			out.print(V[i] + " ");
		}
		out.println();
	}

	public static class DJSet {
		public int[] upper;
		public int[] nes;
		public long[][] ps;

		public DJSet(int n) {
			upper = new int[n];
			nes = new int[n];
			Arrays.fill(upper, -1);
			Arrays.fill(nes, 0);
			ps = new long[n][];
			for(int i = 0;i < n;i++){
				ps[i] = new long[]{1L};
			}
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
				nes[x] += nes[y];
				ps[x] = mulnaive(ps[x], ps[y]);
			}
			nes[x]++;

			return x == y;
		}

		static final int mod = 998244353;
		static final long big = 8L*mod*mod;

		public static long[] mulnaive(long[] a, long[] b)
		{
			long[] c = new long[a.length+b.length-1];
			for(int i = 0;i < a.length;i++){
				for(int j = 0;j < b.length;j++){
					c[i+j] += a[i]*b[j];
					if(c[i+j] >= big)c[i+j] -= big;
				}
			}
			for(int i = 0;i < c.length;i++)c[i] %= mod;
			return c;
		}

		public int count() {
			int ct = 0;
			for (int u : upper) if (u < 0) ct++;
			return ct;
		}

		public int[][] toBucket() {
			int n = upper.length;
			int[][] ret = new int[n][];
			int[] rp = new int[n];
			for (int i = 0; i < n; i++) if (upper[i] < 0) ret[i] = new int[-upper[i]];
			for (int i = 0; i < n; i++) {
				int r = root(i);
				ret[r][rp[r]++] = i;
			}
			return ret;
		}
	}


	void run() throws Exception
	{
//		int n = 1500, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		int[][] a = new int[n][n];
//		int p = 1;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < i; j++) {
//				a[i][j] = a[j][i] = p++;
//			}
//		}
//		for(int i = 0;i  <n;i++){
//			for(int j = 0;j < n;j++) {
//				sb.append(a[i][j] + " ");
//			}
//		}
//		INPUT = sb.toString();


		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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