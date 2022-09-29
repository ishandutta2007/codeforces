//package round623;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long S = System.currentTimeMillis();
		int n = ni(), K = ni();
		int[][] M = new int[n][];
		for(int i = 0;i < n;i++) {
			M[i] = na(n);
		}
		Random gen = new Random();
		
		long ans = Long.MAX_VALUE;
		while(System.currentTimeMillis() - S <= 2700) {
			boolean[] hey = new boolean[n];
			for(int i = 0;i < n/2;i++) {
				while(true) {
					int id = gen.nextInt(n-1)+1;
					if(!hey[id]) {
						hey[id] = true;
						break;
					}
				}
			}
			long[] dp = new long[n];
			Arrays.fill(dp, Long.MAX_VALUE / 3);
			dp[0] = 0;
			long[] cs = new long[K+1];
			for(int i = 0;i < K;i++) {
				long[] ndp = new long[n];
				Arrays.fill(ndp, Long.MAX_VALUE / 3);
				if(i % 2 == 0) {
					for(int j = 0;j < n;j++) {
						for(int k = 0;k < n;k++) {
							if(j != k && hey[k]) {
								ndp[k] = Math.min(ndp[k], dp[j] + M[j][k]);
							}
						}
					}
				}else {
					for(int j = 0;j < n;j++) {
						for(int k = 0;k < n;k++) {
							if(j != k && !hey[k]) {
								ndp[k] = Math.min(ndp[k], dp[j] + M[j][k]);
							}
						}
					}
				}
				dp = ndp;
			}
			ans = Math.min(ans, dp[0]);
		}
		
		out.println(ans);
	}
	
	void run() throws Exception
	{
//		int n = 80, m = 99999;
//		Random gen = new Random(1);
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(10 + " ");
//		for (int i = 0; i < n*n; i++) {
//			sb.append(gen.nextInt(100000000) + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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