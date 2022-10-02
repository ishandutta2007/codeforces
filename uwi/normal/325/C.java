//package memsql2013.r1;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int Z = 314000000;
	int I = 999999999;
	
	static class Rule
	{
		int from;
		int dia;
		int[] to;
		public Rule(int from, int dia, int[] to) {
			this.from = from;
			this.dia = dia;
			this.to = to;
		}
	}
	
	void solve()
	{
		int n = ni(), K = ni();
		Rule[] rules = new Rule[n];
		int[] row = new int[100001];
		int[] from = new int[100001];
		int[] to = new int[100001];
		int[] from2 = new int[n];
		int[] to2 = new int[n];
		int q = 0;
		for(int i = 0;i < n;i++){
			int f = ni()-1;
			int L = ni();
			int p = 0;
			int dia = 0;
			from2[i] = f; to2[i] = i;
			for(int j = 0;j < L;j++){
				int x = ni();
				if(x == -1){
					dia++;
				}else{
					row[p++] = x-1;
					from[q] = i; to[q] = x-1; q++;
				}
			}
			rules[i] = new Rule(f, dia, Arrays.copyOf(row, p));
		}
		
		// enemy->rule
		int[][] ig = packD(100000, to, from, q);
		int[][] mrg = packD(100000, from2, to2, n);
		
		int[][] ret = new int[K][2];
		for(int i = 0;i < K;i++){
			ret[i][0] = I;
		}
		
		for(Rule r : rules){
			if(r.to.length == 0){
				ret[r.from][0] = Math.min(ret[r.from][0], r.dia);
			}
		}
		MinHeap h = new MinHeap(K);
		for(int i = 0;i < K;i++){
			if(ret[i][0] < I){
				h.add(i, ret[i][0]);
			}
		}
		
		{
			boolean[] ved = new boolean[K];
			int[] rscore = new int[n];
			int[] rsced = new int[n];
			while(h.size() > 0){
				int cur = h.argmin();
				ved[cur] = true;
				h.remove(cur);
				for(int e : ig[cur]){
					int mons = rules[e].from;
					if(!ved[mons]){
						rscore[e] += ret[cur][0];
						if(rscore[e] > Z)rscore[e] = Z;
						rsced[e]++;
						if(rsced[e] == rules[e].to.length){
							rscore[e] += rules[e].dia;
							if(rscore[e] > Z)rscore[e] = Z;
							if(rscore[e] < ret[mons][0]){
								ret[mons][0] = rscore[e];
								h.update(mons, ret[mons][0]);
							}
						}
					}
				}
			}
		}
		
		boolean[] bad = new boolean[n];
		for(int i = 0;i < K;i++){
			if(ret[i][0] == I){
				ret[i][0] = ret[i][1] = -1;
				for(int e : ig[i]){
					bad[e] = true;
				}
			}
		}
		
		boolean[] ved = new boolean[K];
		boolean[] aed = new boolean[K];
		for(int i = 0;i < K;i++){
			if(ret[i][1] == 0){
				dfs(i, rules, bad, mrg, ved, aed, ret);
			}
		}
		for(int i = 0;i < K;i++){
			out.println(ret[i][0] + " " + ret[i][1]);
		}
	}
	
	int dfs(int cur, Rule[] rules, boolean[] bad, int[][] mrg, boolean[] ved, boolean[] aed, int[][] ret)
	{
		if(ret[cur][1] != 0){
			return ret[cur][1];
		}
		if(aed[cur]){
			return ret[cur][1] = -2;
		}
		
		aed[cur] = true;
		int val = 0;
		outer:
		for(int idr : mrg[cur]){
			if(!bad[idr]){
				int all = rules[idr].dia;
				for(int t : rules[idr].to){
					if(t == cur){
						val = -2;
						break outer;
					}
					int lv = dfs(t, rules, bad, mrg, ved, aed, ret);
					if(lv == -2){
						val = -2;
						break outer;
					}
					all += lv;
					if(all >= Z)all = Z;
				}
				val = Math.max(val, all);
			}
		}
		aed[cur] = false;
		
		return ret[cur][1] = val;
	}
	
	public static int[][] packD(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
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
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
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