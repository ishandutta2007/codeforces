//package round639;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
//	String INPUT = "4 4 2 1 1 3 2 4 4 3";
//	String INPUT = "4 4 4 1 1 3 4 2 2 3";
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packD(n, from, to);
		int[] ord = sortTopologically(g);
		if(ord == null){
			out.println(-1);
			return;
		}
		int[][] ig = packD(n, to, from);
		
		int[] minsf = new int[n];
		Arrays.fill(minsf, 999999999);
		for(int i = 0;i < n;i++){
			int cur = ord[i];
			minsf[cur] = Math.min(minsf[cur], cur);
			for(int e : g[cur]){
				minsf[e] = Math.min(minsf[e], minsf[cur]);
			}
		}
		
		int[] minsb = new int[n];
		Arrays.fill(minsb, 999999999);
		for(int i = n-1;i >= 0;i--){
			int cur = ord[i];
			minsb[cur] = Math.min(minsb[cur], cur);
			for(int e : ig[cur]){
				minsb[e] = Math.min(minsb[e], minsb[cur]);
			}
		}
		
		char[] ans = new char[n];
		int num = 0;
		for(int i = 0;i < n;i++){
			if(minsf[i] == i && minsb[i] == i){
				ans[i] = 'A';
				num++;
			}else{
				ans[i] = 'E';
			}
		}
		out.println(num);
		out.println(new String(ans));
	}
	
	public static int[] sortTopologically(int[][] g)
	{
		int n = g.length;
		int[] ec = new int[n];
		for(int i = 0;i < n;i++){
			for(int to : g[i])ec[to]++;
		}
		int[] ret = new int[n];
		int q = 0;
		
		// sources
		for(int i = 0;i < n;i++){
			if(ec[i] == 0)ret[q++] = i;
		}
		
		for(int p = 0;p < q;p++){
			for(int to : g[ret[p]]){
				if(--ec[to] == 0)ret[q++] = to;
			}
		}
		// loop
		for(int i = 0;i < n;i++){
			if(ec[i] > 0)return null;
		}
		return ret;
	}

	
	static int[][] packD(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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