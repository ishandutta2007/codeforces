//package educational.round21;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT ="" ;
	
	void solve()
	{
		char[] s = ns().toCharArray();
		char[] t = ns().toCharArray();
		int[] kmp = kmpTable(t);
		int[][] rkmp = redundantKMP(t);
		int n = s.length;
		int m = t.length;
		int[] dp = new int[m];
		Arrays.fill(dp, -999999999);
		dp[0] = 0;
		for(int i = 0;i < n;i++){
			int[] ndp = new int[m];
			Arrays.fill(ndp, -999999999);
			if(s[i] == '?'){
				for(int j = 0;j < m;j++){
					for(int k = 0;k < 26;k++){
						int nj = j;
						int hit = 0;
						if(k == t[nj]-'a'){
							++nj;
						}else{
							nj = rkmp[j][k];
						}
						if(nj == m){
							hit = 1;
							nj = kmp[m];
						}
						ndp[nj] = Math.max(ndp[nj], dp[j] + hit);
					}
				}
			}else{
				for(int j = 0;j < m;j++){
					int k = s[i]-'a';
					int nj = j;
					int hit = 0;
					if(k == t[nj]-'a'){
						++nj;
					}else{
						nj = rkmp[j][k];
					}
					if(nj == m){
						hit = 1;
						nj = kmp[m];
					}
					ndp[nj] = Math.max(ndp[nj], dp[j] + hit);
				}
			}
			dp = ndp;
		}
		out.println(Arrays.stream(dp).max().getAsInt());
	}
	
	public static int[][] redundantKMP(char[] s)
	{
		int n = s.length;
		final int W = 26;
		int[][] dp = new int[n][W];
		int[] kmp = new int[n+1];
		kmp[0] = -1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < W;j++){
				if(kmp[i] == -1){
					dp[i][j] = 0;
				}else if(j == s[kmp[i]]-'a'){
					dp[i][j] = kmp[i] + 1;
				}else{
					dp[i][j] = dp[kmp[i]][j];
				}
			}
			kmp[i+1] = dp[i][s[i]-'a'];
		}
		return dp;
	}

	
	public static int[] kmpTable(char[] str)
	{
		int n = str.length;
		int[] kmp = new int[n+1];
		kmp[0] = -1; kmp[1] = 0;
		for(int i = 2, j = 0;i <= n;i++){
			while(j > 0 && str[i-1] != str[j])j = kmp[j];
			kmp[i] = str[i-1] == str[j] ? ++j : 0;
		}
		return kmp;
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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