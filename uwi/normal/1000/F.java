//package educational.round46;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
//		long S = System.currentTimeMillis();
		int n = ni();
		int[] a = na(n);
		int o = 500000;
		int[][] g = makeBuckets(a, o);
		
		int Q = ni();
		int[][] es = new int[2*n+Q][];
		int p = 0;
		{
			for(int i = 1;i <= o;i++){
				if(g[i].length == 0){
					continue;
				}else{
					for(int j = 0;j < g[i].length;j++){
						int L = j-1 >= 0 ? g[i][j-1]+1 : 0;
						int M = g[i][j];
						int R = j+1 < g[i].length ? g[i][j+1]-1 : n-1;
						es[p++] = new int[]{L, M, R+1, i, 1};
						es[p++] = new int[]{M+1, M, R+1, i, -1};
					}
				}
			}
		}
		for(int i = 0;i < Q;i++){
			es[p++] = new int[]{ni()-1, ni()-1, i};
		}
		
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				if(a.length != b.length)return -(a.length - b.length);
				return a.length == 5 ? a[4] - b[4] : 0;
			}
		});
//		long G = System.currentTimeMillis();
//		tr(G-S);
//		SegmentTreeAnyOne.maxpp = 0;
		SegmentTreeAnyOne st = new SegmentTreeAnyOne(n, o+1);
		int[] anss = new int[Q];
		Arrays.fill(anss, -1);
		for(int[] e : es){
			if(e.length == 5){
				if(e[4] == 1){
					st.put(e[1], e[2], e[3]);
				}else{
					st.remove(e[3]);
				}
			}else{
				anss[e[2]] = st.get(e[1]);
				if(anss[e[2]]  < 0)anss[e[2]] = 0;
			}
		}
		
		for(int ans : anss){
			out.println(ans);
		}
//		tr(SegmentTreeAnyOne.maxpp);
	}
	
	public static class SegmentTreeAnyOne {
		public int M, H, N;
		public int[] heads;
		public int[] prevs;
		public int[] nexts;
		int[] pp;
		
		static final int U = 40;
		
		public SegmentTreeAnyOne(int n, int vlim)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			heads = new int[M];
			for(int i = 0;i < M;i++){
				heads[i] = vlim*U+i;
			}
			prevs = new int[vlim*U+M];
			nexts = new int[vlim*U+M];
			Arrays.fill(prevs, -1);
			Arrays.fill(nexts, -1);
			pp = new int[vlim];
		}
		
		void insert(int cur, int v)
		{
			int tar = v*U+pp[v]++;
			int h = heads[cur];
			nexts[tar] = nexts[h];
			prevs[tar] = h;
			nexts[h] = tar;
			if(nexts[tar] != -1)prevs[nexts[tar]] = tar;
		}
		
		public void put(int l, int r, int v) { if(l < r)put(l, r, v, 0, H, 1); }
		
		private void put(int l, int r, int v, int cl, int cr, int cur)
		{
			if(cur >= H){
				insert(cur, v);
			}else if(l <= cl && cr <= r){
				insert(cur, v);
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					put(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					put(l, r, v, mid, cr, 2*cur+1);
				}
			}
		}
		
		
		public void remove(int val)
		{
			for(int i = 0;i < pp[val];i++){
				int tar = val*U+i;
				int nex = nexts[tar];
				int pre = prevs[tar];
				nexts[pre] = nex;
				if(nex != -1)prevs[nex] = pre;
				nexts[tar] = prevs[tar] = -1;
			}
			pp[val] = 0;
		}
		
		public int get(int x)
		{
			for(int i = H+x;i >= 1;i>>>=1){
				if(nexts[heads[i]] != -1)return nexts[heads[i]]/U;
			}
			return -1;
		}
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
	
	void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder();
//		Random gen = new Random(1*1000000009L);
//		int n = 500000;
//		int q = 500000;
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append((i+1) +" ");
//		}
//		sb.append(q + " ");
//		for(int i = 0;i < q;i++){
//			int v1 = gen.nextInt(n);
//			int v2 = gen.nextInt(n);
//			sb.append(Math.min(v1, v2) + 1 + " ");
//			sb.append(Math.max(v1, v2) + 1 + " ");
//		}
//		INPUT = sb.toString();
		
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