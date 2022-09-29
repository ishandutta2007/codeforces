//package round605;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		char[] t = ns().toCharArray();
		int n = s.length;
		int m = t.length;
		int w = 2*(n+m);
		int[][][] dp = new int[n+1][m+1][w+1];
		byte[][][] pre = new byte[n+1][m+1][w+1];
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= m;j++){
				Arrays.fill(dp[i][j], 99999999);
			}
		}
		dp[0][0][0] = 0;
		char[] oc = "()".toCharArray();
		for(int i = 0;i <= n;i++){
			for(int j = 0;j <= m;j++){
				for(int k = 0;k <= w;k++){
					for(char y : oc){
						int ni = i, nj = j, nk = k;
						if(i+1 <= n && s[i] == y)ni++;
						if(j+1 <= m && t[j] == y)nj++;
						nk += y == '(' ? 1 : -1;
						if(nk >= 0 && nk <= w && dp[ni][nj][nk] > dp[i][j][k] + 1){
							dp[ni][nj][nk] = dp[i][j][k] + 1;
							pre[ni][nj][nk] = (byte)(ni-i<<2|nj-j<<1|(y=='('?0:1));
						}
					}
				}
			}
		}
		
		int min = 99999999;
		int arg = 0;
		for(int k = 0;k <= w;k++){
			if(dp[n][m][k] + k < min){
				min = dp[n][m][k] + k;
				arg = k;
			}
		}
		
		int i = n, j = m, k = arg;
		char[] ret = new char[dp[n][m][k]];
		int q = ret.length-1;
		while(q >= 0){
			int p = pre[i][j][k];
			int ni = i-(p>>>2&1);
			int nj = j-(p>>>1&1);
			int nk = (p&1) == 0 ? k-1 : k+1;
			ret[q] = (p&1) == 0 ? '(' : ')';
			i = ni; j = nj; k = nk;
			q--;
		}
		out.print(new String(ret));
		for(int u = 0;u < arg;u++){
			out.print(")");
		}
		out.println();
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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