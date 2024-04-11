//package round234;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		int[] a = na(K);
		
		int[] kind = new int[n];
		int p = 0;
		for(int i = 0;i < K;i++){
			for(int j = 0;j < a[i];j++){
				kind[p++] = i;
			}
		}
		
		int[][] es = new int[m][];
		for(int i = 0;i < m;i++){
			es[i] = new int[]{ni()-1, ni()-1, ni()};
		}
		DJSet ds = new DJSet(n);
		for(int i = 0;i < m;i++){
			if(es[i][2] == 0)ds.union(es[i][0], es[i][1]);
		}
		for(int i = 0;i < n-1;i++){
			if(kind[i] == kind[i+1]){
				if(!ds.equiv(i, i+1)){
					out.println("No");
					return;
				}
			}
		}
		
		int[][] g = new int[K][K];
		int I = 1000000000;
		for(int i = 0;i < K;i++){
			Arrays.fill(g[i], I+20000);
			g[i][i] = 0;
		}
		
		for(int i = 0;i < m;i++){
			int ki = kind[es[i][0]], kj = kind[es[i][1]];
			if(ki != kj){
				g[ki][kj] = g[kj][ki] = Math.min(g[ki][kj], es[i][2]);
			}
		}
		for(int k = 0;k < K;k++){
			for(int i = 0;i < K;i++){
				for(int j = 0;j < K;j++){
					if(g[i][j] > g[i][k] + g[k][j]){
						g[i][j] = g[i][k] + g[k][j];
					}
				}
			}
		}
		out.println("Yes");
		for(int i = 0;i < K;i++){
			for(int j = 0;j < K;j++){
				if(g[i][j] >= I){
					out.print("-1 ");
				}else{
					out.print(g[i][j] + " ");
				}
			}
			out.println();
		}
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
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
			if(x != y){
				if(upper[y] < upper[x]){
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for(int u : upper)
				if(u < 0)
					ct++;
			return ct;
		}
	}
	
	void run() throws Exception
	{
//		int n = 500, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n-1 + " ");
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++)sb.append(1 + " ");
//		for(int i = 0;i < n-1;i++){
//			sb.append((i+1) + " ");
//			sb.append((i+2) + " ");
//			sb.append(1 + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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