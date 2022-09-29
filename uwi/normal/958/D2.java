//package helvetic2018;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Random;

public class D2X2 {
	InputStream is;
	PrintWriter out;
//	String INPUT = "2 5\r\n" + 
//			"5 0 9 2 0 -30 0 -31 36 0 -3 0 -41 -30 0 25 0 -16 1 0 -10 0 31 35 0 42 \r\n" + 
//			"5 0 -40 42 0 35 0 -17 -36 0 -14 0 12 6 0 -48 0 6 6 0 -19 0 -43 4 0 -26 ";
//	
	String INPUT = "";
	
	void solve()
	{
		Random gen = new Random();
		int n = ni(), D = ni();
		
		double[][] X = new double[D][D];
		for(int i = 0;i < D;i++){
			for(int j = 0;j < D;j++){
				X[i][j] = gen.nextDouble();
			}
		}
		
		double[][][] ms = new double[n][][];
		double[] hs = new double[n];
		for(int i = 0;i < n;i++){
			int K = ni();
			double[][] vs = new double[K][];
			for(int j = 0;j < K;j++){
				vs[j] = new double[D];
				for(int k = 0;k < D;k++)vs[j][k] = nd();
			}
			double[][] ovs = orthonormalize(vs);
			ms[i] = projectionMatrix(ovs, D);
//			for(double[] row : ms[i])tr(row);

			double h = 0;
			for(int j = 0;j < D;j++){
				for(int k = 0;k < D;k++){
					h = h + X[j][k] * ms[i][j][k];
				}
			}
			hs[i] = h;
		}
		
		double[][] hi = new double[n][];
		for(int i = 0;i < n;i++){
			hi[i] = new double[]{hs[i], i};
		}
		
		Arrays.sort(hi, new Comparator<double[]>() {
			public int compare(double[] a, double[] b) {
				return Double.compare(a[0], b[0]);
			}
		});
		int[] iord = new int[n];
		for(int i = 0;i < n;i++){
			iord[(int)hi[i][1]] = i;
		}
		
		int[] ar = new int[n];
		Arrays.fill(ar, -1);
//		tr(hi);
		
		int id = 1;
		double eps = 1e-10;
		for(int i = 0;i < n;i++){
			if(ar[iord[i]] == -1){
				ar[iord[i]] = id;
				for(int x = iord[i]-1;x >= 0 && ar[x] == -1;x--){
					if(Math.abs(hi[x][0] - hi[iord[i]][0]) < eps){
						ar[x] = id;
					}else{
						break;
					}
				}
				for(int x = iord[i]+1;x < n && ar[x] == -1;x++){
					if(Math.abs(hi[x][0] - hi[iord[i]][0]) < eps){
						ar[x] = id;
					}else{
						break;
					}
				}
				id++;
			}
			out.print(ar[iord[i]] + " ");
		}
	}
	
	static double[][] projectionMatrix(double[][] ovs, int D)
	{
		double[][] M = new double[D][D];
		for(double[] v : ovs){
			for(int i = 0;i < D;i++){
				for(int j = 0;j < D;j++){
					M[i][j] += v[i] * v[j];
				}
			}
		}
		return M;
	}
	
	public static double[][] orthonormalize(double[][] vs)
	{
		int K = vs.length;
		int D = vs[0].length;
		double[][] ovs = new double[K][];
		ovs[0] = vs[0];
		for(int j = 1;j < K;j++){
			double[] h = Arrays.copyOf(vs[j], D);
			for(int l = 0;l < j;l++){
				double dot = 0;
				double norm = 0;
				for(int k = 0;k < D;k++){
					dot += vs[j][k] * ovs[l][k];
					norm += ovs[l][k] * ovs[l][k];
				}
				if(norm < 1e-11)continue;
				double t = dot / norm;
				for(int k = 0;k < D;k++){
					h[k] -= ovs[l][k] * t;
				}
			}
			ovs[j] = h;
		}
		for(int j = 0;j < K;j++){
			ovs[j] = normalize(ovs[j]);
		}
		return ovs;
	}
	
	static double norm(double[] v)
	{
		double n = 0;
		for(double w : v)n += w*w;
		return n;
	}
	
	static double dot(double[] a, double[] b)
	{
		double ret = 0;
		for(int i = 0;i < a.length;i++){
			ret += a[i] * b[i];
		}
		return ret;
	}
	
	static double[] normalize(double[] v)
	{
		double n = Math.sqrt(norm(v));
		if(n < 1e-10)return new double[v.length];
		for(int i = 0;i < v.length;i++)v[i] /= n;
		return v;
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
	
	public static void main(String[] args) throws Exception { new D2X2().run(); }
	
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