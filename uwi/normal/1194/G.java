//package educational.round68;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G3 {
	InputStream is;
	PrintWriter out;
//	String INPUT = "42";
	String INPUT = "";
	
	public static void trnz(long... o)
	{
		for(int i = 0;i < o.length;i++)if(o[i] != 0)System.out.print(i+":"+o[i]+" ");
		System.out.println();
	}

	
	void solve()
	{
		BigInteger n = new BigInteger(ns());
		long ans = 0;
		for(int i = 1;i <= 9;i++){
			for(int j = 1;j <= i;j++){
				if(gcd(i, j) == 1){
					if(i == 1){
						ans += n.mod(BigInteger.valueOf(998244353L)).longValue();
					}else{
						long lans = count(n, i, j);
						if(i != j){
							ans += lans*2;
						}else{
							ans += lans;
						}
//						if(lans > 0)tr(i, j, lans, ans);
					}
				}
			}
		}
		out.println(ans % 998244353);
	}
	
	long count(BigInteger N, int u, int v)
	{
		char[] s = ("0" + N.divide(BigInteger.valueOf(u)).add(BigInteger.ONE).toString()).toCharArray();
		
		int n = s.length;
		// u:2 v:1
		// ut*u
		// vt*v
		int w = 9/u;
		long[][][][] dp = new long[1<<w][1<<w][10][10]; // valid carry
		long[][][][] ep = new long[1<<w][1<<w][10][10]; // valid carry
		int mod = 998244353;
		ep[0][0][0][0] = 1;
		
		int[][] va0 = new int[10][10];
		int[][] va1 = new int[10][10];
		int[][] nextc0 = new int[10][10];
		int[][] nextc1 = new int[10][10];
		for(int d = 0;d < 10;d++){
			for(int c0 = 0;c0 <= 9;c0++){
				int v0 = d*u + c0;
				for(int t = 1;t <= w;t++){
					if(t*u == v0%10){
						va0[d][c0] |= 1<<t-1;
					}
				}
				nextc0[d][c0] = v0 / 10;
			}
			for(int c1 = 0;c1 <= 9;c1++){
				int v1 = d*v + c1;
				for(int t = 1;t <= w;t++){
					if(t*v == v1%10){
						va1[d][c1] |= 1<<t-1;
					}
				}
				nextc1[d][c1] = v1 / 10;
			}
		}
		
		for(int i = n-1;i >= 0;i--){
			long[][][][] ndp = new long[1<<w][1<<w][10][10]; // valid carry
			long[][][][] nep = new long[1<<w][1<<w][10][10]; // valid carry
			
			for(int j = 0;j < 1<<w;j++){
				for(int k = 0;k < 1<<w;k++){
					for(int l = 0;l < 10;l++){
						for(int m = 0;m < 10;m++){
							int d = s[i]-'0';
							int nj = j|va0[d][l];
							int nk = k|va1[d][m];
							int nl = nextc0[d][l];
							int nm = nextc1[d][m];
							ndp[nj][nk][nl][nm] += dp[j][k][l][m];
							if(ndp[nj][nk][nl][nm] >= mod)ndp[nj][nk][nl][nm] -= mod;
						}
					}
				}
			}
			
			for(int j = 0;j < 1<<w;j++){
				for(int k = 0;k < 1<<w;k++){
					for(int l = 0;l < 10;l++){
						for(int m = 0;m < 10;m++){
							for(int d = 0;d < 10;d++){
								int nj = j|va0[d][l];
								int nk = k|va1[d][m];
								int nl = nextc0[d][l];
								int nm = nextc1[d][m];
								nep[nj][nk][nl][nm] += ep[j][k][l][m];
								if(nep[nj][nk][nl][nm] >= mod)nep[nj][nk][nl][nm] -= mod;
								if(d < s[i]-'0'){
									ndp[nj][nk][nl][nm] += ep[j][k][l][m];
									if(ndp[nj][nk][nl][nm] >= mod)ndp[nj][nk][nl][nm] -= mod;
								}
							}
						}
					}
				}
			}
			
			dp = ndp;
			ep = nep;
		}
		
		long ret = 0;
		for(int i = 0;i < 1<<w;i++){
			for(int j = 0;j < 1<<w;j++){
				if((i&j) != 0){
					ret += dp[i][j][0][0];
				}
			}
		}
		return ret % mod;
	}
	
	public static int gcd(int a, int b) {
		while (b > 0) {
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
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
	
	public static void main(String[] args) throws Exception { new G3().run(); }
	
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