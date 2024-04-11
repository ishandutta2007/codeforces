//package educational.round02;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int D;
	
	int[][] doEdgeColoring(boolean[][] g)
	{
		int n = g.length, m = g[0].length;
		D = 0; // maxdeg
		for(int i = 0;i < n;i++){
			int ld = 0;
			for(int j = 0;j < m;j++)if(g[i][j])ld++;
			if(ld > D)D = ld;
		}
		for(int j = 0;j < m;j++){
			int ld = 0;
			for(int i = 0;i < n;i++)if(g[i][j])ld++;
			if(ld > D)D = ld;
		}
		
		int[][] ltocolor = new int[n][D]; // [l][color] = r
		int[][] rtocolor = new int[m][D]; // [r][color] = l 
		int[][] color = new int[n][m]; // [l][r] = color
		
		for(int i = 0;i < n;i++)Arrays.fill(color[i], -1);
		for(int i = 0;i < n;i++)Arrays.fill(ltocolor[i], -1);
		for(int i = 0;i < m;i++)Arrays.fill(rtocolor[i], -1);
		
		boolean[] vedf = new boolean[n];
		boolean[] vedt = new boolean[m];
		int[] routet = new int[n+m];
		for(int f = 0;f < n;f++){
			for(int t = 0;t < m;t++){
				if(g[f][t]){
					int cf = -1, ct = -1;
					for(int j = 0;j < D;j++){
						if(ltocolor[f][j] == -1){
							cf = j;
							break;
						}
					}
					for(int j = 0;j < D;j++){
						if(rtocolor[t][j] == -1){
							ct = j;
							break;
						}
					}
					if(cf == ct){
						color[f][t] = cf;
						ltocolor[f][cf] = t;
						rtocolor[t][cf] = f;
					}else{
						// alternating path
						int rtp = 0;
						routet[rtp++] = f;
						routet[rtp++] = t;
						vedf[f] = true;
						vedt[t] = true;
						while(true){
							// t->nf mf->mt
							int lr = routet[rtp-1];
							if(rtocolor[lr][cf] == -1 || vedf[rtocolor[lr][cf]])break;
							routet[rtp++] = rtocolor[lr][cf];
							vedf[routet[rtp-1]] = true;
							
							int ll = routet[rtp-1];
							if(ltocolor[ll][ct] == -1 || vedt[ltocolor[ll][ct]])break;
							routet[rtp++] = ltocolor[ll][ct];
							vedt[routet[rtp-1]] = true;
						}
						
						for(int j = 0;j < rtp-1;j++){
							if((j&1) == 1){ // r->l cf->ct
								color[routet[j+1]][routet[j]] = ct;
								ltocolor[routet[j+1]][cf] = -1;
								ltocolor[routet[j+1]][ct] = routet[j];
								rtocolor[routet[j]][ct] = routet[j+1];
							}else{ // l->r ct->cf
								color[routet[j]][routet[j+1]] = cf;
								ltocolor[routet[j]][cf] = routet[j+1];
								rtocolor[routet[j+1]][ct] = -1;
								rtocolor[routet[j+1]][cf] = routet[j];
							}
						}
						
						vedf[f] = false;
						for(int j = 0;j < rtp;j++){
							if((j&1) == 1){
								vedt[routet[j]] = false;
							}else{
								vedf[routet[j]] = false;
							}
						}
					}
				}
			}
		}
		return color;
	}
	
	void solve()
	{
		int n = ni(), m = ni(), e = ni();
		int[] from = new int[e];
		int[] to = new int[e];
		boolean[][] g = new boolean[n][m];
		for(int i = 0;i < e;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
			g[from[i]][to[i]] = true;
		}
		int[][] color = doEdgeColoring(g);
		
//		verify(color, g);
		
		out.println(D);
		for(int i = 0;i < e;i++){
			out.print((color[from[i]][to[i]]+1) + " ");
		}
	}
	
	void verify(int[][] color, boolean[][] g)
	{
		int n = g.length;
		int m = g[0].length;
		boolean[][] lc = new boolean[n][n+m];
		boolean[][] rc = new boolean[m][n+m];
		boolean[] ac = new boolean[D];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(g[i][j]){
					assert 0 <= color[i][j];
					assert color[i][j] < D;
					assert !lc[i][color[i][j]];
					lc[i][color[i][j]] = true;
					assert !rc[j][color[i][j]];
					rc[j][color[i][j]] = true;
					ac[color[i][j]] = true;
				}else{
					assert color[i][j] == -1;
				}
			}
		}
		for(int i = 0;i < D;i++){
			assert ac[i];
		}
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
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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