//package round161;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] from = new int[2*n];
		int[] to = new int[2*n];
		for(int i = 0;i < 2*n;i++){
			from[i] = ni()-1;
			to[i] = ni()-1;
		}
		if(n == 5){
			out.println("1 2 3 4 5");
			return;
		}
		if(n == 6){
			boolean[][] q = new boolean[6][6];
			for(int i = 0;i < 2*n;i++){
				q[from[i]][to[i]] = q[to[i]][from[i]] = true;
			}
			for(int i = 0;i < n;i++){
				q[i][i] = true;
			}
			
			int[] o = new int[n];
			for(int i = 0;i < n;i++){
				int op = -1;
				for(int j = 0;j < n;j++){
					if(!q[i][j]){
						if(op == -1){
							op = j;
						}else{
							out.println(-1);
							return;
						}
					}
				}
				o[i] = op;
			}
			
			int[] ret = new int[n];
			int p = 0;
			for(int i = 0;i < n;i++){
				if(i < o[i]){
					ret[p] = i; ret[p+3] = o[i];
					p++;
				}
			}
			for(int i = 0;i < n;i++){
				if(i > 0)out.print(" ");
				out.print(ret[i]+1);
			}
			out.println();
			return;
		}
		
		int[][] g = packU(n, from, to);
		for(int[] r : g){
			if(r.length != 4){
				out.println(-1);
				return;
			}
			Arrays.sort(r);
		}
		
		boolean[] ved = new boolean[n];
		int[] hist = new int[n];
		int cur = 0;
		outer:
		for(int step = 0;step < n;step++){
			ved[cur] = true;
			hist[step] = cur;
			if(step == n-1)break;
			for(int x : g[cur]){
				if(!ved[x] && eq(g[x], g[cur]) == 2){
					cur = x;
					continue outer;
				}
			}
			out.println(-1);
			return;
		}
		for(int i = 0;i < n;i++){
			if(i > 0)out.print(" ");
			out.print(hist[i]+1);
		}
		out.println();
		
//		// check
//		for(int i = 0;i < n;i++){
//			int[] u = new int[4];
//			u[0] = hist[(i+1)%n];
//			u[1] = hist[(i+2)%n];
//			u[2] = hist[(i+n-1)%n];
//			u[3] = hist[(i+n-2)%n];
//			Arrays.sort(u);
//			if(!Arrays.equals(u, g[hist[i]])){
//				tr("break", i);
//			}
//		}
	}
	
	static int eq(int[] a, int[] b)
	{
		int ct = 0;
		for(int p = 0, q = 0;p < 4 && q < 4;){
			if(a[p] == b[q]){
				ct++;
				p++; q++;
			}else if(a[p] < b[q]){
				p++;
			}else if(a[p] > b[q]){
				q++;
			}
		}
		return ct;
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
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