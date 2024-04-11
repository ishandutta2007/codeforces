//package round355;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), P = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = na(m);
		}
		int[][] as = new int[n*m+1][];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				as[p++] = new int[]{a[i][j], i, j};
			}
		}
		as[p++] = new int[]{0, 0, 0};
		Arrays.sort(as, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int[] offset = new int[P+2];
		for(int i = p-1;i >= 0;i--){
			offset[as[i][0]] = i;
		}
		offset[P+1] = p;
		int[] d = new int[p];
		Arrays.fill(d, 999999999);
		d[0] = 0;
		for(int i = 0;i < P;i++){
			go(offset[i], offset[i+1], offset[i+2],  as, d, n, m);
		}
		out.println(d[d.length-1]);
	}
	
	void go(int o0, int o1, int o2, int[][] as, int[] d, int h, int w)
	{
		int n = as.length;
		if((long)(o2-o0)*(o2-o0) >= 10000000){
			int[][] ds = new int[h][w];
			for(int i = 0;i < h;i++)Arrays.fill(ds[i], 99999999);
			MinHeap q = new MinHeap(h*w);
			for(int i = o0;i < o1;i++){
				ds[as[i][1]][as[i][2]] = d[i];
				q.add(as[i][1]*w+as[i][2], d[i]);
			}
			int[] dr = { 1, 0, -1, 0 };
			int[] dc = { 0, 1, 0, -1 };
			while(q.size() > 0){
				int cur = q.argmin();
				q.remove(cur);
				int r = cur / w, c = cur % w;
				for(int k = 0;k < 4;k++){
					int nr = r + dr[k], nc = c + dc[k];
					if(nr >= 0 && nr < h && nc >= 0 && nc < w){
						if(ds[nr][nc] > ds[r][c] + 1){
							ds[nr][nc] = ds[r][c] + 1;
							q.update(nr*w+nc, ds[nr][nc]);
						}
					}
				}
			}
			for(int i = o1;i < o2;i++){
				d[i] = ds[as[i][1]][as[i][2]];
			}
		}else{
			for(int i = o0;i < o1;i++){
				for(int j = o1;j < o2;j++){
					d[j] = Math.min(d[j], d[i] + Math.abs(as[j][1]-as[i][1]) + Math.abs(as[j][2]-as[i][2]));
				}
			}
		}
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
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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