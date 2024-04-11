//package round353;
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
		int n = ni();
		int[] a = na(n-1);
		for(int i = 0;i < n-1;i++)a[i]--;
		int[] ma = new int[n];
		for(int i = 0;i < n-1;i++)ma[i] = -a[i];
		SegmentTreeRMQPos st = new SegmentTreeRMQPos(ma);
		int[] par = new int[n];
		par[n-1] = -1;
		for(int i = n-2;i >= 0;i--){
			long min = st.min(i+1, a[i]+1);
			int nex = st.minpos;
			par[i] = nex;
		}
		int[][] ch = parentToChildren(par);
		stack = new int[n+2][];
		sp = 0;
		val = 0;
		hist = new int[n+2][];
		hp = 0;
		ret = 0;
		for(int c : ch[n-1]){
			dfs(c, par, ch, a, 1);
		}
		out.println(ret);
	}
	
	int[][] stack;
	int sp;
	long val;
	int[][] hist;
	int hp;
	long ret;
	
	void dfs(int cur, int[] par, int[][] ch, int[] a, int dep)
	{
		int ohp = hp;
		long oval = val;
		int n = a.length+1;
		while(sp-1 >= 0 && a[cur] >= stack[sp-1][0]){
			hist[hp++] = stack[sp-1];
			int len = (sp-2 >= 0 ? stack[sp-2][0] : n) - stack[sp-1][0];
			val -= (long)stack[sp-1][1]*len;
			sp--;
		}
		boolean ex = false;
		if(a[cur]+1 < (sp-1 >= 0 ? stack[sp-1][0] : n)){
			ex = true;
			stack[sp++] = new int[]{a[cur]+1, hist[hp-1][1]};
			int len = (sp-2 >= 0 ? stack[sp-2][0] : n) - stack[sp-1][0];
			val += (long)stack[sp-1][1]*len;
		}
		stack[sp++] = new int[]{cur+1, dep};
		int len = (sp-2 >= 0 ? stack[sp-2][0] : n) - stack[sp-1][0];
		val += (long)stack[sp-1][1]*len;
		
//		tr(cur, (long)(n-cur-1)*(dep+1)-val, val, Arrays.copyOf(stack, sp));
		ret += (long)(n-cur-1)*(dep+1)-val;
		
		for(int c : ch[cur]){
			dfs(c, par, ch, a, dep+1);
		}
		
		val = oval;
		sp--;
		if(ex)sp--;
		while(hp > ohp){
			stack[sp++] = hist[hp-1];
			hp--;
		}
	}
	
	public static int[][] parentToChildren(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
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
			}
		}
		
		return g;
	}

	
	public static class SegmentTreeRMQPos {
		public int M, H, N;
		public long[] st;
		public int[] pos;
		
		public SegmentTreeRMQPos(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			pos = new int[M];
			for(int i = 0;i < N;i++)pos[H+i] = i;
			Arrays.fill(st, 0, M, 0);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public SegmentTreeRMQPos(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new long[M];
			pos = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
				pos[H+i] = i;
			}
			Arrays.fill(st, H+N, M, Long.MAX_VALUE);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public void update(int pos, long x)
		{
			st[H+pos] = x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(st[2*i] <= st[2*i+1]){
				st[i] = st[2*i];
				pos[i] = pos[2*i];
			}else{
				st[i] = st[2*i+1];
				pos[i] = pos[2*i+1];
			}
		}
		
		public int minpos;
		public long minval;
		
		public long minx(int l, int r){
			if(l >= r)return 0;
			minval = Long.MAX_VALUE;
			minpos = -1;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				long v = st[(H+l)/f];
				if(v < minval){
					minval = v;
					minpos = pos[(H+l)/f];
				}
				l += f;
			}
			
			while(l < r){
				int f = r&-r;
				long v = st[(H+r)/f-1];
				if(v < minval){
					minval = v;
					minpos = pos[(H+r)/f-1];
				}
				r -= f;
			}
			return minval;
		}
		
		public long min(int l, int r){ 
			minpos = -1;
			minval = Long.MAX_VALUE;
			min(l, r, 0, H, 1);
			return minval;
		}
		
		private void min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(st[cur] < minval){
					minval = st[cur];
					minpos = pos[cur];
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid)min(l, r, cl, mid, 2*cur);
				if(mid < r && l < cr)min(l, r, mid, cr, 2*cur+1);
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
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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