//package vk2016.r1;
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
	
	void solve()
	{
		int n = ni(), K = ni();
		long[] a = new long[n+1];
		long[] b = new long[n+100];
		for(int i = 0;i < n+1;i++){
			b[i] = a[i] = nl();
		}
		for(int i = 0;i < n+100-1;i++){
			long c = b[i]/2;
			b[i] -= 2*c;
			if(b[i] < 0){
				b[i]+=2;
				c--;
			}
			b[i+1] += c;
		}
		if(b[n+99] == -1){
			Arrays.fill(b, 0);
			for(int i = 0;i < n+1;i++){
				a[i] = -a[i];
				b[i] = a[i];
			}
			for(int i = 0;i < n+100-1;i++){
				long c = b[i]/2;
				b[i] -= 2*c;
				if(b[i] < 0){
					b[i]+=2;
					c--;
				}
				b[i+1] += c;
			}
		}
		
		int lim = -1;
		for(int i = b.length-1;i >= 0;i--){
			if(b[i] != 0){
				lim = i;
				break;
			}
		}
		if(lim == -1){
			out.println(0);
			return;
		}
		
		for(int i = 0;i < lim-50;i++){
			if(b[i] != 0){
				out.println(0);
				return;
			}
		}
		
		int ct = 0;
		long[] bb = Arrays.copyOf(b, b.length);
		for(int i = Math.max(0, lim-50);i <= lim && i <= n;i++){
			b[i] -= a[i];
			for(int j = i;j < b.length-1;j++){
				long c = b[j]/2;
				b[j] -= 2*c;
				if(b[j] < 0){
					b[j]+=2;
					c--;
				}
				b[j+1] += c;
			}
			if(b[b.length-1] != 0){
				for(int k = i;k < b.length;k++){
					b[k] = -bb[k];
				}
				b[i] += a[i];
				for(int j = i;j < b.length-1;j++){
					long c = b[j]/2;
					b[j] -= 2*c;
					if(b[j] < 0){
						b[j]+=2;
						c--;
					}
					b[j+1] += c;
				}
			}
			long x = 0;
			long t = 1;
			boolean ok = true;
			for(int j = i;j < b.length-1;j++,t*=2){
				if(j > i+50 && b[j] != 0){
					ok = false;
					break;
				}
				x -= b[j] * t;
				if(Math.abs(x) > K){
					ok = false;
					break;
				}
			}
			if(ok && !(i == n && x == 0)){
				ct++;
			}
			for(int k = i;k < b.length;k++){
				b[k] = bb[k];
			}
			if(b[i] != 0)break;
		}
		out.println(ct);
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