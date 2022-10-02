//package educational.round10;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int o = 1000000000;
		int[][] co = new int[n][];
		int[] ys = new int[n];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni(), ni()+o, i};
			ys[i] = co[i][1];
		}
		ys = shrink(ys);
		for(int i = 0;i < n;i++)co[i][1] = ys[i];
		
		Arrays.sort(co, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		int[] ret = new int[n];
		int[] ft = new int[n+3];
		for(int i = n-1;i >= 0;i--){
			ret[co[i][2]] = sumFenwick(ft, co[i][1]);
			addFenwick(ft, co[i][1], 1);
		}
		for(int i = 0;i < n;i++){
			out.println(ret[i]);
		}
	}
	
	public static int sumFenwick(int[] ft, int i) {
		int sum = 0;
		for (i++; i > 0; i -= i & -i)
			sum += ft[i];
		return sum;
	}

	public static void addFenwick(int[] ft, int i, int v) {
		if (v == 0 || i < 0)
			return;
		int n = ft.length;
		for (i++; i < n; i += i & -i)
			ft[i] += v;
	}

	public static int findGFenwick(int[] ft, int v) {
		int i = 0;
		int n = ft.length;
		for (int b = Integer.highestOneBit(n); b != 0 && i < n; b >>= 1) {
			if (i + b < n) {
				int t = i + b;
				if (v >= ft[t]) {
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i + 1) : i - 1;
	}

	public static int valFenwick(int[] ft, int i) {
		return sumFenwick(ft, i) - sumFenwick(ft, i - 1);
	}

	public static int[] restoreFenwick(int[] ft) {
		int n = ft.length - 1;
		int[] ret = new int[n];
		for (int i = 0; i < n; i++)
			ret[i] = sumFenwick(ft, i);
		for (int i = n - 1; i >= 1; i--)
			ret[i] -= ret[i - 1];
		return ret;
	}

	public static int before(int[] ft, int x) {
		int u = sumFenwick(ft, x - 1);
		if (u == 0)
			return -1;
		return findGFenwick(ft, u - 1) + 1;
	}

	public static int after(int[] ft, int x) {
		int u = sumFenwick(ft, x);
		int f = findGFenwick(ft, u);
		if (f + 1 >= ft.length - 1)
			return -1;
		return f + 1;
	}

	public static int[] buildFenwick(int[] a) {
		int n = a.length;
		int[] ft = new int[n + 1];
		System.arraycopy(a, 0, ft, 1, n);
		for (int k = 2, h = 1; k <= n; k *= 2, h *= 2) {
			for (int i = k; i <= n; i += k) {
				ft[i] += ft[i - h];
			}
		}
		return ft;
	}

	public static int[] buildFenwick(int n, int v) {
		int[] ft = new int[n + 1];
		Arrays.fill(ft, 1, n + 1, v);
		for (int k = 2, h = 1; k <= n; k *= 2, h *= 2) {
			for (int i = k; i <= n; i += k) {
				ft[i] += ft[i - h];
			}
		}
		return ft;
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
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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