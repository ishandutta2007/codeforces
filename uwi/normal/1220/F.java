//package round586;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "7 1 2 3 4 5 6 7";
	
	
	void solve()
	{
		// 1
		// 1k
		// 1kk1
		// kl
		// 1
		
		int n = ni();
		int[] a = na(n);
		int one = 0;
		for(int i = 0;i < n;i++){
			if(a[i] == 1){
				one = i;
			}
		}
		int[] sa = new int[n];
		for(int i = 0;i < n;i++){
			sa[i] = a[(i+one)%n];
		}
		int[] ra = solve(sa);
		int[] sb = new int[n];
		for(int i = 0;i < n;i++){
			sb[i] = sa[(n-i)%n];
		}
		int[] rb = solve(sb);
		int ans = 999999999;
		int arg = -1;
		for(int i = 0;i < n;i++){
			int v = Math.max(ra[i], rb[n-1-i]);
//			tr(i, v);
			if(v < ans){
				ans = v;
				arg = i;
			}
		}
		out.println(ans+1 + " " + (one + n-arg)%n);
//		out.println(ans+1);
	}
	
	public static int[] rev(int[] a)
	{
		int[] b = new int[a.length];
		for(int i = 0;i < a.length;i++)b[a.length-1-i] = a[i];
		return b;
	}
	

	
	int[] solve(int[] a)
	{
		int n = a.length;
		int[] raiser = new int[n];
		int[][][] st = buildP(a);
		dfs(0, n, -1, a, st, raiser);
//		tr(raiser);
		
		StarrySkyTree sst = new StarrySkyTree(n);
		int[] ret = new int[n];
		for(int i = 0;i < n;i++){
			int pdep = raiser[i] <= 0 ? -1 : -sst.min(raiser[i]-1, raiser[i]);
			sst.add(raiser[i], i, -1);
			sst.add(i, i+1, -pdep-1);
			ret[n-1-i] = -sst.min(0, i+1);
		}
		return ret;
	}
	
	void dfs(int l, int r, int lpar, int[] a, int[][][] st, int[] raiser)
	{
		if(l >= r)return;
		int pos = rmqpos(st, l, r);
		raiser[pos] = lpar + 1;
		
		dfs(l, pos, lpar, a, st, raiser);
		dfs(pos+1, r, pos, a, st, raiser);
	}
	
	public static class StarrySkyTree {
		public int M, H, N;
		public int[] st;
		public int[] plus;
		public int I = Integer.MAX_VALUE/4; // I+plus<int
		
		public StarrySkyTree(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			plus = new int[H];
		}
		
		public StarrySkyTree(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			plus = new int[H];
			Arrays.fill(st, H+N, M, I);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			st[i] = Math.min(st[2*i], st[2*i+1]) + plus[i];
		}
		
		public void add(int l, int r, int v){ if(l < r)add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, int v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(cur >= H){
					st[cur] += v;
				}else{
					plus[cur] += v;
					propagate(cur);
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public int min(int l, int r){ return l >= r ? I : min(l, r, 0, H, 1);}
		
		private int min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				int ret = I;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
				}
				return ret + plus[cur];
			}
		}
		
		public void fall(int i)
		{
			if(i < H){
				if(2*i < H){
					plus[2*i] += plus[i];
					plus[2*i+1] += plus[i];
				}
				st[2*i] += plus[i];
				st[2*i+1] += plus[i];
				plus[i] = 0;
			}
		}
		
		public int firstle(int l, int v) {
			int cur = H+l;
			for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
				fall(i);
				i = i*2|cur>>>j&1;
			}
			while(true){
				fall(cur);
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur;
					}else{
						return cur-H;
					}
				}else{
					cur++;
					if((cur&cur-1) == 0)return -1;
					cur = cur>>>Integer.numberOfTrailingZeros(cur);
				}
			}
		}
		
		public int lastle(int l, int v) {
			int cur = H+l;
			for(int i = 1, j = Integer.numberOfTrailingZeros(H)-1;i <= cur;j--){
				fall(i);
				i = i*2|cur>>>j&1;
			}
			while(true){
				fall(cur);
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur+1;
					}else{
						return cur-H;
					}
				}else{
					if((cur&cur-1) == 0)return -1;
					cur = cur>>>Integer.numberOfTrailingZeros(cur);
					cur--;
				}
			}
		}
		
		public int[] toArray() { return toArray(1, 0, H, new int[H]); }
		
		private int[] toArray(int cur, int l, int r, int[] ret)
		{
			if(r-l == 1){
				ret[cur-H] = st[cur];
			}else{
				toArray(2*cur, l, l+r>>>1, ret);
				toArray(2*cur+1, l+r>>>1, r, ret);
				for(int i = l;i < r;i++)ret[i] += plus[cur];
			}
			return ret;
		}
	}

	
	public static int[][][] buildP(int[] a)
	{
		int n = a.length;
		int b = 32-Integer.numberOfLeadingZeros(n);
		int[][] ret = new int[b][];
		int[][] pos = new int[b][];
		for(int i = 0, l = 1;i < b;i++, l*=2) {
			if(i == 0) {
				ret[i] = a;
				pos[i] = new int[n];
				for(int j = 0;j < n;j++)pos[i][j] = j;
			}else {
				ret[i] = new int[n-l+1];
				pos[i] = new int[n-l+1];
				for(int j = 0;j < n-l+1;j++) {
					if(ret[i-1][j] < ret[i-1][j+l/2]){
						ret[i][j] = ret[i-1][j];
						pos[i][j] = pos[i-1][j];
					}else{
						ret[i][j] = ret[i-1][j+l/2];
						pos[i][j] = pos[i-1][j+l/2];
					}
				}
			}
		}
		return new int[][][]{ret, pos};
	}
	
	public static int[][][] buildP(int[] a, int[] ord)
	{
		int n = a.length;
		int b = 32-Integer.numberOfLeadingZeros(n);
		int[][] ret = new int[b][];
		int[][] pos = new int[b][];
		for(int i = 0, l = 1;i < b;i++, l*=2) {
			if(i == 0) {
				ret[i] = a;
				pos[i] = ord;
			}else {
				ret[i] = new int[n-l+1];
				pos[i] = new int[n-l+1];
				for(int j = 0;j < n-l+1;j++) {
					if(ret[i-1][j] < ret[i-1][j+l/2]){
						ret[i][j] = ret[i-1][j];
						pos[i][j] = pos[i-1][j];
					}else{
						ret[i][j] = ret[i-1][j+l/2];
						pos[i][j] = pos[i-1][j+l/2];
					}
				}
			}
		}
		return new int[][][]{ret, pos};
	}
	
	public static int rmqpos(int[][][] st, int a, int b)
	{
		int t = 31-Integer.numberOfLeadingZeros(b-a);
		if(st[0][t][a] < st[0][t][b-(1<<t)]){
			return st[1][t][a];
		}else{
			return st[1][t][b-(1<<t)];
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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