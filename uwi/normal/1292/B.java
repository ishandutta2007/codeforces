//package round614;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class B {
	InputStream is;
	PrintWriter out;
//	String INPUT = "1 1 2 2 0 0 1000000000 1000000000 10";
	String INPUT = "";
	
	void solve()
	{
		long x0 = nl();
		long y0 = nl();
		long ax = nl();
		long ay = nl();
		long bx = nl();
		long by = nl();
		long xs = nl();
		long ys = nl();
		long T = nl();
		List<long[]> co = new ArrayList<>();
		co.add(new long[]{x0, y0});
		while(true){
			long[] p = co.get(co.size()-1);
			double xx = (double)p[0] * ax + bx;
			double yy = (double)p[1] * ay + by;
			if(xx+yy > 1e17)break;
			long[] q = {
					p[0] * ax + bx,
					p[1] * ay + by
			};
			co.add(q);
		}
		long I = 100000000000000000L;
		int n = co.size();
		long[][][] dp = new long[2][n][n];
		int ans = 0;
		for(int len = 1;len <= n;len++){
			for(int i = 0;i+len-1 < n;i++){
				int j = i+len-1;
				if(len == 1){
					dp[0][i][j] = dp[1][i][j] = Math.abs(xs-co.get(i)[0]) + 
							Math.abs(ys-co.get(i)[1]);
				}else{
					dp[0][i][j] = Math.min(
							dp[0][i+1][j] + d(i, i+1, co),
							dp[1][i+1][j] + d(j, i, co));
					dp[1][i][j] = Math.min(
							dp[1][i][j-1] + d(j-1, j, co),
							dp[0][i][j-1] + d(i, j, co));
				}
				dp[0][i][j] = Math.min(dp[0][i][j], I);
				dp[1][i][j] = Math.min(dp[1][i][j], I);
				if(dp[0][i][j] <= T || dp[1][i][j] <= T){
					ans = Math.max(ans, j-i+1);
				}
			}
		}
		out.println(ans);
	}
	
	long d(int i, int j, List<long[]> co)
	{
		return 
				Math.abs(co.get(i)[0] - co.get(j)[0]) + 
				Math.abs(co.get(i)[1] - co.get(j)[1]); 
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