//package round658;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			go();
		}
	}
	
	void go()
	{
		int n = ni(), x = ni(), y = ni();
		int[] a = na(n);
		int[] f = new int[n+1];
		for(int v : a){
			f[v-1]++;
		}
		MinHeap h = new MinHeap(n+1);
		for(int i = 0;i < n+1;i++){
			if(f[i] > 0){
				h.add(i, -f[i]);
			}
		}
		int nomat = -1;
		for(int i = 0;i <= n;i++){
			if(f[i] == 0)nomat = i;
		}
		
		int[] mat = new int[n+1];
		for(int i = 0;i < x;i++){
			int u = h.argmin();
			mat[u]++;
			f[u]--;
			h.update(u, h.min() + 1);
		}
		
		// SUP: sum min(f, n-f)
		
		// 4-3+2=3
		
		if((y-x > 0 && -h.min() == n-x) || y-x > n-x-(-h.min()) + Math.min(-h.min(), n-x-(-h.min()))){
			out.println("NO");
			return;
		}
		
		out.println("YES");
		int[] b = new int[n];
		int[][] rm = new int[n][];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(mat[a[i]-1] > 0){
				mat[a[i]-1]--;
				b[i] = a[i];
			}else{
				rm[p++] = new int[]{a[i], i};
			}
		}
		Arrays.sort(rm, 0, p, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int mf = (n-x)/2;
		
		int done = 0;
		for(int i = 0, j = mf;i < p;i++,j++){
			if(j == p)j = 0;
			
			if(a[rm[j][1]] == rm[i][0] || done >= y-x){
				b[rm[j][1]] = nomat+1;
			}else{
				b[rm[j][1]] = rm[i][0];
				done++;
			}
		}
		for(int v : b){
			out.print(v + " ");
		}
		out.println();
		
//		tr("ans", b);
//		check(b, a, x, y);
	}
	
	void check(int[] b, int[] a, int xx, int yy)
	{
		int n = a.length;
		for(int i = 0;i < n;i++)a[i]--;
		for(int i = 0;i < n;i++)b[i]--;
		int[] fa = new int[n+1];
		for(int v : a)fa[v]++;
		int[] fb = new int[n+1];
		for(int v : b)fb[v]++;
		int pmat = 0;
		for(int i = 0;i < n;i++){
			if(a[i] == b[i])pmat++;
		}
		
		int mat = 0;
		for(int i = 0;i <= n;i++){
			mat += Math.min(fa[i], fb[i]);
		}
		tr(pmat, mat, xx, yy);
		
		assert pmat == xx;
		assert mat == yy;
	}
	
	public static class MinHeap {
		public int[] a;
		public int[] map;
		public int[] imap;
		public int n;
		public int pos;
		public static int INF = Integer.MAX_VALUE;
		
		public MinHeap(int m)
		{
			n = m+2;
			a = new int[n];
			map = new int[n];
			imap = new int[n];
			Arrays.fill(a, INF);
			Arrays.fill(map, -1);
			Arrays.fill(imap, -1);
			pos = 1;
		}
		
		public int add(int ind, int x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}
			return ret != -1 ? a[ret] : x;
		}
		
		public int update(int ind, int x)
		{
			int ret = imap[ind];
			if(imap[ind] < 0){
				a[pos] = x; map[pos] = ind; imap[ind] = pos;
				pos++;
				up(pos-1);
			}else{
				int o = a[ret];
				a[ret] = x;
				up(ret);
				down(ret);
//				if(a[ret] > o){
//					up(ret);
//				}else{
//					down(ret);
//				}
			}
			return x;
		}
		
		public int remove(int ind)
		{
			if(pos == 1)return INF;
			if(imap[ind] == -1)return INF;
			
			pos--;
			int rem = imap[ind];
			int ret = a[rem];
			map[rem] = map[pos];
			imap[map[pos]] = rem;
			imap[ind] = -1;
			a[rem] = a[pos];
			a[pos] = INF;
			map[pos] = -1;
			
			up(rem);
			down(rem);
			return ret;
		}
		
		public int min() { return a[1]; }
		public int argmin() { return map[1]; }
		public int size() {	return pos-1; }
		
		private void up(int cur)
		{
			for(int c = cur, p = c>>>1;p >= 1 && a[p] > a[c];c>>>=1, p>>>=1){
				int d = a[p]; a[p] = a[c]; a[c] = d;
				int e = imap[map[p]]; imap[map[p]] = imap[map[c]]; imap[map[c]] = e;
				e = map[p]; map[p] = map[c]; map[c] = e;
			}
		}
		
		private void down(int cur)
		{
			for(int c = cur;2*c < pos;){
				int b = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
				if(a[b] < a[c]){
					int d = a[c]; a[c] = a[b]; a[b] = d;
					int e = imap[map[c]]; imap[map[c]] = imap[map[b]]; imap[map[b]] = e;
					e = map[c]; map[c] = map[b]; map[b] = e;
					c = b;
				}else{
					break;
				}
			}
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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