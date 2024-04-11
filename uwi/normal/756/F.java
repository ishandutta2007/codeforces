//package eightvc.f;
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
	char[] s;
	int pos, len;
	int mod = 1000000007;
	int emod = mod-1;
	long modx = (long)mod*emod;
	
	long[] tm = new long[64];
	
	long tes(long nume, long mul)
	{
		long B = mul;
		long s0 = 1;
		long s1 = 0;
		long res1 = 0;
		for(int d = 0;d < 63;d++){
			if(nume<<~d<0){
				res1 = (res1 * B + s1 + s0*((nume&(1L<<d)-1)%mod)) % mod;
			}
//			s1 = (s1 * (B+1) + (s0<<d)) % mod;
			s1 = (s1 * (B+1) + s0*((1L<<d)%mod)) % mod;
			s0 = s0 * (B+1) % mod;
			B = B * B % mod;
		}
		return res1;
	}
	
	void solve()
	{
		for(int i = 0;i < 63;i++){
			tm[i] = (1L<<i)%mod;
		}
		
		s = ns().toCharArray();
		pos = 0; len = s.length;
		Modnum res = expr();
		assert pos == len;
		out.println(res.v);
	}
	
	Modnum expr()
	{
		Modnum t = term();
		while(pos < len && s[pos] == '+'){
			pos++;
			Modnum lt = term();
			t = concat(t, lt);
		}
		return t;
	}
	
	Modnum term()
	{
		Modnum n = number();
		if(pos < len && s[pos] == '-'){
			pos++;
			Modnum ln = number();
			return range(n, ln);
		}
		if(pos < len && s[pos] == '('){
			pos++;
			Modnum e = expr();
			assert s[pos] == ')';
			pos++;
			return repeat(e, n);
		}
		return n;
	}
	
	long mul10(long v)
	{
		long v2 = v + v;
		if(v2 >= modx)v2 -= modx;
		v = v2 * 5;
		while(v >= modx)v -= modx;
		return v;
	}
	
	Modnum number()
	{
		long vx = 0;
		int nlen = 0;
		while(pos < len && s[pos] >= '0' && s[pos] <= '9'){
			vx = mul10(vx) + (s[pos]-'0');
			if(vx >= modx)vx -= modx;
			nlen++;
			pos++;
		}
		assert nlen != 0;
		return new Modnum(vx%mod, nlen, vx);
	}
	
	Modnum concat(Modnum a, Modnum b)
	{
		return new Modnum(
				(a.v * pow(10, b.len, mod) + b.v)% mod,
				(a.len + b.len) % emod
		);
	}
	
	Modnum range(Modnum a, Modnum b)
	{
		Modnum ret = new Modnum(0, 0);
		long t = pow(10, a.len, mod);
		long px = powSafe(10, a.len-1, modx);
		for(long i = a.len;i <= b.len;i++){
			long npx = mul10(px);
			long inf = i == a.len ? a.vx : px;
			long sup = i == b.len ? b.vx : npx-1;
			if(sup < 0)sup += modx;
			
			long num = sup-inf+1;
			if(num < 0)num += modx;
			long base = (inf%mod)*sumGP(t, num, mod)%mod;
			// 0 1 ... sup-inf
			
			num %= modx;
			long mul = t;
			long B = mul;
			long s0 = 1;
			long s1 = 0;
			long res1 = 0;
			long q = 0;
			for(int d = 0;d < 63;d++){
				if(num<<~d<0){
					res1 = (res1 * B + s1 + s0*q) % mod;
					q += tm[d];
					if(q >= mod)q -= mod;
				}
				s1 = (s1 * (B+1) + s0*tm[d]) % mod;
				s0 = s0 * (B+1) % mod;
				B = B * B % mod;
			}
			t = t * 10 % mod;
			px = npx;
			
			ret = concat(ret, new Modnum((base+res1)%mod, i*(num%emod)%emod));
		}
		return ret;
	}
	
	Modnum repeat(Modnum a, Modnum rep)
	{
		return new Modnum(
				sumGP(pow(10, a.len, mod), rep.vx, mod) * a.v % mod,
				a.len*(rep.vx%emod)%emod
				);
	}
	
	public static class Modnum
	{
		public long v;
		public long vx;
		public long len;
		public Modnum(long v, long len) {
			this.v = v;
			this.len = len;
		}
		public Modnum(long v, long len, long vx) {
			this.v = v;
			this.len = len;
			this.vx = vx;
		}
		@Override
		public String toString() {
			return "Datum [v=" + v + ", len=" + len + "]";
		}
	}
	
	public static long powSafe(long a, long n, long mod)
	{
//		a %= mod;
		long ret = 1; // 1%mod if mod=1,n=0
		int x = 63-Long.numberOfLeadingZeros(n);
		for(;x >= 0;x--){
			ret = mulEx(ret, ret, mod);
			if(n<<~x<0)ret = mulEx(ret, a, mod);
		}
		return ret;
	}
	
	public static long mul(long a, long b, long mod)
	{
		if(a >= mod || a < 0)a %= mod;
		if(a < 0)a += mod;
		if(b >= mod || b < 0)b %= mod;
		if(b < 0)b += mod;
		
		long ret = 0;
		int x = 63-Long.numberOfLeadingZeros(b);
		for(;x >= 0;x--){
			ret += ret;
			if(ret >= mod)ret -= mod;
			if(b<<~x<0){
				ret += a;
				if(ret >= mod)ret -= mod;
			}
		}
		return ret;
	}
	
	public static long mulEx(long a, long b, long mod)
	{
		if(a >= mod || a < 0)a %= mod;
		if(a < 0)a += mod;
		if(b >= mod || b < 0)b %= mod;
		if(b < 0)b += mod;
		
		long ret = 0;
		int x = 63-Long.numberOfLeadingZeros(b);
		for(;x >= 0;x--){
			ret += ret;
			if(Long.compareUnsigned(ret, mod) >= 0)ret -= mod;
			if(b<<~x<0){
				ret += a;
				if(Long.compareUnsigned(ret, mod) >= 0)ret -= mod;
			}
		}
		return ret;
	}
	
	public static long sumGP(long a, long n, long mod)
	{
		long smul = 1; // % mod
		long mul = a % mod;
		long ret = 0;
		for(;n > 0;n >>>= 1){
			if((n&1)==1){
				ret = (ret * mul + smul) % mod;
			}
			smul = smul * (mul + 1) % mod;
			mul = mul * mul % mod;
		}
		return ret;
	}
	
	public static long pow(long a, long n, long mod) {
		//		a %= mod;
		long ret = 1;
		int x = 63 - Long.numberOfLeadingZeros(n);
		for (; x >= 0; x--) {
			ret = ret * ret % mod;
			if (n << 63 - x < 0)
				ret = ret * a % mod;
		}
		return ret;
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