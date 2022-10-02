//package round298;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long[] a = new long[n+1];
		for(int i = 1;i <= n;i++)a[i] = ni();
		int m = ni();
		int[] f = new int[n+1];
		for(int i = 0;i < m;i++)f[ni()]++;
		
		if(f[n] == f[1]+1){
			long cy = f[1];
			f[1] -= cy; f[n] -= cy;
			for(int i = 2;i <= n-1;i++){
				f[i] -= 2*cy;
			}
			
			long ret = cy*2L*(a[n]-a[1]);
			for(int i = 1;i <= n-1;i++){
				if(f[i] == 0 && f[i+1] >= 1){
					ret += a[n]-a[i+1];
				}
				if(f[i] <= 1 && f[i+1] == 2){
					ret += a[n]-a[i+1];
				}
			}
			out.println(ret);
		}else if(f[1] == f[n]+1){
			long cy = f[n];
			f[1] -= cy; f[n] -= cy;
			for(int i = 2;i <= n-1;i++){
				f[i] -= 2*cy;
			}
			
			long ret = cy*2L*(a[n]-a[1]);
			for(int i = 1;i <= n-1;i++){
				if(f[i+1] == 0 && f[i] >= 1){
					ret += a[i]-a[1];
				}
				if(f[i+1] <= 1 && f[i] == 2){
					ret += a[i]-a[1];
				}
			}
			out.println(ret);
		}else if(f[1] == f[n]){
			long cy = f[n];
			f[1] -= cy; f[n] -= cy;
			for(int i = 2;i <= n-1;i++){
				f[i] -= 2*cy;
			}
			
			boolean ch = false;
			long ret = cy*2L*(a[n]-a[1]);
			for(int i = 1;i <= n-1;i++){
				if(f[i] < f[i+1]){
					ret -= a[i+1];
					ch = true;
				}else if(f[i] > f[i+1]){
					ret += a[i];
					ch = true;
				}
			}
			if(ch){
				out.println(ret);
			}else{
				long del = a[2]-a[1];
				for(int i = 1;i <= n-1;i++){
					if(del != a[i+1]-a[i]){
						out.println(-1);
						return;
					}
				}
				out.println(ret-del);
			}
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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