//package round646;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)go();
	}
	
	void go()
	{
		int n = ni();
		char[] s = ns(n);
		char[] t = ns(n);
		char[] ss = Arrays.copyOf(s, n);
		Arrays.sort(ss);
		char[] tt = Arrays.copyOf(t, n);
		Arrays.sort(tt);
		if(!Arrays.equals(ss, tt)){
			out.println(-1);
			return;
		}
		
		int[][] ft = new int[26][n+1];
		for(int i = 0;i < 26;i++){
			for(int j = 0;j < n;j++){
				ft[i][j+1] = ft[i][j] + (t[j] == 'a' + i ? 1 : 0);
			}
		}
		
		int[][] fs = new int[26][n+1];
		for(int i = 0;i < 26;i++){
			for(int j = 0;j < n;j++){
				fs[i][j+1] = fs[i][j] + (s[j] == 'a' + i ? 1 : 0);
			}
		}
		
		int[] dp = new int[n+1];
		for(int i = 0;i <= n;i++){
			int[] ndp = new int[n+1];
			Arrays.fill(ndp, 99999999);
			for(int j = 0;j <= n;j++){
				if(i == 0 && j == 0){
					ndp[j] = 0;
					continue;
				}
				if(i-1 >= 0 && j-1 >= 0){
					if(s[i-1] == t[j-1]){
						ndp[j] = dp[j-1];
						continue;
					}
				}
				if(i-1 >= 0)ndp[j] = Math.min(ndp[j], dp[j] + (fs[s[i-1]-'a'][i] <= ft[s[i-1]-'a'][j] ? 1 : 99999999));
				if(j-1 >= 0)ndp[j] = Math.min(ndp[j], ndp[j-1]);
			}
			dp = ndp;
		}
		out.println(dp[n]);
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
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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