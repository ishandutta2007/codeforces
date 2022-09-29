//package round507;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long t = nl();
		long[] a = new long[n];
		for(int i = 0;i < n;i++){
			a[i] = nl();
		}
		int[] x = na(n);
		for(int i = 0;i < n;i++)x[i]--;
		for(int i = 0;i < n;i++){
			if(x[i] < i){
				out.println("No");
				return;
			}
		}
		for(int i = 0;i < n-1;i++){
			if(x[i] > x[i+1]){
				out.println("No");
				return;
			}
		}
		for(int i = 0;i < n-1;i++){
			if(x[i] < x[i+1]){
				if(x[i] != i){
					out.println("No");
					return;
				}
			}
		}
		long D = 2000000000000000000L;
		long[] b = new long[n];
		for(int i = n-1;i >= 0;){
			int j = i;
			while(j >= 0 && x[i] == x[j])j--;
			
			// (j,i]
			long p = D;
			for(int k = i;k >= j+1;k--){
				b[k] = p--;
			}
			boolean ok = true;
			for(int k = j+2;k <= i;k++){
				if(b[k-1] >= a[k]){
				}else{
					ok = false;
				}
			}
			if(!ok){
				out.println("No");
				return;
			}
			D = a[j+1]-1;
			
			i = j;
		}
		
		for(int i = 0;i < n;i++)b[i] += t;
		for(int i = 0;i < n-1;i++){
			if(b[i] >= b[i+1]){
				out.println("No");
				return;
			}
		}
		out.println("Yes");
		for(int i = 0;i < n;i++){
			out.print(b[i] + " ");
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
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
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