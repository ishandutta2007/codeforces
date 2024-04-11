//package round327;
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
		int n = ni(), K = ni(), s = ni();
		int[] a = na(n);
		int swk = K*(K-1)/2;
		int ms = Math.min(n-K, K);
		long[][] dp = new long[ms+1][swk+1]; // #, #swap
		long I = Long.MIN_VALUE / 3;
		for(int i = 0;i <= ms;i++){
			Arrays.fill(dp[i], Long.MIN_VALUE / 3);
		}
		dp[0][0] = 0;
		// maximize
		for(int i = K-1;i >= 0;i--){
			for(int j = ms;j >= 0;j--){
				for(int k = swk;k >= 0;k--){
					if(dp[j][k] == I)continue;
					if(j+1 <= ms){
						dp[j+1][K-1-i-j+k] = Math.max(dp[j+1][K-1-i-j+k], dp[j][k] + a[i]);
					}
				}
			}
		}
		
		int swik = (n-K)*(n-K-1)/2;
		long J = Long.MAX_VALUE / 3;
		long[][] ep = new long[ms+1][swik+1];
		for(int i = 0;i <= ms;i++){
			Arrays.fill(ep[i], J);
		}
		ep[0][0] = 0;
		// minimize
		for(int i = K;i < n;i++){
			for(int j = ms;j >= 0;j--){
				for(int k = swik;k >= 0;k--){
					if(ep[j][k] == J)continue;
					if(j+1 <= ms){
						ep[j+1][i-K-j+k] = Math.min(ep[j+1][i-K-j+k], ep[j][k] + a[i]);
					}
				}
			}
		}
		long ret = 0;
		for(int i = 0;i <= ms;i++){
			long min = J;
			int p = 0;
			for(;p <= swik && swk+p+i*i <= s;p++){
				min = Math.min(min, ep[i][p]);
			}
			
			for(int j = swk;j >= 0;j--){
				if(p <= swik && j+p+i*i <= s){
					min = Math.min(min, ep[i][p]);
					p++;
				}
				if(dp[i][j] != I){
					ret = Math.min(ret, min - dp[i][j]);
				}
			}
		}
		for(int i = 0;i < K;i++)ret += a[i];
		out.println(ret);
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