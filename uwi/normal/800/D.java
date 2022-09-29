//package round409;
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
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int mod = 1000000007;
		int[] s0 = new int[1000000];
		for(int v : a){
			s0[v] += 1;
		}
		for(int i = 1;i <= 100000;i*=10){
			for(int j = 999999;j >= 0;j--){
				if(j / i % 10 > 0){
					s0[j-i] += s0[j];
				}
			}
		}
		
		
		long[] s1 = new long[1000000];
		for(int v : a){
			s1[v] += v;
			if(s1[v] >= mod)s1[v] -= mod;
		}
		for(int i = 1;i <= 100000;i*=10){
			for(int j = 999999;j >= 0;j--){
				if(j / i % 10 > 0){
					s1[j-i] += s1[j];
					if(s1[j-i] >= mod)s1[j-i] -= mod;
				}
			}
		}
		long[] s2 = new long[1000000];
		for(int v : a){
			s2[v] += (long)v*v;
			s2[v] %= mod;
		}
		for(int i = 1;i <= 100000;i*=10){
			for(int j = 999999;j >= 0;j--){
				if(j / i % 10 > 0){
					s2[j-i] += s2[j];
					if(s2[j-i] >= mod)s2[j-i] -= mod;
				}
			}
		}
		
		long[] pows = new long[1000005];
		pows[0] = 1;
		for(int i = 1;i < pows.length;i++){
			pows[i] = pows[i-1] * 2 % mod;
		}
		long[] vals = new long[1000000];
		for(int i = 0;i < 1000000;i++){
			vals[i] = (s0[i]-1 >= 0 ? s2[i] * pows[s0[i]-1] : 0);
			vals[i] += (s0[i]-2 >= 0 ? (s1[i]*s1[i]-s2[i])%mod*pows[s0[i]-2] : 0);
			vals[i] %= mod;
			if(vals[i] < 0)vals[i] += mod;
		}
		for(int i = 1;i <= 100000;i*=10){
			for(int j = 0;j < 1000000;j++){
				if(j / i % 10 > 0){
					vals[j-i] -= vals[j];
					if(vals[j-i] < 0)vals[j-i] += mod;
				}
			}
		}
		long ret = 0;
		for(int j = 0;j < 1000000;j++){
			ret ^= vals[j]*j;
		}
		out.println(ret);
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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