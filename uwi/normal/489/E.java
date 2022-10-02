//package round277h;
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
		int n = ni(), L = ni();
		int[][] rest = new int[n][];
		for(int i = 0;i < n;i++){
			rest[i] = new int[]{ni(), ni()};
		}
		double low = 0, high = 2000000;
		for(int rep = 0;rep < 70;rep++){
			double h = (low + high) / 2;
			if(ok(h, rest, L)){
				high = h;
			}else{
				low = h;
			}
		}
		int[] rroute = route(high, rest, L);
		for(int i = rroute.length-1;i >= 0;i--){
			out.print(rroute[i] + " ");
		}
		out.println();
	}
	
	boolean ok(double h, int[][] rest, int L)
	{
		int n = rest.length;
		double[] dp = new double[n+1];
		for(int i = 1;i <= n;i++){
			double min = Double.POSITIVE_INFINITY;
			for(int j = 0;j < i;j++){
				double r = rest[i-1][0] - (j == 0 ? 0 : rest[j-1][0]);
				min = Math.min(min, Math.sqrt(Math.abs(r-L)) + dp[j] - h * rest[i-1][1]);
			}
			dp[i] = min;
		}
		return dp[n] < 0;
	}
	
	int[] route(double h, int[][] rest, int L)
	{
		int n = rest.length;
		int[] prev = new int[n+1];
		Arrays.fill(prev, -1);
		double[] dp = new double[n+1];
		for(int i = 1;i <= n;i++){
			double min = Double.POSITIVE_INFINITY;
			int arg = -1;
			for(int j = 0;j < i;j++){
				double r = rest[i-1][0] - (j == 0 ? 0 : rest[j-1][0]);
				double v = Math.sqrt(Math.abs(r-L)) + dp[j] - h * rest[i-1][1];
				if(v < min){
					min = v;
					arg = j;
				}
			}
			dp[i] = min;
			prev[i] = arg;
		}
		
		int[] route = new int[n+1];
		int p = 0;
		for(int u = n;u != 0;u = prev[u]){
			route[p++] = u;
		}
		return Arrays.copyOf(route, p);
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