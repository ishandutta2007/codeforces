//package round428;
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
//	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		long[] g = new long[n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				g[i] |= nl()<<j;
			}
			g[i] |= 1L<<i;
		}
		
		// (K/M)^2*M(M-1)/2
		// K^2*(M-1)/2M
		int mc = solveMaximumClique(g);
		out.printf("%.14f\n", (double)K*K*(mc-1)/2/mc);
	}
	
	public static int solveMaximumClique(long[] g)
	{
		int n = g.length;
		int h = n/2;
		int[] dp = new int[1<<n-h];
		for(int i = 0;i < 1<<h;i++){
			long cover = (1L<<n)-1;
			for(int j = 0;j < h;j++){
				if(i<<~j<0)cover &= g[j];
			}
			if((cover&i) == i){
				dp[(int)(cover>>>h)] = Math.max(dp[(int)(cover>>>h)], Integer.bitCount(i));
			}
		}
		for(int i = 0;i < n-h;i++){
			for(int j = 0;j < 1<<n-h;j++){
				if(j<<~i>=0){
					dp[j] = Math.max(dp[j], dp[j|1<<i]);
				}
			}
		}
		
		int ret = 0;
		for(int i = 0;i < 1<<n-h;i++){
			long cover = (1L<<n)-1;
			for(int j = 0;j < n-h;j++){
				if(i<<~j<0)cover &= g[j+h];
			}
			if((cover&(long)i<<h) == (long)i<<h){
				ret = Math.max(ret, Integer.bitCount(i) + dp[i]);
			}
		}
		return ret;
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