//package round638;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	// 3 7
	// 4 1
	// 4 2
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] a = new int[n];
		int[] b = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = ni(); b[i] = ni();
		}
		
		long[] dp = new long[K];
		Arrays.fill(dp, Long.MIN_VALUE / 2);
		dp[0] = 0;
		
		long s = 0;
		for(int i = 0;i < n;i++){
			long[] ndp = new long[K];
			Arrays.fill(ndp, Long.MIN_VALUE / 2);
			long ns = (s + a[i] + b[i]) % K;
			for(int j = 0;j < K;j++){
				int rem = (a[i] + b[i] - j) % K;
				if(a[i] >= j && b[i] >= rem){
					long plus = (a[i]+b[i]-j)/K;
					for(int k = 0, t = j, u = (int)((s-k+K)%K);k < K;k++,t++,u--){
						if(t == K)t = 0;
						if(u < 0)u = K-1;
						ndp[t] = Math.max(ndp[t], 
						dp[k] + plus + (k+j >= K ? 1 : 0) + (u + rem >= K ? 1 : 0));
						
//						ndp[(k+j)%K] = Math.max(ndp[(k+j)%K], 
//								dp[k] + (a[i] + b[i] - j) / K + (k+j >= K ? 1 : 0) + ((s-k+K) % K + rem >= K ? 1 : 0));
					}
				}
			}
			dp = ndp;
			s = ns;
		}
		long ans = 0;
		for(int i = 0;i < K;i++){
			ans = Math.max(ans, dp[i]);
		}
		out.println(ans);
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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