//package round618;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = na(2);
		}
		
		int[][] rco = new int[n][];
		for(int i = 0;i < n;i++){
			rco[i] = new int[]{-co[i][0], -co[i][1]};
		}
		
		int[][] vs = new int[2*n][];
		for(int i = 0;i < n;i++){
			int j = (i+1) % n;
			vs[i] = new int[]{co[j][0] - co[i][0], co[j][1] - co[i][1]};
			vs[i+n] = new int[]{rco[j][0] - rco[i][0], rco[j][1] - rco[i][1]};
		}
		Arrays.sort(vs, compArgi);
		
		long[] lens = new long[n];
		int p = 0;
		for(int i = 0;i < 2*n;){
			int j = i;
			while(j < 2*n && compArgi.compare(vs[i], vs[j]) == 0){
				j++;
			}
			long x = 0, y = 0;
			for(int k = i;k < j;k++){
				x += vs[k][0];
				y += vs[k][1];
			}
			if(p >= n){
				out.println("NO");
				return;
			}
			BigInteger X = BigInteger.valueOf(x);
			BigInteger Y = BigInteger.valueOf(y);
			BigInteger M = X.multiply(X).add(Y.multiply(Y));
			if(M.testBit(1) || M.testBit(0)){
				out.println("NO");
				return;
			}
			lens[p++] = M.shiftRight(2).longValue();
			
			i = j;
		}
		if(p < n){
			out.println("NO");
			return;
		}
		
		long[] olen = new long[n];
		for(int i = 0;i < n;i++){
			int j = (i+1) % n;
			long dx = co[j][0] - co[i][0];
			long dy = co[j][1] - co[i][1];
			olen[i] = dx*dx+dy*dy;
		}
		
		long[] hey = new long[3*n];
		for(int i = 0;i < n;i++){
			hey[i] = olen[i];
			hey[i+n] = hey[i+2*n] = lens[i];
		}
		int[] z = Z(hey);
		for(int i = n;i < 3*n;i++){
			if(z[i] >= n){
				out.println("YES");
				return;
			}
		}
		out.println("NO");
	}
	
	public static int[] Z(long[] str)
	{
		int n = str.length;
		int[] z = new int[n];
		if(n == 0)return z;
		z[0] = n;
		int l = 0, r = 0;
		for(int i = 1;i < n;i++){
			if(i > r){
				l = r = i;
				while(r < n && str[r-l] == str[r])r++;
				z[i] = r-l; r--;
			}else{
				if(z[i-l] < r-i+1){
					z[i] = z[i-l];
				}else{
					l = i;
					while(r < n && str[r-l] == str[r])r++;
					z[i] = r-l; r--;
				}
			}
		}
		
		return z;
	}

	
	public static Comparator<int[]> compArgi = new Comparator<int[]>(){
		public int compare(int[] a, int[] b)
		{
			long ax = a[0], ay = a[1];
			long bx = b[0], by = b[1];
			int za = ay > 0 || ay == 0 && ax > 0 ? 0 : 1;
			int zb = by > 0 || by == 0 && bx > 0 ? 0 : 1;
			if(za != zb)return za - zb;
			if(ay*bx-ax*by != 0)return Long.signum(ay*bx-ax*by);
			return 0;
//			return Long.signum((ax*ax+ay*ay)-(bx*bx+by*by));
		}
	};

	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append((gen.nextInt(200000000)-100000000) * 2 + " ");
//			sb.append((gen.nextInt(200000000)-100000000) * 2 + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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