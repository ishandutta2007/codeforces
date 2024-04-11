//package round352;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int z = 200000;
//		int z = 10;
		int[] ia = new int[z+1];
		Arrays.fill(ia, -1);
		for(int i = 0;i < n;i++)ia[a[i]] = i;
		if(n == 1){
			out.println(0);
			return;
		}
		// 3 0 0
		// 0 1 0
		// 0 0 2
		
		int gg = 0;
		for(int v : a)gg = gcd(v, gg);
		
		int[][] es = new int[3*z+n+1][];
		int p = 0;
		int X = 1000000;
		for(int i = 1;i < n;i++){
			es[p++] = new int[]{i, i, X};
		}
		for(int d = z;d >= 1;d--){
			int f1 = -1, f2 = -1, l1 = -1, l2 = -1;
			for(int i = d;i <= z;i+=d){
				if(ia[i] != -1){
					int x = ia[i];
					if(f1 == -1 || x < f1){
						f2 = f1;
						f1 = x;
					}else if(f2 == -1 || x < f2){
						f2 = x;
					}
					if(l1 == -1 || x > l1){
						l2 = l1;
						l1 = x;
					}else if(l2 == -1 || x > l2){
						l2 = x;
					}
				}
			}
			if(f2 == -1)continue;
			// Y1 -> L2-1
			// X2 -> F2+1
			// Y2 -> L1-1
			// X1 -> F1+1
			int NY1 = l2-1;
			int NX2 = f2+1;
			int NY2 = l1-1;
			int NX1 = f1+1;
			
			es[p++] = new int[]{0, NY1+1, d};
			es[p++] = new int[]{NX1, NY2+1, d};
			es[p++] = new int[]{NX2, n, d};
			
		}
		Arrays.sort(es, 0, p, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return -(a[2] - b[2]);
			}
		});
		
		LST bound = new LST(n+2);
		bound.set(0);
		long[] ft0 = new long[n+3];
		long[] ft1 = new long[n+3];
		long sum = 0;
		int px = 0;
		for(int[] e : es){
			if(e == null)break;
			if(e[0]-px > 0)sum += sumRangeFenwick(ft0, ft1, n) * (e[0]-px);
			px = e[0];
			int L = e[1];
//			tr("come", e, bound);
			// [prev,L)
			while(true){
				int prev = bound.prev(e[1]-1);
//				tr(restoreRangeFenwick(ft0, ft1), e[1]-1, prev);
				if(prev <= -1)break;
				long val = sumRangeFenwick(ft0, ft1, prev) - sumRangeFenwick(ft0, ft1, prev-1);
				if(val < e[2]){
//					tr("sub", prev, L-1, -val);
					addRangeFenwick(ft0, ft1, prev, L-1, -val);
					bound.unset(prev);
					L = prev;
				}else{
					break;
				}
			}
			bound.set(L);
//			tr("bound", bound);
			if(L <= e[1]-1){
//				tr("add", L, e[1]-1, e[2]);
				addRangeFenwick(ft0, ft1, L, e[1]-1, e[2]);
				bound.set(e[1]);
			}
//			tr("hi", sumRangeFenwick(ft0, ft1, n));
//			tr(sum, e);
		}
		sum += sumRangeFenwick(ft0, ft1, n) * (n-px);
		out.println(sum-(long)n*(n-1)/2*X);
	}
	
	public static class LST {
		public long[][] set;
		public int n;
//		public int size;
		
		public LST(int n) {
			this.n = n;
			int d = 1;
			for(int m = n;m > 1;m>>>=6, d++);
			
			set = new long[d][];
			for(int i = 0, m = n>>>6;i < d;i++, m>>>=6){
				set[i] = new long[m+1];
			}
//			size = 0;
		}
		
		// [0,r)
		public LST setRange(int r)
		{
			for(int i = 0;i < set.length;i++, r=r+63>>>6){
				for(int j = 0;j < r>>>6;j++){
					set[i][j] = -1L;
				}
				if((r&63) != 0)set[i][r>>>6] |= (1L<<r)-1;
			}
			return this;
		}
		
		// [0,r)
		public LST unsetRange(int r)
		{
			if(r >= 0){
				for(int i = 0;i < set.length;i++, r=r+63>>>6){
					for(int j = 0;j < r+63>>>6;j++){
						set[i][j] = 0;
					}
					if((r&63) != 0)set[i][r>>>6] &= ~((1L<<r)-1);
				}
			}
			return this;
		}
		
		public LST set(int pos)
		{
			if(pos >= 0 && pos < n){
//				if(!get(pos))size++;
				for(int i = 0;i < set.length;i++, pos>>>=6){
					set[i][pos>>>6] |= 1L<<pos;
				}
			}
			return this;
		}
		
		public LST unset(int pos)
		{
			if(pos >= 0 && pos < n){
//				if(get(pos))size--;
				for(int i = 0;i < set.length && (i == 0 || set[i-1][pos] == 0L);i++, pos>>>=6){
					set[i][pos>>>6] &= ~(1L<<pos);
				}
			}
			return this;
		}
		
		public boolean get(int pos)
		{
			return pos >= 0 && pos < n && set[0][pos>>>6]<<~pos<0;
		}
		
		public int prev(int pos)
		{
			if(pos < 0)return -1;
			for(int i = 0;i < set.length && pos >= 0;i++, pos>>>=6, pos--){
				int pre = prev(set[i][pos>>>6], pos&63);
				if(pre != -1){
					pos = pos>>>6<<6|pre;
					while(i > 0)pos = pos<<6|63-Long.numberOfLeadingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		public int next(int pos)
		{
			for(int i = 0;i < set.length && pos>>>6 < set[i].length;i++, pos>>>=6, pos++){
				int nex = next(set[i][pos>>>6], pos&63);
				if(nex != -1){
					pos = pos>>>6<<6|nex;
					while(i > 0)pos = pos<<6|Long.numberOfTrailingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		private static int prev(long set, int n)
		{
			long h = Long.highestOneBit(set<<~n);
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)-(63-n);
		}
		
		private static int next(long set, int n)
		{
			long h = Long.lowestOneBit(set>>>n);
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)+n;
		}
		
		@Override
		public String toString()
		{
			List<Integer> list = new ArrayList<Integer>();
			for(int pos = next(0);pos != -1;pos = next(pos+1)){
				list.add(pos);
			}
			return list.toString();
		}
	}

	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int firstGEFenwick(long[] ft, long v)
	{
		int i = 0, n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0;b >>= 1){
			if((i|b) < n && ft[i|b] < v){
				i |= b;
				v -= ft[i];
			}
		}
		return i;
	}
	
	public static int findGFenwick(long[] ft, long v)
	{
		int i = 0;
		int n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0 && i < n;b >>= 1){
			if(i + b < n){
				int t = i + b;
				if(v >= ft[t]){
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i+1) : i-1;
	}
	
	public static long[] restoreFenwick(long[] ft)
	{
		int n = ft.length-1;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	public static long[] buildFenwick(long[] a)
	{
		int n = a.length;
		long[] ft = new long[n+1];
		System.arraycopy(a, 0, ft, 1, n);
		for(int k = 2, h = 1;k <= n;k*=2, h*=2){
			for(int i = k;i <= n;i+=k){
				ft[i] += ft[i-h];
			}
		}
		return ft;
	}
	
	public static void addRangeFenwick(long[] ft0, long[] ft1, int i, long v)
	{
		addFenwick(ft1, i+1, -v);
		addFenwick(ft1, 0, v);
		addFenwick(ft0, i+1, v*(i+1));
	}
	
	public static void addRangeFenwick(long[] ft0, long[] ft1, int a, int b, long v)
	{
		if(a <= b){
			addFenwick(ft1, b+1, -v);
			addFenwick(ft0, b+1, v*(b+1));
			addFenwick(ft1, a, v);
			addFenwick(ft0, a, -v*a);
		}
	}
	
	public static long sumRangeFenwick(long[] ft0, long[] ft1, int i)
	{
		return sumFenwick(ft1, i) * (i+1) + sumFenwick(ft0, i);
	}
	
	public static long[] restoreRangeFenwick(long[] ft0, long[] ft1)
	{
		int n = ft0.length-1;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++)ret[i] = sumRangeFenwick(ft0, ft1, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}

	
	public static int gcd(int a, int b) {
		while (b > 0) {
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
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