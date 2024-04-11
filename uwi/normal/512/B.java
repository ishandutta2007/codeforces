//package round290;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] L = na(n);
		int[] c = na(n);
		IntHashMap dp = new IntHashMap();
		for(int i = 0;i < n;i++){
			IntHashMap ndp = new IntHashMap();
			ndp.put(L[i], c[i]);
			for(dp.itrreset();;){
				int key = dp.next();
				if(key == Integer.MIN_VALUE)break;
				int k = gcd(key, L[i]);
				if(!ndp.containsKey(k) || (Integer)ndp.get(k) > (Integer)dp.get(key) + c[i]){
					ndp.put(k, (Integer)dp.get(key) + c[i]);
				}
			}
			for(ndp.itrreset();;){
				int key = ndp.next();
				if(key == Integer.MIN_VALUE)break;
				if(!dp.containsKey(key) || ((Integer)dp.get(key)).intValue() > ((Integer)ndp.get(key)).intValue()){
					dp.put(key, ndp.get(key));
				}
			}
		}
		if(dp.containsKey(1)){
			out.println(dp.get(1));
		}else{
			out.println(-1);
		}
	}
	
	public static class IntHashMap {
		public int[] keys;
		public Object[] allocated;
		private int scale = 1<<2;
		private int rscale = 1<<1;
		private int mask = scale-1;
		public int size = 0;
		
		public IntHashMap(){
			allocated = new Object[scale];
			keys = new int[scale];
		}
		
		public boolean containsKey(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != null){
				if(x == keys[pos])return true;
				pos = pos+1&mask;
			}
			return false;
		}
		
		public Object get(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != null){
				if(x == keys[pos])return allocated[pos];
				pos = pos+1&mask;
			}
			return null;
		}
		
		public Object put(int x, Object v)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != null){
				if(x == keys[pos]){
					Object oldval = allocated[pos];
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
			return null;
		}
		
		public boolean remove(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != null){
				if(x == keys[pos]){
					size--;
					// take last and fill rmpos
					int last = pos;
					pos = pos+1&mask;
					while(allocated[pos] != null){
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
					allocated[last] = null;
					
					return true;
				}
				pos = pos+1&mask;
			}
			return false;
		}
		
		private void resizeAndPut(int x, Object v)
		{
			int nscale = scale<<1;
			int nrscale = rscale<<1;
			int nmask = nscale-1;
			Object[] nallocated = new Object[nscale];
			int[] nkeys = new int[nscale];
			itrreset();
			while(true){
				int y = next();
				if(end())break;
				int pos = h(y)&nmask;
				while(nallocated[pos] != null)pos = pos+1&nmask;
				nkeys[pos] = y;
				nallocated[pos] = allocated[itr];
			}
			{
				int pos = h(x)&nmask;
				while(nallocated[pos] != null)pos = pos+1&nmask;
				nkeys[pos] = x;
				nallocated[pos] = v;
			}
			allocated = nallocated;
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
			while(++itr < scale && allocated[itr] == null);
			if(itr == scale){
				itr = -1;
				return NG;
			}
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
	
	public static void main(String[] args) throws Exception { new B2().run(); }
	
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