//package round438;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		a = na(n);
		long[] dp = new long[n+1];
		Arrays.fill(dp, Long.MAX_VALUE / 3);
		dp[0] = 0;
		for(int i = 0;i < K;i++){
			as = new long[17][n+1];
			vs = new long[17];
			heads = new int[17];
			tails = new int[17];
			long[] ndp = new long[n+1];
			Arrays.fill(ndp, Long.MAX_VALUE / 3);
			divideAndConquer(0, n+1, 0, n+1, dp, ndp, 0);
			dp = ndp;
		}
		out.println(dp[n]);
	}
	
	int[] a;
	
	public void divideAndConquer(int l, int r, int argl, int argr, long[] pre, long[] cur, int dep)
	{
		if(l >= r)return;
		int h = l+r>>1;
		long min = Long.MAX_VALUE / 3;
		int argmin = -1;
		
		while(heads[dep] < h){
			vs[dep] += as[dep][a[heads[dep]]];
			as[dep][a[heads[dep]]]++;
			heads[dep]++;
		}
		for(int i = Math.max(argl, 0);i < argr && i < h;i++){
			while(tails[dep] < i){
				as[dep][a[tails[dep]]]--;
				vs[dep] -= as[dep][a[tails[dep]]];
				tails[dep]++;
			}
			long val = pre[i] + f(i, h, dep); // [i,h)
			if(val < min){
				min = val;
				argmin = i;
			}
		}
		cur[h] = min;
		
		if(r-l > 1){
			divideAndConquer(l, h, argl, argmin+1, pre, cur, dep+1);
			divideAndConquer(h+1, r, argmin, argr, pre, cur, dep+1);
		}
	}
	
	long[][] as;
	long[] vs;
	private int[] heads, tails;
	private long f(int l, int r, int dep){ return vs[dep]; }
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F3().run(); }
	
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