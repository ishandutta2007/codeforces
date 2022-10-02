//package round294;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[] a = na(26);
		char[] s = ns().toCharArray();
		int n = s.length;
		long[] cum = new long[n+1];
		for(int i = 0;i < n;i++){
			cum[i+1] = cum[i] + a[s[i]-'a'];
		}
		long num = 0;
		for(int i = 0;i < 26;i++){
			LongHashMap lhm = new LongHashMap();
			for(int j = 0;j < n;j++){
				if(s[j] == 'a'+i){
					{
						Object val = lhm.get(cum[j]);
						if(val != null){
							num += (Integer)val;
						}
					}
					
					{
						Object val = lhm.get(cum[j+1]);
						if(val != null){
							int x = (Integer)val;
							lhm.put(cum[j+1], x+1);
						}else{
							lhm.put(cum[j+1], 1);
						}
					}
				}
			}
		}
		out.println(num);
		
	}
	
	public static class LongHashMap {
		public long[] keys;
		public Object[] allocated;
		private int scale = 1<<2;
		private int rscale = 1<<1;
		private int mask = scale-1;
		public int size = 0;
		
		public LongHashMap(){
			allocated = new Object[scale];
			keys = new long[scale];
		}
		
		public boolean containsKey(long x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != null){
				if(x == keys[pos])return true;
				pos = pos+1&mask;
			}
			return false;
		}
		
		public Object get(long x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != null){
				if(x == keys[pos])return allocated[pos];
				pos = pos+1&mask;
			}
			return null;
		}
		
		public Object put(long x, Object v)
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
		
		public boolean remove(long x)
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
		
		private void resizeAndPut(long x, Object v)
		{
			int nscale = scale<<1;
			int nrscale = rscale<<1;
			int nmask = nscale-1;
			Object[] nallocated = new Object[nscale];
			long[] nkeys = new long[nscale];
			itrreset();
			while(true){
				long y = next();
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
		public long next() {
			while(++itr < scale && allocated[itr] == null);
			if(itr == scale){
				itr = -1;
				return NG;
			}
			return keys[itr];
		}
		
		private int h(long x)
		{
			x ^= x>>>33;
			x *= 0xff51afd7ed558ccdL;
			x ^= x>>>33;
			x *= 0xc4ceb9fe1a85ec53L;
			x ^= x>>>33;
			return (int)x;
		}
		
		@Override
		public String toString()
		{
			itrreset();
			long[] vals = new long[size];
			int p = 0;
			while(true){
				long y = next();
				if(end())break;
				vals[p++] = y;
			}
			return Arrays.toString(vals);
		}
	}
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		for (int i = 0; i < 26; i++) {
//			sb.append(0 + " ");
//		}
//		for(int i = 0;i < n;i++){
//			sb.append((char)('a'+0));
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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