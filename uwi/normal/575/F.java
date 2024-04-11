//package bubble8;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int x = ni();
		int[][] rs = new int[n][];
		for(int i = 0;i < n;i++){
			rs[i] = new int[]{ni(), ni()};
		}
		int[] xs = new int[2*n+1];
		for(int i = 0;i < n;i++){
			xs[2*i] = rs[i][0];
			xs[2*i+1] = rs[i][1];
		}
		xs[2*n] = x;
		int[] imap = shrinkX(xs);
		
		long[] pre = new long[imap.length];
		long[] cur = new long[imap.length];
		Arrays.fill(pre, Long.MAX_VALUE / 100);
		pre[xs[2*n]] = 0;
		int m = imap.length;
		for(int i = 0;i < n;i++){
			int l = xs[i*2], r = xs[i*2+1];
			Arrays.fill(cur, Long.MAX_VALUE / 100);
			long minc = Long.MAX_VALUE / 100;
			for(int j = 0;j < m;j++){
				minc = Math.min(minc, pre[j]);
				cur[j] = Math.min(cur[j], minc + d(imap[l], imap[r], imap[j]));
				if(j+1 < m)minc += imap[j+1] - imap[j];
			}
			minc = Long.MAX_VALUE / 100;
			for(int j = m-1;j >= 0;j--){
				minc = Math.min(minc, pre[j]);
				cur[j] = Math.min(cur[j], minc + d(imap[l], imap[r], imap[j]));
				if(j-1 >= 0)minc += imap[j] - imap[j-1];
			}
			long[] dum = pre; pre = cur; cur = dum;
		}
		long ret = Long.MAX_VALUE;
		for(long v : pre)ret = Math.min(ret, v);
		out.println(ret);
	}
	
	int d(int l, int r, int d)
	{
		if(d < l){
			return l-d;
		}else if(d > r){
			return d - r;
		}else{
			return 0;
		}
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
	
	public static void main(String[] args) throws Exception { new F3().run(); }
	
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