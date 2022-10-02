//package round283;
import java.awt.geom.Line2D;
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
		int[] P = new int[]{ni(), ni()};
		int n = ni();
		int[][] coa = new int[n+1][];
		for(int i = 0;i < n;i++)coa[i] = na(2);
		int[] Q = new int[]{ni(), ni()};
		int m = ni();
		int[][] cob = new int[m+1][];
		for(int i = 0;i < m;i++)cob[i] = na(2);
		cob[m] = cob[0];
		coa[n] = coa[0];
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(ok(coa[i], coa[i+1], cob[j], cob[j+1], P, Q)){
					out.println("YES");
					return;
				}
			}
		}
		out.println("NO");
	}
	
	boolean ok(int[] a, int[] b, int[] c, int[] d, int[] e, int[] f)
	{
		int[][] q = new int[5][];
		q[0] = new int[]{c[0]-a[0]-f[0]+e[0], c[1]-a[1]-f[1]+e[1]};
		q[1] = new int[]{c[0]-a[0]-f[0]+e[0]+d[0]-c[0], c[1]-a[1]-f[1]+e[1]+d[1]-c[1]};
		q[3] = new int[]{c[0]-a[0]-f[0]+e[0]-b[0]+a[0], c[1]-a[1]-f[1]+e[1]-b[1]+a[1]};
		q[2] = new int[]{c[0]-a[0]-f[0]+e[0]+d[0]-c[0]-b[0]+a[0], 
				c[1]-a[1]-f[1]+e[1]+d[1]-c[1]-b[1]+a[1]};
		q[4] = q[0];
		
		double min = -1;
		int[] ccws = new int[4];
		for(int i = 0;i < 4;i++){
			ccws[i] = ccw(q[i][0], q[i][1], q[i+1][0], q[i+1][1], 0, 0);
			if(isACB(q[i][0], q[i][1], q[i+1][0], q[i+1][1], 0, 0))min = 0;
		}
		boolean same = true;
		for(int i = 1;i < 4;i++){
			if(ccws[i] != ccws[i-1]){
				same = false;
			}
		}
		if(same)min = 0;
		
		if(min == -1){
			min = Double.POSITIVE_INFINITY;
			for(int i = 0;i < 4;i++){
				min = Math.min(min, Line2D.ptSegDistSq(q[i][0], q[i][1], q[i+1][0], q[i+1][1], 0, 0));
			}
		}
		
		long max = 0;
		for(int i = 0;i < 4;i++){
			max = Math.max(max, (long)q[i][0]*q[i][0]+(long)q[i][1]*q[i][1]);
		}
		
		long gx = e[0]-f[0];
		long gy = e[1]-f[1];
		return min <= gx*gx+gy*gy && gx*gx+gy*gy <= max;
	}
	
	public static boolean isACB(long ax, long ay, long bx, long by, long cx, long cy)
	{
		return (cx-ax)*(by-ay)-(cy-ay)*(bx-ax)==0 && (cx-ax)*(cx-bx)+(cy-ay)*(cy-by) <= 0;
	}
	
	public static int ccw(long ax, long ay, long bx, long by, long tx, long ty)
	{
		return Long.signum((tx-ax)*(by-ay)-(bx-ax)*(ty-ay));
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