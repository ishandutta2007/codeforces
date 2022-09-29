//package round593;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.TreeSet;

public class D {
	InputStream is;
	PrintWriter out;
//	String INPUT = "3 4 5 1 4 2 4 3 4 2 1 2 2";
//	String INPUT = "1 100000 0";
	String INPUT = "";
	
	void solve()
	{
		long n = ni(), m = ni();
		int K = ni();
		TreeSet<Long> xy = new TreeSet<>();
		TreeSet<Long> yx = new TreeSet<>();
		TreeSet<Long> xmy = new TreeSet<>();
		TreeSet<Long> ymx = new TreeSet<>();
		for(int i = 0;i < K;i++){
			long x = nl(), y = nl();
			x--; y--;
			xy.add(x<<32|y);
			yx.add(m-1-y<<32|x);
			xmy.add(n-1-x<<32|m-1-y);
			ymx.add(y<<32|n-1-x);
		}
		long r = 0, c = 0;
		long minr = 0, maxr = n-1;
		long minc = 0, maxc = m-1;
		long all = (long)n*m - K;
		long ved = 1;
		boolean first = true;
		out:
		while(true){
//			tr(r, c, n, m, minr, maxr, minc, maxc, ved);
			
			Long rc = xy.ceiling(r<<32|c);
			while(true){
				if(rc != null){
					long nr = rc>>>32, nc = (int)(long)rc;
					if(nr == r && nc <= maxc){
						nc--;
						if(nc == c && !first)break out;
						first = false;
						ved += nc-c;
						c = nc;
						break;
					}
				}
				long nc = maxc;
				if(nc == c && !first)break out;
				first = false;
				ved += nc-c;
				c = nc;
				break;
			}
			minr = r + 1;
			
			long x = minr; minr = m-1-maxc;
			maxc = maxr; maxr = m-1-minc;
			minc = x;
			
			{long d = r; r = m-1-c; c = d;}
			{long d = n; n = m; m = d;}
			
			{TreeSet<Long> d = xy; xy = yx; yx = xmy; xmy = ymx; ymx = d;}
		}
		out.println(all == ved ? "Yes" : "No");
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