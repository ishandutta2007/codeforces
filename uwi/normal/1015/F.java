//package round501;
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
		int n = ni();
		char[] s = ns().toCharArray();
		int m = s.length;
		
		int[] t = mpTable(s);
		
		int[][] to = new int[m+1][2];
		to[m][0] = to[m][1] = m;
		for(int i = 0;i < m;i++){
			int u = 0;
			for(char c : "()".toCharArray()){
				int p = i;
				while(p >= 0 && s[p] != c)p = t[p];
				p++;
				to[i][u] = p;
				u++;
			}
		}
		
		int mod = 1000000007;
		int[][] dp = new int[2*n+1][m+1]; // height pos_in_mp
		dp[0][0] = 1;
		for(int i = 0;i < 2*n;i++){
			int[][] ndp = new int[2*n+1][m+1];
			for(int j = 0;j <= 2*n;j++){
				for(int k = 0;k <= m;k++){
					for(int l = 0, o = 1;l < 2;l++, o -= 2){
						if(j+o <= 2*n && j+o >= 0){
							ndp[j+o][to[k][l]] += dp[j][k];
							if(ndp[j+o][to[k][l]] >= mod)ndp[j+o][to[k][l]] -= mod;
						}
					}
				}
			}
			dp = ndp;
		}
		out.println(dp[0][m]);
	}
	
	public static int[] mpTable(char[] str)
	{
		int n = str.length;
		int[] mp = new int[n+1];
		mp[0] = -1;
		for(int i = 1, j = 0;i < n;i++){
			while(j >= 0 && str[i] != str[j])j = mp[j];
			mp[i+1] = ++j;
		}
		return mp;
	}

	
	void run() throws Exception
	{
//		int n = 100, m = 200;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < m; i++) {
//			sb.append("()".charAt(gen.nextInt(2)));
//		}
//		INPUT = sb.toString();

		
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