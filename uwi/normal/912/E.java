//package round456;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E6 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "16 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 750000000";
	
	long[] temp = new long[1000000];
	int tp;
	
	void dfs(int cur, long v, int[] a)
	{
		temp[tp++] = v;
		for(int i = cur;i < a.length;i++){
			if((double)v*a[i] < 1.01e18){
				dfs(i, v*a[i], a);
			}else{
				break;
			}
		}
	}
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] ls = new int[n];
		int[] rs = new int[n];
		{
			int lp = 0;
			for(int i = 0;i < n;i++){
				if(i % 4 == 0 || i % 4 == 3){
					ls[lp++] = a[i];
				}
			}
			ls = Arrays.copyOf(ls, lp);
		}
		{
			int lp = 0;
			for(int i = 0;i < n;i++){
				if(i % 4 == 1 || i % 4 == 2){
					rs[lp++] = a[i];
				}
			}
			rs = Arrays.copyOf(rs, lp);
		}
		
		tp = 0;
		dfs(0, 1L, ls);
		long[] left = Arrays.copyOf(temp, tp);
		tp = 0;
		dfs(0, 1L, rs);
		long[] right = Arrays.copyOf(temp, tp);
		left = radixSort(left);
		right = radixSort(right);
		
		long K = nl();
		
		long low = 0, high = 1000000000000000007L;
		while(high - low > 1){
			long h = high+low>>1;
			if(count(h, left, right, K)){
				high = h;
			}else{
				low = h;
			}
		}
		out.println(high);
	}
	
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

	
	boolean count(long h, long[] left, long[] right, long K)
	{
		int p = left.length-1;
		long ret = K;
		for(int i = 0;i < right.length;i++){
			long v = right[i];
			while(p >= 0 && (v * left[p] > h || (double)v * left[p] > 1e18)){
				p--;
			}
			K -= p+1;
			if(K <= 0)return true;
			if(K - (long)(p+1) * (right.length - i - 1) > 0)return false;
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
	
	public static void main(String[] args) throws Exception { new E6().run(); }
	
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