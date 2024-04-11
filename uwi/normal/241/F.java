//package bayan2012;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int dis(char c)
	{
		if(c == '#')return 0;
		if(c >= '1' && c <= '9')return c - '0';
		return 1;
	}
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		char[][] b = new char[n][];
		for(int i = 0;i < n;i++){
			b[i] = ns(m);
		}
		int sr = ni()-1, sc = ni()-1;
		char[] cor = ns(1001);
		int er = ni()-1, ec = ni()-1;
		
		int[][] co = new int[28][];
		co[26] = new int[]{sr, sc};
		co[27] = new int[]{er, ec};
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(b[i][j] >= 'a' && b[i][j] <= 'z'){
					co[b[i][j]-'a'] = new int[]{i, j};
				}
			}
		}
		
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		
		int[][] d = new int[28][28];
		for(int i = 0;i < 28;i++){
			Arrays.fill(d[i], 199999999);
			if(co[i] != null){
				for(int k = 0;k < 4;k++){
					int r = co[i][0], c = co[i][1];
					int dis = dis(b[r][c]);
					r += dr[k]; c += dc[k];
					while(r >= 0 && r < n && c >= 0 && c < m && b[r][c] >= '1' && b[r][c] <= '9'){
						dis += dis(b[r][c]);
						if(er == r && ec == c){
							d[i][27] = dis;
						}
						r += dr[k]; c += dc[k];
					}
					if(r >= 0 && r < n && c >= 0 && c < m && b[r][c] != '#'){
						d[i][b[r][c]-'a'] = dis;
					}
				}
			}
		}
		
		char[] path = ("{" + new String(cor) + "|").toCharArray();
		
		for(int i = 0;i < path.length-1;i++){
			int nk = K - d[path[i]-'a'][path[i+1]-'a'];
			if(nk <= 0){
				int xr = co[path[i]-'a'][0] - co[path[i+1]-'a'][0];
				int xc = co[path[i]-'a'][1] - co[path[i+1]-'a'][1];
				if(xr != 0)xr /= Math.abs(xr);
				if(xc != 0)xc /= Math.abs(xc);
				
				int r = co[path[i+1]-'a'][0], c = co[path[i+1]-'a'][1];
				while(nk < 0){
					int nr = r + xr, nc = c + xc;
					nk += dis(b[nr][nc]);
					r = nr; c = nc;
				}
				
				out.println((r+1) + " " + (c+1));
				return;
			}
			K = nk;
		}
		out.println((er+1) + " " + (ec+1));
	}
	
	public static int[] dijkp(int[][][] g, int from)
	{
		int n = g.length;
		int[] td = new int[n];
		Arrays.fill(td, 999999999); // max
		MinHeap q = new MinHeap(n);
		q.add(from, 0);
		td[from] = 0;
		int[] prev = new int[n];
		Arrays.fill(prev, -1);
		
		while(q.size() > 0){
			int cur = q.argmin();
			q.remove(cur);
			
			for(int[] e : g[cur]){
				int next = e[0];
				int nd = td[cur] + e[1];
				if(nd < td[next]){
					prev[next] = cur;
					td[next] = nd;
					q.update(next, nd);
				}
			}
		}
		
		return prev;
	}
	
	public static int[] dijk(int[][][] g, int from)
	{
		int n = g.length;
		int[] td = new int[n];
		Arrays.fill(td, 999999999); // max
		MinHeap q = new MinHeap(n);
		q.add(from, 0);
		td[from] = 0;
		
		while(q.size() > 0){
			int cur = q.argmin();
			q.remove(cur);
			
			for(int[] e : g[cur]){
				int next = e[0];
				int nd = td[cur] + e[1];
				if(nd < td[next]){
					td[next] = nd;
					q.update(next, nd);
				}
			}
		}
		
		return td;
	}
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w, int sup)
	{
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]][2];
		for(int i = 0;i < sup;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
		}
		return g;
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
		new F2().run();
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