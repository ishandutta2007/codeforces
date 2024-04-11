//package round157;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[n-1];
		int[] to = new int[n-1];
		for(int i = 0;i < n-1;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[][] g = packU(n, from, to);
		int[][] pars = parents(g, 0);
		int[] par = pars[0];
		int[][] rs = makeRights(g, par, 0);
		int[] ord = rs[0], iord = rs[1], right = rs[2];
		
		int[][] pluss = new int[m][];
		for(int q = 0;q < m;q++){
			int a = ni()-1, b = ni()-1;
			int la = iord[a], ra = right[iord[a]];
			int lb = iord[b], rb = right[iord[b]];
			pluss[q] = new int[]{la, ra, lb, rb};
		}
		
		long[] ev = new long[4*m];
		int p = 0;
		for(int q = 0;q < m;q++){
			ev[p++] = (long)pluss[q][0]<<33|1L<<32|q;
			ev[p++] = (long)pluss[q][1]+1<<33|0L<<32|q;
			ev[p++] = (long)pluss[q][2]<<33|1L<<32|q;
			ev[p++] = (long)pluss[q][3]+1<<33|0L<<32|q;
		}
		
		ev = radixSort(ev);
		
		SegmentTreeRSQ st = new SegmentTreeRSQ(n);
		p = 0;
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			while(p < 4*m && ev[p]>>>33 <= i){
				int ind = (int)ev[p];
				int pl = ev[p]<<63-32<0 ? 1 : -1;
				st.add(pluss[ind][0], pluss[ind][1], pl);
				st.add(pluss[ind][2], pluss[ind][3], pl);
				p++;
			}
			a[ord[i]] = Math.max(st.stand[1]-1, 0);
		}
		for(int i = 0;i < n;i++){
			if(i > 0)out.print(" ");
			out.print(a[i]);
		}
		out.println();
	}
	
	public static long[] radixSort(long[] f)
	{
		long[] to = new long[f.length];
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>16&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>16&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>32&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>32&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>48&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>48&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		return f;
	}
	
	public static class SegmentTreeRSQ {
		public int M, H, N, B;
		public int[] st;
		public int[] plus;
		public int[] stand;
		
		public SegmentTreeRSQ(int n)
		{
			N = n;
			H = Integer.highestOneBit(Math.max(n,1))<<1;
			M = H<<1;
			B = Integer.numberOfTrailingZeros(H);
			st = new int[M];
			plus = new int[H];
			stand = new int[M];
		}
		
		private void propagate(int i)
		{
			int u = H/Integer.highestOneBit(i);
			st[i] = st[2*i]+st[2*i+1]+plus[i]*u;
			if(plus[i] > 0){
				stand[i] = u;
			}else{
				stand[i] = stand[2*i]+stand[2*i+1];
			}
		}
		
		public void add(int f, int t, int v) { add(f, t, v, B); }
		
		protected void add(int f, int t, int v, int b)
		{
			if(b == 0){
				st[H+f] += v;
				stand[H+f] = st[H+f] > 0 ? 1 : 0;
			}else if(f>>b<<b==f && t+1>>b<<b==t+1){
				plus[(H|f)>>b] += v;
				propagate((H+f)>>b);
			}else{
				b--;
				if((f^t)<<31-b<0){
					int w = t>>b<<b;
					add(f, w-1, v, b);
					add(w, t, v, b);
				}else{
					add(f, t, v, b);
				}
				propagate((H|f)>>b+1);
			}
		}
	}
	
	public static int[][] makeRights(int[][] g, int[] par, int root)
	{
		int n = g.length;
		int[] ord = sortByPreorder(g, root);
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[ord[i]] = i;
		
		int[] right = new int[n];
		for(int i = n-1;i >= 0;i--){
			int v = i;
			for(int e : g[ord[i]]){
				if(e != par[ord[i]]){
					v = Math.max(v, right[iord[e]]);
				}
			}
			right[i] = v;
		}
		return new int[][]{ord, iord, right};
	}
	
	public static int[] sortByPreorder(int[][] g, int root){
		int n = g.length;
		int[] stack = new int[n];
		int[] ord = new int[n];
		BitSet ved = new BitSet();
		stack[0] = root;
		int p = 1;
		int r = 0;
		ved.set(root);
		while(p > 0){
			int cur = stack[p-1];
			ord[r++] = cur;
			p--;
			for(int e : g[cur]){
				if(!ved.get(e)){
					stack[p++] = e;
					ved.set(e);
				}
			}
		}
		return ord;
	}
	
	public static int[][] parents(int[][] g, int root)
	{
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);
		
		int[] q = new int[n];
		q[0] = root;
		for(int p = 0, r = 1;p < r;p++) {
			int cur = q[p];
			for(int nex : g[cur]){
				if(par[cur] != nex){
					q[r++] = nex;
					par[nex] = cur;
				}
			}
		}
		return new int[][] {par, q};
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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