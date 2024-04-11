//package loosery;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] a = na(n);
		int[] L = enumPrevWall(a);
		int[] RR = enumPrevWall2(rev(a));
		rev(a);
		int[] R = new int[n];
		for(int i = 0;i < n;i++){
			R[i] = n-1-RR[n-1-i];
		}
		
		int[] cum = new int[n+1];
		for(int i = 0;i < n;i++){
			cum[i+1] = cum[i] + a[i];
			cum[i+1] %= K;
		}
		
		LST lst = new LST(n);
		for(int i = 0;i < n;i++)lst.set(i);
		
		int[][] as = new int[n][];
		for(int i = 0;i < n;i++){
			as[i] = new int[]{a[i], i};
		}
		Arrays.sort(as, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return -(a[1] - b[1]);
			}
		});
		
		IntHashCounter[] ihcs = new IntHashCounter[n];
		for(int i = 0;i < n;i++){
//			ihcs[i] = new IntHashCounter();
//			ihcs[i].inc(cum[i+1], 1L);
		}
//		tr(cum);
//		tr(a);
//		tr(ihcs);
		long ret = 0;
		for(int i = 0;i < n;i++){
			int x = as[i][1];
			IntHashCounter left = new IntHashCounter();
			while(true){
				int pre = lst.prev(x-1);
				if(pre == -1 || pre <= L[x])break;
				if(left == null){
					left = ihcs[pre];
				}else{
					left = ihcs[pre].size < left.size ? left.incAll(ihcs[pre]) : ihcs[pre].incAll(left);
				}
				ihcs[pre] = null;
				lst.unset(pre);
			}
			left.inc(cum[x], 1);
			
			IntHashCounter right = new IntHashCounter();
			while(true){
				int nex = lst.next(x+1);
				if(nex == -1 || nex >= R[x])break;
				if(right == null){
					right = ihcs[nex];
				}else{
					right = ihcs[nex].size < right.size ? right.incAll(ihcs[nex]) : ihcs[nex].incAll(right);
				}
				ihcs[nex] = null;
				lst.unset(nex);
			}
			right.inc(cum[R[x]], 1);
			
//			tr(x, left, right, a[x]);
			if(left.size < right.size){
				for(int j = left.next(0);j < left.scale;j = left.next(j+1)){
					int y = left.keys[j];
					long val = left.get(y);
					// r-l-mid=0 (%K)
					ret += right.get((y+a[x])%K)*val;
				}
				ret--;
				ihcs[x] = right.incAll(left);
				ihcs[x].inc(cum[R[x]], -1);
			}else{
				for(int j = right.next(0);j < right.scale;j = right.next(j+1)){
					int y = right.keys[j];
					long val = right.get(y);
					// r-l-mid=0 (%K)
					int d = (y-a[x])%K;
					if(d < 0)d += K;
					ret += left.get(d)*val;
				}
				ret--;
				ihcs[x] = left.incAll(right);
				ihcs[x].inc(cum[R[x]], -1);
			}
		}
		
		out.println(ret);
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

	
	public static class IntHashCounter {
		public int[] keys;
		public long[] allocated;
		private int scale = 1<<2;
		private int rscale = 1<<1;
		private int mask = scale-1;
		public int size = 0;
		
		public IntHashCounter(){
			allocated = new long[scale];
			Arrays.fill(allocated, NG);
			keys = new int[scale];
		}
		
		private static final long NG = 0L;
		
		public boolean containsKey(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos])return true;
				pos = pos+1&mask;
			}
			return false;
		}
		
		public long get(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos])return allocated[pos];
				pos = pos+1&mask;
			}
			return NG;
		}
		
		public long put(int x, long v)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos]){
					long oldval = allocated[pos];
					allocated[pos] = v;
					return oldval;
				}
				pos = pos+1&mask;
			}
			if(size == rscale){
				resizeAndPut(x, v);
			}else{
				keys[pos] = x;
				allocated[pos] = v;
			}
			size++;
			return NG;
		}
		
		public long inc(int x, long v)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos]){
					allocated[pos] += v;
					return allocated[pos];
				}
				pos = pos+1&mask;
			}
			if(size == rscale){
				resizeAndPut(x, v);
			}else{
				keys[pos] = x;
				allocated[pos] = v;
			}
			size++;
			return v;
		}
		
		public boolean remove(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos]){
					size--;
					// take last and fill rmpos
					int last = pos;
					pos = pos+1&mask;
					while(allocated[pos] != NG){
						int lh = h(keys[pos])&mask;
						// lh <= last < pos
						if(
								lh <= last && last < pos ||
								pos < lh && lh <= last ||
								last < pos && pos < lh
								){
							keys[last] = keys[pos];
							allocated[last] = allocated[pos];
							last = pos;
						}
						pos = pos+1&mask;
					}
					keys[last] = 0;
					allocated[last] = NG;
					
					return true;
				}
				pos = pos+1&mask;
			}
			return false;
		}
		
		private void resizeAndPut(int x, long v)
		{
			int nscale = scale<<1;
			int nrscale = rscale<<1;
			int nmask = nscale-1;
			long[] nallocated = new long[nscale];
			int[] nkeys = new int[nscale];
			for(int i = next(0);i < scale;i = next(i+1)){
				int y = keys[i];
				int pos = h(y)&nmask;
				while(nallocated[pos] != NG)pos = pos+1&nmask;
				nkeys[pos] = y;
				nallocated[pos] = allocated[i];
			}
			{
				int pos = h(x)&nmask;
				while(nallocated[pos] != NG)pos = pos+1&nmask;
				nkeys[pos] = x;
				nallocated[pos] = v;
			}
			allocated = nallocated;
			keys = nkeys;
			scale = nscale;
			rscale = nrscale;
			mask = nmask;
		}
		
		public int next(int itr)
		{
			while(itr < scale && allocated[itr] == NG)itr++;
			return itr;
		}
		
		public IntHashCounter incAll(IntHashCounter ihc)
		{
			for(int i = ihc.next(0);i < ihc.scale;i = ihc.next(i+1)){
				int y = ihc.keys[i];
				this.inc(y, ihc.get(y));
			}
			return this;
		}
		
		public int h(int x)
		{
			x ^= x>>>16;
			x *= 0x85ebca6b;
			x ^= x>>>13;
			x *= 0xc2b2ae35;
			x ^= x>>>16;
			return x;
		}
		
