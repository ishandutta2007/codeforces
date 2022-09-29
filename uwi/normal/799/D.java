//package round413;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int a = ni(), b = ni(), h = ni(), w = ni(), n = ni();
		int[] mul = na(n);
		mul = radixSort(mul);
		if(n >= 34){
			mul = Arrays.copyOfRange(mul, mul.length-34, mul.length);
		}
		
		int ret = 999999999;
		ret = Math.min(ret, go((a+h-1)/h, (b+w-1)/w, mul));
		ret = Math.min(ret, go((a+w-1)/w, (b+h-1)/h, mul));
		if(ret >= 10000){
			out.println(-1);
		}else{
			out.println(ret);
		}
	}
	
	// |mul|<=34
	int go(long a, long b, int[] mul)
	{
		if(a == 1 && b == 1)return 0;
		int n = mul.length;
		for(int u = 1;u <= n;u++){
			int h = u/2;
			long[] fi = new long[1<<h];
			for(int j = 0;j < 1<<h;j++){
				long m = 1;
				long im = 1;
				for(int k = 0;k < h;k++){
					if(j<<~k<0){
						m *= mul[n-1-k];
						if(m >= 1e9)m = 1000000000;
					}else{
						im *= mul[n-1-k];
						if(im >= 1e9)im = 1000000000;
					}
				}
				fi[j] = m<<32|1000000000-im;
			}
			Arrays.sort(fi);
			
			for(int j = 0;j < 1<<u-h;j++){
				long m = 1;
				long im = 1;
				for(int k = 0;k < u-h;k++){
					if(j<<~k<0){
						m *= mul[n-1-h-k];
						if(m >= 1e9)m = 1000000000;
					}else{
						im *= mul[n-1-h-k];
						if(im >= 1e9)im = 1000000000;
					}
				}
				long la = (a+m-1)/m;
				int ind = Arrays.binarySearch(fi, la<<32);
				if(ind < 0)ind = -ind-1;
				if(ind < fi.length){
					long xb = (1000000000-(int)fi[ind]) * im;
					if(xb >= b)return u;
				}
			}
		}
		return 999999999;
	}
	
	public static int[] radixSort(int[] f){ return radixSort(f, f.length); }
	public static int[] radixSort(int[] f, int n)
	{
		int[] to = new int[n];
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[f[i]&0xffff]++] = f[i];
			int[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(f[i]>>>16)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[f[i]>>>16]++] = f[i];
			int[] d = f; f = to;to = d;
		}
		return f;
	}

	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		sb.append(1 + " ");
//		sb.append(2 + " ");
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(310 + " ");//gen.nextInt(100000)+2 + " ");
//		}
//		INPUT = sb.toString();

		
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