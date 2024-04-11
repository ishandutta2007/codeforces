//package round267;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2X {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] imap = shrinkX(a);
		int[][] g = makeBuckets(a, n);
		int[] next = new int[n];
		int I = 9999999;
		Arrays.fill(next, I);
		for(int[] row : g){
			Arrays.sort(row);
			for(int i = 0;i < row.length-1;i++){
				next[row[i]] = row[i+1];
			}
		}
		
		int[] reach = new int[n];
		long[] cons = new long[n];
		Arrays.fill(reach, I);
		
		for(int i = 0;i < g.length;i++){
			for(int j = 0;j+3 < g[i].length;j++){
				reach[g[i][j]] = g[i][j+3]+1;
				cons[g[i][j]] = (long)imap[i]<<32|imap[i];
			}
		}
		
		SegmentTreeRMQPos2 st = new SegmentTreeRMQPos2(next);
		
		int[] ps = new int[n];
		for(int i = 0;i < n;i++){
			int ind = ps[a[i]]++;
			if(ind >= 1){
				st.update(g[a[i]][ind-1], I);
				int bind = ind-1;
				int min = st.min(g[a[i]][bind]+1, i);
				if(min < I){
					int minpos = next[st.minpos];
	//						tr(i, ind, bind, minpos, restoreFenwick(ft), g[a[i]][bind]);
					if(minpos+1 < reach[g[a[i]][bind]]){
						reach[g[a[i]][bind]] = minpos+1;
						cons[g[a[i]][bind]] = (long)imap[a[i]]<<32|imap[a[minpos]];
					}
				}
			}
			if(next[i] == I){
				st.update(i, I);
			}
		}
		
		int[] dp = new int[n+1];
		boolean[] user = new boolean[n];
		for(int i = n-1;i >= 0;i--){
			dp[i] = dp[i+1];
			if(reach[i] != I && dp[reach[i]] + 1 > dp[i]){
				dp[i] = dp[reach[i]] + 1;
				user[i] = true;
			}
		}
		
		out.println(4L*dp[0]);
		for(int i = 0;i < n;){
			if(user[i]){
				out.print((cons[i]>>>32) + " ");
				out.print(((int)cons[i]) + " ");
				out.print((cons[i]>>>32) + " ");
				out.print(((int)cons[i]) + " ");
				i = reach[i];
			}else{
				i++;
			}
		}
		out.println();
	}
	
	public static int[][] makeBuckets(int[] a, int sup)
	{
		int n = a.length;
		int[][] bucket = new int[sup+1][];
		int[] bp = new int[sup+1];
		for(int i = 0;i < n;i++)bp[a[i]]++;
		for(int i = 0;i <= sup;i++)bucket[i] = new int[bp[i]];
		for(int i = n-1;i >= 0;i--)bucket[a[i]][--bp[a[i]]] = i;
		return bucket;
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
			Arrays.fill(st, 0, M, Integer.MAX_VALUE);
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
	
	public static int[] shrinkX(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
//		Arrays.sort(b);
		b = radixSort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || (b[i]^b[i-1])>>32!=0)ret[p++] = (int)(b[i]>>32);
			a[(int)b[i]] = p-1;
		}
		return Arrays.copyOf(ret, p);
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
	
	public static void main(String[] args) throws Exception { new E2X().run(); }
	
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