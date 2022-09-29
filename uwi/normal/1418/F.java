//package ecr95;
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
	
	void solve()
	{
		long n = nl(), m = nl();
		long L = nl(), R = nl();

		// sum_i sqrt(min(m, mn/i))*phi(i)
		long[][] anss = new long[(int)n+1][];

		for(int d = 1;d <= n;d++) {
			outer:
			for (int i = d; i <= n-d; i += d) {
				if (anss[i] != null) continue;
				long ly = (L + i - 1) / i;
				long ry = Math.min(m, R / i);
				if (ly > ry)continue;

				long lx2 = i/d+1;
				long rx2 = n/d;
				// x2
				// x2/gcd(x1,x2)ly~ry
				// x2=dk
				// lx2<=k<=rx2ly~ry

				for(long u = 1;u*u <= ry;u++){
					long ll = (ly+u-1)/u, rr = ry/u;
					if(Math.max(ll, lx2) <= Math.min(rr, rx2)){
						anss[i] = new long[]{i, Math.max(ll, lx2)*u,
								Math.max(ll, lx2)*d,
								-1
						};
						anss[i][3] = anss[i][0] * anss[i][1] / anss[i][2];
						continue outer;
					}
				}
				for(long u = 1;u*u <= ry;u++){
					if(ly <= ry/u*u) {
						if (Math.max(u, lx2) <= Math.min(u, rx2)) {
							anss[i] = new long[]{i, Math.max(u, lx2) * (ry/u),
									Math.max(u, lx2)*d,
									-1
							};
							anss[i][3] = anss[i][0] * anss[i][1] / anss[i][2];
							continue outer;
						}
					}
				}

			}
		}

		for(int i = 1;i <= n;i++){
			if(anss[i] ==null){
				out.println(-1);
			}else{
//				out.println(1);
								long[] v = anss[i];
//								tr(v);
									long x1 = v[0];
									long y1 = v[1];
									long x2 = v[2];
									long y2 = v[3];
									assert x1 < x2;
									assert y2 < y1;
									assert x2 <= n;
									assert y1 <= m;
									assert x1 * y1 == x2 * y2;
									assert L <= x1 * y1;
									assert x1 * y1 <= R;
				out.println(v[0] + " " + v[1] + " "+  v[2] + " " + v[3]);
			}
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