//package educational.round22;
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
		int n = ni(), K = ni();
		int[] a = na(n);
		int[][] g = makeBuckets(a, 100001);
		int[] t = new int[n];
		Arrays.fill(t, 199999);
		for(int i = 0;i < 100001;i++){
			for(int j = 0;j+K < g[i].length;j++){
				t[g[i][j]] = g[i][j+K];
			}
		}
		PersistentSegmentTreeRSQSimple pst = new PersistentSegmentTreeRSQSimple(200000, n);
		for(int i = 0;i < n;i++)pst.add(t[i], 1L);
		
		int last = 0;
		for(int Q = ni();Q > 0;Q--){
			int l = ni(), r = ni();
			l = (l+last)%n;
			r = (r+last)%n;
			if(l > r){
				int d = l;l = r;r = d;
			}
			last = (int)(r-l+1-(pst.sum(0, r+1, n) - pst.sum(0, r+1, l)));
			out.println(last);
		}
	}
	
	public static class PersistentSegmentTreeRSQSimple {
		public long[] st;
		public int[] len;
		public int[] L;
		public int[] R;
		public int gen;
		public int egen;
		public int H;
		public int[] entries;
		
		public PersistentSegmentTreeRSQSimple(int n, int q) {
			H = Integer.highestOneBit(Math.max(n-1, 1))<<1;
			int bufsize = (1+Integer.numberOfTrailingZeros(H)) * q + 2*H;
			
			gen = 0;
			entries = new int[q+1];
			st = new long[bufsize];
			len = new int[bufsize];
			L = new int[bufsize];
			R = new int[bufsize];
			Arrays.fill(L, -1);
			Arrays.fill(R, -1);
			
			egen = 0;
			entries[egen++] = make(0, H);
		}
		
		private int make(int l, int r)
		{
			int id = gen++;
			len[id] = r-l;
			if(r-l > 1){
				L[id] = make(l, l+r>>>1);
				R[id] = make(l+r>>>1, r);
			}
			return id;
		}
		
		public void add(int x, long v)
		{
			add(x, v, egen-1);
		}
		
		public void add(int x, long v, int eid)
		{
			entries[egen++] = adddfs(x, v, entries[eid]);
		}
		
		private int clone(int id)
		{
			int cloned = gen++;
			len[cloned] = len[id];
			L[cloned] = L[id];
			R[cloned] = R[id];
			st[cloned] = st[id];
			return cloned;
		}
		
		private int adddfs(int x, long v, int cur)
		{
			assert cur != -1;
			int cloned = clone(cur);
			if(len[cloned] == 1){
				st[cloned] += v;
				return cloned;
			}else{
				int h = len[cloned]/2;
				if(x < h){
					L[cloned] = adddfs(x, v, L[cloned]);
				}else{
					R[cloned] = adddfs(x-h, v, R[cloned]);
				}
				propagate(cloned);
				return cloned;
			}
		}
		
		
		public long sum(int l, int r, int eid)
		{
			return l >= r ? 0L : sumdfs(l, r, entries[eid]);
		}
		
		private long sumdfs(int l, int r, int cur)
		{
//				tr(l, r, cur, len[cur]);
			assert cur != -1;
			if(l == 0 && r == len[cur]){
				return st[cur];
			}else{
				int h = len[cur]/2;
				long ret = 0;
				if(l < h)ret += sumdfs(l, Math.min(h, r), L[cur]);
				if(h < r)ret += sumdfs(Math.max(l-h, 0), r-h, R[cur]);
				return ret;
			}
		}
		
		private void propagate(int cur)
		{
			st[cur] = 0;
			if(L[cur] != -1)st[cur] += st[L[cur]];
			if(R[cur] != -1)st[cur] += st[R[cur]];
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
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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