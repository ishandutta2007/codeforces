//package round7;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F1 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[][] map = nm(n,n);
		
		int h = n/2;
		int[][][] dp = new int[1<<n][n][1];
		for(int i = 0;i < n;i++){
			dp[1<<i][i][0] = 1;
		}
		int[][][] L = null, R = null;
		if(1 == h+1)L = dp;
		if(1 == n-h)R = dp;
		
		for(int i = 2;i <= h+1;i++){
			int[][][] ndp = new int[1<<n][n][1<<i-1];
			for(int k = 0;k < 1<<n;k++){
				for(int l = 0;l < n;l++){
					for(int j = 0;j < 1<<i-2;j++){
						if(dp[k][l][j] == 0)continue;
						for(int m = 0;m < n;m++){
							if(k<<~m>=0){
								int f = map[l][m]-'0';
								ndp[k|1<<m][m][j|f<<i-2] += dp[k][l][j];
							}
						}
					}
				}
			}
			if(i == h+1)L = ndp;
			if(i == n-h)R = ndp;
			dp = ndp;
		}
		
		int[] rev = new int[1<<n-h-1];
		for(int i = 0;i < 1<<n-h-1;i++){
			int s = 0;
			for(int j = 0;j < n-h-1;j++){
				s |= (i>>>j&1)<<n-h-1-j-1;
			}
			rev[i] = s;
		}
		
		long[] ret = new long[1<<n-1];
		for(int j = 0;j < 1<<n;j++){
			for(int k = 0;k < n;k++){
				int rj = (1<<n)-1^j^1<<k;
				for(int i = 0;i < 1<<h;i++){
					if(L[j][k][i] == 0)continue;
					for(int u = 0;u < 1<<n-h-1;u++){
						ret[rev[u]<<h|i] += (long)L[j][k][i] * R[rj][k][u];
					}
				}
			}
		}
		for(long v : ret){
			out.print(v + " ");
		}
		out.println();
	}
	
	void run() throws Exception
	{
//		int n = 14, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		boolean[][] b = new boolean[n][n];
//		for(int i = 0;i < n;i++){
//			for(int j = i+1;j < n;j++){
//				b[i][j] = b[j][i] = gen.nextBoolean();
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			for(int j = 0;j < n;j++){
//				sb.append(b[i][j]?1:0);
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
	
	public static void main(String[] args) throws Exception { new F1().run(); }
	
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