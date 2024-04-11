//package rohspc2018;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] a = new int[n][];
		int[][] ai = new int[n][];
		int all = 0;
		for(int i = 0;i < n;i++){
			a[i] = na(ni());
			ai[i] = new int[]{a[i].length, i};
			all += a[i].length;
		}
		Arrays.sort(ai, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return (a[0] - b[0]);
			}
		});
		int[] ideal = new int[n];
		for(int i = 0;i < n;i++)ideal[i] = (all+i)/n;
		int l = 0, r = n-1;
		List<String> ret = new ArrayList<>();
		
		IntHashSetLST[] sets = new IntHashSetLST[n];
		for(int i = 0;i < n;i++){
			IntHashSetLST set = new IntHashSetLST();
			for(int s : a[i]){
				set.add(s);
			}
			sets[i] = set;
		}
		
		int step = 0;
		while(l < r){
			while(l < n && ai[l][0] >= ideal[l])l++;
			while(r >= 0 && ai[r][0] <= ideal[r])r--;
			if(l >= r)break;
			
			int ir = ai[r][1], il = ai[l][1];
			
			// r->l
			sets[ir].itrreset();
			sets[ir].next();
			while(ai[l][0] < ideal[l] && ai[r][0] > ideal[r]){
				ai[r][0]--;
				ai[l][0]++;
				while(true){
					int v = sets[ir].keys[sets[ir].itr];
					if(!sets[il].contains(v)){
						ret.add((ir+1) + " " + (il+1) + " " + v);
						sets[ir].remove(v);
						sets[il].add(v);
						sets[ir].next();
						break;
					}
					sets[ir].next();
				}
			}
		}
		
		out.println(ret.size());
		for(String line : ret){
			out.println(line);
		}
	}
	
	public static class IntHashSetLST {
		public int[] keys;
		private int scale = 1<<2;
		private int rscale = 1<<1;
		private int mask = scale-1;
		public int size = 0;
		public LST lst;
		
		public IntHashSetLST(){
			lst = new LST(scale);
			keys = new int[scale];
		}
		
		public boolean contains(int x)
		{
			int pos = h(x)&mask;
			while(lst.get(pos)){
				if(x == keys[pos])return true;
				pos = pos+1&mask;
			}
			return false;
		}
		
		public boolean add(int x)
		{
			int pos = h(x)&mask;
			while(lst.get(pos)){
				if(x == keys[pos])return false;
				pos = pos+1&mask;
			}
			if(size == rscale){
				resizeAndAdd(x);
			}else{
				keys[pos] = x;
				lst.set(pos);
			}
			size++;
			return true;
		}
		
		public boolean remove(int x)
		{
			int pos = h(x)&mask;
			while(lst.get(pos)){
				if(x == keys[pos]){
					size--;
					int rmpos = pos;
					
					// take last and fill rmpos
					pos = pos+1&mask;
					int last = rmpos;
					while(lst.get(pos)){
						int lh = h(keys[pos])&mask;
						// lh <= last < pos
						if(
								lh <= last && last < pos ||
								pos < lh && lh <= last ||
								last < pos && pos < lh
								){
							keys[last] = keys[pos];
							last = pos;
						}
						pos = pos+1&mask;
					}
					keys[last] = 0;
					lst.unset(last);
					
					return true;
				}
				pos = pos+1&mask;
			}
			return false;
		}
		
		private void resizeAndAdd(int x)
		{
			int nscale = scale<<1;
			int nrscale = rscale<<1;
			int nmask = nscale-1;
			LST nlst = new LST(nscale);
			int[] nkeys = new int[nscale];
			itrreset();
			while(true){
				int y = next();
				if(end())break;
				int pos = h(y)&nmask;
				while(nlst.get(pos))pos = pos+1&nmask; // inefficient
				nkeys[pos] = y;
				nlst.set(pos);
			}
			{
				int pos = h(x)&nmask;
				while(nlst.get(pos))pos = pos+1&nmask; // inefficient
				nkeys[pos] = x;
				nlst.set(pos);
			}
			lst = nlst;
			keys = nkeys;
			scale = nscale;
			rscale = nrscale;
			mask = nmask;
		}
		
		public int itr = -1;
		
		public void itrreset() { itr = -1; }
		public boolean end() { return itr == -1; }
		
		private static int NG = Integer.MIN_VALUE;
		public int next() {
			itr = lst.next(itr+1);
			if(itr == -1)return NG;
			return keys[itr];
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
			itrreset();
			int[] vals = new int[size];
			int p = 0;
			while(true){
				int y = next();
				if(end())break;
				vals[p++] = y;
			}
			return Arrays.toString(vals);
		}
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
		
		public LST toggle(int pos)
		{
			return get(pos) ? unset(pos) : set(pos);
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

	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(100000 + " ");
//		for (int i = 0; i < n-5; i++) {
//			sb.append(0 + " ");
//		}
//		for(int k = 0;k < 5;k++){
//			sb.append(100000 + " ");
//			for(int j = 0;j < 100000;j++){
//				sb.append(j+1 + " ");
//			}
//		}
//		sb.append(0 + " ");
//		for (int i = 0; i < n-1; i++) {
//			sb.append(50000 + " ");
//			for(int j = 0;j < 50000;j++){
//				sb.append(j+1 + " ");
//			}
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
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