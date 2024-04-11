//package round339;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), A = ni(), cf = ni(), cm = ni();
		long m = nl();
		int[] a = na(n);
		int[][] ai = new int[n][];
		for(int i = 0;i < n;i++)ai[i] = new int[]{a[i], i};
		Arrays.sort(ai, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int[] as = new int[n];
		long[] cum = new long[n+1];
		for(int i = 0;i < n;i++){
			as[i] = ai[i][0];
			cum[i+1] = cum[i] + ai[i][0];
		}
		
		long max = -1L;
		int argmax = -1;
		int arglow = -1;
		
		long rem = m;
		for(int perfected = 0;perfected <= n;perfected++){
			if(perfected > 0){
				rem -= A-ai[n-perfected][0];
			}
			if(rem < 0)break;
			
			int low = 0, high = A+1; // val level
			while(high - low > 1){
				int h = high+low>>>1;
				int lb = lowerBound(as, 0, n-perfected, h);
				long cost = (long)h*lb - cum[lb-1+1];
				if(cost <= rem){
					low = h;
				}else{
					high = h;
				}
			}
			long val = (long)low*cm + (long)cf*perfected;
			if(val > max){
				max = val;
				argmax = perfected;
				arglow = low;
			}
		}
		out.println(max);
		int[] last = new int[n];
		for(int i = 0;i < n;i++){
			if(i >= n-argmax){
				last[ai[i][1]] = A;
			}else{
				last[ai[i][1]] = Math.max(ai[i][0], arglow);
			}
		}
		for(int i = 0;i < n;i++){
			out.print(last[i] + " ");
		}
		out.println();
	}
	
	public static int lowerBound(int[] a, int l, int r, int v)
	{
		if(l > r || l < 0 || r > a.length)throw new IllegalArgumentException();
		int low = l-1, high = r;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h] >= v){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
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