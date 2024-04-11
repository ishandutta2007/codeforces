//package round571;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int[][] cum;
	
	void solve()
	{
		int n = ni() ,m = ni();
		int Q = ni();
		char[][] map = nm(n,m);
		cum = new int[2*n+1][2*m+1];
		for(int i = 0;i < 2*n;i++){
			for(int j = 0;j < 2*m;j++){
				cum[i+1][j+1] = cum[i][j+1] + cum[i+1][j] - cum[i][j]
						+ (i < n && j < m ? map[i][j]-'0' : 0)
						+ (i >= n && j < m ? (1^map[i-n][j]-'0') : 0)
						+ (i < n && j >= m ? (1^map[i][j-m]-'0') : 0)
						+ (i >= n && j >= m ? (map[i-n][j-m]-'0') : 0);
			}
		}
		for(int z = 0;z < Q;z++){
			int r1 = ni()-1, c1 = ni()-1;
			int r2 = ni()-1, c2 = ni()-1;
			out.println(
					count(r2, c2) - 
					count(r1-1, c2) -
					count(r2, c1-1) + 
					count(r1-1, c1-1)
					);
		}
	}
	
	long count(long r, long c)
	{
		int n = cum.length/2;
		int m = cum[0].length/2;
		long ret = 0;
		int inv = 0;
		for(int d = 30;d >= 1;d--){
			long ln = (long)n<<d;
			long lm = (long)m<<d;
			if(r >= ln){
				if(c >= lm){
					ret += ln*lm/2;
					ret += (r-ln+1)*lm/2;
					ret += (c-lm+1)*ln/2;
					r -= ln; c -= lm;
				}else{
					ret += (c+1)*ln/2;
					r -= ln;
					inv ^= 1;
				}
			}else{
				if(c >= lm){
					ret += (r+1)*lm/2;
					c -= lm;
					inv ^= 1;
				}
			}
		}
		if(inv == 0){
			ret += cum[(int)r+1][(int)c+1];
		}else{
			ret += (r+1)*(c+1) - cum[(int)r+1][(int)c+1];
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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