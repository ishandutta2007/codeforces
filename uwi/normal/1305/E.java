//package round2020;
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
		// 5:4, 6:6
		int n = ni();
		int m = ni();
		long max = (long)(n/2)*((n-1)/2);
		if(m > max){
			out.println(-1);
			return;
		}
		
		for(int k = 1;k <= n;k++){
			long lmax = (long)(k/2)*((k-1)/2);
			if(m <= lmax){
				if(lmax == 0){
					for(int i = 0;i < n;i++){
						out.print(1000000000-n+i + " ");
					}
					out.println();
					return;
				}
				
				long[] a = new long[n];
				for(int i = 0;i < k-1;i++){
					out.print(1+i + " ");
					a[i] = i+1;
				}
				long mm = k + (lmax-m)*2;
				out.print(k + (lmax-m)*2 + " ");
				a[k-1] = mm;
				for(int i = 0;i < n-k;i++){
					a[k+i] = 1000000000 - (mm+1)*(n-k-1-i);
					out.print(1000000000 - (mm+1)*(n-k-1-i) + " ");
				}
				out.println();
				check(a, m);
				return;
			}
		}
	}
	
	void check(long[] a, int K)
	{
		int n = a.length;
		for(int i = 0;i < n-1;i++){
			assert a[i] < a[i+1];
		}
		int ct = 0;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				long x = a[i] + a[j];
				if(Arrays.binarySearch(a, x) >= 0){
					ct++;
				}
			}
		}
		assert ct == K;
	}
	
	public static boolean incAscending(int[] a, int base, boolean strict)
	{
		int n = a.length;
		for(int i = n-1;i >= 0;i--){
			if(++a[i] + (strict ? n-1-i : 0) < base){
				for(int j = i+1;j < n;j++)a[j] = a[j-1] + (strict ? 1 : 0);
				return true;
			}
		}
		return false;
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