//package memsql.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns(60000);
		int n = s.length;
		int[] ct = new int[26];
		for(int i = 0;i < n;i++){
			ct[s[i]-'a']++;
		}
		for(int i = 0;i < 26;i++){
			if(ct[i] >= 100){
				for(int j = 0;j < 100;j++){
					out.print((char)(i+'a'));
				}
				out.println();
				return;
			}
		}
		
		char[] rs = Arrays.copyOf(s, n);
		for(int i = 0, j = n-1;i < j;i++,j--){
			char c = rs[i]; rs[i] = rs[j]; rs[j] = c;
		}
		int[][] dp = new int[n+1][n+1];
		int[][] prev = new int[n+1][n+1];
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(s[i-1] == rs[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
					prev[i][j] = 2;
				}else{
					dp[i][j] = -1;
					if(dp[i-1][j] > dp[i][j]){
						dp[i][j] = dp[i-1][j];
						prev[i][j] = 0;
					}
					if(dp[i][j-1] > dp[i][j]){
						dp[i][j] = dp[i][j-1];
						prev[i][j] = 1;
					}
				}
			}
		}
		
		int r = n, c = n;
		StringBuilder sb = new StringBuilder();
		while(r > 0 && c > 0){
			if(prev[r][c] == 2){
				sb.append(s[r-1]);
				r--; c--;
			}else if(prev[r][c] == 0){
				r--;
			}else{
				c--;
			}
		}
		int q = 100;
		if(sb.length() > q){
			if(sb.length() % 2 == 1){
				sb.delete(sb.length() / 2, sb.length() / 2 + 1);
			}
			out.println(sb.substring(sb.length()/2-q/2, sb.length()/2+q/2));
		}else{
			out.println(sb);
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
	
	public static void main(String[] args) throws Exception { new B2().run(); }
	
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