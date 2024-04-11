//package round584;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

// imp:12m
public class E4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";

	
	void solve()
	{
		for(int T = ni(); T> 0;T--){
			int n = ni(), m = ni();
			int[][] a = new int[n][];
			for(int i = 0;i < n;i++)a[i] = na(m);
			
			long[] mx = new long[m];
			for(int i = 0;i < m;i++){
				int u = 0;
				for(int j = 0;j < n;j++){
					u = Math.max(u, a[j][i]);
				}
				mx[i] = 1000000000L-u<<32|i;
			}
			Arrays.sort(mx);
			int[] dp = new int[1<<n];
			for(int i = 0;i < n && i < m;i++){
				int c = (int)mx[i];
				int[] ls = new int[1<<n];
				for(int j = 1;j < 1<<n;j++){
					ls[j] = ls[j&j-1] + a[Integer.numberOfTrailingZeros(j)][c];
				}
				for(int j = 1;j < 1<<n;j++){
					int r = rot(j, n);
					ls[r] = Math.max(ls[r], ls[j]);
				}
				int[] ndp = new int[1<<n];
				for(int j = 0;j < 1<<n;j++){
					if(rot(j, n) == j){
						int cur = j;
						for(int sh = 0;sh < n;sh++){
							cur = cur>>1|(cur&1)<<n-1;
							int mask = (1<<n)-1^cur;
							for(int k = mask;k >= 0;k--){
								k &= mask;
								
								ndp[k|cur] = Math.max(
										ndp[k|cur], dp[k] + ls[j]);
							}
						}
					}
				}
				dp = ndp;
			}
			out.println(dp[(1<<n)-1]);
		}
	}
	
	int rot(int x, int n)
	{
		int ret = x;
		for(int i = 0;i < n;i++){
			x = x>>>1|(x&1)<<n-1;
				ret = Math.min(ret, x);
		}
		return ret;
	}
	
	void run() throws Exception
	{
//		int n = 12, m = 2000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(40 + " ");
//		for(int rep = 0;rep < 40;rep++){
//			sb.append(n + " ");
//			sb.append(m + " ");
//			for (int i = 0; i < n*m; i++) {
//				sb.append(gen.nextInt(100000) + " ");
//			}
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E4().run(); }
	
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