//package educational.round79;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// 
		// 
		
		// 1 2 3 4
		// 4 ? ? ?
		// (K-2)!
		
		long[] F = new long[50];
		F[0] = 1;
		for(int i = 1;i < 21;i++){
			F[i] = F[i-1] * i;
		}
		for(int i = 21;i < 50;i++){
			F[i] = F[i-1];
		}
		
		long I = 2000000000000000000L;
		long[] dp = new long[51];
		dp[0] = 1;
		for(int i = 1;i <= 50;i++){
			double q = 0;
			for(int j = 1;j <= i;j++){
				q += (double)dp[i-j] * (j-2 < 0 ? 1 : F[j-2]);
				dp[i] += dp[i-j] * (j-2 < 0 ? 1 : F[j-2]);
			}
			if(q > I){
				dp[i] = I;
			}
		}
		
		for(int T = ni();T > 0;T--){
			int n = ni();
			long K = nl()-1;
			if(K >= dp[n]){
				out.println(-1);
				continue;
			}
			for(int i = 0;i < n;){
				for(int j = i;j < n;j++){
					long num = i == j ? 1 : F[j-i-1];
					double numd = (double)num * dp[n-1-j];
					num *= dp[n-1-j];
//					tr(i, j, K, num);
					if(numd >= I || K < num){
						long which = K/dp[n-1-j];
						int[] per = kth(j-i+1, which, F);
//						tr("hai", i, j, which, per, dp[n-1-j]);
						for(int k = 0;k < per.length;k++){
							out.print((i+1+per[k]) + " ");
						}
						K %= dp[n-1-j];
						i = j+1;
						break;
					}else{
						K -= num;
					}
				}
			}
			assert K == 0;
			out.println();
		}
	}
	
	public int[] kth(int n, long K, long[] F)
	{
		int[] f = new int[n];
		if(n <= 1){
			return f;
		}
		Arrays.fill(f, -1);
		f[0] = n-1;
		long rem = (1L<<n-1)-1;
		for(int i = 1;i < n-1;i++){
			for(int j = 0;j < n;j++){
				if(rem<<~j<0){
					f[i] = j;
					int x;
					for(x = j;x != -1 && x != i;x = f[x]);
					if(x == -1){
						if(K < F[n-i-2]){
							rem ^= 1L<<j;
							break;
						}else{
							K -= F[n-i-2];
						}
					}
				}
			}
		}
		f[n-1] = Long.numberOfTrailingZeros(rem);
		return f;
	}
	
	public static int[] decPerm(long c, int n) {
		int[] a = new int[n];
		for (int i = n - 1; i >= 0; c /= n - i, i--) {
			a[i] = (int)(c % (n - i));
		}
		long rem = (1L << n) - 1;
		for(int i = 0;i < n;i++){
			long x = rem;
			for(int j = 0;j < a[i];j++, x &= x-1);
			
			a[i] = Long.numberOfTrailingZeros(x);
			rem ^= x&-x;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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