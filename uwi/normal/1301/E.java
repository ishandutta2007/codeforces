//package round619;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.function.IntPredicate;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), Q = ni();
		char[][] map = nm(n,m);
		int[][][] colors = new int[4][][];
		colors[0] = cum(map, (x) -> x == 'R');
		colors[1] = cum(map, (x) -> x == 'G');
		colors[2] = cum(map, (x) -> x == 'Y');
		colors[3] = cum(map, (x) -> x == 'B');
		
		int[][] rd = down(map, (x) -> x == 'R');
		int[][] rr = trans(down(trans(map), (x) -> x == 'R'));
		int[][] hs = new int[n][m];
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				if(rd[i][j] > 0 && rd[i][j] == rr[i][j]) {
					int u = rd[i][j];
					if(
							i+2*u <= n && j+2*u <= m &&
							sum(colors[0], i, j, i+u, j+u) == u*u && 
							sum(colors[1], i, j+u, i+u, j+2*u) == u*u && 
							sum(colors[2], i+u, j, i+2*u, j+u) == u*u && 
							sum(colors[3], i+u, j+u, i+2*u, j+2*u) == u*u
							) {
						hs[i][j] = u;
					}
				}
			}
		}
		
		int[][][] cums = new int[251][][];
		for(int i = 1;i <= 250;i++) {
			int ii = i;
			cums[i] = cum(hs, (x) -> x == ii);
		}
		
		for(int z = 0;z < Q;z++) {
			int r1 = ni()-1, c1 = ni()-1;
			int r2 = ni()-1, c2 = ni()-1;
			int low = 0, high = 251;
			while(high - low > 1) {
				int h = high+low>>1;
				if(sum(cums[h], r1, c1, r2+1-2*h+1, c2+1-2*h+1) > 0) {
					low = h;
				}else {
					high = h;
				}
			}
			out.println(low*low*4);
		}
	}
	
	public static long sum(int[][] cum, int r1, int c1, int r2, int c2)
	{
		if(r1 >= r2 || c1 >= c2)return 0;
		return cum[r2][c2] + cum[r1][c1] - cum[r1][c2] - cum[r2][c1];
	}
	
	public static int[][] down(char[][] map, IntPredicate pr)
	{
		int n = map.length, m = map[0].length;
		int[][] ret = new int[n][m];
		for(int i = n-1;i >= 0;i--){
			for(int j = 0;j < m;j++){
				ret[i][j] = i == n-1 ? 1 : ret[i+1][j] + 1;
				if(!pr.test(map[i][j]))ret[i][j] = 0;
			}
		}
		return ret;
	}
	
	public static char[][] trans(char[][] a)
	{
		if(a.length == 0)return new char[0][0];
		int n = a.length, m = a[0].length;
		char[][] ret = new char[m][n];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				ret[i][j] = a[j][i];
			}
		}
		return ret;
	}

	public static int[][] trans(int[][] a)
	{
		if(a.length == 0)return new int[0][0];
		int n = a.length, m = a[0].length;
		int[][] ret = new int[m][n];
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				ret[i][j] = a[j][i];
			}
		}
		return ret;
	}


	
	public static int[][] cum(char[][] a, IntPredicate pr)
	{
		int n = a.length, m = a[0].length;
        int[][] cum = new int[n+1][m+1];
        for(int i = 0;i < n;i++){
        	for(int j = 0;j < m;j++){
        		cum[i+1][j+1] = cum[i+1][j] + cum[i][j+1] - cum[i][j] + (pr.test(a[i][j]) ? 1 : 0);
        	}
        }
        return cum;
	}

	public static int[][] cum(int[][] a, IntPredicate pr)
	{
		int n = a.length, m = a[0].length;
        int[][] cum = new int[n+1][m+1];
        for(int i = 0;i < n;i++){
        	for(int j = 0;j < m;j++){
        		cum[i+1][j+1] = cum[i+1][j] + cum[i][j+1] - cum[i][j] + (pr.test(a[i][j]) ? 1 : 0);
        	}
        }
        return cum;
	}

	
	void run() throws Exception
	{
//		int n = 500, m = 500, Q = 300000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		sb.append(Q + " ");
//		for (int i = 0; i < n; i++) {
//			for (int j = 0;j < m;j++) {
//				sb.append("RBGY".charAt(gen.nextInt(4)));
//			}
//			sb.append("\n");
//		}
//		for(int i = 0;i < Q;i++) {
//			int v1 = gen.nextInt(n);
//			int v2 = gen.nextInt(n);
//			int w1 = gen.nextInt(m);
//			int w2 = gen.nextInt(m);
//			sb.append(Math.min(v1, v2) + 1 + " ");
//			sb.append(Math.min(w1, w2) + 1 + " ");
//			sb.append(Math.max(v1, v2) + 1 + " ");
//			sb.append(Math.max(w1, w2) + 1 + " ");
//		}
//		INPUT = sb.toString();

		
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