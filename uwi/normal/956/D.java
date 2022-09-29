//package round472;
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
		int n = ni(), W = ni();
		// x1 + (v1+w)t = 0
		// x2 + (v2+w)t = 0
		// (x1-x2) + (v1-v2)t = 0
		// t = -(x1-x2)/(v1-v2)
		// w = -x1/t - v1 = x1(v1-v2)/(x1-x2)-v1
		// (v1x2-v2x1)/(x1-x2)
		// (v1/x1-v2/x2)/(1/x2-1/x1)
		// -W <= (v1x2-v2x1)/(x1-x2) <= W
		
		// (1,W) -> (0,1)
		// (1,-W) -> (1,0)
		
		// a+bW = 0
		// c+dW = 1
		// a-bW = 1
		// c-dW = 0
		
		// a = 1/2, b = -1/2/W
		// c = 1/2, d = 1/2/W
		
		// W = 0
		// v1x2-v2x1 = 0
		// v1/x1-v2/x2
		
		if(W == 0){
			long[][] as = new long[n][];
			for(int i = 0;i < n;i++){
				int X = ni(), V = ni();
				as[i] = reduce(new long[]{V, X});
			}
			Arrays.sort(as, new Comparator<long[]>() {
				public int compare(long[] a, long[] b) {
					return comp.compare(a, b);
				}
			});
			long ans = 0;
			for(int i = 0;i < n;){
				int j = i;
				while(j < n && Arrays.equals(as[i], as[j]))j++;
				ans += (long)(j-i)*(j-i-1)/2;
				i = j;
			}
			out.println(ans);
			return;
		}
		
		Point[] ps = new Point[n];
		for(int i = 0;i < n;i++){
			int X = ni(), V = ni();
			long[] y = reduce(new long[]{V, X});
			long[] x = reduce(new long[]{W, X});
			// W -1
			// W +1
			long[] ny = add(x, y);
			y[0] = -y[0];
			long[] nx = add(x, y);
			ps[i] = new Point(nx, ny, 0);
		}
		Arrays.sort(ps, new Comparator<Point>() {
			public int compare(Point a, Point b) {
				return comp.compare(a.yr, b.yr);
			}
		});
		int yy = 0;
		for(int i = 0;i < n;){
			int j = i;
			while(j < n && Arrays.equals(ps[i].yr, ps[j].yr))j++;
			for(int k = i;k < j;k++){
				ps[k].y = yy;
			}
			yy++;
			
			i = j;
		}
		Arrays.sort(ps, new Comparator<Point>() {
			public int compare(Point a, Point b) {
				int com = comp.compare(a.xr, b.xr);
				if(com != 0)return com;
				return a.y - b.y;
			}
		});
		long ans = 0;
		
		{
			int[] ft = new int[n+3];
			for(int i = 0;i < n;i++){
				ans += sumFenwick(ft, ps[i].y);
				addFenwick(ft, ps[i].y, 1);
			}
		}
		out.println(ans);
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

	
	static class Point
	{
		long[] xr, yr;
		int y;
		public Point(long[] xr, long[] yr, int y) {
			this.xr = xr;
			this.yr = yr;
			this.y = y;
		}
	}
	
	public static long[] reduce(long[] f)
	{
		if(f[1] == 0) { // n/0
			f[0] = 1;
		}else if(f[0] == 0) { // 0/n
			f[1] = 1;
		}else {
			if(f[1] < 0) { // -a/-b ->a/b
				f[0] = -f[0];
				f[1] = -f[1];
			}
			long a = Math.abs(f[0]), b = f[1];
			while (b > 0) {
				long c = a;
				a = b;
				b = c % b;
			}
			f[0] /= a;
			f[1] /= a;
		}
		return f;
	}
	
	public static long[] add(long[] a, long[] b){ return reduce(new long[]{a[0]*b[1]+a[1]*b[0], a[1]*b[1]}); }
	public static long[] sub(long[] a, long[] b){ return reduce(new long[]{a[0]*b[1]-a[1]*b[0], a[1]*b[1]}); }
	public static long[] mul(long[] a, long[] b){ return reduce(new long[]{a[0]*b[0], a[1]*b[1]}); }
	public static long[] div(long[] a, long[] b){ return reduce(new long[]{a[0]*b[1], a[1]*b[0]}); }
		
	public static int compare(long[] a, long[] b){return Long.signum(a[0] * b[1] - a[1] * b[0]);}
	
	public static long[] min(long[] a, long[] b){ return compare(a, b) <= 0 ? a : b; }
	public static long[] max(long[] a, long[] b){ return compare(a, b) >= 0 ? a : b; }
	
	public static int lowerBound(long[][] es, int p, long[] r)
	{
		int low = -1, high = p;
		while(high-low > 1){
			int h = high+low>>>1;
			if(Long.compare(r[0]*es[h][1], r[1]*es[h][0]) <= 0){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
	}
	
	public static Comparator<long[]> comp = (a, b) -> Long.signum(a[0]*b[1]-a[1]*b[0]);

	
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