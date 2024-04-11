//package mailru.r3;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)insolve();
	}
	
	void insolve()
	{
		int n = ni();
		double C = nd(), GT = nd();
		int[][] as = new int[n][];
		for(int i = 0;i < n;i++){
			as[i] = new int[]{ni(), ni()};
			// a p
		}
		Arrays.sort(as, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[0] - b[0]);
			}
		});
		double[][] dp = new double[n+1][10*n+1];
		for(int i = 0;i <= n;i++)Arrays.fill(dp[i], Double.POSITIVE_INFINITY);
		dp[0][0] = 0;
		double[] pows = new double[n+1];
		pows[0] = 1;
		for(int i = 1;i <= n;i++)pows[i] = pows[i-1] / 0.9;
		for(int[] a : as){
			int p = a[1];
			int d = a[0];
			for(int i = n;i >= 0;i--){
				for(int j = 10*n;j >= 0;j--){
					if(Double.isInfinite(dp[i][j]))continue;
					dp[i+1][j+p] = Math.min(dp[i+1][j+p], dp[i][j] + pows[i+1] * d);
				}
			}
		}
		for(int i = 10*n;i >= 0;i--){
			for(int j = n;j >= 0;j--){
				if(Double.isInfinite(dp[j][i]))continue;
//				- (GT - 10N) <= -T or
//						(GT-10N-1.0/C) >= 0 and min <= -T/C
				if(dp[j][i] + 10*j <= GT || GT - 10*j-1.0/C >= 0 && -(GT - 10*j+1.0/C)*(GT - 10*j+1.0/C)/4 <= -dp[j][i]/C){
					out.println(i);
					return;
				}
			}
		}
		out.println(0);
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