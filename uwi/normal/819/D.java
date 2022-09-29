//package round421;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long T = nl();
		int n = ni();
		int[] a = na(n);
		long[] c = new long[n+1];
		for(int i = 0;i < n;i++){
			c[i+1] = c[i] + a[(i+1)%n];
		}
		long g = gcd(c[n], T);
		long[][] ci = new long[n][];
		long f = invl(c[n]/g, T/g);
		for(int i = 0;i < n;i++){
			long t = c[i]/g%(T/g)*f%(T/g);
			ci[i] = new long[]{c[i] % g, t, i};
		}
		// c[n]*x+u = c
		
		Arrays.sort(ci, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				if(a[0] != b[0])return Long.compare(a[0], b[0]);
				if(a[1] != b[1])return Long.compare(a[1], b[1]);
				return -Long.compare(a[2], b[2]);
			}
		});
		long[] ans = new long[n];
		for(int i = 0;i < n;){
			int j = i;
			while(j < n && ci[i][0] == ci[j][0])j++;
			
			for(int k = i;k < j-1;k++){
				ans[(int)ci[k][2]] = ci[k+1][1] - ci[k][1];
			}
			ans[(int)ci[j-1][2]] = ci[i][1] - ci[j-1][1] + (T/g);
//			for(int k = i+1;k < j;k++){
//				if(ci[k][1] == ci[k-1][1])continue;
//				ans[(int)ci[k][2]] = ci[k][1] - ci[k-1][1];
//			}
//			ans[(int)ci[i][2]] = ci[i][1] - ci[j-1][1] + (T/g);
			i = j;
		}
		// 0 2 5
		for(int i = 0;i < n;i++){
			out.print(ans[i] + " ");
		}
		out.println();
	}
	
	public static long invl(long a, long mod) {
		a %= mod;
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
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
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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