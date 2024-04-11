//package round660;
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
	
	public static int gcd(int a, int b) {
		while (b > 0) {
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = na(3);
		}
		
//		Set<Double> set = new HashSet<>();
//		for(int i = 1990000;i <= 2000000;i++){
//			for(int j = i+1;j <= 2000000;j++){
//				if(gcd(i, j) != 1)continue;
//				if(!set.add((double)i/j)){
//					tr(i, j, (double)i/j);
//					assert false;
//				}
//			}
//		}
		
		double[][] es = new double[n*n][];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(co[i][2] < co[j][2]){
					int[] D = co[i], U = co[j];
					double ngl = (double)(D[0]-U[1])/(U[2]-D[2]);
					double ngr = (double)(D[1]-U[0])/(U[2]-D[2]);
					assert ngl <= ngr;
					es[p++] = new double[]{ngl, 1};
					es[p++] = new double[]{ngr, -1};
				}
			}
		}
		es = Arrays.copyOf(es, p);
		Arrays.sort(es, new Comparator<double[]>() {
			public int compare(double[] a, double[] b) {
				if(a[0] != b[0])return Double.compare(a[0], b[0]);
				return Double.compare(a[1], b[1]);
			}
		});
		
		
		EnvelopeLinearD elmin = new EnvelopeLinearD(n);
		EnvelopeLinearD elmax = new EnvelopeLinearD(n);
		int[][] mins = new int[n][];
		int[][] maxs = new int[n][];
		for(int i= 0;i < n;i++){
			// x - ky
			mins[i] = new int[]{-co[i][2], co[i][0]};
			maxs[i] = new int[]{-co[i][2], co[i][1]};
		}
		Arrays.sort(mins, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[0] - b[0]);
			}
		});
		Arrays.sort(maxs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[0] - b[0]);
			}
		});
		for(int[] u : mins){
			elmin.add(u[0], u[1]);
		}
		for(int[] u : maxs){
			elmax.add(u[0], -u[1]);
		}

		int h = 0;
		double ans = -elmax.min(2000005)-elmin.min(-2000005);

		for(double[] e : es){
			h += e[1];
			if(e[1] > 0 && h == 1 || e[1] < 0 && h <= 0){
//				tr(e, -elmax.min(e[0]), -elmin.min(-e[0]));
				ans = Math.min(ans, -elmax.min(e[0])-elmin.min(-e[0]));
			}
		}
		out.printf("%.14f\n", ans);
	}
	
	public static class EnvelopeLinearD {
		public static final double INF = Double.NEGATIVE_INFINITY;
		
		public double[] xs;
		public double[] intercepts, slopes;
		public int p;
		
		public EnvelopeLinearD(int n)
		{
			xs = new double[n];
			intercepts = new double[n];
			slopes = new double[n];
			p = 0;
		}
		
		public void clear()
		{
			p = 0;
		}
		
		public void add(double slope, double intercept)
		{
			assert p == 0 || slopes[p-1] >= slope;
			while(p > 0){
				int i = p-1;
				if(p > 1 && intercept+xs[i]*slope <= intercepts[i]+xs[i]*slopes[i]){ // x=xs[i]
					p--;
					continue;
				}
				if(slope == slopes[i]){
					if(intercept >= intercepts[i]){
						return;
					}else{
						p--;
						continue;
					}
				}
				// y=sx+i vs y=Sx+I
				// sx+i=Sx+I
				// x=(i-I)/(S-s)
				double num = intercept-intercepts[i];
				double den = slopes[i]-slope;
				xs[p] = num/den;
				intercepts[p] = intercept;
				slopes[p] = slope;
				p++;
				return;
			}
			
			xs[p] = INF;
			intercepts[p] = intercept;
			slopes[p] = slope;
			p++;
		}
		
		public int argmin(double x)
		{
			if(p <= 0)return -1;
			int ind = Arrays.binarySearch(xs, 0, p, x);
			if(ind < 0)ind = -ind-2;
			return ind;
		}
		
		public double min(double x)
		{
			if(p <= 0)return Double.NEGATIVE_INFINITY;
			int ind = Arrays.binarySearch(xs, 0, p, x);
			if(ind < 0)ind = -ind-2;
			return slopes[ind]*x + intercepts[ind];
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