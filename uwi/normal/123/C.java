//package round92re;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		long K = nl()-1;
		
		int[][] a = new int[n][m];
		int[] yo = new int[n+m-1];
		Arrays.fill(yo, 9999999);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				a[i][j] = ni();
				yo[i+j] = Math.min(yo[i+j], a[i][j]);
			}
		}
		yo = shrink(yo);
//		tr(yo);
		int[] iyo = new int[n+m-1];
		for(int i = 0;i < n+m-1;i++){
			iyo[yo[i]] = i;
		}
//		tr(iyo);
		
		char[] ret = new char[n+m-1];
		Arrays.fill(ret, '?');
		for(int i = 0;i < n+m-1;i++){
			ret[iyo[i]] = '(';
			long c = count(ret);
//			tr(ret, c);
			if(c <= K){
				K -= c;
				ret[iyo[i]] = ')';
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				out.print(ret[i+j]);
			}
			out.println();
		}
	}
	
	long count(char[] a)
	{
		int n = a.length;
		long[][] dp = new long[n+1][n+1];
		dp[0][0] = 1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j <= n;j++){
				if(dp[i][j] == 0)continue;
				if((a[i] == '?' || a[i] == '(') && j+1 <= n){
					dp[i+1][j+1] += dp[i][j];
					if(dp[i+1][j+1] >= 1000000000000000001L){
						dp[i+1][j+1] = 1000000000000000001L;
					}
				}
				if((a[i] == '?' || a[i] == ')') && j-1 >= 0){
					dp[i+1][j-1] += dp[i][j];
					if(dp[i+1][j-1] >= 1000000000000000001L){
						dp[i+1][j-1] = 1000000000000000001L;
					}
				}
			}
		}
		return dp[n][0];
	}
	
	public static int[] shrink(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0)p++;
			ret[(int)b[i]] = p;
		}
		return ret;
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