//package round179;
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
	int[][] fif = enumFIF(7000, mod);
	
	void solve()
	{
		int n = ni(), m = ni();
		
		long ret = 0;
		for(int w = 1;w < m;w++){
			long[] num = new long[n+1];
			long[] cum = new long[n+1];
			for(int L = 1;L <= n;L++){
				num[L] = C(w-1+2*(L-1), 2*(L-1));
				cum[L] = cum[L-1] + num[L];
				if(cum[L] >= mod)cum[L]-=mod;
			}
			
			long lsum = 0;
			for(int L = 1;L <= n;L++){
				lsum += num[L]*cum[n-L+1]%mod*(m-w)%mod;
			}
			ret += lsum%mod;
		}
		out.println(ret%mod);
	}
	
	long C(int n, int r)
	{
		if(n < 0 || r < 0 || n < r)return 0;
		return (long)fif[0][n]*fif[1][r]%mod*fif[1][n-r]%mod;
	}
	
	public static int[][] enumFIF(int n, int mod)
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