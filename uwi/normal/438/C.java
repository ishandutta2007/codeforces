//package round250;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
//	String INPUT = "6 0 0 -1 1 -2 0 0 -1 2 0 1 1";
	String INPUT = "";
	
	public static boolean isClockwise(long[][] poly)
	{
		int n = poly.length;
		long minx = Long.MAX_VALUE;
		long miny = Long.MAX_VALUE;
		int mini = -1;
		for(int i = 0;i < n;i++){
			if(poly[i][0] < minx || poly[i][0] == minx && poly[i][1] < miny){
				minx = poly[i][0]; miny = poly[i][1]; mini = i;
			}
		}
		int prev = (mini+n-1)%n;
		int next = (mini+1)%n;
		return ccw(poly[prev][0], poly[prev][1], poly[mini][0], poly[mini][1], poly[next][0], poly[next][1]) == 1;
	}
	
	void solve()
	{
		int n = ni();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			co[i] = new long[]{ni(), ni()};
		}
		if(isClockwise(co)){
			for(int i = 1, j = n-1;i < j;i++,j--){
				long[] d = co[i]; co[i] = co[j]; co[j] = d;
			}
		}
		
		long[][][] up = new long[n][n][4];
		long[][][] on = new long[n][n][4];
		long[][][] down = new long[n][n][4];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				for(int k = 0;k < n;k++){
					if(i == k || j == k)continue;
					int ccw = ccw(co[i][0], co[i][1], co[j][0], co[j][1], co[k][0], co[k][1]);
					if(ccw < 0){
						up[i][j][k>>>6] |= 1L<<k;
					}else if(ccw == 0){
						on[i][j][k>>>6] |= 1L<<k;
					}else{
						down[i][j][k>>>6] |= 1L<<k;
					}
				}
			}
		}
		
		final int mod = 1000000007;
		int[][] dp = new int[n][n];
		for(int len = 2;len <= n;len++){
			for(int i = 0;i+len-1 < n;i++){
				int j = i+len-1;
				if(len == 2){
					dp[i][j] = 1;
					continue;
				}
				long s = 0;
				inner:
				for(int k = i+1;k < j;k++){
					if(ccw(co[i][0], co[i][1], co[j][0], co[j][1], co[k][0], co[k][1]) == 0)continue;
					for(int L = 0;L < 4;L++){
						long f = (up[i][k][L]|on[i][k][L])&(up[k][j][L]|on[k][j][L])&(up[j][i][L]|on[j][i][L]);
						if(f != 0){
							continue inner;
						}
					}
					s += (long)dp[i][k] * dp[k][j] % mod;
				}
				dp[i][j] = (int)(s % mod);
			}
		}
//		tr(dp);
		out.println(dp[0][n-1]);
	}
	
	public static int ccw(long ax, long ay, long bx, long by, long tx, long ty)
	{
		return Long.signum((tx-ax)*(by-ay)-(bx-ax)*(ty-ay));
	}
	
	void run() throws Exception
	{
//		int n = 200, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append((int)(2000*Math.cos(i*Math.PI*2/n)) + " ");
//			sb.append((int)(2000*Math.sin(i*Math.PI*2/n)) + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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