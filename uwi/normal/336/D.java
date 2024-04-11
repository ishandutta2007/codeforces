//package round195;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int mod = 1000000007;
	int[][] fif = enumFIF(220000, mod);
	
	void solve()
	{
		int n = ni(), m = ni(), g = ni();
		if(g == 0){
			long ct = count(n-1, m) + count(n-1, m-1) + count(n, m-2);
			out.println(ct%mod);
		}else{
			if(n == 0 && m == 1){
				out.println(1);
				return;
			}
			long ct = count(n-2, m) + count(n-2, m-1) + count(n-1, m-2);
			out.println(ct%mod);
		}
	}
	
	long count(int x, int y)
	{
		if(x < 0 || y < 0)return 0;
		long ct = 0;
		for(int k = 0;2*k <= x;k++){
			int u = x-2*k;
			if(u < 0)continue;
			int v = y-u;
			if(v < 0)continue;
			ct += (long)fif[0][k+u+v]*fif[1][k]%mod*fif[1][u]%mod*fif[1][v]%mod;
		}
		return ct%mod;
	}
	
	
	
	public int[][] enumFIF(int n, int mod)
	{
		int[] f = new int[n+1];
		int[] invf = new int[n+1];
		invf[1] = 1;
		for(int i = 2;i <= n;i++){
			invf[i] = (int)(invf[mod%i]*(long)(mod-mod/i)%mod);
		}
		
		f[0] = invf[0] = 1;
		for(int i = 1;i <= n;i++){
			f[i] = (int)((long)f[i-1] * i % mod);
			invf[i] = (int)((long)invf[i-1] * invf[i] % mod);
		}
		return new int[][]{f, invf};
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