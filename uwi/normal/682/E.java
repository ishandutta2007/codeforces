//package round358;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long S = nl();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			co[i] = new long[]{ni(), ni()};
		}
		
		co = convexHull(co);
		
		long maxs = -1L;
		int bi = -1, bj = -1, bk = -1;
		int m = co.length;
		for(int i = 0;i < m;i++){
			int k = i;
			for(int j = i;j < m;j++){
				if(k < j)k = j;
				long curs = S(co[i], co[j], co[k]);
				while(k+1 < m){
					long nexs = S(co[i], co[j], co[k+1]);
					if(nexs > curs){
						curs = nexs;
						k++;
					}else{
						break;
					}
				}
//				tr(i, j, k, curs);
				if(curs > maxs){
					maxs = curs;
					bi = i;
					bj = j;
					bk = k;
				}
			}
		}
		long ax = co[bi][0] + (co[bj][0]-co[bi][0]) + (co[bk][0]-co[bi][0]);
		long ay = co[bi][1] + (co[bj][1]-co[bi][1]) + (co[bk][1]-co[bi][1]);
		long bx = co[bi][0] + (co[bj][0]-co[bi][0]) - (co[bk][0]-co[bi][0]);
		long by = co[bi][1] + (co[bj][1]-co[bi][1]) - (co[bk][1]-co[bi][1]);
		long cx = co[bi][0] - (co[bj][0]-co[bi][0]) + (co[bk][0]-co[bi][0]);
		long cy = co[bi][1] - (co[bj][1]-co[bi][1]) + (co[bk][1]-co[bi][1]);
		out.println(ax + " " + ay);
		out.println(bx + " " + by);
		out.println(cx + " " + cy);
//		check(ax, ay, bx, by, cx, cy, co, maxs);
	}
	
	void check(long ax, long ay, long bx, long by, long cx, long cy, long[][] co, long maxs)
	{
		int n = co.length;
		for(int i = 0;i < n;i++){
			int ccws = 0;
			{
				int cw = ccw(co[i][0], co[i][1], ax, ay, bx, by);
				if(cw == 0)continue;
				ccws += cw;
			}
			{
				int cw = ccw(co[i][0], co[i][1], bx, by, cx, cy);
				if(cw == 0)continue;
				ccws += cw;
			}
			{
				int cw = ccw(co[i][0], co[i][1], cx, cy, ax, ay);
				if(cw == 0)continue;
				ccws += cw;
			}
			if(ccws == 3 || ccws == -3){
			}else{
				tr(ax, ay, bx, by, cx, cy, co[i]);
				throw new RuntimeException();
			}
		}
		
		long us = S(new long[]{ax, ay}, new long[]{bx, by}, new long[]{cx, cy});
		if(us > 4*maxs){
			tr(us, maxs);
			throw new RuntimeException();
		}
	}
	
	long S(long[] a, long[] b, long[] c)
	{
		long ax = b[0]-a[0];
		long ay = b[1]-a[1];
		long bx = c[0]-a[0];
		long by = c[1]-a[1];
		return Math.abs(ax*by-bx*ay);
	}
	
	
	public static int ccw(long ax, long ay, long bx, long by, long tx, long ty) {
		return Long.signum((tx - ax) * (by - ay) - (bx - ax) * (ty - ay));
	}

	
	public static Comparator<long[]> compArgi = new Comparator<long[]>(){
		public int compare(long[] a, long[] b)
		{
			long ax = a[0], ay = a[1];
			long bx = b[0], by = b[1];
			int za = ay > 0 || (ay == 0 && ax > 0) ? 0 : 1;
			int zb = by > 0 || (by == 0 && bx > 0) ? 0 : 1;
			if(za != zb)return za - zb;
			return Long.signum(ay*bx-ax*by);
		}
	};
	
	public static long[][] convexHull(long[][] co)
	{
		int n = co.length;
		if(n <= 1)return co;
		Arrays.sort(co, new Comparator<long[]>(){
			public int compare(long[] a, long[] b){
				if(a[0] != b[0])return Long.compare(a[0], b[0]);
				return Long.compare(a[1], b[1]);
			}
		});
		
		int[] inds = new int[n + 1];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(p >= 1 && co[inds[p-1]][0] == co[i][0] && co[inds[p-1]][1] == co[i][1])continue;
			while(p >= 2 && ccw(co[inds[p-2]], co[inds[p-1]], co[i]) >= 0)p--; // if you need point on line
			inds[p++] = i;
		}
		
		int inf = p + 1;
		for(int i = n - 2;i >= 0;i--){
			if(co[inds[p-1]][0] == co[i][0] && co[inds[p-1]][1] == co[i][1])continue;
			while(p >= inf && ccw(co[inds[p-2]], co[inds[p-1]], co[i]) >= 0)p--; // if you need point on line
			inds[p++] = i;
		}
		
		long[][] ret = new long[p-1][];
		for(int i = 0;i < p-1;i++)ret[i] = co[inds[i]];
		return ret;
	}
	
	public static int ccw(long[] a, long[] b, long[] t) {
		return Long.signum((t[0] - a[0]) * (b[1] - a[1]) - (b[0] - a[0]) * (t[1] - a[1]));
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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