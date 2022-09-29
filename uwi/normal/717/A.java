//package bubblecup9f;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class A5 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	final int mod = 1000000007;
	
	public static int[][] enumFIF(int n, int mod) {
		int[] f = new int[n + 1];
		int[] invf = new int[n + 1];
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			f[i] = (int) ((long) f[i - 1] * i % mod);
		}
		long a = f[n];
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
		invf[n] = (int) (p < 0 ? p + mod : p);
		for (int i = n - 1; i >= 0; i--) {
			invf[i] = (int) ((long) invf[i + 1] * (i + 1) % mod);
		}
		return new int[][] { f, invf };
	}

	
	void solve()
	{
		int K = ni();
		long L = nl(), R = nl();
		
		int[][] fif = enumFIF(K+2, mod);
		
		long[][] fs = new long[K+1][K+1];
		fs[0][0] = fif[1][K];
		for(int i = 0;i < K;i++){
			for(int j = 0;j <= i;j++){
				fs[i+1][j+1] += fs[i][j];
				if(fs[i+1][j+1] >= mod)fs[i+1][j+1] -= mod;
				fs[i+1][j] += fs[i][j] * (mod-i);
				fs[i+1][j] %= mod;
			}
		}
		
		long ret = count(R+1, fs[K], fif) - count(L, fs[K], fif);
		if(ret < 0)ret += mod;
		out.println(ret);
	}
	
	long count(long n, long[] fs, int[][] fif)
	{
		long ret = 0;
		for(int i = 0;i < fs.length;i++){
			ret += fpowsum(i, n, mod, fif) * fs[i];
			ret %= mod;
		}
		return ret;
	}
	
	long fpowsum(int K, long n, int mod, int[][] fif)
	{
		Exmod plus = Exmod.div(new Exmod(1,1),2);
		Exmod[] pluss = new Exmod[K+1];
		pluss[0] = new Exmod(1);
		for(int i = 1;i <= K;i++)pluss[i] = Exmod.mul(pluss[i-1], plus);
		
		Exmod minus = Exmod.div(new Exmod(1,-1),2);
		Exmod[] minuss = new Exmod[K+1];
		minuss[0] = new Exmod(1);
		for(int i = 1;i <= K;i++)minuss[i] = Exmod.mul(minuss[i-1], minus);
		
		Exmod ret = new Exmod(0);
		for(int i = K, sig = 1;i >= 0;i--, sig = -sig){
			Exmod ratio = Exmod.mul(pluss[i], minuss[K-i]);
			ret.add(Exmod.mul(Exmod.sumgp(ratio, n+2), C(K, i, mod, fif) * sig));
		}
		
		Exmod fifth = Exmod.pow(Exmod.inv(new Exmod(0, 1)), K);
		ret.mul(fifth);
		
		assert ret.b == 0;
		return ret.a;
	}
	
	public static long C(int n, int r, int mod, int[][] fif) {
		if (n < 0 || r < 0 || r > n)
			return 0;
		return (long) fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod;
	}
	
	public static class Exmod {
		public long a, b;
		public static final long E = 5;
		public static final int mod = 1000000007;
		
		@Override
		public String toString() {
			if(a == 0 && b == 0)return "0";
			StringBuilder ret = new StringBuilder();
			if(a != 0){
				ret.append(a);
				if(b > 0)ret.append("+");
			}
			if(b != 0)ret.append(b + "" + E);
			return ret.toString();
		}

		public Exmod(long a) {
			this.a = a;
			this.b = 0;
			normalize();
		}
		
		public Exmod(long a, long b) {
			this.a = a;
			this.b = b;
			normalize();
		}
		
		public Exmod(Exmod e) {
			this.a = e.a;
			this.b = e.b;
			normalize();
		}
		
		public void normalize(){
			if(a >= mod || a < 0){
				a %= mod;
				if(a < 0)a += mod;
			}
			if(b >= mod || b < 0){
				b %= mod;
				if(b < 0)b += mod;
			}
		}
		
		public Exmod add(Exmod t){ a += t.a; b += t.b; normalize(); return this; }
		public Exmod sub(Exmod t){ a -= t.a; b -= t.b; normalize(); return this; }
		public Exmod mul(Exmod t){
			long na = a * t.a + b * t.b * E;
			long nb = a * t.b + b * t.a;
			a = na; b = nb; normalize(); return this;
		}
		public Exmod div(Exmod t){
			long den = t.a*t.a-E*t.b*t.b;
			den %= mod; if(den < 0)den += mod;
			long iden = invl(den, mod);
			long numr = (a*t.a - b*t.b*E) % mod * iden % mod;
			long numi = (b*t.a - a*t.b) % mod * iden % mod;
			a = numr; b = numi; normalize(); return this;
		}
		public Exmod negate(){ a = -a; b = -b; normalize(); return this; }

		public static Exmod negate(Exmod a){ return new Exmod(-a.a, -a.b);}
		public static Exmod add(Exmod a, Exmod b){return new Exmod(a.a + b.a, a.b + b.b);}
		public static Exmod sub(Exmod a, Exmod b){return new Exmod(a.a - b.a, a.b - b.b);}
		public static Exmod mul(Exmod a, Exmod b){return new Exmod(a.a * b.a + a.b * b.b * E, a.a * b.b + a.b * b.a);}
		public static Exmod div(Exmod a, Exmod b){
			long den = b.a*b.a-E*b.b*b.b;
			den %= mod; if(den < 0)den += mod;
			long iden = invl(den, mod);
			long numr = (a.a*b.a - a.b*b.b*E) % mod * iden % mod;
			if(numr < 0)numr += mod;
			long numi = (a.b*b.a - a.a*b.b) % mod * iden % mod;
			if(numi < 0)numi += mod;
			return new Exmod(numr, numi);
		}
		
		public static Exmod inv(Exmod a){
			long den = a.a*a.a-E*a.b*a.b;
			den %= mod; if(den < 0)den += mod;
			long iden = invl(den, mod);
			long numr = a.a * iden % mod;
			long numi = -a.b * iden % mod;
			if(numi < 0)numi += mod;
			return new Exmod(numr, numi);
		}
		
		// a+bx (a+bx)(c-dx) (ac-bdE)+x(bc-ad)
		// ----=------------=-----------------
		// c+dx (c+dx)(c-dx)    c^2-Ed^2
		
		public static Exmod mul(Exmod a, long b){return new Exmod(a.a * b, a.b * b);}
		public static Exmod div(Exmod a, long b){return mul(a, invl(b, mod));}
		
		public static Exmod pow(Exmod a, long n) {
			Exmod ret = new Exmod(1);
			int x = 63 - Long.numberOfLeadingZeros(n);
			for (; x >= 0; x--) {
				ret = mul(ret, ret);
				if(n<<~x<0)ret = mul(ret, a);
			}
			return ret;
		}
		
		public static Exmod sumgp(Exmod a, long n)
		{
			Exmod mul = new Exmod(1);
			Exmod ret = new Exmod(0);
			for(int i = 63-Long.numberOfLeadingZeros(n);i >= 0;i--){
				mul.a += 1;
				ret = mul(ret, mul);
				mul.a -= 1;
				mul = mul(mul, mul);
				if(n<<~i<0){
					ret = mul(ret, a);
					ret.a++; ret.normalize();
					mul = mul(mul, a);
				}
			}
			return ret;
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
	
	public static void main(String[] args) throws Exception { new A5().run(); }
	
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