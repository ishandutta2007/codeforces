//package bubblecup13.f;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class J {
	InputStream is;
	PrintWriter out;
	String INPUT = "";

	void solve()
	{
		final int mod = 1000000007;
		for(int T = ni();T > 0;T--){
			long m = nl();
			out.println(((m/4+1)%mod)*(((m/2+1)/2+1)%mod) % mod);
//			// 8 4 2 1 = 15
//			long[] dp = new long[9];
//			dp[0] = 1;
//			for(int i = 60;i >= 0;i--){
//				long[] ndp = new long[9];
//				int nj = (int) (m >>> i & 1);
//				int njl = nj - 7;
//				for(int j = 0;j < 8;j++) {
//					ndp[Math.max(0, njl)] += dp[j];
//					if(nj+1 < 9)ndp[nj+1] += mod - dp[j];
////
////					for (int k = 0; k <= 7; k++) {
////						int nj = (j * 2 + (int) (m >>> i & 1)) - k;
////						if (nj < 8 && nj >= 0) {
////							ndp[nj] += dp[j];
////							if (ndp[nj] >= mod) ndp[nj] -= mod;
////						}
////					}
//					nj += 2; njl += 2;
//				}
//				for(int j = 1;j < 9;j++){
//					ndp[j] += ndp[j-1];
//				}
//				for(int j = 0;j < 9;j++){
//					ndp[j] %= mod;
//				}
//				dp = ndp;
//			}
//			long ex = ((m/4+1)%mod)*(((m/2+1)/2+1)%mod) % mod;
////			out.println(dp[0]);
//			assert dp[0] == ex;
		}
	}
	
	void run() throws Exception
	{
//		int n = 500000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(Math.abs(gen.nextLong() % (long)1e18) + " ");
//		}
//		INPUT = sb.toString();


		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new J().run(); }
	
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