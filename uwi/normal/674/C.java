//package vk2016.r3;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	long[] cum;
	double[] cumi, cumr;
	void solve()
	{
		int n = ni(), K = ni();
		int[] a = na(n);
		cum = new long[n+1];
		for(int i = 0;i < n;i++)cum[i+1] = cum[i] + a[i];
		cumi = new double[n+1];
		for(int i = 0;i < n;i++)cumi[i+1] = cumi[i] + 1./a[i];
		cumr = new double[n+1];
		for(int i = 0;i < n;i++)cumr[i+1] = cumr[i] + (double)cum[i+1]/a[i];
		double[][] dp = new double[K+1][n+1];
		for(int i = 0;i <= K;i++){
			Arrays.fill(dp[i], Double.POSITIVE_INFINITY);
		}
		dp[0][0] = 0;
		for(int i = 1;i <= K;i++){
			int[] argmins = new int[n+2];
			Arrays.fill(argmins, -1);
			argmins[0] = 0;
			argmins[n+1] = n;
			dfs(0, n+1, argmins, dp[i-1], dp[i]);
		}
		out.printf("%.14f\n", dp[K][n]);
	}
	
	void dfs(int l, int r, int[] argmins, double[] pre, double[] cur)
	{
		int h = l+r>>>1;
		int al = argmins[l];
		int ar = Math.min(h-1, argmins[r]);
		int argmin = l;
		double min = Double.POSITIVE_INFINITY;
		for(int i = al;i <= ar;i++){
			double v = pre[i] + (cumr[h]-cumr[i])-cum[i]*(cumi[h]-cumi[i]);
			if(v < min){
				min = v;
				argmin = i;
			}
		}
		cur[h] = min;
		argmins[h] = argmin;
		if(r-l > 1){
			dfs(l, h, argmins, pre, cur);
			dfs(h, r, argmins, pre, cur);
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
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
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