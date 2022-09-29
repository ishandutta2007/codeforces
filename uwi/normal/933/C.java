//package round462;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C4 {
	InputStream is;
	PrintWriter out;
//	String INPUT = "3 0 0 3 1 0 2 -2 0 1";
//	String INPUT = "3 0 0 1 1 0 1 2 0 1";
//	String INPUT = "3 0 0 5 6 0 5 0 -8 5";
//	String INPUT = "3 0 0 3 1 0 2 2 0 1";
//	String INPUT = "3 0 0 9 0 0 8 0 -10 10";
//	String INPUT = "3 0 10 10 0 -10 10 0 0 1";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			co[i] = new long[]{ni(), ni(), ni()};
		}
		
		double[][] nodes = new double[10][];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				double[] ts = crossSimple(
						co[i][0], co[i][1], co[i][2],
						co[j][0], co[j][1], co[j][2]
								);
				for(int k = 0;k < ts.length;k++){
					nodes[p++] = new double[]{
							co[i][0] + co[i][2] * Math.cos(ts[k]),
							co[i][1] + co[i][2] * Math.sin(ts[k])
					};
				}
			}
		}
		nodes = Arrays.copyOf(nodes, p);
		int q = 0;
		outer:
		for(int i = 0;i < p;i++){
			for(int j = i+1;j < p;j++){
				if(d2(nodes[i][0], nodes[i][1], nodes[j][0], nodes[j][1]) < 1e-12){
					continue outer;
				}
			}
			nodes[q++] = nodes[i];
		}
		
		int nnodes = q;
		int ne = 0;
		int con = 1;
		for(int j = 0;j < n;j++){
			int e = 0;
			for(int i = 0;i < q;i++){
				if(Math.abs(d2(nodes[i][0], nodes[i][1], co[j][0], co[j][1])-co[j][2]*co[j][2]) < 1e-12){
					e++;
				}
			}
			if(e == 0)con++;
			ne += e;
		}
		if(con > n)con = n;
		out.println(ne-nnodes+con+1);
	}
	
	public static double d2(double ax, double ay, double bx, double by)
	{
		return (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
	}

	
	static double EPS = 1E-10;
	
	// (x,y,r)(tx,ty,tr)
	public static double[] crossSimple(long x, long y, long r, long tx, long ty, long tr)
	{
		long d2 = d2(x, y, tx, ty);
		if(d2 < (r-tr)*(r-tr))return new double[0]; // covered or covering
		if(d2 > (r+tr)*(r+tr))return new double[0]; // not intersects or touched
		double base = Math.atan2(ty-y, tx-x);
		double wing = Math.acos((d2+r*r-tr*tr)/(2*Math.sqrt(d2)*r)); // Law of cosines
//		assert Double.isFinite(base);
//		assert Double.isFinite(wing);
		double inf = base - wing, sup = base + wing;
		return new double[]{inf, sup};
	}
	
	public static long d2(long ax, long ay, long bx, long by)
	{
		return (bx-ax)*(bx-ax)+(by-ay)*(by-ay);
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
	
	public static void main(String[] args) throws Exception { new C4().run(); }
	
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