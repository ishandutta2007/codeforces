//package round416;
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
		int n = ni(), m = ni(), Q = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = na(m);
		}
		
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = new int[]{ni()-1, ni()-1, i};
		}
		int[] anss = new int[Q];
		go(0, m, a, qs, anss);
		
		for(int v : anss){
			out.println(v);
		}
	}
	
	void go(int l, int r, int[][] a, int[][] qs, int[] anss)
	{
		int n = a.length;
		if(r-l == 1){
			int con = n;
			for(int i = 0;i < n-1;i++){
				if(a[i][l] == a[i+1][l])con--;
			}
			for(int[] q : qs){
				anss[q[2]] = con;
			}
			return;
		}
		
		int h = l+r>>1;
		// [l,h),[h,r)
		int[] consl = new int[h-l];
		int[][] samel = new int[h-l][n];
		{
			DJSet ds = new DJSet((h-l)*n);
			int con = 0;
			for(int j = h-1;j >= l;j--){
				con += n;
				for(int i = 0;i < n-1;i++){
					if(a[i][j] == a[i+1][j]){
						if(!ds.union(i*(h-l)+j-l, (i+1)*(h-l)+j-l)){
							con--;
						}
					}
				}
				if(j < h-1){
					for(int i = 0;i < n;i++){
						if(a[i][j] == a[i][j+1]){
							if(!ds.union(i*(h-l)+j-l, i*(h-l)+j-l+1)){
								con--;
							}
						}
					}
				}
				consl[j-l] = con;
				inner:
				for(int i = 0;i < n;i++){
					for(int k = 0;k < i;k++){
						if(ds.equiv(k*(h-l)+h-1-l, i*(h-l)+h-1-l)){
							samel[j-l][i] = k;
							continue inner;
						}
					}
					samel[j-l][i] = -1;
				}
			}
		}
		int[] consr = new int[r-h];
		int[][] samer = new int[r-h][n];
		{
			DJSet ds = new DJSet((r-h)*n);
			int con = 0;
			for(int j = h;j < r;j++){
				con += n;
				for(int i = 0;i < n-1;i++){
					if(a[i][j] == a[i+1][j]){
						if(!ds.union(i*(r-h)+j-h, (i+1)*(r-h)+j-h)){
							con--;
						}
					}
				}
				if(j > h){
					for(int i = 0;i < n;i++){
						if(a[i][j] == a[i][j-1]){
							if(!ds.union(i*(r-h)+j-h, i*(r-h)+j-h-1)){
								con--;
							}
						}
					}
				}
				consr[j-h] = con;
				inner:
				for(int i = 0;i < n;i++){
					for(int k = 0;k < i;k++){
						if(ds.equiv(k*(r-h)+0, i*(r-h)+0)){
							samer[j-h][i] = k;
							continue inner;
						}
					}
					samer[j-h][i] = -1;
				}
			}
		}
//		tr(l, h, r);
//		tr(samel, samer);
//		tr(consl, consr);
		
		int[][] lqs = new int[qs.length][];
		int[][] rqs = new int[qs.length][];
		int lp = 0, rp = 0;
		for(int[] q : qs){
			if(q[0] < h && q[1] >= h){
				int basecon = consl[q[0]-l] + consr[q[1]-h];
				int[] cl = samel[q[0]-l];
				int[] cr = samer[q[1]-h];
				DJSet ds = new DJSet(2*n);
				for(int u = 0;u < n;u++){
					if(cl[u] != -1){
						ds.union(u, cl[u]);
					}
					if(cr[u] != -1){
						ds.union(u+n, cr[u]+n);
					}
				}
				for(int u = 0;u < n;u++){
					if(a[u][h-1] == a[u][h]){
						if(!ds.union(u, u+n)){
							basecon--;
						}
					}
				}
				anss[q[2]] = basecon;
			}else if(q[1] < h){
				lqs[lp++] = q;
			}else{
				rqs[rp++] = q;
			}
		}
		if(lp > 0){
			go(l, h, a, Arrays.copyOf(lqs, lp), anss);
		}
		if(rp > 0){
			go(h, r, a, Arrays.copyOf(rqs, rp), anss);
		}
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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