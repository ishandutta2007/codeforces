//package round558;
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
		char[] x = ns().toCharArray();
		char[] s = ns().toCharArray();
		char[] t = ns().toCharArray();
		int[] ms = mpTable(s);
		int[] mt = mpTable(t);
		
		int[][] dp = new int[ms.length][mt.length];
		for(int i = 0;i < ms.length;i++)Arrays.fill(dp[i], -9999999);
		dp[0][0] = 0;
		for(char c : x){
			int[][] ndp = new int[ms.length][mt.length];
			for(int i = 0;i < ms.length;i++)Arrays.fill(ndp[i], -9999999);
			for(char y = c == '*' ? 'a' : c;y <= (c=='*' ? 'z' : c);y++){
				for(int i = 0;i < ms.length;i++){
					for(int j = 0;j < mt.length;j++){
						if(dp[i][j] < -99999)continue;
						int plus = 0;
						int ii = i;
						{
							while(ii >= 0 && s[ii] != y)ii = ms[ii];
							ii++;
							if(ii == ms.length-1){
								ii = ms[ii];
								plus++;
							}
						}
						int jj = j;
						{
							while(jj >= 0 && t[jj] != y)jj = mt[jj];
							jj++;
							if(jj == mt.length-1){
								jj = mt[jj];
								plus--;
							}
						}
						ndp[ii][jj] = Math.max(ndp[ii][jj], dp[i][j] + plus);
					}
				}
			}
			dp = ndp;
		}
		
		int max = -9999999;
		for(int i = 0;i < ms.length;i++){
			for(int j = 0;j < mt.length;j++){
				max = Math.max(max, dp[i][j]);
			}
		}
		out.println(max);
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
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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