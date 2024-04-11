//package educational.round0x;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			co[i] = new long[]{Math.round(nd()*100), Math.round(nd()*100)};
		}
		if(isClockwise(co)){
			for(int i = 1, j = n-1;i < j;i++,j--){
				long[] d = co[i]; co[i] = co[j]; co[j] = d;
			}
		}
		
		long[][][] ts = clipEar(co);
		
		for(int i = 0;i < m;i++){
			long ax = Math.round(nd()*100);
			long ay = Math.round(nd()*100);
			long bx = Math.round(nd()*100);
			long by = Math.round(nd()*100);
			long[] a = new long[]{ax, ay};
			long[] b = new long[]{bx, by};
			double ret = 0;
			double e = 0;
			outer:
			for(long[][] t : ts){
				double min = Double.POSITIVE_INFINITY;
				double max = Double.NEGATIVE_INFINITY;
				for(int j = 0, k = 1;j < 3;j++,k++){
					if(k == 3)k = 0;
					long[] v0 = t[j], v1 = t[k];
					long[] il = interLinesS(a, b, v0, v1);
//					tr(v0, v1, a, b, il);
					if(il != null && 0 <= il[1] && il[1] <= il[2]){
						min = Math.min(min, (double)il[0]/il[2]);
						max = Math.max(max, (double)il[0]/il[2]);
					}else if(il == null && onSameLine(ax, ay, bx, by, v0[0], v0[1])){
						e += Math.sqrt(d2(v0[0], v0[1], v1[0], v1[1]));
						continue outer;
					}
				}
				if(Double.isFinite(min)){
					ret += (max-min)*Math.sqrt(d2(ax, ay, bx, by));
				}
			}
			for(int j = 0, k = 1;j < n;j++,k++){
				if(k == n)k = 0;
				if(onSameLine(ax, ay, bx, by, co[j][0], co[j][1]) && onSameLine(ax, ay, bx, by, co[k][0], co[k][1])){
					e += Math.sqrt(d2(co[j][0], co[j][1], co[k][0], co[k][1]));
				}
			}
			ret += e/2;
			out.printf("%.14f\n", ret/100);
		}
	}
	
	public static double d2(double ax, double ay, double bx, double by)
	{
		return (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
	}

	
	public static boolean onSameLine(long ax, long ay, long bx, long by, long cx, long cy)
	{
		return (cx-ax)*(by-ay)-(cy-ay)*(bx-ax)==0;
	}
	
	public static boolean isClockwise(long[][] poly)
	{
		int n = poly.length;
		if(n <= 2)return true;
		long minx = Long.MAX_VALUE;
		long miny = Long.MAX_VALUE;
		int mini = -1;
		for(int i = 0;i < n;i++){
			if(poly[i][0] < minx || poly[i][0] == minx && poly[i][1] < miny){
				minx = poly[i][0]; miny = poly[i][1]; mini = i;
			}
		}
		int prev = (mini+n-1)%n;
		int next = (mini+1)%n;
		return ccw(poly[prev][0], poly[prev][1], poly[mini][0], poly[mini][1], poly[next][0], poly[next][1]) == 1;
	}
	
	public static int ccw(long ax, long ay, long bx, long by, long tx, long ty){ return Long.signum((tx-ax)*(by-ay)-(bx-ax)*(ty-ay)); }
	public static int ccw(long[] a, long[] b, long[] t){ return Long.signum((t[0]-a[0])*(b[1]-a[1])-(b[0]-a[0])*(t[1]-a[1])); }

	public long[][][] clipEar(long[][] poly)
	{
		if(poly.length == 2)return null;
		
		int n = poly.length;
		// 
		// O(N^2)
		// O(N^2)?
		List<long[]> list = new ArrayList<long[]>();
		for(long[] co : poly)list.add(co);
		
		long[][][] ret = new long[n-2][][];
		int p = 0;
		while(list.size() > 3){
			outer:
			for(int i = 0;i < list.size();i++){
				int m = list.size();
				long[] b = list.get(i), a = list.get((i+m-1)%m), c = list.get((i+1)%m);
				long cross = -(b[1]-a[1])*(c[0]-a[0])+(b[0]-a[0])*(c[1]-a[1]);
//				tr(i, cross, a, b, c);
				// 
				if(cross > 0){
					for(int j = 0;j < list.size();j++){
						if(j == i || j == (i+m-1)%m || j == (i+1) % m)continue;
						long[] u = list.get(j);
						if(isACB(a, c, u)){
							continue outer;
						}
						if(ccw(a, b, u) <= 0 && ccw(b, c, u) <= 0 && ccw(c, a, u) <= 0){
							continue outer;
						}
					}
//					
//					for(int j = 0;j < list.size();j++){
//						if(j == i || j == (i+m-1)%m)continue;
//						long[] u = list.get(j), v = list.get((j+1)%m);
//						long[] il = interLinesS(a, c, u, v);
//						if(il != null && il[0] > 0 && il[0] < il[2] && il[1] >= 0 && il[1] <= il[2]){
//							// crossing with some edge
//							continue outer;
//						}
//					}
					ret[p++] = new long[][]{a, b, c};
					list.remove(i);
					break;
				}else if(cross == 0){
					list.remove(i);
					break;
				}
			}
		}
		ret[p++] = new long[][]{list.get(0), list.get(1), list.get(2)};
		return Arrays.copyOf(ret, p);
	}
	
	public static boolean isACB(long ax, long ay, long bx, long by, long cx, long cy)
	{
		return (cx-ax)*(by-ay)-(cy-ay)*(bx-ax)==0 && (cx-ax)*(cx-bx)+(cy-ay)*(cy-by) <= 0;
	}
	
	public static boolean isACB(long[] a, long[] b, long[] c)
	{
		return (c[0]-a[0])*(b[1]-a[1])-(c[1]-a[1])*(b[0]-a[0])==0 && (c[0]-a[0])*(c[0]-b[0])+(c[1]-a[1])*(c[1]-b[1]) <= 0;
	}
	
	public static long[] interLinesS(long ax, long ay, long bx, long by,
			long cx, long cy, long dx, long dy) {
		long aa = bx - ax;
		long cc = by - ay;
		long bb = cx - dx;
		long dd = cy - dy;
		long xx = cx - ax;
		long yy = cy - ay;
		long det = aa * dd - bb * cc;
		if (det == 0)
			return null;
		long tnum = dd * xx - bb * yy;
		long unum = -cc * xx + aa * yy;
		if (det < 0) {
			det = -det;
			tnum = -tnum;
			unum = -unum;
		}
		//		if(tnum < 0 || tnum > det || unum < 0 || unum > det)return null;
		return new long[] { tnum, unum, det };
	}

	public static long[] interLinesS(long[] a, long[] b, long[] c, long[] d) {
		return interLinesS(a[0], a[1], b[0], b[1], c[0], c[1], d[0], d[1]);
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