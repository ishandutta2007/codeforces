//package round356;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long[] bury = {
				0L, 1L, 2L, 3L, 4L, 5L, 6L, 7L, 15L, 23L, 50L, 114L, 330L, 1330L, 10591L, 215970L, 19464802L, 16542386125L, 409477218238718L
		};
		long n = nl();
		int max = 0;
		for(int i = bury.length-1;i >= 0;i--){
			if(n >= bury[i]){
				max = i;
				break;
			}
		}
		int[] dp = new int[1000001];
		int[] dpmax = new int[1000001];
		int[] argmax = new int[1000001];
		dp[0] = 0;
		int p = 0;
		for(int i = 1;i <= dp.length-1;i++){
			if((long)(p+1)*(p+1)*(p+1) <= i)p++;
			dp[i] = dp[i-p*p*p] + 1;
			if(dp[i] >= dpmax[i-1]){
				argmax[i] = i;
			}else{
				argmax[i] = argmax[i-1];
			}
			dpmax[i] = Math.max(dpmax[i-1], dp[i]);
		}
		out.println(max + " " + dfs(n, max, dpmax, argmax));
	}
	
	long dfs(long n, int need, int[] dpmax, int[] argmax)
	{
		if(n <= dpmax.length-1){
			if(dpmax[(int)n] == need){
				return argmax[(int)n];
			}else{
				return -1;
			}
		}
		long cb = (long)Math.cbrt(n)-1;
		while((cb+1)*(cb+1)*(cb+1) <= n)cb++;
		long res = dfs(n-cb*cb*cb, need-1, dpmax, argmax);
		if(res == -1)return dfs(cb*cb*cb-1, need, dpmax, argmax);
		return res+cb*cb*cb;
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
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