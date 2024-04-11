//package round449;
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
	
	long seed;
	
	int rnd()
	{
		long ret = seed;
		seed = (seed * 7 + 13) % 1000000007;
		return (int)ret;
	}
	
	void solve()
	{
		int n = ni(), m = ni();
		seed = nl();
		int vmax = ni();
		
		long[] a = new long[n];
		for(int i = 0;i < n;i++){
			a[i] = (rnd() % vmax) + 1;
		}
		
		LST lst = new LST(n);
		lst.setRange(n+2);
		
		long[][] as = new long[n][];
		outer:
		for(int z = 0;z < m;z++){
			int op = rnd() % 4 + 1;
			int l = rnd() % n;
			int r = rnd() % n;
			if(l > r){
				int d = l; l = r; r = d;
			}
			int x;
			if(op == 3){
				x = rnd() % (r-l+1) + 1;
			}else{
				x = rnd() % vmax + 1;
			}
			int y = -1;
			if(op == 4){
				y = rnd() % vmax + 1;
			}
			
			if(op == 2){
				if(r+1 < n){
					a[r+1] = a[lst.prev(r+1)];
					lst.set(r+1);
				}
				for(int i = lst.next(l);i != -1 && i <= r;i = lst.next(l)){
					lst.unset(i);
				}
				lst.set(l);
				a[l] = x;
			}else if(op == 1){
				int pr = lst.prev(l);
				if(pr < l){
					lst.set(l);
					a[l] = a[pr];
				}
				if(r+1 < n){
					int ne = lst.next(r+1);
					if(ne > r+1){
						a[r+1] = a[lst.prev(r+1)];
						lst.set(r+1);
					}
				}
				for(int i = l;i <= r && i != -1;i = lst.next(i+1)){
					a[i] += x;
				}
			}else if(op == 4){
				long ans = 0;
				for(int i = lst.prev(l);i <= r && i != -1;i = lst.next(i+1)){
					int j = lst.next(i+1);
					// [i,j), [l,r]
					long len = Math.min(j, r+1) - Math.max(i, l);
					ans += len * pow(a[i], x, y);
					ans %= y;
				}
				out.println(ans);
			}else if(op == 3){
				int p = 0;
				for(int i = lst.prev(l);i <= r && i != -1;i = lst.next(i+1)){
					int j = lst.next(i+1);
					// [i,j), [l,r]
					long len = Math.min(j, r+1) - Math.max(i, l);
					as[p++] = new long[]{a[i], len};
				}
				Arrays.sort(as, 0, p, new Comparator<long[]>() {
					public int compare(long[] a, long[] b) {
						return Long.compare(a[0], b[0]);
					}
				});
				x--;
				for(int k = 0;k < p;k++){
					if(x < as[k][1]){
						out.println(as[k][0]);
						continue outer;
					}else{
						x -= as[k][1];
					}
				}
			}
		}
	}
	
	public static long pow(long a, long n, long mod) {
				a %= mod;
		long ret = 1 % mod;
		int x = 63 - Long.numberOfLeadingZeros(n);
		for (; x >= 0; x--) {
			ret = ret * ret % mod;
			if (n << 63 - x < 0)
				ret = ret * a % mod;
		}
		return ret;
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