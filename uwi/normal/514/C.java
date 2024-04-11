//package round291;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[] HS = {999999937, 999999929};
		int[] MS = {31, 37};
		int n = ni(), m = ni();
		char[][] s = new char[n+m][];
		for(int i = 0;i < n+m;i++){
			s[i] = ns().toCharArray();
		}
		boolean[] ok = new boolean[m];
		Arrays.fill(ok, true);
		for(int H : HS){
			for(int M : MS){
				long[] mm = new long[700000];
				mm[0] = 1;
				for(int i = 1;i < mm.length;i++){
					mm[i] = mm[i-1] * M % H;
				}
				
				IntHashSet set = new IntHashSet();
				for(int i = 0;i < n;i++){
					long h = 0;
					for(char c : s[i]){
						h = (h * M + c) % H;
					}
					set.add((int)h);
				}
				inner:
				for(int i = 0;i < m;i++){
					if(!ok[i])continue;
					long h = 0;
					for(char c : s[n+i]){
						h = (h * M + c) % H;
					}
					
					for(int j = 0;j < s[n+i].length;j++){
						for(char u = 'a';u <= 'c';u++){
							if(s[n+i][j] != u){
								long lh = (h + (u-s[n+i][j])*mm[s[n+i].length-1-j])%H;
								if(lh < 0)lh += H;
								if(set.contains((int)lh)){
									continue inner;
								}
							}
						}
					}
					ok[i] = false;
				}
			}
		}
		
		for(int i = 0;i < m;i++){
			out.println(ok[i] ? "YES" : "NO");
		}
	}
	
	public static class IntHashSet {
		public int[] keys;
		public boolean[] allocated;
		private int scale = 1<<2;
		private int rscale = 1<<1;
		private int mask = scale-1;
		public int size = 0;
		
		public IntHashSet(){
			allocated = new boolean[scale];
			keys = new int[scale];
		}
		
		public boolean contains(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos]){
				if(x == keys[pos])return true;
				pos = pos+1&mask;
			}
			return false;
		}
		
		public boolean add(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos]){
				if(x == keys[pos])return false;
				pos = pos+1&mask;
			}
			if(size == rscale){
				resizeAndAdd(x);
			}else{
				keys[pos] = x;
				allocated[pos] = true;
			}
			size++;
			return true;
		}
		
		public boolean remove(int x)
		{
			int pos = h(x)&mask;
			while(allocated[pos]){
				if(x == keys[pos]){
					size--;
					// take last and fill rmpos
					int last = pos;
					pos = pos+1&mask;
					while(allocated[pos]){
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
					allocated[last] = false;
					
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
			boolean[] nallocated = new boolean[nscale];
			int[] nkeys = new int[nscale];
			itrreset();
			while(true){
				int y = next();
				if(end())break;
				int pos = h(y)&nmask;
				while(nallocated[pos])pos = pos+1&nmask;
				nkeys[pos] = y;
				nallocated[pos] = true;
			}
			{
				int pos = h(x)&nmask;
				while(nallocated[pos])pos = pos+1&nmask;
				nkeys[pos] = x;
				nallocated[pos] = true;
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
			while(++itr < scale && !allocated[itr]);
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
	
	void run() throws Exception
	{
//		int n = 300000/100000, m = n;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n+m; i++) {
//			for(int j = 0;j < 100000;j++){
//				sb.append((char)(gen.nextInt(3)+'a'));
//			}
//			sb.append("\n");
//		}
//		INPUT = sb.toString();
		
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