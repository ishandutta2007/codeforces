//package round415;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int mod = 1000000007;
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			cache = new LongHashMap();
			int x1 = ni(), y1 = ni(), x2 = ni(), y2 = ni(), K = ni();
			long ret = 
			count(x2, y2, 29, K)[0]
			- count(x1-1, y2, 29, K)[0]
			- count(x2, y1-1, 29, K)[0]
			+ count(x1-1, y1-1, 29, K)[0];
			ret %= mod;
			if(ret < 0)ret += mod;
			out.println(ret);
		}
	}
	
	static final long[] Z = new long[]{0L, 0L};
	static long[][] zs = new long[40][];
	LongHashMap cache = new LongHashMap();
	
	long[] count(int r, int c, int d, int K)
	{
		if(r <= 0 || c <= 0 || K <= 0)return Z;
		if(r == 1<<d+1 && c == 1<<d+1 && K >= 1<<d+1){
			if(zs[d+1] == null){
				long u = 1L<<d+1;
				zs[d+1] = new long[]{u*(u+1)/2%mod*u%mod, u*u%mod};
			}
			return zs[d+1];
		}
		long code = (long)r*1000000009 + c;
		code = code * 1000000009L + d;
		code = code * 1000000009L + K;
		if(cache.containsKey(code))return (long[])cache.get(code);
		if(r == 1<<d+1 && c == 1<<d+1){
			long u = 1L<<d+1;
			long[] res = new long[]{(long)K*(K+1)/2%mod*u%mod, K*u%mod};
			cache.put(code, res);
			return res;
		}

//		tr(r, c, d, K);
		
		// 1<<d
		long ret = 0;
		long num = 0;
		{
			long[] res = count(Math.min(r, 1<<d), Math.min(c, 1<<d), d-1, Math.min(K, 1<<d+1));
			ret += res[0];
			num += res[1];
		}
		{
			long[] res = count(Math.min(r, 1<<d), c-(1<<d), d-1, K-(1<<d));
			ret += res[0] + res[1] * (1L<<d);
			num += res[1];
		}
		{
			long[] res = count(r-(1<<d), Math.min(c, 1<<d), d-1, K-(1<<d));
			ret += res[0] + res[1] * (1L<<d);
			num += res[1];
		}
		{
			long[] res = count(r-(1<<d), c-(1<<d), d-1, Math.min(K, 1<<d+1));
			ret += res[0];
			num += res[1];
		}
		long[] re = new long[]{ret%mod, num%mod};
		cache.put(code, re);
		return re;
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
			for(int i = next(0);i < scale;i = next(i+1)){
				long y = keys[i];
				int pos = h(y)&nmask;
				while(nallocated[pos] != null)pos = pos+1&nmask;
				nkeys[pos] = y;
				nallocated[pos] = allocated[i];
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
		
		public int next(int itr)
		{
			while(itr < scale && allocated[itr] == null)itr++;
			return itr;
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
			StringBuilder sb = new StringBuilder();
			for(int i = next(0);i < scale;i = next(i+1)){
				sb.append(",");
				sb.append(keys[i] + ":" + allocated[i]);
			}
			return sb.length() == 0 ? "" : sb.substring(1);
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