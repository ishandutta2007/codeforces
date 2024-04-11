//package round142;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			w[i] = ni();
		}
		int[][][] g = packWU(n, from, to, w);
		
		int[][] a = new int[n][];
		int[][] e = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = new int[ni()];
			for(int j = 0;j < a[i].length;j++){
				a[i][j] = ni();
			}
			
			e[i] = new int[a[i].length];
			for(int j = a[i].length-1;j >= 0;j--){
				if(j < a[i].length-1 && a[i][j+1] == a[i][j]+1){
					e[i][j] = e[i][j+1];
				}else{
					e[i][j] = a[i][j]+1;
				}
			}
		}
		
		int[] ret = dijk(g, 0, a, e);
		if(ret[n-1] >= Integer.MAX_VALUE / 2){
			out.println(-1);
		}else{
			out.println(ret[n-1]);
		}
	}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}
	
	public int[] dijk(int[][][] g, int from, int[][] a, int[][] c)
	{
		int n = g.length;
		int[] td = new int[n];
		Arrays.fill(td, Integer.MAX_VALUE / 2); // max
		MinHeap q = new MinHeap(n);
		q.add(from, 0);
		td[from] = 0;
		
		while(q.size() > 0){
			int cur = q.argmin();
			q.remove(cur);
			int myd = td[cur];
			int ind = Arrays.binarySearch(a[cur], myd);
			if(ind >= 0){
				myd = c[cur][ind];
			}
			
			for(int[] e : g[cur]){
				int next = e[0];
				int nd = myd + e[1];
				if(nd < td[next]){
					td[next] = nd;
					q.update(next, nd);
				}
			}
		}
		
		return td;
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
			n = Integer.highestOneBit((m+1)<<1);
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
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}