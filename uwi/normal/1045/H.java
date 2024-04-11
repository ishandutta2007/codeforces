//package bubble11;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class H {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int mod = 1000000007;
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
	
	int[][] fif = enumFIF(300000, mod);

	
	void solve()
	{
		char[] s = ns().toCharArray();
		char[] t = add1(ns().toCharArray());
//		char[] s = sub1(ns().toCharArray());
//		char[] t = ns().toCharArray();
		int[] con = na(4);
//		tr(t, count(t, Arrays.copyOf(con, 4)));
//		tr(s, count(s, Arrays.copyOf(con, 4)));
		long ans = count(t, Arrays.copyOf(con, 4)) - count(s, Arrays.copyOf(con, 4)) + mod;
		ans %= mod;
		out.println(ans);
	}
	
	long count(char[] s, int[] con)
	{
		if(s.length == 0)return 0;
		int n = s.length;
		int nd = con[0] + con[1] + con[2] + con[3] + 1;
		if(s.length < nd){
			return 0;
		}else if(s.length > nd){
			return count(con);
		}
		
		long ans = 0;
		if(s.length == 1 && s[0] == '1')ans++;
		for(int i = 1;i < n;i++){
			if(s[i] == '1'){
				con[(s[i-1]-'0')*2]--;
				ans += count0(con);
				con[(s[i-1]-'0')*2]++;
			}
			int d = (s[i-1]-'0')*2 + s[i]-'0';
			con[d]--;
		}
		
		return ans % mod;
	}
	
	long count(int[] con)
	{
		for(int v : con){
			if(v < 0)return 0;
		}
		if(con[1] == con[2] + 1){
			// 01 .. 10 .. 01
			return 0L;
		}else if(con[1] == con[2] - 1){
			// 10 .. 01 .. 10
			return 
			C(con[0] + con[1], con[1], mod, fif) *
			C(con[3] + con[1], con[1], mod, fif)
			% mod;
		}else if(con[1] == con[2]){
			// 10 .. 01
			if(con[1] == 0){
				return con[0] == 0 ? con[3] == 0 ? 2 : 1 : 0;
			}
			
			return 
			C(con[0] + con[1] - 1, con[1] - 1, mod, fif) *
			C(con[3] + con[1], con[1], mod, fif)
			% mod;
		}
		return 0;
	}
	
	
	long count0(int[] con)
	{
		for(int v : con){
			if(v < 0)return 0;
		}
		if(con[1] == con[2] + 1){
			// 01 .. 10 .. 01
			return 
			C(con[0] + con[2], con[2], mod, fif) *
			C(con[3] + con[2], con[2], mod, fif)
			% mod;
		}else if(con[1] == con[2] - 1){
			// 10 .. 01 .. 10
			return 0L;
		}else if(con[1] == con[2]){
			// 01 .. 10
			if(con[1] == 0){
				return con[3] == 0 ? 1 : 0;
			}
			
			return 
			C(con[0] + con[1], con[1], mod, fif) *
			C(con[3] + con[1] - 1, con[1] - 1, mod, fif)
			% mod;
		}
		return 0;
	}
	
	public static long C(int n, int r, int mod, int[][] fif) {
		if (n < 0 || r < 0 || r > n)
			return 0;
		return (long) fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod;
	}

	
	char[] add1(char[] s)
	{
		boolean inp = false;
		for(int i = s.length-1;i >= 0;i--){
			if(++s[i] == '2'){
				s[i] = '0';
			}else{
				inp = true;
				break;
			}
		}
		if(inp){
			return s;
		}else{
			char[] ret = new char[s.length+1];
			Arrays.fill(ret, '0');
			ret[0] = '1';
			return ret;
		}
	}
	
	char[] sub1(char[] s)
	{
		if(s.length == 1 && s[0] == '0')return new char[0];
		for(int i = s.length-1;i >= 0;i--){
			if(--s[i] < '0'){
				s[i] = '1';
			}
		}
		return s;
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
	
	public static void main(String[] args) throws Exception { new H().run(); }
	
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