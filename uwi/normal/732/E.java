//package round377;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] ps = na(n);
		int[] ss = na(m);
		long[] pi = new long[n];
		for(int i = 0;i < n;i++){
			pi[i] = (long)ps[i]<<32|i;
		}
		pi = radixSort(pi);
		SimpleMinHeapL pq = new SimpleMinHeapL(m+1);
		for(int i = 0;i < m;i++){
			pq.add(1000000000L-ss[i]<<32|i);
		}
		int[] use = new int[m];
		int[] mat = new int[n];
		Arrays.fill(mat, -1);
		int p = n-1;
		while(pq.size() > 0 && p >= 0){
			long cur = pq.poll();
			long val = 1000000000L-(cur>>>32);
			int luse = ((int)cur)>>>20;
			int id = (int)cur&(1<<20)-1;
			while(p >= 0 && pi[p]>>>32 > val){
				p--;
			}
			if(p >= 0 && pi[p]>>>32 == val){
				mat[(int)pi[p]] = id;
				use[id] = luse;
				p--;
			}else{
				val = (val+1)/2;
				luse++;
				pq.add(1000000000L-val<<32|luse<<20|id);
			}
		}
		out.println(Arrays.stream(mat).filter(x -> x != -1).count() + " " +
				Arrays.stream(use).sum());
		for(int i = 0;i < m;i++){
			out.print(use[i] + " ");
		}
		out.println();
		for(int i = 0;i < n;i++){
			out.print(mat[i]+1 + " ");
		}
		out.println();
		
	}
	
	public static long[] radixSort(long[] f)
	{
		long[] to = new long[f.length];
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>16&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>16&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>32&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>32&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>48&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>48&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		return f;
	}

	
	public static class SimpleMinHeapL {
		public long[] a;
		public int n;
		public int pos;
		public static final long INF = Long.MAX_VALUE;
		
		public SimpleMinHeapL(int m)
		{
			n = m+1;
			a = new long[n];
			Arrays.fill(a, INF);
			pos = 1;
		}
		
		public SimpleMinHeapL(long[] in)
		{
			n = in.length+1;
			if((n&1)==1)n++;
			a = new long[n];
			pos = 1+in.length;
//			Arrays.fill(a, INF);
			a[0] = a[n-1] = a[n-2] = INF;
			System.arraycopy(in, 0, a, 1, in.length);
			for(int t = pos/2-1;t >= 1;t--){
				for(int c = t;2*c < pos;){
					int smaller = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
					if(a[smaller] < a[c]){
						long d = a[c]; a[c] = a[smaller]; a[smaller] = d;
						c = smaller;
					}else{
						break;
					}
				}
			}
		}
		
		public void add(long x)
		{
			a[pos++] = x;
			for(int c = pos-1, p = c>>>1;p >= 1 && a[c] < a[p];c>>>=1, p>>>=1){
				long d = a[p]; a[p] = a[c]; a[c] = d;
			}
		}
		
		public long poll()
		{
			if(pos == 1)return INF;
			pos--;
			long ret = a[1];
			a[1] = a[pos];
			a[pos] = INF;
			for(int c = 1;2*c < pos;){
				int smaller = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
				if(a[smaller] < a[c]){
					long d = a[c]; a[c] = a[smaller]; a[smaller] = d;
					c = smaller;
				}else{
					break;
				}
			}
			return ret;
		}
		
		public long min() { return a[1]; }
		public int size() { return pos-1; }
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
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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