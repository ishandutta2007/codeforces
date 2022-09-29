//package hello2019;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int X = 7005;
		int[][] ds = new int[X][X];
		int[] dsp = new int[X];
		for(int i = 1;i < X;i++) {
			for(int j = i;j < X;j+=i) {
				ds[j][dsp[j]++] = i;
			}
		}
		for(int i = 0;i < X;i++)ds[i] = Arrays.copyOf(ds[i], dsp[i]);
		
		int M = 7000/64+2;
		long[][] ms = new long[n][M];
		
		int[] lpf = enumLowestPrimeFactors(X);
		int[] mob = enumMobiusByLPF(X, lpf);
		long[][] filters = new long[X][M];
		for(int i = X-1;i >= 1;i--) {
			for(int j = i;j < X;j+=i) {
				if(mob[j/i] != 0) {
					filters[i][j>>>6] |= 1L<<j;
				}
			}
		}
		
		for(int o = 0;o < Q;o++) {
			int type = ni();
			if(type == 1) {
				int x = ni()-1;
				int v = ni();
				long[] row = new long[M];
				for(int d : ds[v]) {
					row[d>>>6] |= 1L<<d;
				}
				ms[x] = row;
			}else if(type == 2) {
				int x = ni()-1, y = ni()-1, z = ni()-1;
				long[] row = new long[M];
				for(int j = 0;j < M;j++) {
					row[j] = ms[y][j] ^ ms[z][j];
				}
				ms[x] = row;
			}else if(type == 3) {
				int x = ni()-1, y = ni()-1, z = ni()-1;
				long[] row = new long[M];
				for(int j = 0;j < M;j++) {
					row[j] = ms[y][j] & ms[z][j];
				}
				ms[x] = row;
			}else if(type == 4) {
				int x = ni()-1, v = ni();
				int ans = 0;
				for(int i = 0;i < M;i++) {
					ans ^= Long.bitCount(ms[x][i]&filters[v][i]);
				}
				out.print(ans&1);
			}
//			for(int q = 0;q < n;q++) {
//				long[] u = ms[q];
//				tr(Long.toBinaryString(u[0]));
//			}
//			tr();
		}
		out.println();
	}
	
	public static int[] enumMobiusByLPF(int n, int[] lpf)
	{
		int[] mob = new int[n+1];
		mob[1] = 1;
		for(int i = 2;i <= n;i++){
			int j = i/lpf[i];
			if(lpf[j] == lpf[i]){
//				mob[i] = 0;
			}else{
				mob[i] = -mob[j];
			}
		}
		return mob;
	}

	
	public static int[] enumLowestPrimeFactors(int n) {
		int tot = 0;
		int[] lpf = new int[n + 1];
		int u = n + 32;
		double lu = Math.log(u);
		int[] primes = new int[(int) (u / lu + u / lu / lu * 1.5)];
		for (int i = 2; i <= n; i++)
			lpf[i] = i;
		for (int p = 2; p <= n; p++) {
			if (lpf[p] == p)
				primes[tot++] = p;
			int tmp;
			for (int i = 0; i < tot && primes[i] <= lpf[p] && (tmp = primes[i] * p) <= n; i++) {
				lpf[tmp] = primes[i];
			}
		}
		return lpf;
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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