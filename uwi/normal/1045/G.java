//package bubble11;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class G4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[][] rs = new int[n][];
		for(int i = 0;i < n;i++){
			rs[i] = new int[]{ni(), ni(), ni(), i, -1};
		}
		int[] qs = new int[n];
		for(int i = 0;i < n;i++)qs[i] = rs[i][2];
		int[] imap = shrinkX(qs);
		int m = imap.length;
		
		for(int i = 0;i < n;i++)rs[i][2] = qs[i];
		int[][][] b = makeBuckets(rs, n, 2);
		
		int[][][] cated = new int[b.length][][];
		long ans = 0;
		for(int i = 0;i < m;i++){
			int p = 0;
			for(int j = i;j < m;j++){
				if(imap[j] - imap[i] <= K){
					cated[p++] = b[j];
				}else{
					break;
				}
			}
			int[][] es = concat(Arrays.copyOf(cated, p));
			ans += solve(es, i);
		}
		out.println(ans);
	}
	
	Stopwatch sw = new Stopwatch();
	
	Comparator<int[]> comp = (x, y) -> {
		if(x[0] != y[0])return x[0] - y[0];
		if(x[2] != y[2])return x[2] - y[2];
		return x[3] - y[3];
	};
	
	long solve(int[][] es, int base)
	{
		Arrays.sort(es, comp);
		
		int n = es.length;
		int[][] ees = Arrays.copyOf(es, 2*n);
		
		for(int i = 0;i < n;i++)es[i][4] = i;
		int[] tops = new int[n];
		for(int i = 0;i < n;i++)tops[i] = es[i][0];
		
		for(int i = 0;i < n;i++){
			int[] top = es[i];
			ees[i+n] = new int[]{top[0] + top[1] + 1, top[4], top[2] == base ? -1 : -2, -1};
		}
		Arrays.sort(ees, comp);
		
		int[] ft = new int[n+3];
		int[] ft2 = new int[n+3];
		
		long ans = 0;
		int ins = 0;
		int ins2 = 0;
		
		for(int[] top : ees){
			if(top[2] >= 0){
				if(top[2] == base){
					int lb = lowerBound(tops, top[0] - top[1])-1;
					ans += ins - sumFenwick(ft, lb);
					ans += ins2 - sumFenwick(ft2, lb);
					addFenwick(ft, top[4], 1);
					ins++;
				}else{
					ans += ins - sumFenwick(ft, lowerBound(tops, top[0] - top[1])-1);
					addFenwick(ft2, top[4], 1);
					ins2++;
				}
			}else{
				if(top[2] == -1){
					addFenwick(ft, top[1], -1);
					ins--;
				}else{
					addFenwick(ft2, top[1], -1);
					ins2--;
				}
			}
		}
		return ans;
	}
	
	public static int lowerBound(int[] a, int v){ return lowerBound(a, 0, a.length, v); }
	public static int lowerBound(int[] a, int l, int r, int v)
	{
		if(l > r || l < 0 || r > a.length)throw new IllegalArgumentException();
		int low = l-1, high = r;
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

	
	public static class Stopwatch {
		private long ret = 0;
		private boolean active = false;
		public Stopwatch start() { assert !active; ret -= System.nanoTime(); active = true; return this; }
		public Stopwatch reset() { assert !active; ret = 0; return this;}
		public long stop() { assert active; ret += System.nanoTime(); active = false; return ret; }
		public long lap() { assert active; return System.nanoTime() + ret; }
		public long lapAndReset() { assert active; long r = System.nanoTime() + ret; ret = -System.nanoTime(); return r; }
		public static Stopwatch go() { return new Stopwatch().start(); }
		public String eta(long cur, long all) { 
			long elapsed = (System.nanoTime() + ret)/1000000;
			long eta = Math.round((double)(all-cur)/cur*elapsed/1000);
			return String.format("%d/%d, ETA:%02d:%02d:%02d, speed:%.3f/s",
					cur, all,
					eta/3600, eta/60%60, eta%60,
					(double)cur*1000/elapsed 
					);
		}
		
		public String ms(long x){return x/1000000+"ms";}
		public String s(long x){return x/1000000000+"s";}
		@Override
		public String toString() { return ms(active ? ret + System.nanoTime() : ret); }
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

	
	public static int[][] concat(int[][]... s)
	{
		int n = 0; // if making first element 0, n = 1.
		for(int[][] u : s)n += u.length;
		int[][] ret = new int[n][];
		n = 0; // if making first element 0, n = 1.
		for(int[][] u : s){
			System.arraycopy(u, 0, ret, n, u.length);
			n += u.length;
		}
		return ret;
	}

	
	public static int[][][] makeBuckets(int[][] a, int sup, int ind)
	{
		int n = a.length;
		int[][][] bucket = new int[sup+1][][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i][ind]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]][];
		for(int i = n-1;i >= 0;i--)bucket[a[i][ind]][--bp[a[i][ind]]] = a[i];
		return bucket;
	}

	
	
	public static int[] shrinkX(int[] a) {
		int n = a.length;
		long[] b = new long[n];
		for (int i = 0; i < n; i++)
			b[i] = (long) a[i] << 32 | i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		ret[0] = (int) (b[0] >> 32);
		for (int i = 0; i < n; i++) {
			if (i > 0 && (b[i] ^ b[i - 1]) >> 32 != 0) {
				p++;
				ret[p] = (int) (b[i] >> 32);
			}
			a[(int) b[i]] = p;
		}
		return Arrays.copyOf(ret, p + 1);
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
	
	public static void main(String[] args) throws Exception { new G4().run(); }
	
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