//package round227;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] from = new int[m];
		int[] to = new int[m];
		for(int i = 0;i < m;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		int[] nfrom = new int[m];
		int[] nto = new int[m];
		int min = 999999999;
		for(int i = 0;i < n;i++){
			int p = 0;
			for(int j = 0;j < m;j++){
				if(from[j] != i && to[j] != i){
					nfrom[p] = from[j];
					nto[p] = to[j];
					p++;
				}
			}
			int[][] g = packD(n, nfrom, nto, p);
			int mat = doBipartiteMatchingHKNoRec(g, n);
			
			int ch = p - mat + (n-1-mat);
			ch += 2*n-1 - (m - p); 
			min = Math.min(min, ch);
		}
		out.println(min);
	}
	
	public static int doBipartiteMatchingHKNoRec(int[][] g, int m)
	{
		int n = g.length;
		if(n == 0)return 0;
		int[] from = new int[m];
		int[] to = new int[n];
		Arrays.fill(to, -1);
		Arrays.fill(from, n);
		
		int[] d = new int[n+1];
		int mat = 0;
		int[] stack = new int[n+1];
		int[] adjind = new int[n+1];
		while(true){
			Arrays.fill(d, -1);
			int[] q = new int[n];
			int r = 0;
			for(int i = 0;i < n;i++){
				if(to[i] == -1){
					d[i] = 0;
					q[r++] = i;
				}
			}
			
			for(int p = 0;p < r;p++) {
				int cur = q[p];
				for(int adj : g[cur]){
					int nex = from[adj];
					if(d[nex] == -1) {
						if(nex != n)q[r++] = nex;
						d[nex] = d[cur] + 1;
					}
				}
			}
			if(d[n] == -1)break;
			
			for(int i = 0;i < n;i++){
				if(to[i] == -1){
					int sp = 1;
					stack[0] = i;
					adjind[0] = 0;
					boolean prevB = false;
					outer:
					while(sp >= 1){
						int cur = stack[sp-1];
						if(cur == n){
							prevB = true;
							sp--;
							continue;
						}
						for(;adjind[sp-1] < 2*g[cur].length;){
							int adj = g[cur][adjind[sp-1]/2];
							if(adjind[sp-1] % 2 == 0){
								int nex = from[adj];
								if(d[nex] == d[cur] + 1){
									stack[sp] = nex;
									adjind[sp] = 0;
									adjind[sp-1]++;
									sp++;
									continue outer;
								}else{
									adjind[sp-1]+=2;
								}
							}else{
								if(prevB){
									to[cur] = adj;
									from[adj] = cur;
									prevB = true;
									sp--;
									continue outer;
								}
								adjind[sp-1]++;
							}
						}
						d[cur] = -1;
						prevB = false;
						sp--;
					}
					if(prevB)mat++;
				}
			}
		}
		
		return mat;
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
	
	void run() throws Exception
	{
//		int n = 500, m = 1000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		boolean[][] g = new boolean[n][n];
//		for(int i = 0;i < m;i++){
//			while(true){
//				int r = gen.nextInt(n);
//				int c = gen.nextInt(n);
//				if(!g[r][c]){
//					g[r][c] = true;
//					break;
//				}
//			}
//		}
//		for(int i = 0;i < n;i++){
//			for(int j = 0;j < n;j++){
//				if(g[i][j]){
//					sb.append((i+1) + " ");
//					sb.append((j+1) + " ");
//				}
//			}
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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