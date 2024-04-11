//package educational.round27;
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
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		if(n < m){
			map = trans(map);
			int d = n; n = m;m  = d;
		}
		// m<=16
		int mod = 1000000007;
		long[][][] dp = new long[2][2][1<<m]; // [space][horizontal ray pattern][vertical ray pattern (no rolling)]
		dp[0][0][0] = 1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				long[][][] ndp = new long[2][2][1<<m]; // [space][horizontal ray pattern][vertical ray pattern (no rolling)]
				if(map[i][j] == 'x'){
					for(int s = 0;s < 2;s++){
						for(int h = 0;h < 2;h++){
							for(int k = 0;k < 1<<m;k++){
								int nk = k&~(1<<j);
								ndp[s][0][nk] += dp[s][h][k];
								if (ndp[s][0][nk] >= mod)
									ndp[s][0][nk] -= mod;
							}
						}
					}
				}else{
					for(int s = 0;s < 2;s++){
						for(int h = 0;h < 2;h++){
							for(int k = 0;k < 1<<m;k++){
								// put
								{
									int nh = j == m-1 ? 0 : (h|1);
									int nk = k|1<<j;
									ndp[s][nh][nk] += dp[s][h][k];
									if (ndp[s][nh][nk] >= mod)
										ndp[s][nh][nk] -= mod;
								}
								// not put
								{
									int ns = h == 0 && k<<~j>=0 ? s+1 : s;
									int nh = j == m-1 ? 0 : h;
									if(ns < 2){
										ndp[ns][nh][k] += dp[s][h][k];
										if (ndp[ns][nh][k] >= mod)
											ndp[ns][nh][k] -= mod;
									}
								}
							}
						}
					}
				}
				dp = ndp;
			}
		}
		long ret = 0;
		for(int i = 0;i < 2;i++){
			for(int j = 0;j < 1<<m;j++){
				ret += dp[0][i][j];
				ret += dp[1][i][j];
			}
		}
		out.println(ret%mod);
	}
	
	public static char[][] trans(char[][] a)
	{
		if(a.length == 0)return new char[0][0];
		int n = a.length, m = a[0].length;
		char[][] ret = new char[m][n];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				ret[i][j] = a[j][i];
			}
		}
		return ret;
	}

	
	void run() throws Exception
	{
//		int n = 15, m = 16;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			for(int j = 0;j < m;j++){
//				sb.append("x");
//			}
//			sb.append("\n");
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