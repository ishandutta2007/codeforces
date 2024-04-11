//package test6;
import java.awt.geom.Point2D;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.TreeSet;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		if(n == 3 || n == 4){
			out.println("No solution");
			return;
		}
		double E = n*60;
		Random gen = new Random();
		double[][] co = new double[n][];
		outer:
		while(true){
			for(int i = 0;i < n;i++){
				co[i] = new double[]{E*Math.cos(i*Math.PI*2/n), E*Math.sin(i*Math.PI*2/n)};
			}
			
			for(int i = 0;i < 10000;i++){
				int ind = gen.nextInt(n);
				int nex = (ind+1)%n;
				double ta = -Math.PI/2+ind*Math.PI*2/n-Math.PI/n;
				double tb = Math.PI/2+nex*Math.PI*2/n+Math.PI/n;
	//			tr(ta, tb, ind, nex);
				double del = gen.nextDouble() * 6 - (double)3;
				co[ind][0] += del * Math.cos(ta);
				co[ind][1] += del * Math.sin(ta);
				co[nex][0] += del * Math.cos(tb);
				co[nex][1] += del * Math.sin(tb);
			}
			double minlen = Double.POSITIVE_INFINITY;
			double maxlen = 0;
			for(int i = 0;i < n;i++){
				int e = (i+1)%n;
				double d = Point2D.distance(co[i][0], co[i][1], co[e][0], co[e][1]);
				if(d < minlen){
					minlen = d;
				}
				if(d > maxlen){
					maxlen = d;
				}
			}
			if(minlen < 1.001)continue;
			if(maxlen > 999.999)continue;
			
			TreeSet<Double> ts = new TreeSet<Double>();
			for(int i = 0;i < n;i++){
				int e = (i+1)%n;
				ts.add(Point2D.distance(co[i][0], co[i][1], co[e][0], co[e][1]));
			}
//			tr(ts.first());
//			tr(ts.last());
			
			double prev = 0;
			double min = Double.POSITIVE_INFINITY;
			for(double x : ts){
				if(x-prev < 0.01)continue outer;
				min = Math.min(min, x-prev);
				prev = x;
			}
			break;
		}
		
//		TreeSet<Double> ts = new TreeSet<Double>();
//		for(int i = 0;i < n;i++){
//			int e = (i+1)%n;
//			ts.add(Point2D.distance(co[i][0], co[i][1], co[e][0], co[e][1]));
//		}
//		tr(ts.first());
//		tr(ts.last());
//		
//		double prev = 0;
//		double min = Double.POSITIVE_INFINITY;
//		for(double x : ts){
//			min = Math.min(min, x-prev);
//			prev = x;
//		}
//		tr("min", min);
		
		for(int i = 0;i < n;i++){
			out.printf("%.3f %.3f\n", co[i][0], co[i][1]);
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