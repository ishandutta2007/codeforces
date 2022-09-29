//package round442;
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
		int n = ni();
		int[] par = new int[n];
		par[0] = -1;
		for(int i = 1;i < n;i++)par[i] = ni()-1;
		int[][] g = parentToG(par);
		int[] a = na(n);
		int[][] rs = makeRights(g, par, 0);
		int[] iord = rs[1], right = rs[2];
		int[] b = new int[n];
		for(int i = 0;i < n;i++){
			b[iord[i]] = a[i];
		}
		
		SegmentTreeRXQ st = new SegmentTreeRXQ(b);
		for(int Q = ni(); Q> 0;Q--){
			String type = ns();
			if(type.equals("get")){
				int x = ni()-1;
				out.println(st.count(iord[x], right[iord[x]]+1));
			}else{
				int x = ni()-1;
				st.flip(iord[x], right[iord[x]]+1);
			}
		}
	}
	
	public static class SegmentTreeRXQ {
		public int M, H, N;
		public boolean[] plus;
		public int[] ct;
		
		public SegmentTreeRXQ(int n)
		{
			N = n;
			H = Integer.highestOneBit(Math.max(n,1))<<1;
			M = H<<1;
			plus = new boolean[H];
			ct = new int[M];
		}
		
		public SegmentTreeRXQ(int[] a)
		{
			N = a.length;
			H = Integer.highestOneBit(Math.max(N,1))<<1;
			M = H<<1;
			plus = new boolean[H];
			ct = new int[M];
			System.arraycopy(a, 0, ct, H, N);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(plus[i]){
				int q = H / Integer.highestOneBit(i);
				ct[i] = q - (ct[2*i] + ct[2*i+1]);
			}else{
				ct[i] = ct[2*i] + ct[2*i+1];
			}
		}
		
		public void flip(int l, int r){ flip(l, r, 0, H, 1); }
		
		private void flip(int l, int r, int cl, int cr, int cur)
		{
			if(cur >= H){
				ct[cur] ^= 1;
			}else if(l <= cl && cr <= r){
				plus[cur] ^= true;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					flip(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					flip(l, r, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public int count(int l, int r) { return l >= r ? 0 : count(l, r, 0, H, 1); }
		
		private int count(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return ct[cur];
			}else{
				int mid = cl+cr>>>1;
				int ret = 0;
				if(cl < r && l < mid){
					ret += count(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					ret += count(l, r, mid, cr, 2*cur+1);
				}
				return plus[cur] ? Math.min(r, cr) - Math.max(l, cl) - ret : ret;
			}
		}
	}

	
	public static int[] sortByPreorder(int[][] g, int root){
		int n = g.length;
		int[] stack = new int[n];
		int[] ord = new int[n];
		boolean[] ved = new boolean[n];
		stack[0] = root;
		int p = 1;
		int r = 0;
		ved[root] = true;
		while(p > 0){
			int cur = stack[p-1];
			ord[r++] = cur;
			p--;
			for(int e : g[cur]){
				if(!ved[e]){
					ved[e] = true;
					stack[p++] = e;
				}
			}
		}
		return ord;
	}
	
	public static int[][] makeRights(int[][] g, int[] par, int root)
	{
		int n = g.length;
		int[] ord = sortByPreorder(g, root);
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[ord[i]] = i;
		
		int[] right = new int[n];
		for(int i = n-1;i >= 1;i--){
			if(right[i] == 0)right[i] = i;
			int p = iord[par[ord[i]]];
			right[p] = Math.max(right[p], right[i]);
		}
		return new int[][]{ord, iord, right};
	}

	
	public static int[][] parentToG(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[i]++;
				ct[par[i]]++;
			}
		}
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++){
			g[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				g[par[i]][--ct[par[i]]] = i;
				g[i][--ct[i]] = par[i];
			}
		}
		return g;
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