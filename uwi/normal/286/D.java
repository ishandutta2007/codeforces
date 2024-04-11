//package round176;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int m = ni(), n = ni();
		int[][] rs = new int[n][];
		for(int i = 0;i < n;i++){
			rs[i] = new int[]{ni(), ni(), ni()};
		}
		
		int[][] es = new int[2*n][];
		for(int i = 0;i < n;i++){
			es[2*i] = new int[]{rs[i][0], 1, i};
			es[2*i+1] = new int[]{rs[i][1], -1, i};
		}
		Arrays.sort(es, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		
		int[][] zs = new int[4*n+10][];
		int f = 0;
		
		MinHeap h = new MinHeap(n);
		int prev = -1;
		for(int i = 0;i < 2*n;i++){
			if(prev < es[i][0] && h.size() > 0){
				// L=prev, R=es[i][0], T=h.min
				int l = prev, r = es[i][0], t = h.min();
				zs[f++] = new int[]{t-r, 1, -(t-r)}; // (r-l)+(t-r)
				zs[f++] = new int[]{t-l, -1, t-l};
			}
			if(es[i][1] == 1){
				h.add(es[i][2], rs[es[i][2]][2]);
			}else{
				h.remove(es[i][2]);
			}
			prev = es[i][0];
		}
		
		Arrays.sort(zs, 0, f, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		long c0 = 0, c1 = 0;
		int p = 0;
		for(int i = 0;i < m;i++){
			int q = ni();
			while(p < f && zs[p][0] <= q){
				c1 += zs[p][1];
				c0 += zs[p][2];
				p++;
			}
			out.println(c1 * q + c0);
		}
	}
	
	public static class MinHeap {
		public int[] a;
		public int[] map; // 
		public int[] imap; // 
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
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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