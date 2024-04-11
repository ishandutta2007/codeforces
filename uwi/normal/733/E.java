//package round378;
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
		char[] s = ns(n);
		long[] ds = new long[n+1];
		long[] cds = new long[n+1];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(s[i] == 'D'){
				ds[p++] = i;
			}
		}
		for(int i = 0;i < p;i++){
			cds[i+1] = cds[i] + ds[i];
		}
		
		long[] us = new long[n+1];
		long[] cus = new long[n+1];
		int q = 0;
		for(int i = n-1;i >= 0;i--){
			if(s[i] == 'U'){
				us[q++] = n-1-i;
			}
		}
		for(int i = 0;i < q;i++){
			cus[i+1] = cus[i] + us[i];
		}
		
		int pp = 0;
		int qq = q;
		for(int i = 0;i < n;i++){
			long ret = 0;
			if(s[i] == 'U'){
				int nd = p-pp;
				int nu = q-qq;
				if(nd <= nu){
					// up
					nu = nd;
					ret += ((cds[pp+nd] - cds[pp]) - (long)i*nd) * 2;
					ret += ((cus[qq+nu] - cus[qq]) - (long)(n-1-i)*nu) * 2;
					ret += n-i;
				}else{
					// down
					nd = nu + 1;
					ret += ((cds[pp+nd] - cds[pp]) - (long)i*nd) * 2;
					ret += ((cus[qq+nu] - cus[qq]) - (long)(n-1-i)*nu) * 2;
					ret += i+1;
				}
				qq--;
			}else{
				pp++;
				int nd = p-pp;
				int nu = q-qq;
				if(nu <= nd){
					// down
					nd = nu;
					ret += ((cds[pp+nd] - cds[pp]) - (long)i*nd) * 2;
					ret += ((cus[qq+nu] - cus[qq]) - (long)(n-1-i)*nu) * 2;
					ret += i+1;
				}else{
					// up
					nu = nd + 1;
					ret += ((cds[pp+nd] - cds[pp]) - (long)i*nd) * 2;
					ret += ((cus[qq+nu] - cus[qq]) - (long)(n-1-i)*nu) * 2;
					ret += n-i;
				}
			}
			out.print(ret + " ");
		}
		out.println();
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