//		private long h(long x)
//		{
//			x ^= x>>>33;
//			x *= 0xff51afd7ed558ccdL;
//			x ^= x>>>33;
//			x *= 0xc4ceb9fe1a85ec53L;
//			x ^= x>>>33;
//			return x;
//		}
		
		@Override
		public String toString()
		{
			StringBuilder sb = new StringBuilder();
			for(int i = next(0);i < scale;i = next(i+1)){
				sb.append(",");
				sb.append(keys[i] + ":" + allocated[i]);
			}
			return sb.length() == 0 ? "NONE" : sb.substring(1);
		}
	}


	
	static int[] rev(int[] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			int d = a[i]; a[i] = a[j]; a[j] = d;
		}
		return a;
	}
	
	public static int[] enumPrevWall(int[] a)
	{
		int n = a.length;
		int[] L = new int[n];
		L[0] = -1;
		for(int i = 1;i < n;i++){
			L[i] = i-1;
			while(L[i] >= 0 && a[L[i]] < a[i])L[i] = L[L[i]];
		}
		return L;
	}
	
	public static int[] enumPrevWall2(int[] a)
	{
		int n = a.length;
		int[] L = new int[n];
		L[0] = -1;
		for(int i = 1;i < n;i++){
			L[i] = i-1;
			while(L[i] >= 0 && a[L[i]] <= a[i])L[i] = L[L[i]];
		}
		return L;
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