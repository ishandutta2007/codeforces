//package educational.round79;
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
		int n = ni(), K = ni(), L = ni();
		char[] s = ns(n);
		if((long)K*L >= n){
			out.println(0);
			return;
		}
		boolean[] h = new boolean[n];
		for(int i = 0;i < n;i++){
			h[i] = s[i] >= 'a' && s[i] <= 'z';
		}
		long ans = go(h, K, L);
		for(int i = 0;i < n;i++){
			h[i] ^= true;
		}
		ans = Math.min(ans, go(h, K, L));
		out.println(ans);
	}
	
	long go(boolean[] h, int K, int L)
	{
		int n = h.length;
		double low = -1, high = n+1;
		for(int rep = 0;rep < 50;rep++){
			double q = low + (high - low) / 2;
			int cr = which(h, L, q);
			if(cr > K){
				low = q;
			}else{
				high = q;
			}
		}
		
		double pe = high;
//		int cr = which(h, L, pe);
		double[] dp = new double[n+1];
		for(int i = 1;i <= n;i++){
			dp[i] = dp[i-1] + (h[i-1] ? 1 : 0);
			double v = dp[Math.max(0, i-L)] + pe;
			if(v < dp[i]){
				dp[i] = v;
			}
		}
		return Math.round(dp[n] - pe * K);
	}
	
	int which(boolean[] h, int L, double pe)
	{
		int n = h.length;
		double[] dp = new double[n+1];
		int[] used = new int[n+1];
		for(int i = 1;i <= n;i++){
			dp[i] = dp[i-1] + (h[i-1] ? 1 : 0);
			double v = dp[Math.max(0, i-L)] + pe;
			if(v < dp[i]){
				dp[i] = v;
				used[i] = used[Math.max(0, i-L)] + 1;
			}else{
				used[i] = used[i-1];
			}
		}
		return used[n];
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