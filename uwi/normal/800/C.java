//package round409;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] ng = na(n);
		boolean[] isng = new boolean[m];
		for(int v : ng)isng[v] = true;
		
		int[] f = new int[m+1];
		int[] af = new int[m+1];
		int[][] fi = new int[m][];
		for(int i = 0;i < m;i++){
			int g = gcd(i, m);
			f[g]++;
			fi[i] = new int[]{g, i};
		}
		for(int v : ng){
			af[gcd(v, m)]++;
		}
		
		int[] dp = new int[m+1];
		for(int i = m;i >= 1;i--){
			int ne = 0;
			for(int j = i*2;j <= m;j += i){
				if(f[j] > 0 && dp[j] >= 0){
					ne = Math.max(ne, dp[j]);
				}
			}
			dp[i] = f[i] == af[i] ? -1 : ne + f[i] - af[i];
		}
		int max = -1;
		int cur = -1;
		for(int i = 1;i <= m;i++){
			if(dp[i] > max){
				max = dp[i];
				cur = i;
			}
		}
		
		boolean[] ok = new boolean[m+1];
		outer:
		while(cur != -1){
			ok[cur] = true;
			for(int i = cur*2;i <= m;i+=cur){
				if(dp[i] + f[cur] - af[cur] == dp[cur]){
					cur = i;
					continue outer;
				}
			}
			break;
		}
		Arrays.sort(fi, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int[] prods = new int[m+1];
		int p = 0;
		prods[p++] = 1;
		for(int[] item : fi){
			if(!isng[item[1]] && ok[item[0]]){
				prods[p++] = item[1];
			}
		}
		out.println(p-1);
		for(int i = 0;i < p-1;i++){
			int from = prods[i], to = prods[i+1];
			int mod = m;
			int g = gcd(gcd(from, to), m);
			from /= g; to /= g; mod /= g;
			long d = invl(from, mod) * to % m;
			assert prods[i] * d % m == prods[i+1];
			out.print(d + " ");
		}
		out.println();
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


	
	public static int gcd(int a, int b) {
		while (b > 0) {
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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