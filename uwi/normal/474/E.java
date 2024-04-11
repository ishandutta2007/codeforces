//package round271;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), d = ni();
		long[] h = new long[n];
		for(int i = 0;i < n;i++)h[i] = nl();
		
		long[] sh = Arrays.copyOf(h, n);
		sh = radixSort(sh);
		int p = 0;
		for(int i = 0;i < n;i++){
			if(i == 0 || sh[i] != sh[i-1]){
				sh[p++] = sh[i];
			}
		}
		sh = Arrays.copyOf(sh, p);
		SegmentTreeRMQPos2 st = new SegmentTreeRMQPos2(new int[p]);
		int maxlen = 0;
		int[] prev = new int[n];
		int argmax = -1;
		int[] last = new int[p];
		for(int i = 0;i < n;i++){
			long low = h[i]-d;
			long high = h[i]+d;
			int indl = Arrays.binarySearch(sh, low);
			if(indl < 0)indl = -indl-2;
			int indh = Arrays.binarySearch(sh, high);
			if(indh < 0)indh = -indh-1;
			
			int minl = st.min(0, indl+1);
			int minposl = st.minpos;
			int minh = st.min(indh, p);
			int minposh = st.minpos;
			prev[i] = -1;
			if(minl >= 0 && minh >= 0){
				prev[i] = -1;
			}else if(minl < minh){
				prev[i] = last[minposl];
			}else{
				prev[i] = last[minposh];
			}
			int min = Math.max(0, -Math.min(minl, minh));
			if(min+1 > maxlen){
				argmax = i;
				maxlen = min+1;
			}
			int y = Arrays.binarySearch(sh, h[i]);
			st.update(y, -(min+1));
			last[y] = i;
		}
		out.println(maxlen);
		int[] ls = new int[maxlen];
		int q = maxlen-1;
		for(int s = argmax; s != -1; s = prev[s], q--){
			ls[q] = s+1;
		}
		for(int i = 0;i < maxlen;i++){
			out.print(ls[i] + " ");
		}
		out.println();
	}
	
	public static class SegmentTreeRMQPos2 {
		public int M, H, N;
		public int[] st;
		public int[] pos;
		
		public SegmentTreeRMQPos2(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < N;i++)pos[H+i] = i;
			Arrays.fill(st, 0, M, Integer.MAX_VALUE/2);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public SegmentTreeRMQPos2(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
				pos[H+i] = i;
			}
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public void update(int pos, int x)
		{
			st[H+pos] = x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(st[2*i] <= st[2*i+1]){
				st[i] = st[2*i];
				pos[i] = pos[2*i];
			}else{
				st[i] = st[2*i+1];
				pos[i] = pos[2*i+1];
			}
		}
		
		public int minpos;
		public int minval;
		
		public int min(int l, int r){ 
			minpos = -1;
			minval = Integer.MAX_VALUE;
			min(l, r, 0, H, 1);
			return minval;
		}
		
		private void min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(st[cur] < minval){
					minval = st[cur];
					minpos = pos[cur];
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid)min(l, r, cl, mid, 2*cur);
				if(mid < r && l < cr)min(l, r, mid, cr, 2*cur+1);
			}
		}
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
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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