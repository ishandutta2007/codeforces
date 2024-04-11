//package round190;
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
	
	void solve()
	{
		int n = ni(), K = ni();
		int[][] a = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				a[i][j] = ni();
			}
		}
		int[][] imos = new int[n+1][n+1];
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				imos[i][j] = imos[i-1][j] + imos[i][j-1] - imos[i-1][j-1] + a[i-1][j-1];
			}
		}
		
		int[] cur = new int[n+1];
		int[] pre = new int[n+1];
		Arrays.fill(pre, Integer.MAX_VALUE / 3);
		pre[0] = 0;
		int[] argmin = new int[n+1];
		for(int k = 1;k <= K;k++){
			fill(0, n+1, k, argmin, cur, pre, imos);
			int[] dum = pre; pre = cur; cur = dum;
		}
		out.println(pre[n]/2);
	}
	
	void fill(int l, int r, int k, int[] argmin, int[] cur, int[] pre, int[][] imos)
	{
		if(l >= r)return;
		int n = argmin.length;
		int i = (l+r)/2;
		int inf = l == 0 ? 0 : argmin[l-1];
		int sup = r == n ? n : argmin[r];
		int min = Integer.MAX_VALUE;
		for(int j = inf;j <= sup && j < n;j++){
			int val = pre[j] + imos[j][j]+imos[i][i]-imos[i][j]-imos[j][i];
			if(val < min){
				min = val;
				argmin[i] = j;
			}
		}
		cur[i] = min;
		fill(l, i, k, argmin, cur, pre, imos);
		fill(i+1, r, k, argmin, cur, pre, imos);
	}
	
	void run() throws Exception
	{
//		int n = 4000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++){
//				sb.append(gen.nextInt(10) + " ");
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