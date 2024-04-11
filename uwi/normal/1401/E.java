//package round665;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	public static long[] radixSort(long[] f){ return radixSort(f, f.length); }
	public static long[] radixSort(long[] f, int n)
	{
		long[] to = new long[n];
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]>>>16&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]>>>16&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]>>>32&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]>>>32&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < n;i++)b[1+(int)(f[i]>>>48&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < n;i++)to[b[(int)(f[i]>>>48&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		return f;
	}

	
	long numIntersections(int[][] hors, int[][] vers)
	{
		int n = hors.length, m = vers.length;
		long[] es = new long[2*n+m];
		int p = 0;
		for(int i = 0;i < n;i++) {
			es[p++] = (long)hors[i][1]<<32|0L<<25|hors[i][0];
			es[p++] = (long)hors[i][2]<<32|2L<<25|hors[i][0];
		}
		for(int i = 0;i < m;i++) {
			es[p++] = (long)vers[i][0]<<32|1L<<25|i;
		}
		es = radixSort(es);
//		Arrays.sort(es);
		
		int[] ft = new int[1000005];
		long inter = 0;
		for(long e : es) {
			int t = ((int)e)>>>25;
			if(t != 1) {
				int y = ((int)e)&(1<<25)-1;
				addFenwick(ft, y, 1-t);
			}else {
				int ind = ((int)e)&(1<<25)-1;
				int yh = vers[ind][2];
				int yl = vers[ind][1];
				inter += sumFenwick(ft, yh) - sumFenwick(ft, yl - 1);
			}
		}
		
		return inter;
	}
	
	public static int[] shrink(int[] a) {
		int n = a.length;
		long[] b = new long[n];
		for (int i = 0; i < n; i++)
			b[i] = (long) a[i] << 32 | i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && (b[i] ^ b[i - 1]) >> 32 != 0)
				p++;
			ret[(int) b[i]] = p;
		}
		return ret;
	}

	
	long numIntersections2(int[][] hors, int[][] vers)
	{
		int n = hors.length, m = vers.length;
		int[] ys = new int[n+2*m];
		int p = 0;
		for(int i = 0;i < n;i++) {
			ys[p++] = hors[i][0];
		}
		for(int i = 0;i < m;i++) {
			ys[p++] = vers[i][1];
			ys[p++] = vers[i][2];
		}
		ys = shrink(ys);
		p = 0;
		for(int i = 0;i < n;i++) {
			hors[i][0] = ys[p++];
		}
		for(int i = 0;i < m;i++) {
			vers[i][1] = ys[p++];
			vers[i][2] = ys[p++];
		}
		int D = ys.length;
		
		long[] es = new long[2*n+m];
		p = 0;
		for(int i = 0;i < n;i++) {
			es[p++] = (long)hors[i][1]<<32|0L<<25|hors[i][0];
			es[p++] = (long)hors[i][2]<<32|2L<<25|hors[i][0];
		}
		for(int i = 0;i < m;i++) {
			es[p++] = (long)vers[i][0]<<32|1L<<25|i;
		}
		Arrays.sort(es);
		
		int[] ft = new int[D+5];
		long inter = 0;
		for(long e : es) {
			int t = ((int)e)>>>25;
			if(t != 1) {
				int y = ((int)e)&(1<<25)-1;
				addFenwick(ft, y, 1-t);
			}else {
				int ind = ((int)e)&(1<<25)-1;
				int yh = vers[ind][2];
				int yl = vers[ind][1];
				inter += sumFenwick(ft, yh) - sumFenwick(ft, yl - 1);
			}
		}
		
		return inter;
	}
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] hors = new int[n+2][];
		int[][] vers = new int[m+2][];
		for(int i = 0;i < n;i++)hors[i] = na(3);
		for(int i = 0;i < m;i++)vers[i] = na(3);
		int M = 1000000;
		hors[n] = new int[] {0, 0, M};
		hors[n+1] = new int[] {M, 0, M};
		vers[m] = new int[] {0, 0, M};
		vers[m+1] = new int[] {M, 0, M};
		
		out.println(numIntersections(hors, vers) - n - m - 3);
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int l, int r, int v)
	{
		addFenwick(ft, l, v);
		addFenwick(ft, r, -v);
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0 || i < 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
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
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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