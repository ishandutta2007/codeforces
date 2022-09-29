//package round548;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// (pref, inc)
		// (b, p-s)
		// (pref, inc)
		int n = ni();
		int m = ni();
		int[] ps = na(n);
		int[] ss = na(n);
		int[] bs = na(n);
		int[] incs = na(m);
		int[] prefs = na(m);
		
		long[][] es = new long[n*2+m][];
		int p = 0;
		long[][] yls = new long[n][];
		long[][] yhs = new long[n][];
		for(int i = 0;i < n;i++){
			es[p++] = new long[]{bs[i] + ps[i], ps[i] - bs[i], -1, i};
			yls[i] = new long[]{ps[i] - bs[i], i};
			// (b-(s-p), s)
			// (b+(s-p), s)
			// (b+p, s-(b-(s-p))) // y-x
			// (s) : original x
			yhs[i] = new long[]{ss[i], i};
			es[p++] = new long[]{(long)bs[i] + 2L*ss[i]-ps[i], i};
		}
		Arrays.sort(yls, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return Long.compare(a[0], b[0]);
			}
		});
		Arrays.sort(yhs, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return Long.compare(a[0], b[0]);
			}
		});
		int[] imapl = new int[n];
		for(int i = 0;i < n;i++)imapl[(int)yls[i][1]] = i;
		long[] yl = new long[n];
		for(int i = 0;i < n;i++)yl[i] = yls[i][0];
		int[] imaph = new int[n];
		for(int i = 0;i < n;i++)imaph[(int)yhs[i][1]] = i;
		long[] yh = new long[n];
		for(int i = 0;i < n;i++)yh[i] = yhs[i][0];
		
		for(int i = 0;i < m;i++){
			es[p++] = new long[]{prefs[i] + incs[i], incs[i], i};
		}
		Arrays.sort(es, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				if(a[0] != b[0])return Long.compare(a[0], b[0]);
				return -(a.length - b.length);
			}
		});
		
		long[] anss = new long[m];
		int[] ftl = new int[n+5];
		int[] fth = new int[n+5];
		for(long[] e : es){
			if(e.length == 4){
				addFenwick(ftl, imapl[(int)e[3]], 1);
				addFenwick(fth, imaph[(int)e[3]], 1);
			}else if(e.length == 2){
				addFenwick(ftl, imapl[(int)e[1]], -1);
				addFenwick(fth, imaph[(int)e[1]], -1);
			}else{
				int lind = lowerBound(yl, incs[(int)e[2]] - prefs[(int)e[2]]+1);
				int hind = lowerBound(yh, e[1]);
//				sumFenwick(ftl, n) - sumFenwick(ftl, lind-1) + sumFenwick(fth, hind-1);
				anss[(int)e[2]] = sumFenwick(ftl, lind-1) - sumFenwick(fth, hind-1);
			}
		}
		for(long v : anss){
			out.print(v + " ");
		}
		out.println();
	}
	
	public static int lowerBound(long[] a, long v)
	{
		int low = -1, high = a.length;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h] >= v){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
	}

	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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