//package round247;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		BigInteger[][] c = new BigInteger[62][62];
		for(int i = 0;i < 62;i++){
			Arrays.fill(c[i], BigInteger.ZERO);
		}
		for(int i = 0;i < 62;i++){
			c[i][0] = BigInteger.ONE;
			for(int j = 1;j <= i;j++){
				c[i][j] = c[i-1][j].add(c[i-1][j-1]);
			}
		}
		
		long m = nl();
		int K = ni();
		long om = m;
		int o = 0;
		long ans = 0;
		for(int d = 59;d >= 0;d--){
			BigInteger v = C(d+1, K-o, c).subtract(C(d, K-o, c));
			if(v.signum() != 0 && v.compareTo(BigInteger.valueOf(m)) <= 0 && (ans|1L<<d) <= 1000000000000000000L){
				ans |= 1L<<d;
				m -= v.longValue();
				o++;
			}
		}
		if(m != 0)throw new RuntimeException(Long.toString(m));
//		if(m != 0)return;
//		for(long i = ans+1;i <= 2*ans;i++){
//			if(Long.bitCount(i) == K)om--;
//		}
//		if(om != 0)throw new RuntimeException(Long.toString(om));
		if(ans == 0){
			out.println(1);
			return;
//			throw new RuntimeException();
		}
//		out.println("hey");
		out.println(ans);
	}
	
	BigInteger C(int n, int r, BigInteger[][] c)
	{
		if(n < 0 || r < 0 || n < r)return BigInteger.ZERO;
		return c[n][r];
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
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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