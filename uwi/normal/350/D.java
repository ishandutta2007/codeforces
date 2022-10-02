//package round203;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	void solve()
	{
		int n = ni(), m = ni();
		int[][] seg = new int[n][];
		for(int i = 0;i < n;i++){
			seg[i] = new int[]{ni(), ni(), ni(), ni(), 0, 0, 0};
		}
		int[][] cir = new int[m][];
		for(int i = 0;i < m;i++){
			cir[i] = na(3);
		}
		
		for(int[] s : seg){
			int[] d = go(s[2]-s[0], s[3]-s[1]);
			int dx = d[0], dy = d[1];
			s[4] = dx; s[5] = dy;
			// y-b=dy/dx*(x-a)
			// ydx-bdx=xdy-ady
			// xdy-ydx+ady-bdx=0
			s[6] = s[0]*dy-s[1]*dx;
			if(s[0] > s[2] || s[0] == s[2] && s[1] > s[3]){
				int u = s[0]; s[0] = s[2]; s[2] = u;
				u = s[1]; s[1] = s[3]; s[3] = u;
			}
			s[0] *= 2; s[1] *= 2; s[2] *= 2; s[3] *= 2;
		}
		
		long[][] es = new long[2*n+m*(m-1)/2][];
		int p = 0;
		for(int i = 0;i < n;i++){
			long code1 = (((seg[i][4]+10000L) * 20002L) + seg[i][5]+10000L)<<32|seg[i][6] + 400000000L;
			es[p++] = new long[]{
					code1,
					(seg[i][0]+20000L)<<32|(seg[i][1]+20000L)<<3|0
			};
			es[p++] = new long[]{
					code1,
					(seg[i][2]+20000L)<<32|(seg[i][3]+20000L)<<3|2
			};
		}
		
		for(int i = 0;i < m;i++){
			for(int j = i+1;j < m;j++){
				if(cir[i][2] == cir[j][2] && (cir[i][0]-cir[j][0])*(cir[i][0]-cir[j][0])+(cir[i][1]-cir[j][1])*(cir[i][1]-cir[j][1]) > cir[i][2]*cir[i][2]*4){
					int[] d = go(cir[i][1]-cir[j][1], -(cir[i][0]-cir[j][0]));
					int dx = d[0], dy = d[1];
					int z = (cir[i][0]+cir[j][0])*dy-(cir[i][1]+cir[j][1])*dx;
					if(z % 2 == 0){
						z /= 2;
						int mx2 = cir[i][0]+cir[j][0];
						int my2 = cir[i][1]+cir[j][1];
						int[] cap = new int[]{mx2, my2, mx2, my2, dx, dy, z};
						long ccode  = (((cap[4]+10000L) * 20002L) + cap[5]+10000L)<<32|cap[6] + 400000000L;
						long pcode = (cap[0]+20000L)<<32|(cap[1]+20000L)<<3|1;
						es[p++] = new long[]{ccode, pcode};
					}
				}
			}
		}
		Arrays.sort(es, 0, p, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				if(a[0] != b[0])return Long.compare(a[0], b[0]);
				return Long.compare(a[1], b[1]);
			}
		});
		
		long ret = 0;
		int dup = 0;
		for(int i = 0;i < p;i++){
			int type = (int)es[i][1]&3;
			if(type == 0){
				dup++;
			}else if(type == 2){
				dup--;
			}else{
				ret += dup;
			}
		}
		
		out.println(ret);
	}
	
	int[] go(int dx, int dy)
	{
		if(dx < 0){
			dx = -dx;
			dy = -dy;
		}
		if(dx == 0){
			dy = 1;
		}else if(dy == 0){
			dx = 1;
		}else{
			int g = gcd(dx, Math.abs(dy));
			dx /= g; dy /= g;
		}
		return new int[]{dx, dy};
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