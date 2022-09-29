//package round478;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "4 10 0 0 10 5 10 10 0 5 1 1 3 "
//			+ "2 1 2 2 2 3 2 4 "
//			+ "  1 2 3 2 1 2 2 2 3 2 4";
//	String INPUT = "3 8\r\n" + 
//	"0 0\r\n" + 
//	"2 0\r\n" + 
//	"2 2\r\n" + 
//	"1 1 1\r\n" + 
//	"2 1\r\n" + 
//	"2 2\r\n" + 
//	"2 3\r\n" +
//	"1 2 2\r\n" + 
//	"2 1\r\n" + 
//	"2 2\r\n" + 
//	"2 3";
//	String INPUT = "3 8 0 0 2 2 0 2 1 1 3 2 1 2 2 2 3 1 2 1 2 1 2 2 2 3";
//	String INPUT = "3 5\r\n" + 
//			"0 0\r\n" + 
//			"2 0\r\n" + 
//			"2 2\r\n" + 
//			"1 1 2\r\n" + 
//			"1 2 1\r\n" + 
//			"2 1\r\n" + 
//			"2 2\r\n" + 
//			"2 3";

	
	double[] g;
	int root = -1;
	double[][] co;
	double rx = 0, ry = 0;
	
	void solve()
	{
		int n = ni(), Q = ni();
		co = new double[n][];
		for(int i = 0;i < n;i++){
			co[i] = new double[]{ni(), ni()};
		}
		g = g(co);
		int[] pin = {0, 1};
		for(int z = 0;z < Q;z++){
			int type = ni();
			if(type == 1){
				int f = ni()-1, t = ni()-1;
				int ind = f == pin[0] ? 0 : 1;
				if(root != -1){
					double[] res = get(pin[ind^1]);
					rx = res[0];
					ry = res[1];
				}else{
					rx = co[pin[ind^1]][0];
					ry = co[pin[ind^1]][1];
				}
				root = pin[ind^1];
				pin[ind] = t;
			}else{
				int x = ni()-1;
				double[] res = get(x);
				out.printf("%.14f %.14f\n", res[0], res[1]);
			}
		}
	}
	
	double[] get(int id){
		if(root == -1){
			return co[id];
		}
		double theta = 3*Math.PI/2 - Math.atan2(g[1] - co[root][1], g[0] - co[root][0]);
		
		double x = co[id][0] - co[root][0];
		double y = co[id][1] - co[root][1];
		double cos = Math.cos(theta);
		double sin = Math.sin(theta);
		
		return new double[]{
				x*cos - y*sin + rx,
				x*sin + y*cos + ry
		};
	}
	
//	public static double[] g(double[][] co)
//	{
//		int n = co.length;
//		double S = 0;
//		double sx = 0, sy = 0;
//		for(int i = 0, j = 1;i < n;i++, j++){
//			if(j == n)j = 0;
//			double[] a = co[i], b = co[j];
//			double lgx = (a[0]+b[0])/3;
//			double lgy = (a[1]+b[1])/3;
//			double ls = (a[0]*b[1]-b[0]*a[1])/2;
//			S += ls;
//			sx += lgx*ls;
//			sy += lgy*ls;
//		}
//		return new double[]{sx/S, sy/S};
//	}

	public static double[] g(double[][] co)
	{
		int n = co.length;
		double S = 0;
		double sx = 0, sy = 0;
		double ox = co[0][0], oy = co[0][1];
		for(int i = 1, j = 2;j < n;i++,j++){
			double[] a = co[i], b = co[j];
			double lgx = (ox+a[0]+b[0])/3;
			double lgy = (oy+a[1]+b[1])/3;
			double ls = ((a[0]-ox)*(b[1]-oy)-(b[0]-ox)*(a[1]-oy))/2;
			S += ls;
			sx += lgx*ls;
			sy += lgy*ls;
		}
		return new double[]{sx/S, sy/S};
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