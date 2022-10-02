//package round198;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		long[][][][] ft = new long[2][2][n/2+2][n/2+2];
		
		for(int q = 0;q < Q;q++){
			int t = ni();
			if(t == 2){
				int x0 = ni()-1, y0 = ni()-1, x1 = ni()-1, y1 = ni()-1;
				long v = nl();
				
				if((x1-x0+1)%2 == 0){
					if((y1-y0+1)%2 == 0){
						addFenwick(ft[x0&1][y0&1], x0/2, y0/2, v);
						addFenwick(ft[x0&1][y0&1], x0/2, (y1+1)/2, v);
						addFenwick(ft[x0&1][y0&1], (x1+1)/2, y0/2, v);
						addFenwick(ft[x0&1][y0&1], (x1+1)/2, (y1+1)/2, v);
					}else{
						addFenwick(ft[x0&1][y0&1], x0/2, y0/2, v);
						addFenwick(ft[x0&1][y0&1], (x1+1)/2, y0/2, v);
						addFenwick(ft[x0&1][y0&1^1], x0/2, (y1+1)/2, v);
						addFenwick(ft[x0&1][y0&1^1], (x1+1)/2, (y1+1)/2, v);
					}
				}else{
					if((y1-y0+1)%2 == 0){
						addFenwick(ft[x0&1][y0&1], x0/2, y0/2, v);
						addFenwick(ft[x0&1][y0&1], x0/2, (y1+1)/2, v);
						addFenwick(ft[x0&1^1][y0&1], (x1+1)/2, y0/2, v);
						addFenwick(ft[x0&1^1][y0&1], (x1+1)/2, (y1+1)/2, v);
					}else{
						addFenwick(ft[x0&1][y0&1], x0/2, y0/2, v);
						addFenwick(ft[x0&1^1][y0&1], (x1+1)/2, y0/2, v);
						addFenwick(ft[x0&1][y0&1^1], x0/2, (y1+1)/2, v);
						addFenwick(ft[x0&1^1][y0&1^1], (x1+1)/2, (y1+1)/2, v);
					}
				}
//				tr(x0, y0, x1, y1, v);
//				for(long[] u : restoreFenwick(ft[0][0])){
//					tr(u);
//				}
//				tr();
//				for(long[] u : restoreFenwick(ft[0][1])){
//					tr(u);
//				}
//				tr();
//				for(long[] u : restoreFenwick(ft[1][0])){
//					tr(u);
//				}
//				tr();
//				for(long[] u : restoreFenwick(ft[1][1])){
//					tr(u);
//				}
//				tr();
			}else{
				int x0 = ni()-1, y0 = ni()-1, x1 = ni()-1, y1 = ni()-1;
				x0--; y0--;
				out.println(
						(x0 >= 0 && y0 >= 0 ? sumFenwick(ft[x0&1][y0&1], x0/2, y0/2) : 0) ^ 
						(x0 >= 0 ? sumFenwick(ft[x0&1][y1&1], x0/2, y1/2) : 0) ^
						(y0 >= 0 ? sumFenwick(ft[x1&1][y0&1], x1/2, y0/2) : 0) ^
						sumFenwick(ft[x1&1][y1&1], x1/2, y1/2)
						);
			}
		}
	}
	
	public static long[][] restoreFenwick(long[][] ft)
	{
		int n = ft.length-1;
		int m = ft[0].length-1;
		long[][] ret = new long[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				ret[i][j] = sumFenwick(ft, i, j);
			}
		}
		for(int i = n-1;i >= 0;i--){
			for(int j = m-1;j >= 0;j--){
				if(j-1 >= 0)ret[i][j] ^= ret[i][j-1];
				if(i-1 >= 0)ret[i][j] ^= ret[i-1][j];
				if(i-1 >= 0 && j-1 >= 0)ret[i][j] ^= ret[i-1][j-1];
			}
		}
		return ret;
	}
		
	public static long sumFenwick(long[][] ft, int r, int c)
	{
		long sum = 0;
		r++; c++;
		for(int rr = r;rr > 0;rr -= rr&-rr){
			for(int cc = c;cc > 0;cc -= cc&-cc){
				sum ^= ft[rr][cc];
			}
		}
		return sum;
	}
	
	public static void addFenwick(long[][] ft, int r, int c, long v)
	{
		if(v == 0)return;
		int R = ft.length;
		int C = ft[0].length;
		r++; c++;
		for(int rr = r;rr < R;rr += rr&-rr){
			for(int cc = c;cc < C;cc += cc&-cc){
				ft[rr][cc] ^= v;
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
	
	public static void main(String[] args) throws Exception { new D3().run(); }
	
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