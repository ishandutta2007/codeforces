//package round526;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "4\r\n" + 
			"6 2 4\r\n" + 
			"1 6 2\r\n" + 
			"2 4 3\r\n" + 
			"5 3 8";
	
	void solve()
	{
		int n = ni();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			co[i] = new long[]{nl(), nl(), nl()};
		}
		Arrays.sort(co, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return Long.compare(a[0], b[0]);
			}
		});
		
		EnvelopeLinearDeque eld = new EnvelopeLinearDeque(n+1);
		eld.add(0, 0);
		long[] dp = new long[n];
		long ans = 0;
		for(int i = 0;i < n;i++){
			dp[i] = (long)co[i][0] * co[i][1] - co[i][2] - eld.get(-co[i][1]);
			eld.add(-co[i][0], -dp[i]);
			ans = Math.max(ans, dp[i]);
		}
		out.println(ans);
	}

	public static class EnvelopeLinearDeque {
		public long[] slopes, intercepts;
		public int f, b;
		
		public EnvelopeLinearDeque(int n)
		{
			slopes = new long[n];
			intercepts = new long[n];
			f = b = 0;
		}
		
		public long f(long x, int ind)
		{
			return slopes[ind]*x+intercepts[ind];
		}
		
		public double f(double x, int ind)
		{
			return slopes[ind]*x+intercepts[ind];
		}
		
		public long get(long x)
		{
			while(f-b > 1 && f(x, b) > f(x, b+1))b++;
			return f(x, b);
		}
			
		public void add(long slope, long intercept)
		{
			if(f-b > 0)assert slope <= slopes[f-1];
			if(f-b > 0 && slope == slopes[f-1] && intercept >= intercepts[f-1])return;
			
			while(f-b > 0){
				// sl*x+in = lsl*x+lin
				// (sl-lsl)*x = lin-in
				double x = (double)(intercept-intercepts[f-1])/(slopes[f-1]-slope);
				if(f-1-b > 0 && f(x, f-2) < f(x, f-1)){
					f--;
				}else{
					break;
				}
			}
			slopes[f] = slope;
			intercepts[f] = intercept;
			f++;
		}
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