//package round444;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	// a,b c,d
	// x,y r
	void solve()
	{
		int a = ni(), b = ni(), c = ni(), d = ni();
		double bx = a + (double)(c-a)/2;
		double by = b + (double)(d-b)/2;
		double tx = -(d-b);
		double ty = c-a;
		
		int n = ni();
		int[][] cs = new int[n][];
		double[][] rs = new double[2*n][];
		for(int i = 0;i < n;i++){
			cs[i] = na(3);
			int side = Line2D.relativeCCW(a, b, c, d, cs[i][0], cs[i][1]);
			double[] range = new double[2];
			{
				double mr = Math.sqrt(tx * tx + ty * ty);
				double low = -1e13/mr, high = 1e13/mr;
				for(int rep = 0;rep < 70;rep++){
					double h = low + (high-low)/2;
					double cx = bx + tx * h;
					double cy = by + ty * h;
					double R = Point2D.distance(cx, cy, a, b);
					if(side == -1){
						// positive
						if(Point2D.distance(cx, cy, cs[i][0], cs[i][1]) >= R + cs[i][2]){
							low = h;
						}else{
							high = h;
						}
					}else{
						// negative
						if(Point2D.distance(cx, cy, cs[i][0], cs[i][1]) >= R + cs[i][2]){
							high = h;
						}else{
							low = h;
						}
					}
				}
				range[0] = low;
			}
			{
				double mr = Math.sqrt(tx * tx + ty * ty);
				double low = -1e13/mr, high = 1e13/mr;
				for(int rep = 0;rep < 70;rep++){
					double h = low + (high-low)/2;
					double cx = bx + tx * h;
					double cy = by + ty * h;
					double R = Point2D.distance(cx, cy, a, b);
					if(side == -1){
						// positive
						if(Point2D.distance(cx, cy, cs[i][0], cs[i][1]) >= R - cs[i][2]){
							low = h;
						}else{
							high = h;
						}
					}else{
						// negative
						if(Point2D.distance(cx, cy, cs[i][0], cs[i][1]) >= R - cs[i][2]){
							high = h;
						}else{
							low = h;
						}
					}
				}
				range[1] = low;
			}
			Arrays.sort(range);
//			tr(range);
			rs[i] = new double[]{range[0], 1};
			rs[i+n] = new double[]{range[1], -1};
		}
		Arrays.sort(rs, new Comparator<double[]>() {
			public int compare(double[] a, double[] b) {
				return Double.compare(a[0], b[0]);
			}
		});
		
		int h = 0;
		double prex = Double.NEGATIVE_INFINITY;
		double ans = Double.POSITIVE_INFINITY;
		for(double[] r : rs){
			if(h == 0){
				// prex, r[0]
				ans = Math.min(ans, Math.abs(prex));
				ans = Math.min(ans, Math.abs(r[0]));
				if(prex <= 0 && 0 <= r[0]){
					ans = 0;
				}
			}
			h += r[1];
			prex = r[0];
		}
		if(h == 0){
			ans = Math.min(ans, Math.abs(prex));
			if(prex <= 0){
				ans = 0;
			}
		}
		double cx = bx + tx * ans;
		double cy = by + ty * ans;
		out.printf("%.14f\n", Point2D.distance(cx, cy, a, b));
	}
	
	public static double d2(double ax, double ay, double bx, double by)
	{
		return (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
	}

	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		sb.append(-n + " ");
//		sb.append(-n + " ");
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(200000)-100000 + " ");
//			sb.append(gen.nextInt(200000)-100000 + " ");
//			sb.append(gen.nextInt(10)+1 + " ");
//		}
//		INPUT = sb.toString();

		
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