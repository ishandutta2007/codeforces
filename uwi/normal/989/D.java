//package round487;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long L = ni();
		long wmax = ni();
		
		int[] right = new int[n];
		int[] left = new int[n];
		int rp = 0, lp = 0;
		for(int i = 0;i < n;i++){
			int x = ni(), v = ni();
			if(v == 1){
				right[rp++] = x;
			}else{
				left[lp++] = x;
			}
		}
		right = radixSort(Arrays.copyOf(right, rp));
		left = radixSort(Arrays.copyOf(left, lp));
		
		int p = 0;
		long ans = 0;
		for(int i = 0;i < rp;i++){
			while(p < lp && right[i] > left[p])p++;
			
			// 0 10
			// -wmax <= -(xi+xj+b)/(xj-xi+a) <= wmax
			
			// -1 < -(0+x+10)/(x-0+10) < 1
			
			// wmax(xj-xi+a) >= -(xi+xj+b)
			// (wmax+1)xj >= (wmax-1)xi-b-wmax*a
			// xj >= ((wmax-1)xi-b-wmax*a)/(wmax+1)
			
			// -wmax <= -(xi+xj+b)/(xj-xi+a)
			// -wmax(xj-xi+a) <= -(xi+xj+b)
			// (wmax+1)xi-wmax*a+b <= (wmax-1)xj
			// xj >= ((wmax+1)xi-wmax*a+b)/(wmax-1)
			// a=-L, b=L
			
			long[][] all = {
					right[i]+0 == -right[i]+0 && wmax == 1 ? new long[]{1, 0} : 
					max(
							new long[]{(wmax-1)*right[i], wmax+1},
							new long[]{(wmax+1)*right[i], wmax-1}
							),
					right[i]+2*L == -right[i]+0 && wmax == 1 ? new long[]{1, 0} : 
					max(
							new long[]{(wmax-1)*right[i]-2*L, wmax+1},
							new long[]{(wmax+1)*right[i]+2*L, wmax-1}
							),
					right[i]+L == -right[i]-L && wmax == 1 ? new long[]{1, 0} : 
					max(
							new long[]{(wmax-1)*right[i]-L+wmax*L, wmax+1},
							new long[]{(wmax+1)*right[i]+L+wmax*L, wmax-1}
							),
					right[i]+L == -right[i]+L && wmax == 1 ? new long[]{1, 0} : 
					max(
							new long[]{(wmax-1)*right[i]-L-wmax*L, wmax+1},
							new long[]{(wmax+1)*right[i]+L-wmax*L, wmax-1}
							)
			};
//			tr(							new long[]{(wmax-1)*right[i]-L-wmax*L, wmax+1},
//					new long[]{(wmax+1)*right[i]+L-wmax*L, wmax-1});

			long[] min = {1, 0};
			for(long[] a : all){
				min = min(min, a);
			}
			
//			upperBound(left, min);
//				tr(right[i], left[h], wmax, L, 
//						valid(right[i], left[h], wmax, L)
//						);
//			tr(right[i], left, min);
			
			{
				int low = p-1, high = lp;
				while(high - low > 1){
					int h = high+low>>1;
					if(compare(min, new long[]{left[h], 1}) < 0){
						high = h;
					}else{
						low = h;
					}
				}
				ans += lp - high;
			}
//			tr(ans);
		}
		out.println(ans);
	}
	
	// -(xi+xj)/(xj-xi) <= wmax ? 
	// -1-2xi/(xj-xi) <= wmax
	// xj-xi >= -2xi/(1+wmax)
	
	boolean valid(long xi, long xj, int wmax, int L)
	{
		
		// (xj-xi+L)/2
		long[][] poss = {
				{xi+xj, 2},
				{xi+xj+2*L, 2},
				{xi+xj+L, 2},
				{xi+xj+L, 2}
		};
		long[][] ts = {
				{xj-xi, 2},
				{xj-xi, 2},
				{xj-xi-L, 2},
				{xj-xi+L, 2}
		};
		
		int left = 0, right = 0;
		for(int k = 0;k < 4;k++){
			long[] pos = poss[k], t = ts[k];
			// pos + t*w <=> 0
			// w <=> -pos / t
			// inf+((xj-xi)/2+L/2)w <= 0 <= sup+((xj-xi)/2+L/2)w
			// -(sup)*2/(xj-xi+L) <= w <= -inf*2/(xj-xi+L)
			long[] w = div(pos, neg(t));
			if(compare(w, new long[]{-wmax, 1}) <= 0){
				left++;
			}
			if(compare(w, new long[]{wmax, 1}) >= 0){
				right++;
			}
		}
		return !(left == 4 || right == 4);
	}
	
	long[] inv(long[] a) { return new long[]{a[1], a[0]};}
	long[] neg(long[] a) { return new long[]{-a[0], a[1]}; }
	
	long[][] and(long[][] a, long[][] b)
	{
		if(a.length == 0 || b.length == 0)return new long[0][];
		long[] inf = max(a[0], b[0]);
		long[] sup = min(a[1], b[1]);
		if(compare(inf, sup) < 0)return new long[][]{inf, sup};
		return new long[0][];
	}
	
	// a(b+w) < c(d+w)
	// (a-c)w < cd-ab
	long[][] solve(long a, long b, long c, long d, char e)
	{
		int dir = e == '<' ? -1 : 1;
		if(a-c < 0){
			dir = -dir;
		}
		if(dir == -1){
			return new long[][]{{-1, 0}, reduce(new long[]{c*d-a*b, a-c})};
		}else{
			return new long[][]{reduce(new long[]{c*d-a*b, a-c}), {1, 0}};
		}
	}
	
	public static int[] radixSort(int[] f){ return radixSort(f, f.length); }
	public static int[] radixSort(int[] f, int n)
	{
		for(int i = 0;i < n;i++){
			f[i] += 100000000;
		}
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
		for(int i = 0;i < n;i++){
			f[i] -= 100000000;
		}
		return f;
	}

	
	long[][] go(long xi, long vi, long xj, long vj, int L)
	{
		long A = -xj-L+xi;
		long B = -xi*vj+(xj+L)*vi;
		if(A > 0){
			return new long[][]{{0, 1}, reduce(new long[]{B, A})};
		}else if(A == 0){
			if(B > 0){
				return new long[][]{{0, 1}, {1, 0}};
			}else{
				return new long[0][];
			}
		}else{
			return new long[][]{reduce(new long[]{B, A}), {1, 0}};
		}
	}
	
	public static long[] reduce(long[] f)
	{
		if(f[1] == 0) { // n/0
			f[0] = f[0] > 0 ? 1 : -1;
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
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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