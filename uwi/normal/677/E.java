//package round355;
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
	
	double max = Double.NEGATIVE_INFINITY;
	long ret = 0;
	double[] logs = new double[4];
	long[] invs = new long[4];
	
	void solve()
	{
		int n = ni();
		char[][] map = nm(n,n);
		for(int i = 0;i < 4;i++)logs[i] = Math.log(i);
		int mod = 1000000007;
		for(int i = 0;i < 4;i++)invs[i] = invl(i, mod);
		
		int[][] a = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				a[i][j] = map[i][j] - '0';
			}
		}
		boolean zo = true;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(a[i][j] != 0)zo = false;
			}
		}
		if(zo){
			out.println(0);
			return;
		}
		 
		go(a);
		int[][] b = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if((i+j)%2 == 0){
					b[(i+j)/2][(i-j+n)/2] = a[i][j];
				}
			}
		}
		go(b);
		int[][] c = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if((i+j)%2 == 1){
					c[(i+j)/2][(i-j+n)/2] = a[i][j];
				}
			}
		}
		go(c);
		out.println(ret);
	}
	
	void go(int[][] a)
	{
		int n = a.length;
		int mod = 1000000007;
		long[][] mrow = new long[n+1][n];
		double[][] drow = new double[n+1][n];
		Arrays.fill(mrow[0], 1);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				mrow[i+1][j] = mrow[i][j] * Math.max(1, a[i][j]) % mod;
				drow[i+1][j] = drow[i][j] + logs[Math.max(1, a[i][j])];
			}
		}
		long[][] mcol = new long[n][n+1];
		double[][] dcol = new double[n][n+1];
		for(int i = 0;i < n;i++)mcol[i][0] = 1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				mcol[i][j+1] = mcol[i][j] * Math.max(1, a[i][j]) % mod;
				dcol[i][j+1] = dcol[i][j] + logs[Math.max(1, a[i][j])];
			}
		}
		
		int[][] zrow = new int[n+1][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				zrow[i+1][j] = zrow[i][j] + (a[i][j] == 0 ? 1 : 0);
			}
		}
		int[][] zcol = new int[n][n+1];
		for(int i = 0;i < n;i++)zcol[i][0] = 1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				zcol[i][j+1] = zcol[i][j] + (a[i][j] == 0 ? 1 : 0);
			}
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				int lim = Math.min(Math.min(i, n-1-i), Math.min(j, n-1-j));
				int low = 0, high = lim+1;
				if(a[i][j] == 0)continue;
				while(high - low > 1){
					int r = high+low>>>1;
					if(zrow[i+r+1][j] - zrow[i-r][j] > 0 || zcol[i][j+r+1]-zcol[i][j-r] > 0){
						high = r;
					}else{
						low = r;
					}
				}
				int r = low;
				double val = drow[i+r+1][j] - drow[i-r][j] + dcol[i][j+r+1] - dcol[i][j-r] - logs[a[i][j]];
				if(val > max){
					max = val;
					ret = mrow[i+r+1][j] * invl(mrow[i-r][j], mod) % mod * mcol[i][j+r+1] % mod * invl(mcol[i][j-r], mod) % mod * invs[a[i][j]] % mod;
				}
			}
		}
	}
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}

	
	void run() throws Exception
	{
//		int n = 1000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			for(int j = 0;j < n;j++){
//				sb.append(gen.nextInt(3)+1);
//			}
//			sb.append("\n");
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