//package round313;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	long[] e2;
	
	void sl(long[] x)
	{
		x[1] *= 2;
		add(x, x[0]);
	}
	
	void add(long[] x, long a) {
		if(a < 0){
			if(x[0] + a < 0){
				x[0] += 1L<<63;
				x[0] += a;
				x[1]--;
			}else{
				x[0] += a;
			}
		}else{
			if(x[0] + a < 0){
				x[0] -= 1L<<63;
				x[0] += a;
				x[1]++;
			}else{
				x[0] += a;
			}
		}
	}
	
	void solve()
	{
		int n = ni();
		long[][] co = new long[n][];
		long minx = Long.MAX_VALUE;
		for(int i = 0;i < n;i++){
			co[i] = new long[]{ni(), ni()};
			minx = Math.min(minx, co[i][0]);
		}
		
		int D = 43;
		long O = -1000000001;
		long[] x = new long[2];
		long[] y = new long[2];
		double hn = Math.pow(0.5, n);
		for(int d = 1;d <= D && d < n;d++){
			for(int i = 0, j = d%n;i < n;i++,j++){
				if(j == n)j = 0;
				long ax = co[i][0], ay = co[i][1];
				long bx = co[j][0], by = co[j][1];
				if(bx < ax){
					long hl = by-O, hr = ay-O;
					long base = ax-bx;
					long inner = ((hl+hr)*base-(gcd(Math.abs(hr-hl), base)+hl+hr+base))/2 + 1;
					
					add(x, hl+inner-1);
					add(y, hl+inner-1);
				}else if(bx > ax){
					long hl = ay-O, hr = by-O;
					long base = bx-ax;
					long g = gcd(Math.abs(hr-hl), base);
					long inner = ((hl+hr)*base-(g+hl+hr+base))/2 + 1;
					
					add(x, -(hl+inner-1+g));
					add(y, -(hl+inner-1+g));
				}else{
					if(by < ay){
						add(x, -(ay-by));
						add(y, -(ay-by));
					}
				}
			}
			sl(x);
//			E += hd-hn;
		}
		BigInteger X = BigInteger.valueOf(x[1]).shiftLeft(63).add(BigInteger.valueOf(x[0]));
		BigInteger Y = BigInteger.valueOf(y[1]).shiftLeft(63).add(BigInteger.valueOf(y[0]));
		BigDecimal XX = new BigDecimal(X).divide(BigDecimal.valueOf(2L).pow(Math.min(D, n-1)+2));
		BigDecimal YY = new BigDecimal(Y).divide(BigDecimal.valueOf(2L).pow(Math.min(n, 100)));
		double E = XX.subtract(YY).doubleValue();
		
		E /= 1. - (1+n+(long)n*(n-1)/2)*hn;
		E += 1;

		out.printf("%.15f\n", E);
	}
	
	public static long gcd(long a, long b) {
		while (b > 0) {
			long c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			long r = 1000000000;
//			sb.append(Math.round(r*Math.cos(i*Math.PI*2/n)) + " ");
//			sb.append(Math.round(r*Math.sin(i*Math.PI*2/n)) + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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