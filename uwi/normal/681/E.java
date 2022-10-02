//package round357;
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
		long x0 = ni(), y0 = ni(), v = ni(), T = ni();
		int n = ni();
		
		double[][] es = new double[4*n][];
		int p = 0;
		for(int i = 0;i < n;i++){
			long x = ni()-x0, y = ni()-y0, r = ni();
			// x^2+y^2 >= (vT+r)^2
			if(x*x+y*y > (double)(v*T+r)*(v*T+r)){
				continue;
			}
			if(x*x+y*y <= r*r){
				out.println(1);
				return;
			}
			double d = Math.sqrt(x*x+y*y);
			double base = Math.atan2(y, x);
			double e = Math.sqrt(x*x+y*y-r*r);
			double wing = 0;
			if(e <= v*T){
				wing = Math.asin(r/d);
			}else{
				double ac = ((double)(v*T)*(v*T)+(x*x+y*y)-r*r)/(2.*v*T*d);
				if(ac >= 1)ac = 1;
				if(ac <= -1)ac = -1;
				wing = Math.acos(ac);
			}
			double inf = base - wing;
			double sup = base + wing;
			for(double u = -4*Math.PI, w = -2*Math.PI;w <= 4*Math.PI;u +=  2*Math.PI, w += 2 * Math.PI){
				if(Math.max(inf, u) < Math.min(sup, w)){
					es[p++] = new double[]{Math.max(inf, u)-u, 1};
					es[p++] = new double[]{Math.min(sup, w)-u, -1};
				}
			}
		}
		Arrays.sort(es, 0, p, new Comparator<double[]>() {
			public int compare(double[] a, double[] b) {
				return Double.compare(a[0], b[0]);
			}
		});
		double pre = 0;
		int h = 0;
		double ret = 0;
		for(int i = 0;i < p;i++){
			if(h > 0){
				ret += es[i][0]-pre;
			}
			pre = es[i][0];
			h += (int)es[i][1];
		}
		out.printf("%.14f\n", ret/(2*Math.PI));
	}
	
	
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(1000000000 + " ");
//		sb.append(1000000000 + " ");
//		sb.append(0 + " ");
//		sb.append(1000000000 + " ");
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(2000000000)-1000000000 + " ");
//			sb.append(gen.nextInt(2000000000)-1000000000 + " ");
//			sb.append(gen.nextInt(101) + " ");
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