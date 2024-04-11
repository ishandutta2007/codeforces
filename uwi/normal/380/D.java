//package round222;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int mod = 1000000007;
	int[][] fif = enumFIF(100005, mod);
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[][] rese = new int[n][];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(a[i] != 0){
				rese[p++] = new int[]{a[i], i};
			}
		}
		if(p == 0){
			out.println(pow(2, n-1, mod));
			return;
		}
		Arrays.sort(rese, 0, p, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		if(rese[0][0] == 1){
			long[] ft = buildFenwick(a);
			out.println(go(rese, p, n, ft));
			return;
		}else{
			int num = rese[0][0];
			int pos = rese[0][1];
			long ret = 0;
			if(pos-num+1 >= 0){
				boolean ok = true;
				for(int i = pos-num+1;i < pos;i++){
					if(a[i] != 0)ok = false;
				}
				if(ok){
					a[pos-num+1] = 1;
					int[][] drese = Arrays.copyOf(rese, p+1);
					drese[p] = new int[]{1, pos-num+1};
					Arrays.sort(drese, 0, p+1, new Comparator<int[]>() {
						public int compare(int[] a, int[] b) {
							return a[0] - b[0];
						}
					});
					long[] ft = buildFenwick(a);
					ret += go(drese, p+1, n, ft) * pow(2, num-2, mod) % mod;
					a[pos-num+1] = 0;
				}
			}
			if(pos+num-1 < n){
				boolean ok = true;
				for(int i = pos+1;i <= pos+num-1;i++){
					if(a[i] != 0)ok = false;
				}
				if(ok){
					a[pos+num-1] = 1;
					int[][] drese = Arrays.copyOf(rese, p+1);
					drese[p] = new int[]{1, pos+num-1};
					Arrays.sort(drese, 0, p+1, new Comparator<int[]>() {
						public int compare(int[] a, int[] b) {
							return a[0] - b[0];
						}
					});
					long[] ft = buildFenwick(a);
					ret += go(drese, p+1, n, ft) * pow(2, num-2, mod) % mod;
					a[pos+num-1] = 0;
				}
			}
			out.println(ret%mod);
		}
	}
	
	long go(int[][] rese, int p, int n, long[] ft)
	{
		long ret = 1;
		int left = rese[0][1];
		int right = rese[0][1];
		long lsum = 1;
		for(int i = 1;i < p;i++){
			int num = rese[i][0];
			int pos = rese[i][1];
			if(Math.abs(pos-right) > num-rese[i-1][0] && Math.abs(pos-left) > num-rese[i-1][0]){
				return 0L;
			}
			
			int ex = 0;
			int nleft = Math.min(left, pos);
			int nright = Math.max(right, pos);
			if(pos < left){
				nright += num-rese[i-1][0]-Math.abs(left-pos);
				ex = Math.abs(left-pos)-1;
			}else{
				nleft -= num-rese[i-1][0]-Math.abs(right-pos);
				ex = Math.abs(right-pos)-1;
			}
			if(nleft < 0 || nright >= n){
				return 0L;
			}
			lsum += num;
			if(sumFenwick(ft, nright) - sumFenwick(ft, nleft-1) != lsum){
				return 0L;
			}
			left = nleft;
			right = nright;
			ret = ret * C(num-rese[i-1][0]-1, ex) % mod;
		}
		ret = ret * C(left+(n-1-right), left) % mod;
		return ret;
	}
	
	public static long[] buildFenwick(int[] a)
	{
		int n = a.length;
		long[] ft = new long[n+1];
		for(int i = 0;i < n;i++){
			ft[1+i] = a[i];
		}
//		System.arraycopy(a, 0, ft, 1, n);
		for(int k = 2, h = 1;k <= n;k*=2, h*=2){
			for(int i = k;i <= n;i+=k){
				ft[i] += ft[i-h];
			}
		}
		return ft;
	}
	
	public static long sumFenwick(long[] ft, int i)
	{
		long sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(long[] ft, int i, long v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public long C(int n, int r)
	{
		if(n < 0 || r < 0 || r > n)return 0;
		return (long)fif[0][n]*fif[1][r]%mod*fif[1][n-r]%mod;
	}
	
	public static int[][] enumFIF(int n, int mod)
	{
		int[] f = new int[n+1];
		int[] invf = new int[n+1];
		f[0] = 1;
		for(int i = 1;i <= n;i++){
			f[i] = (int)((long)f[i-1] * i % mod);
		}
		long a = f[n];
		long b = mod;
		long p = 1, q = 0;
		while(b > 0){
			long c = a / b;
			long d;
			d = a; a = b; b = d % b;
			d = p; p = q; q = d - c * q;
		}
		invf[n] = (int)(p < 0 ? p + mod : p);
		for(int i = n-1;i >= 0;i--){
			invf[i] = (int)((long)invf[i+1] * (i+1) % mod);
		}
		return new int[][]{f, invf};
	}
	
	public static long pow(long a, long n, long mod)
	{
//		a %= mod;
		long ret = 1;
		int x = 63-Long.numberOfLeadingZeros(n);
		for(;x >= 0;x--){
			ret = ret * ret % mod;
			if(n<<63-x<0)ret = ret * a % mod;
		}
		return ret;
	}
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		int[] a = new int[n];
//		a[gen.nextInt(n)] = gen.nextInt(n)+1;
//		for(int i = 0;i < n;i++){
//			sb.append(a[i] + " ");
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