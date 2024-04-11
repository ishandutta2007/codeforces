//package round657;
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
		long H = ni();
		long M = ni();
		long K = nl();
		M /= 2;
		H *= 2;
		// [m+1,m+K-1]
		long[] ss = new long[n];
		for(int i = 0;i < n;i++){
			long h = nl(), m = nl();
			h *= 2;
			if(m >= M){
				m -= M;
				h++;
			}
			ss[i] = m+1;
		}
		if(K == 1){
			out.println(0 + " " + 0);
			out.println();
			return;
		}
		
		int[] xs = new int[2*n+2];
		int p = 0;
		xs[p++] = 0;
		xs[p++] = (int)M;
		for(int i = 0;i < n;i++){
			xs[p++] = (int)ss[i];
			xs[p++] = (int)((ss[i]+K-2+1)%M);
		}
		int[] imap = shrinkX(xs);
		
		int w = imap.length;
		int[] imos = new int[w];
		for(int i = 0;i < n;i++){
			int L = xs[2*i+2];
			int R = xs[2*i+3];
			imos[L]++;
			imos[R]--;
			if(L > R){
				imos[0]++;
			}
		}
		for(int i = 0;i < w-1;i++){
			imos[i+1] += imos[i];
		}
		int arg = 0;
		for(int i = 0;i < w;i++){
			if(imos[i] < imos[arg]){
				arg = i;
			}
		}
		out.println(imos[arg] + " " + imap[arg]);
		for(int i = 0;i < n;i++){
			int L = xs[2*i+2];
			int R = xs[2*i+3];
			if(L <= R){
				if(L <= arg && arg < R){
					out.print((i+1) + " ");
				}
			}else{
				if(L <= arg || arg < R){
					out.print((i+1) + " ");
				}
			}
		}
		out.println();
	}
	
	public static int[] shrinkX(int[] a) {
		int n = a.length;
		long[] b = new long[n];
		for (int i = 0; i < n; i++)
			b[i] = (long) a[i] << 32 | i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		ret[0] = (int) (b[0] >> 32);
		for (int i = 0; i < n; i++) {
			if (i > 0 && (b[i] ^ b[i - 1]) >> 32 != 0) {
				p++;
				ret[p] = (int) (b[i] >> 32);
			}
			a[(int) b[i]] = p;
		}
		return Arrays.copyOf(ret, p + 1);
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