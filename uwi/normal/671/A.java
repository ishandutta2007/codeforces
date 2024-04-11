//package round352;
import java.awt.geom.Point2D;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = ""
			+ "";
	
	void solve()
	{
		long ax = ni(), ay = ni();
		long bx = ni(), by = ni();
		long tx = ni(), ty = ni();
		int n = ni();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			co[i] = new long[]{ni(), ni()};
		}
		double base = 0;
		for(int i = 0;i < n;i++){
			base += Point2D.distance(tx, ty, co[i][0], co[i][1])*2;
		}
		double[] gaina = new double[n];
		double[] gainb = new double[n];
		for(int i = 0;i < n;i++){
			gaina[i] = -Point2D.distance(tx, ty, co[i][0], co[i][1])
					 + Point2D.distance(ax, ay, co[i][0], co[i][1]);
			gainb[i] = -Point2D.distance(tx, ty, co[i][0], co[i][1])
					 + Point2D.distance(bx, by, co[i][0], co[i][1]);
		}
		int[] ga = get2(gaina);
		int[] gb = get2(gainb);
		double alla = base + gaina[ga[0]];
		double allb = base + gainb[gb[0]];
		double ret = Math.min(alla, allb);
		if(ga[0] != gb[0]){
			out.printf("%.14f\n", Math.min(ret, base + gaina[ga[0]] + gainb[gb[0]]));
		}else{
			if(n >= 2){
				ret = Math.min(ret, base + gaina[ga[0]] + gainb[gb[1]]);
				ret = Math.min(ret, base + gaina[ga[1]] + gainb[gb[0]]);
			}
			out.printf("%.14f\n", ret);
		}
	}
	
	int[] get2(double[] gain)
	{
		double min = Double.POSITIVE_INFINITY;
		int argmin = -1;
		double min2 = Double.POSITIVE_INFINITY;
		int argmin2 = -1;
		for(int i = 0;i < gain.length;i++){
			if(gain[i] < min){
				min2 = min;
				argmin2 = argmin;
				min = gain[i];
				argmin = i;
			}else if(gain[i] < min2){
				min2 = gain[i];
				argmin2 = i;
			}
		}
		return new int[]{argmin, argmin2};
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
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
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