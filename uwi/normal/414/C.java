//package round240;
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
	
	long[] cum = new long[30];
	long[] same = new long[30];
	
	public long bubbleCount(int[] a, int l, int r)
	{
		if(r - l <= 1)return 0;
		int m = (l+r)/2;
		long ret = bubbleCount(a, l, m) + bubbleCount(a, m, r);
		int[] temp = Arrays.copyOfRange(a, l, r);
		for(int p0 = 0, p1 = m-l, p = l;p < r;){
			if(p0 == m-l){
				a[p++] = temp[p1++];
			}else if(p1 == r-l){
				a[p++] = temp[p0++];
			}else if(temp[p0] <= temp[p1]){
				a[p++] = temp[p0++];
			}else{
				cum[Integer.numberOfTrailingZeros(r-l)] += m-l-p0;
				a[p++] = temp[p1++];
				ret += m-l-p0;
			}
		}
		for(int p0 = 0, p1 = m-l;p0 < m-l;){
			int z0 = p0;
			for(;z0 < m-l && temp[z0] == temp[p0];z0++);
			while(p1 < r-l && temp[p0] > temp[p1])p1++;
			int s1 = p1;
			while(p1 < r-l && temp[p0] == temp[p1])p1++;
			same[Integer.numberOfTrailingZeros(r-l)] += (long)(p1-s1)*(z0-p0);
			p0 = z0;
		}
		
		return ret;
	}
	
	void solve()
	{
		int n = ni();
		int[] a = na(1<<n);
		bubbleCount(a, 0, 1<<n);
		
		int Q = ni();
		for(int i = 0;i < Q;i++){
			int d = ni();
			for(int j = 1;j <= d;j++){
				cum[j] = (1L<<j+n-2)-same[j]-cum[j];
			}
			long sum = 0;
			for(int j = 1;j <= n;j++){
				sum += cum[j];
			}
			out.println(sum);
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