//package educational.round17;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] a = ns().toCharArray();
		char[] b = ns().toCharArray();
		int n = a.length;
		int m = b.length;
		int[] lr = new int[m];
		int[] rr = new int[m];
		int p = 0;
		for(int i = 0;i < m;i++){
			while(p < n && a[p] != b[i])p++;
			if(p < n){
				lr[i] = p;
				p++;
			}else{
				lr[i] = -1;
			}
		}
		p = n-1;
		for(int i = m-1;i >= 0;i--){
			while(p >= 0 && a[p] != b[i])p--;
			if(p >= 0){
				rr[i] = p;
				p--;
			}else{
				rr[i] = -1;
			}
		}
		int ret = 0;
		int argl = -1, argr = -1;
		{
			int nlr = 0;
			for(int i = 0;i < m;i++){
				if(lr[i] != -1){
					nlr++;
				}
			}
			if(nlr > ret){
				ret = nlr;
				argl = nlr; argr = 0;
			}
		}
		{
			int nrr = 0;
			for(int i = 0;i < m;i++){
				if(rr[i] != -1){
					nrr++;
				}
			}
			if(nrr > ret){
				ret = nrr;
				argl = 0; argr = nrr;
			}
		}
		
		// abdcaba
		// abcdcba
		p = 0;
		for(int i = 0;i < m;i++){
			if(lr[i] != -1){
				while(p < m && (rr[p] == -1 || lr[i] >= rr[p] || i >= p))p++;
				int v = i+1+m-p;
				if(v > ret){
					ret = v;
					argl = i+1; argr = m-p;
				}
			}
		}
//		out.println(ret);
		if(ret == 0){
			out.println("-");
		}else{
			out.println(new String(b, 0, argl) + new String(b, b.length-argr, argr));
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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