//package goodbye2013;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = na(K+1);
		}
		double[] S = new double[n];
		for(int i = 0;i < K;i++){
			double[][] cont = new double[][]{
					{0, a[0][i]}, {1, a[0][i+1]}
			};
			double eps = 1E-9;
			double prevs = 0;
			for(int j = 0;j < n;){
				double ls = 0;
				for(int k = 0;k < cont.length-1;k++){
					ls += (cont[k][1]+cont[k+1][1])*(cont[k+1][0]-cont[k][0])/2;
				}
				S[j] += ls - prevs;
				prevs = ls;
				
				j++;
				if(j == n)break;
				
				if(a[j][i] >= cont[0][1]-eps && a[j][i+1] >= cont[cont.length-1][1]-eps){
					cont = new double[][]{
							{0, a[j][i]}, {1, a[j][i+1]}
					};
					continue;
				}
				
				int ins = -1;
				double insx = -1, insy = -1;
				for(int k = 0;k < cont.length-1;k++){
					double[] il = interLines(
							cont[k][0], cont[k][1], cont[k+1][0], cont[k+1][1],
							0, a[j][i], 1, a[j][i+1]
									);
					if(il != null && il[2] >= -eps && il[2] <= 1+eps && il[3] >= -eps && il[3] <= 1+eps){
						ins = k;
						insx = il[0]; insy = il[1];
						break;
					}
				}
				if(ins == -1)continue;
				if(a[j][i] > cont[0][1]+eps){
					double[][] ncont = new double[cont.length-(ins+1)+2][];
					int p = 0;
					ncont[p++] = new double[]{0, a[j][i]};
					ncont[p++] = new double[]{insx, insy};
					for(int k = ins+1;k < cont.length;k++)ncont[p++] = cont[k];
					if(p != ncont.length)throw new RuntimeException();
					cont = ncont;
					continue;
				}
				if(a[j][i+1] > cont[cont.length-1][1]+eps){
					double[][] ncont = new double[ins+1+2][];
					int p = 0;
					for(int k = 0;k <= ins;k++)ncont[p++] = cont[k];
					ncont[p++] = new double[]{insx, insy};
					ncont[p++] = new double[]{1, a[j][i+1]};
					if(p != ncont.length)throw new RuntimeException();
					cont = ncont;
					continue;
				}
				
				int end = -1;
				double endx = -1, endy = -1;
				for(int k = cont.length-2;k >= 0;k--){
					double[] il = interLines(
							cont[k][0], cont[k][1], cont[k+1][0], cont[k+1][1],
							0, a[j][i], 1, a[j][i+1]
									);
					if(il != null && il[2] >= -eps && il[2] <= 1+eps && il[3] >= -eps && il[3] <= 1+eps){
						end = k;
						endx = il[0]; endy = il[1];
						break;
					}
				}
				if(ins == end || end == -1)continue;
				
				double[][] ncont = new double[cont.length+1-(end-ins-1)][];
				int p = 0;
				for(int k = 0;k <= ins;k++)ncont[p++] = cont[k];
				ncont[p++] = new double[]{insx, insy};
				ncont[p++] = new double[]{endx, endy};
				for(int k = end+1;k < cont.length;k++)ncont[p++] = cont[k];
				if(p != ncont.length)throw new RuntimeException();
				cont = ncont;
			}
		}
		for(int i = 0;i < n;i++){
			out.printf("%.15f\n", S[i]);
		}
	}
	
	public static double areaPoly(double[][] poly)
	{
		int n = poly.length;
		if(n <= 2)return 0.;
		double s = 0;
		for(int i = 0;i < n - 1;i++){
			s += (poly[i][0]*poly[i+1][1]-poly[i+1][0]*poly[i][1]) / 2;
		}
		s += (poly[n-1][0]*poly[0][1]-poly[0][0]*poly[n-1][1]) / 2;
		return Math.abs(s);
	}
	
	public static double[] interLines(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy)
	{
		double eps = 1E-9;
		double aa = bx - ax;
		double cc = by - ay;
		double bb = cx - dx;
		double dd = cy - dy;
		double xx = cx - ax;
		double yy = cy - ay;
		double det = aa * dd - bb * cc;
		if(Math.abs(det) < eps)return null;
		double t = (dd * xx - bb * yy) / det;
		double u = (-cc * xx + aa * yy) / det;
		return new double[]{ax + (bx - ax) * t, ay + (by - ay) * t, t, u};
	}
	
	void run() throws Exception
	{
//		int n = 300, m = 300;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			for(int j = 0;j < m+1;j++){
////				sb.append(gen.nextInt(1000)+1 + " ");
//				if(j % 2 == 0){
//					sb.append((1000-i) + " ");
//				}else{
//					sb.append((1000-300+i) + " ");
//				}
//			}
//		}
//		INPUT = sb.toString();
		
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