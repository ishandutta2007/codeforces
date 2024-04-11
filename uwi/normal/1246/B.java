//package round596;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] lpf = enumLowestPrimeFactors(100000);
		int[] a = na(n);
		int[][] fs = new int[n][];
		for(int i = 0;i < n;i++){
			int[][] f = factorFast(a[i], lpf);
			int p = 0;
			for(int j = 0;j < f.length;j++){
				f[j][1] %= K;
				if(f[j][1] > 0){
					f[p++] = f[j];
				}
			}
			int[] flat = new int[2*p];
			for(int j = 0;j < p;j++){
				flat[2*j] = f[j][0];
				flat[2*j+1] = f[j][1];
			}
			fs[i] = flat;
		}
		Arrays.sort(fs, comp);
		
		long ans = 0;
		for(int i = 0;i < n;i++){
			int[] f = fs[i];
			int[] rf = Arrays.copyOf(f, f.length);
			for(int j = 1;j < f.length;j+=2){
				rf[j] = K - f[j];
			}
			int[] rfx = Arrays.copyOf(rf, rf.length+1);
			int high = lowerBound(fs, rfx);
			int low = lowerBound(fs, rf);
			ans += high - low;
			if(low <= i && i < high){
				ans--;
			}
		}
		out.println(ans/2);
	}
	
	Comparator<int[]> comp = new Comparator<int[]>() {
		public int compare(int[] a, int[] b) {
			for(int i = 0;i < a.length && i < b.length;i++){
				if(a[i] != b[i]){
					return a[i] - b[i];
				}
			}
			return a.length - b.length;
		}
	};
	
	public int lowerBound(int[][] a, int[] v)
	{
		int low = -1, high = a.length;
		while(high-low > 1){
			int h = high+low>>>1;
			if(comp.compare(a[h], v) >= 0){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
	}

	
	public static int[][] factorFast(int n, int[] lpf)
	{
		int[][] f = new int[9][];
		int q = 0;
		while(lpf[n] > 0){
			int p = lpf[n];
			if(q == 0 || p != f[q-1][0]){
				f[q++] = new int[]{p, 1};
			}else{
				f[q-1][1]++;
			}
			n /= p;
		}
		if(n > 1){
			// big prime
			return new int[][]{{n, 1}};
		}
		return Arrays.copyOf(f, q);
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
//		int n = 100000, m = 50;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(100000)+1 + " ");
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