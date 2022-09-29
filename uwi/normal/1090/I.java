import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class I {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "1 6 -1237943803 1894029789 1509493097 71508950 852609257 1439678501 1404499368 ";

	void solve()
	{
		for(int T = ni(); T> 0;T--){
			int n = ni();
			long l = ni(), r = ni();
			long x = nl(), y = nl(), z = nl(), b1 = nl(), b2 = nl();
			long[] b = new long[n];
			b[0] = b1; b[1] = b2;
			for(int i = 2;i < n;i++){
				b[i] = (b[i-2] * x + b[i-1] * y + z) & (1L<<32)-1;
			}
			for(int i = 0;i < n;i++){
				b[i] = b[i] % (r - l + 1) + l;
			}
			
			long ans = Long.MAX_VALUE;
			
			long min = Long.MAX_VALUE;
			for(long v : b){
				if(v >= 0 && min < v){
					ans = Math.min(ans, min*v);
				}
				min = Math.min(min, v);
			}
			
			boolean[] can = new boolean[n];
			long maxs = Long.MIN_VALUE;
			int hit = 0;
			for(int i = n-1;i >= 0;i--){
				if(b[i] > maxs){
					maxs = b[i];
					can[i] = true;
					hit++;
				}
			}
			if(hit == n){
				out.println("IMPOSSIBLE");
				continue;
			}
			
			int p = 0;
			for(int i = 0;i < n;i++){
				if(can[i]){
					long max = Long.MIN_VALUE;
					for(int j = p;j < i;j++){
						if(b[j] > max && b[j] < b[i]){
							max = b[j];
						}
					}
					if(max != Long.MIN_VALUE){
						ans = Math.min(ans, max * b[i]);
					}
					p = i;
				}
			}
			
			if(ans < Long.MAX_VALUE){
				out.println(ans);
				continue;
			}
			out.println("IMPOSSIBLE");
		}
	}
	
	public static long[] uniq(long[] a)
	{
		int n = a.length;
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || a[i] != a[i-1])a[p++] = a[i];
		}
		return Arrays.copyOf(a, p);
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
	
	public static void main(String[] args) throws Exception { new I().run(); }
	
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