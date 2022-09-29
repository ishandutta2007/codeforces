//package round363;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		double[] a = new double[n];
		for(int i = 0;i < n;i++)a[i] = nd();
		if(n == 1){
			out.println("1.0");
			return;
		}
		int[] sum = new int[1<<n];
		for(int i = 1;i < 1<<n;i++){
			int j = Integer.numberOfTrailingZeros(i);
			sum[i] = sum[i^1<<j] + (int)Math.round(a[j]*100);
		}
		
		long[][] C = new long[25 + 1][25 + 1];
		for (int i = 0; i <= 25; i++) {
			C[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			}
		}
		long[] w = new long[K];
		Arrays.fill(w, 1);
		for(int i = K-1;i >= 0;i--){
			for(int L = i-1;L >= 0;L--){
				w[L] -= w[i] * C[n-1-L][i-L];
			}
		}
		
		for(int i = 0;i < n;i++){
			if(Math.abs(a[i]) < 1E-9){
				out.printf("%.14f ", 0.);
				continue;
			}
			if(Math.abs(a[i]-1) < 1E-9){
				out.printf("%.14f ", 1.);
				continue;
			}
			
			double p = 0;
			int[] f = new int[K];
			Arrays.fill(f, 1);
			for(int j = 0;j < 1<<n;j++){
				if(j<<~i>=0){
					if(Integer.bitCount(j) < K){
						p += (1./(1-(double)sum[j]/100)) * w[Integer.bitCount(j)];
					}
				}
			}
			out.printf("%.14f ", Math.max(0, Math.min(1, p*a[i])));
		}
	}
	
	void run() throws Exception
	{
//		int n = 20, m = 19;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		sb.append("0.81" + " ");
//		for (int i = 0; i < 19; i++) {
//			sb.append("0.01 ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
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