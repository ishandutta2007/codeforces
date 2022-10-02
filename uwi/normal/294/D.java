//package round178;
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
		int n = ni(), m = ni();
		int r = ni()-1, c = ni()-1;
		char[] dir = ns(3);
		int dr = dir[0] == 'D' ? 1 : -1;
		int dc = dir[1] == 'R' ? 1 : -1;
		
		if(gcd(n-1, m-1) == 1){
			if((r == 0 || r == n-1) && (c == 0 || c == m-1)){
				out.println((long)(n-1)*(m-1)+1);
			}else{
				out.println((long)(n-1)*(m-1) + fastsim(r, c, n, m, dr, dc));
			}
		}else{
			if(gcd(n-1, m-1) == 2 && (r+c) % 2 == 1){
				dr = -dr; dc = -dc;
				out.println((long)(n-1)*(m-1)-fastsim2(r, c, n, m, dr, dc));
			}else{
				out.println(-1);
			}
		}
	}
	
	long fastsim(int r, int c, int n, int m, int dr, int dc)
	{
		long t = 1;
		while(true){
			int ntr = dr == 1 ? n-1-r : r;
			int ntc = dc == 1 ? m-1-c : c;
			if(ntr < ntc){
				t += ntr;
				r += ntr * dr;
				c += ntr * dc;
				dr = -dr;
			}else{
				t += ntc;
				r += ntc * dr;
				c += ntc * dc;
				dc = -dc;
			}
			if((r == 0 || r == n-1) && (c == 0 || c == m-1)){
				break;
			}
		}
		return t;
	}
	
	int fastsim2(int r, int c, int n, int m, int dr, int dc)
	{
		int t = 0;
		int or = r, oc = c;
		while(true){
			int ntr = dr == 1 ? n-1-r : r;
			int ntc = dc == 1 ? m-1-c : c;
			if(ntr < ntc){
				t += ntr;
				r += ntr * dr;
				c += ntr * dc;
				dr = -dr;
			}else{
				t += ntc;
				r += ntc * dr;
				c += ntc * dc;
				dc = -dc;
			}
			if(r != or || c != oc)break;
		}
		return t-1;
	}
	
	public static int gcd(int a, int b) {
		while (b > 0){
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}