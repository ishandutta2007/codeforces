//package bubblecup13.f;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";

	void solve()
	{
		int n = ni();
		int m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] ws = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			ws[i] = ni();
		}

		int low = 0, high = 1000000007;
		while(high - low > 1){
			int h = high+low>>1;
			int[] lf = new int[m];
			int[] lt = new int[m];
			int p = 0;
			for(int i = 0;i < m;i++){
				if(ws[i] <= h){
					lf[p] = from[i];
					lt[p] = to[i];
					p++;
				}
			}
			if(p >= n && doBipartiteMatchingHK(packD(n, lf, lt, p), n) == n){
				high = h;
			}else{
				low = h;
			}
		}
		if(high > 1000000001){
			out.println(-1);
		}else {
			out.println(high);
		}
	}

	public static int[][] packD(int n, int[] from, int[] to) {
		return packD(n, from, to, from.length);
	}

	public static int[][] packD(int n, int[] from, int[] to, int sup) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int i = 0; i < sup; i++) p[from[i]]++;
		for (int i = 0; i < n; i++) g[i] = new int[p[i]];
		for (int i = 0; i < sup; i++) {
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
	}


	public static int doBipartiteMatchingHK(int[][] g, int m)
	{
		int n = g.length;
		if(n == 0)return 0;
		int[] from = new int[m];
		int[] to = new int[n];
		Arrays.fill(to, -1);
		Arrays.fill(from, n);

		int[] d = new int[n+1];
		int mat = 0;
		while(true){
			Arrays.fill(d, -1);
			int[] q = new int[n];
			int r = 0;
			for(int i = 0;i < n;i++){
				if(to[i] == -1){
					d[i] = 0;
					q[r++] = i;
				}
			}

			for(int p = 0;p < r;p++) {
				int cur = q[p];
				for(int adj : g[cur]){
					int nex = from[adj];
					if(d[nex] == -1) {
						if(nex != n)q[r++] = nex;
						d[nex] = d[cur] + 1;
					}
				}
			}
			if(d[n] == -1)break;

			for(int i = 0;i < n;i++){
				if(to[i] == -1){
					if(dfsHK(d, g, n, m, to, from, i))mat++;
				}
			}
		}
		return mat;
	}

	static boolean dfsHK(int[] d, int[][] g, int n, int m, int[] to, int[] from, int cur)
	{
		if(cur == n)return true;
		for(int adj : g[cur]){
			int nex = from[adj];
			if(d[nex] == d[cur] + 1 && dfsHK(d, g, n, m, to, from, nex)){
				to[cur] = adj;
				from[adj] = cur;
				return true;
			}
		}
		d[cur] = -1;
		return false;
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
	
	public static void main(String[] args) throws Exception { new B3().run(); }
	
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