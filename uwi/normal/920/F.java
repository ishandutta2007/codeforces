//package educational.round37;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] a = na(n);
		int[] lpf = enumLowestPrimeFactors(1000000);
		int[] nd = enumNumDivisorsFast(1000000, lpf);
		
		LST lst = new LST(n);
		for(int i = 0;i < n;i++){
			if(a[i] > 2)lst.set(i);
		}
		long[] ft = buildFenwick(a);
		
		for(int z = 0;z < m;z++){
			int t = ni();
			int l= ni()-1, r = ni()-1;
			if(t == 1){
				for(int i = lst.next(l);i != -1 && i <= r;i = lst.next(i+1)){
					addFenwick(ft, i, nd[a[i]] - a[i]);
					a[i] = nd[a[i]];
					if(a[i] <= 2)lst.unset(i);
				}
			}else{
				out.println(sumFenwick(ft, r) - sumFenwick(ft, l-1));
			}
		}
	}
	
	public static long[] buildFenwick(int[] a)
	{
		int n = a.length;
		long[] ft = new long[n+1];
		for(int i = 0;i < n;i++){
			ft[i+1] = a[i];
		}
		for(int k = 2, h = 1;k <= n;k*=2, h*=2){
			for(int i = k;i <= n;i+=k){
				ft[i] += ft[i-h];
			}
		}
		return ft;
	}
	
	public static int[] enumNumDivisorsFast(int n, int[] lpf)
	{
		int[] nd = new int[n+1];
		nd[1] = 1;
		for(int i = 2;i <= n;i++){
			int j = i, e = 0;
			while(j % lpf[i] == 0){
				j /= lpf[i];
				e++;
			}
			nd[i] = nd[j] * (e+1);
		}
		return nd;
	}
	
	public static int[] enumLowestPrimeFactors(int n) {
		int tot = 0;
		int[] lpf = new int[n + 1];
		int u = n + 32;
		double lu = Math.log(u);
		int[] primes = new int[(int) (u / lu + u / lu / lu * 1.5)];
		for (int i = 2; i <= n; i++)
			lpf[i] = i;
		for (int p = 2; p <= n; p++) {
			if (lpf[p] == p)
				primes[tot++] = p;
			int tmp;
			for (int i = 0; i < tot && primes[i] <= lpf[p] && (tmp = primes[i] * p) <= n; i++) {
				lpf[tmp] = primes[i];
			}
		}
		return lpf;
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
			long h = set<<~n;
			if(h == 0L)return -1;
			return -Long.numberOfLeadingZeros(h)+n;
		}
		
		private static int next(long set, int n)
		{
			long h = set>>>n;
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