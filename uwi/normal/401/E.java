//package round235;
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
	
	void solve()
	{
		int n = ni(), m = ni();
		int L = ni(), R = ni(), p = ni();
		
		long ret = 0;
		if(L == 1){
			ret += (long)n*(m+1)+(long)(n+1)*m;
			ret %= p;
		}
		
		Arrays.fill(counts, -1);
		long xsum = countx(n, m, 1, (long)R*R);
		Arrays.fill(counts, -1);
		long xsum2 = countx(n, m, 1, (long)L*L-1);
		Arrays.fill(counts, -1);
		long ysum = countx(m, n, 1, (long)R*R);
		Arrays.fill(counts, -1);
		long ysum2 = countx(m, n, 1, (long)L*L-1);
		Arrays.fill(counts, -1);
		long xysum = countxy(n, m, 1, (long)R*R, p);
		Arrays.fill(counts, -1);
		long xysum2 = countxy(n, m, 1, (long)L*L-1, p);
		Arrays.fill(counts, -1);
		long sum = count(n, m, 1, (long)R*R);
		Arrays.fill(counts, -1);
		long sum2 = count(n, m, 1, (long)L*L-1);
//		tr(xsum, xsum2, ysum, ysum2, xysum, xysum2, sum, sum2);
		// [837209273, 837209273, 458854071, 79301507]
//		if(xsum < 0)throw new RuntimeException("xsum");
//		if(ysum < 0)throw new RuntimeException("ysum");
//		if(xysum < 0)throw new RuntimeException("xysum");
//		if(sum < 0)throw new RuntimeException("sum");
		
//		tr(ret);
		ret += 2L*((xysum-xysum2)%p-(ysum-ysum2)%p*(m+1)%p-(xsum-xsum2)%p*(n+1)%p+(long)(n+1)*(m+1)%p*(sum-sum2)%p);
		out.println((ret%p+p)%p);
//		tr(xsum, ysum, xysum);
	}
	
	long[] counts = new long[110000];
	
	long BIG = 8000000000000000000L;
	
	long count(int n, int m, int d, long R2)
	{
		if(counts[d] >= 0)return counts[d];
		long ret = 0;
		for(long i = 1;i <= m/d;i++){
			double u = ((double)R2/d/d)-i*i;
			if(u < 1)break;
			long x = (long)Math.sqrt(u);
			ret += Math.min(n/d, x);
		}
		if(ret == 0)return counts[d] = 0;
		for(int i = 2*d;i <= n && i <= m;i += d){
			ret -= count(n, m, i, R2);
		}
		return counts[d] = ret;
	}
	
	long countx(int n, int m, int d, long R2)
	{
		if(counts[d] >= 0)return counts[d];
		long ret = 0;
		for(long i = 1;i <= m/d;i++){
			double u = ((double)R2/d/d)-i*i;
			if(u < 1)break;
			long x = (long)Math.sqrt(u);
			ret += Math.min(n/d, x) * i;
		}
		if(ret == 0)return counts[d] = 0;
		for(int i = 2*d, j = 2;i <= n && i <= m;i += d, j++){
			ret -= countx(n, m, i, R2) * j;
		}
		if(ret < 0)throw new RuntimeException();
		return counts[d] = ret;
	}
	
	long countxy(int n, int m, int d, long R2, int P)
	{
		if(counts[d] >= 0)return counts[d];
		long ret = 0;
		for(long i = 1;i <= m/d;i++){
			double u = ((double)R2/d/d)-i*i;
			if(u < 1)break;
			long x = (long)Math.sqrt(u);
			long y = Math.min(n/d, x);
			ret += y*(y+1)/2 * i;
			if(ret >= BIG)ret %= P;
		}
		for(int i = 2*d, j = 2;i <= n && i <= m;i += d, j++){
			long temp = countxy(n, m, i, R2, P) * j;
			if(temp >= 1000000000000L)temp %= P;
			temp *= j;
			ret -= temp;
			if(ret <= -BIG)ret %= P;
//			ret -= count(n, m, i, R2) * j % P * j % P;
		}
		ret %= P;
		if(ret < 0)ret += P;
		return counts[d] = ret;
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