//package round398;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	boolean debug = false;
	
	void solve()
	{
		long tf = nl(), tt = nl();
		long sp = nl();
		int n = ni();
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = nl();
		if(n == 0 || a[0] > tf){
			out.println(debug ? 0 : tf);
		}else{
			long[] ends = new long[n];
			long prev = tf;
			for(int i = 0;i < n;i++){
				long end = a[i] + sp;
				end = Math.max(end, prev + sp);
				ends[i] = end;
				prev = end;
			}
			for(int i = 0;i < n-1;i++){
				if(ends[i] < a[i+1] && ends[i] <= tt-sp){
					out.println(debug ? 0 : ends[i]);
					return;
				}
			}
			if(ends[n-1] <= tt-sp){
				out.println(debug ? 0 : ends[n-1]);
				return;
			}
			long wait = Long.MAX_VALUE;
			long when = -1;
			for(int i = 1;i < n;i++){
				if(a[i] <= a[i-1] + 1)continue;
				long v = ends[i-1]-(a[i]-1);
				if(v < wait && ends[i-1] <= tt-sp){
					wait = v;
					when = a[i]-1;
				}
			}
			
			if(a[0] > 0){
				long v = tf-(a[0]-1);
				if(v < wait){
					wait = v;
					when = a[0]-1;
				}
			}
			
			for(int i = 0;i < n;){
				int j = i;
				while(j < n && a[j] == a[i])j++;
				
				long last = ends[j-1];
				if(last <= tt-sp && last-a[i] < wait){
					wait = last-a[i];
					when = a[i];
				}
				
				i = j;
			}
			assert when != -1;
			out.println(debug ? wait : when);
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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