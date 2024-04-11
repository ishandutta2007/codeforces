//package round642;
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
		for(int T = ni();T > 0;T--)go();
	}
	
	boolean[][] obs;
	long[][] map;
	
	void go()
	{
		int n = ni();
		int m = ni();
		map = new long[n][];
		for(int i = 0;i < n;i++){
			map[i] = new long[m];
			for(int j = 0;j < m;j++){
				map[i][j] = nl();
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				map[i][j] -= i+j;
			}
		}
		long[][] ss = new long[n*m][];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				ss[p++] = new long[]{map[i][j], i, j};
			}
		}
		Arrays.sort(ss, (x, y) -> Long.compare(x[0], y[0]));
		obs = new boolean[n][m];
		long ans = Long.MAX_VALUE;
		dp = new long[n][m];
		for(long[] s : ss){
			int r = (int)s[1], c = (int)s[2];
			ans = Math.min(ans, go(0, 0, r, c) + go(r, c, n-1, m-1) - map[r][c] * (n+m));
			obs[r][c] = true;
		}
		out.println(ans);
	}
	
	long[][] dp;
	
	long go(int r1, int c1, int r2, int c2)
	{
		long I = Long.MAX_VALUE / 3;
		for(int r = r1;r <= r2;r++){
			for(int c = c1;c <= c2;c++){
				if(obs[r][c]){
					dp[r][c] = I;
				}else{
					if(r == r1 && c == c1){
						dp[r][c] = map[r][c];
					}else{
						dp[r][c] = I;
						if(r-1 >= r1){
							dp[r][c] = Math.min(dp[r][c], dp[r-1][c]);
						}
						if(c-1 >= c1){
							dp[r][c] = Math.min(dp[r][c], dp[r][c-1]);
						}
						dp[r][c] = Math.min(I, dp[r][c] + map[r][c]);
					}
				}
			}
		}
		return dp[r2][c2];
	}
	
	void run() throws Exception
	{
//		int n = 100, m = 99;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(1 + " ");
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n*m; i++) {
//			sb.append(gen.nextInt(1000000000) + " ");
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