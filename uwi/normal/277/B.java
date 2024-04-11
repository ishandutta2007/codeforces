//package round170;
import java.awt.geom.Line2D;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Random;

public class B2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		if(m == 3 && n >= 5){
			out.println(-1);
			return;
		}
		int r = 99999997;
		Random gen = new Random();
		long[][] co = new long[n][];
		for(int i = 0;i < m;i++){
			double t = (double)i/m*2*Math.PI;
			co[i] = new long[]{Math.round(r*Math.cos(t)), Math.round(r*Math.sin(t))};
		}
		while(true){
//			int sr = gen.nextInt((r-9)/3)+3;
			int sr = gen.nextInt((int)Math.sqrt(r)-3)+3;
			for(int i = m;i < n;i++){
				double t = (double)((i-m)/(n-m)+gen.nextDouble())*2*Math.PI;
				co[i] = new long[]{Math.round(sr*Math.cos(t)), Math.round(sr*Math.sin(t))};
			}
			if(ok(co, m)){
				for(int i = 0;i < n;i++){
					out.println(co[i][0] + " " + co[i][1]);
				}
				return;
			}
		}
	}
	
	
	boolean ok(long[][] co, int K)
	{
		int n = co.length;
		// sameline
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int k = j+1;k < n;k++){
					if(onSameLine(co[i][0], co[i][1], co[j][0], co[j][1], co[k][0], co[k][1])){
						return false;
					}
				}
			}
		}
		
		if(n < 15){
			for(int i = 0;i < 1<<n;i++){
				if(Integer.bitCount(i) == K+1){
					double[] x = new double[K+1];
					double[] y = new double[K+1];
					int p = 0;
					for(int j = 0;j < n;j++){
						if(i<<31-j<0){
							x[p] = co[j][0];
							y[p] = co[j][1];
							p++;
						}
					}
					if(convexHull(x, y).length == K+1)return false;
				}
			}
		}
		return true;
	}
	
	public static int[] convexHull(final double[] x, final double[] y)
	{
		int n = x.length;
		Integer[] ord = new Integer[n];
		for(int i = 0;i < n;i++)ord[i] = i;
		Arrays.sort(ord, new Comparator<Integer>(){
			public int compare(Integer a, Integer b){
				if(x[a] != x[b])return x[a] < x[b] ? -1 : 1;
				if(y[a] != y[b])return y[a] < y[b] ? -1 : 1;
				return 0;
			}
		});
		
		int[] ret = new int[n + 1];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(p >= 1 && x[ret[p-1]] == x[ord[i]] && y[ret[p-1]] == y[ord[i]])continue;
			while(p >= 2 && Line2D.relativeCCW(
					x[ret[p-2]], y[ret[p-2]],
					x[ret[p-1]], y[ret[p-1]],
					x[ord[i]], y[ord[i]]) == 1)p--;
			ret[p++] = ord[i];
		}
		
		int inf = p + 1;
		for(int i = n - 2;i >= 0;i--){
			if(x[ret[p-1]] == x[ord[i]] && y[ret[p-1]] == y[ord[i]])continue;
			while(p >= inf && Line2D.relativeCCW(
					x[ret[p-2]], y[ret[p-2]],
					x[ret[p-1]], y[ret[p-1]],
					x[ord[i]], y[ord[i]]) == 1)p--;
			ret[p++] = ord[i];
		}
		
		return Arrays.copyOf(ret, p - 1);
	}
	
	public static boolean onSameLine(long ax, long ay, long bx, long by, long cx, long cy)
	{
		return (cx-ax)*(by-ay)-(cy-ay)*(bx-ax)==0;
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
	
	public static void main(String[] args) throws Exception { new B2().run(); }
	
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