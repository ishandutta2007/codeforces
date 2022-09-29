//package aim.r5;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Map;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		// d^2, cos
		Map<Long, List<int[]>> all = new HashMap<>();
		LongHashCounter counter = new LongHashCounter();
		int nall = 0;
		for(int Q = ni();Q > 0;Q--){
			int type = ni();
			if(type == 1){
				int[] c = na(2);
				long d = (long)c[0]*c[0]+(long)c[1]*c[1];
				if(!all.containsKey(d)){
					all.put(d, new ArrayList<>());
				}
				long ride = code(c[0], c[1]);
				if(!counter.containsKey(ride)){
					counter.inc(ride, 2);
				}else{
					counter.inc(ride, 1);
				}
				List<int[]> ex = all.get(d);
				for(int[] e : ex){
					// (e[0]-c[0], e[1]-c[1])
					long code = code(-(e[1]-c[1]), e[0]-c[0]);
					if(!counter.containsKey(code)){
						counter.inc(code, 3);
					}else{
						counter.inc(code, 2);
					}
				}
				ex.add(c);
				nall++;
			}else if(type == 3){
				long code = code(ni(), ni());
				out.println(nall - (Math.max(counter.get(code), 1)-1));
			}else{
				
				int[] c = na(2);
				long d = (long)c[0]*c[0]+(long)c[1]*c[1];
				List<int[]> ex = all.get(d);
				for(int i = 0;i < ex.size();i++){
					if(Arrays.equals(ex.get(i), c)){
						ex.remove(i);
						break;
					}
				}
				long ride = code(c[0], c[1]);
				counter.inc(ride, -1);
				for(int[] e : ex){
					// (e[0]-c[0], e[1]-c[1])
					long code = code(-(e[1]-c[1]), e[0]-c[0]);
					counter.inc(code, -2);
				}
				nall--;
			}
		}
	}
	
	long code(long dx, long dy)
	{
		if(dy < 0 || dy == 0 && dx < 0){
			dy = -dy;
			dx = -dx;
		}
		long g = gcd3(Math.abs(dx), Math.abs(dy));
		dy /= g; dx /= g;
		return dy<<32|dx+1000000000;
	}
	
	public static long gcd3(long a, long b) {
		if(a == 0)return b;
		if(b == 0)return a;
		
		int ashift = Long.numberOfTrailingZeros(a);
		int bshift = Long.numberOfTrailingZeros(b);
		a >>>= ashift;
		b >>>= bshift;
		while(b != a){
			if(a > b){
				long t = a; a = b; b = t;
			}
			b -= a;
			b >>>= Long.numberOfTrailingZeros(b);
		}
		
		return a<<Math.min(ashift, bshift);
	}

	
	public static long gcd(long a, long b) {
		while (b > 0) {
			long c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	
	public class LongHashCounter {
		public long[] keys;
		public int[] allocated;
		private int scale = 1<<2;
		private int rscale = 1<<1;
		private int mask = scale-1;
		public int size = 0;
		
		public LongHashCounter(){
			allocated = new int[scale];
			Arrays.fill(allocated, NG);
			keys = new long[scale];
		}
		
		// if value is NG, entry is removed. (e.g. 0)
		private static final int NG = 0;
		
		public boolean containsKey(long x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos])return true;
				pos = pos+1&mask;
			}
			return false;
		}
		
		public int get(long x)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos])return allocated[pos];
				pos = pos+1&mask;
			}
			return NG;
		}
		
		public int put(long x, int v)
		{
			int pos = h(x)&mask;
			while(allocated[pos] != NG){
				if(x == keys[pos]){
					int oldval = allocated[pos];
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
		
		public int inc(long x, int v)
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
		
		public boolean remove(long x)
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
		
		private void resizeAndPut(long x, int v)
		{
			int nscale = scale<<1;
			int nrscale = rscale<<1;
			int nmask = nscale-1;
			int[] nallocated = new int[nscale];
			Arrays.fill(nallocated, NG);
			long[] nkeys = new long[nscale];
			for(int i = next(0);i < scale;i = next(i+1)){
				long y = keys[i];
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
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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