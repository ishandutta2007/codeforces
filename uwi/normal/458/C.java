//package memsql2014.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] from = new int[n];
		int[] to = new int[n];
		int[] w = new int[n];
		for(int i = 0;i < n;i++){
			from[i] = ni();
			to[i] = i;
			w[i] = ni();
		}
		int M = 100001;
		int[][][] g = packWD(M, from, to, w);
		for(int[][] row : g){
			Arrays.sort(row, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[1] - b[1];
				}
			});
		}
		
		int[][] vs = new int[n][];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(from[i] > 0){
				vs[p++] = new int[]{w[i], i};
			}
		}
		Arrays.sort(vs, 0, p, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int[] ivs = new int[n];
		Arrays.fill(ivs, -1);
		for(int i = 0;i < p;i++)ivs[vs[i][1]] = i;
		
		int[] ft = new int[p+1];
		int[] ftb = new int[p+1];
		for(int i = 0;i < p;i++){
			addFenwick(ft, i, 1);
			addFenwick(ftb, i, vs[i][0]);
		}
		int got = g[0].length;
		
		int[][] glen = new int[M-1][];
		for(int i = 1;i < M;i++){
			glen[i-1] = new int[]{g[i].length, i};
		}
		Arrays.sort(glen, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[0] - b[0]);
			}
		});
		
		int[] toget = new int[100002];
		int[] kill = new int[100002];
		for(int i = 1;i < M;i++){
			int L = g[i].length;
			for(int j = 0;j < g[i].length;j++){
				toget[L-j] += g[i][j][1];
				kill[L-j]++;
			}
		}
		for(int i = 100000;i >= 0;i--){
			toget[i] += toget[i+1];
			kill[i] += kill[i+1];
		}
		
		int all = p;
		int min = Integer.MAX_VALUE;
		for(int t = 100001;t >= got;t--){
			if(t == 0)break;
			for(int j = 0;j < glen.length && glen[j][0] >= t;j++){
//				tr(glen[j][0], t);
				int ind = glen[j][0]-t;
				addFenwick(ft, ivs[g[glen[j][1]][ind][0]], -1);
				addFenwick(ftb, ivs[g[glen[j][1]][ind][0]], -g[glen[j][1]][ind][1]);
				all--;
			}
			
			int rem = t - kill[t] - got;
			int bribe = toget[t];
//			if(t < 10){
//				tr("rem", t, rem);
//				tr(restoreFenwick(ft));
//				tr(restoreFenwick(ftb));
//			}
			if(rem > 0){
				if(all < rem)continue;
				int ind = findGFenwick(ft, rem);
				bribe += sumFenwick(ftb, ind);
			}
//			tr(t, bribe, toget[t]);
			min = Math.min(min, bribe);
			
		}
		out.println(min);
	}
	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0 || i < 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int findGFenwick(int[] ft, int v)
	{
		int i = 0;
		int n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0 && i < n;b >>= 1){
			if(i + b < n){
				int t = i + b;
				if(v >= ft[t]){
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i+1) : i-1;
	}
	
	public static int[][][] packWD(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]][2];
		for (int i = 0; i < from.length; i++) {
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
		}
		return g;
	}
	
	static int[][] packD(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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