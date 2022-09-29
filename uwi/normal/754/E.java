//package round390;
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
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		int u = ni(), w = ni();
		char[][] q = nm(u, w);
		
		int[][] a = new int[400][400];
		int[][] b = new int[400][400];
		int[][] c = new int[400][400];
		int[][] d = new int[400][400];
		int[][] dup = new int[n][m];
		for(char ch = 'a';ch <= 'z';ch+=2){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					a[i][j] = map[i][j] == ch ? 1 : 0;
					c[i][j] = map[i][j] == ch+1 ? 1 : 0;
				}
			}
			for(int i = 0;i < u;i++){
				for(int j = 0;j < w;j++){
					b[u-1-i][w-1-j] = q[i][j] == ch ? 1 : 0;
					d[u-1-i][w-1-j] = q[i][j] == ch+1 ? -1 : 0;
				}
			}
			double[][][] conv = convolute(a, b, c, d);
			for(int i = 0;i < conv.length;i++){
				for(int j = 0;j < conv[0][0].length;j++){
					int rr = i-u+1, cc = j-w+1;
					rr %= n; cc %= m;
					if(rr < 0)rr += n;
					if(cc < 0)cc += m;
					dup[rr][cc] += (int)Math.round(conv[i][0][j]);
				}
			}
		}
		int nq = 0;
		for(int i = 0;i < u;i++){
			for(char ch : q[i]){
				if(ch != '?')nq++;
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				assert dup[i][j] <= nq;
				if(dup[i][j] == nq){
					out.print(1);
				}else{
					out.print(0);
				}
			}
			out.println();
		}
	}
	
	public static double[][] fft(int[] srcRe, int[] srcIm, int n, boolean inverse)
	{
		int m = srcRe.length;
		double[] dstRe = new double[n];
		double[] dstIm = new double[n];
		for(int i = 0;i < m;i++){
			dstRe[i] = srcRe[i];
			dstIm[i] = srcIm[i];
		}
		
		int h = Integer.numberOfTrailingZeros(n);
		for(int i = 0;i < n;i++){
			int rev = Integer.reverse(i)>>>32-h;
			if(i < rev){
				{double d = dstRe[i]; dstRe[i] = dstRe[rev]; dstRe[rev] = d;}
				{double d = dstIm[i]; dstIm[i] = dstIm[rev]; dstIm[rev] = d;}
			}
		}
		
		for(int s = 2;s <= n;s <<= 1){
			int nt = s >>> 1;
			double theta = inverse ? -2*Math.PI/s : 2*Math.PI/s;
			double wRe = Math.cos(theta);
			double wIm = Math.sin(theta);
			for(int j = 0; j < n;j += s){
				double wr = 1, wi = 0;
				for(int t = j;t < j+nt;t++){
					int jp = t + nt;
					double re = dstRe[jp]*wr - dstIm[jp]*wi;
					double im = dstRe[jp]*wi + dstIm[jp]*wr;
					dstRe[jp] = dstRe[t] - re;
					dstIm[jp] = dstIm[t] - im;
					dstRe[t] += re;
					dstIm[t] += im;
					double nwre = wr * wRe - wi * wIm;
					double nwim = wr * wIm + wi * wRe;
					wr = nwre; wi = nwim;
				}
			}
		}
		
		if(inverse){
			for(int i = 0;i < n;i++){
				dstRe[i] /= n;
				dstIm[i] /= n;
			}
		}
		
		return new double[][]{dstRe, dstIm};
	}
	
	public static void fft(double[] re, double[] im, boolean inverse)
	{
		int n = re.length;
		int h = Integer.numberOfTrailingZeros(n);
		for(int i = 0;i < n;i++){
			int rev = Integer.reverse(i)>>>32-h;
			if(i < rev){
				double d = re[i]; re[i] = re[rev]; re[rev] = d;
				d = im[i]; im[i] = im[rev]; im[rev] = d;
			}
		}
		
		for(int s = 2;s <= n;s <<= 1){
			int nt = s >>> 1;
			double theta = inverse ? -2*Math.PI/s : 2*Math.PI/s;
			double wRe = Math.cos(theta);
			double wIm = Math.sin(theta);
			for(int j = 0; j < n;j += s){
				double wr = 1, wi = 0;
				for(int t = j;t < j+nt;t++){
					int jp = t + nt;
					double lre = re[jp]*wr - im[jp]*wi;
					double lim = re[jp]*wi + im[jp]*wr;
					re[jp] = re[t] - lre;
					im[jp] = im[t] - lim;
					re[t] += lre;
					im[t] += lim;
					double nwre = wr * wRe - wi * wIm;
					double nwim = wr * wIm + wi * wRe;
					wr = nwre; wi = nwim;
				}
			}
		}
		
		if(inverse){
			for(int i = 0;i < n;i++){
				re[i] /= n;
				im[i] /= n;
			}
		}
	}
	
	/**
	 * 2D FFT
	 * @param a
	 * @param b
	 * @return
	 * @verified JAG13SpringF
	 */
	public static double[][][] convolute(int[][] a, int[][] b, int[][] c, int[][] d)
	{
		int m = Integer.highestOneBit(Math.max(1, Math.max(a.length, b.length)-1))<<2;
		int n = a.length;
		double[][][] fa = new double[m][][];
		for(int i = 0;i < n;i++){
			fa[i] = fft(a[i], c[i], m, false);
		}
		for(int i = n;i < m;i++){
			fa[i] = new double[2][m];
		}
		
		double[][][] tfa = new double[m][][];
		for(int i = 0;i < m;i++){
			tfa[i] = new double[2][m];
			for(int j = 0;j < m;j++){
				tfa[i][0][j] = fa[j][0][i];
				tfa[i][1][j] = fa[j][1][i];
			}
			fft(tfa[i][0], tfa[i][1], false);
		}
		
		double[][][] fb = new double[m][][];
		for(int i = 0;i < n;i++){
			fb[i] = fft(b[i], d[i], m, false);
		}
		for(int i = n;i < m;i++){
			fb[i] = new double[2][m];
		}
		
		double[][][] tfb = new double[m][][];
		for(int i = 0;i < m;i++){
			tfb[i] = new double[2][m];
			for(int j = 0;j < m;j++){
				tfb[i][0][j] = fb[j][0][i];
				tfb[i][1][j] = fb[j][1][i];
			}
			fft(tfb[i][0], tfb[i][1], false);
		}
		
		for(int j = 0;j < m;j++){
			for(int i = 0;i < m;i++){
				double nfa0 = tfa[j][0][i]*tfb[j][0][i]-tfa[j][1][i]*tfb[j][1][i];
				double nfa1 = tfa[j][0][i]*tfb[j][1][i]+tfa[j][1][i]*tfb[j][0][i];
				tfa[j][0][i] = nfa0;
				tfa[j][1][i] = nfa1;
			}
			fft(tfa[j][0], tfa[j][1], true);
		}
		
		double[][][] r = new double[m][2][m];
		for(int j = 0;j < m;j++){
			for(int k = 0;k < m;k++){
				r[j][0][k] = tfa[k][0][j];
				r[j][1][k] = tfa[k][1][j];
			}
			fft(r[j][0], r[j][1], true);
		}
		
		return r;
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