//package round170;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni(), ni()};
		}
		
		// out:2, in:1
		double[][] g = new double[n][2*n];
		double I = 3000*800;
		for(int i = 0;i < n;i++){
			Arrays.fill(g[i], I);
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(co[i][1] > co[j][1]){
					double d = Math.sqrt(
							(co[i][0]-co[j][0])*(co[i][0]-co[j][0])+
							(co[i][1]-co[j][1])*(co[i][1]-co[j][1])
							);
					g[j][2*i] = g[j][2*i+1] = d;
				}
			}
		}
		double ret = hungarianMin(g);
		ret -= (n-(n-1))*I;
		if(ret >= I){
			out.println(-1);
		}else{
			out.printf("%.12f\n", ret);
		}
	}
	
	public double hungarianMin(double[][] w)
	{
		int n = w.length*2;
		int h = n/2;
		double INF = Double.POSITIVE_INFINITY;
		double[] fx = new double[h];
		double[] fy = new double[n];
		int[] x = new int[h];
		int[] y = new int[n];
		Arrays.fill(x, -1);
		Arrays.fill(y, -1);
		
		int[] t = new int[n];
		int[] s = new int[h+1];
		outer:
		for(int i = 0;i < h;){
			Arrays.fill(t, -1);
			s[0] = i;
			int q = 0;
			for(int p = 0;p <= q;p++){
				for(int k = s[p], j = 0;j < n;j++){
					if(Math.abs(fx[k] + fy[j] - w[k][j]) < 1E-9 && t[j] < 0){
						s[++q] = y[j];
						t[j] = k;
						if(s[q] < 0){
							for(p = j;p >= 0;j = p){
								y[j] = k = t[j];
								p = x[k];
								x[k] = j;
							}
							i++;
							continue outer;
						}
					}
				}
			}
			double d = INF;
			for(int j = 0;j < n;j++){
				if(t[j] < 0){
					for(int k = 0;k <= q;k++){
						d = Math.min(d, w[s[k]][j] - fx[s[k]] - fy[j]);
					}
				}
			}
			
			for(int j = 0;j < n;j++){
				if(t[j] >= 0)fy[j] -= d;
			}
			for(int k = 0;k <= q;k++){
				fx[s[k]] += d;
			}
		}
		
		double ret = 0;
		for(int i = 0;i < h;i++){
			ret += w[i][x[i]];
		}
		return ret;
	}
	
	void run() throws Exception
	{
//		int n = 400, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(1000) + " ");
//			sb.append(gen.nextInt(1000) + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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