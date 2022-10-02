//package round176;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class EX {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[] h = new int[m+1];
		for(int i = 0;i < n;i++){
			h[ni()] = 1;
		}
		int[] h2 = convolute(h);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i <= m;i++){
			if(h[i] != 0){
				if(h2[i] != 0){
					// 
				}else{
					// 
					ret[p++] = i;
				}
			}else{
				if(h2[i] != 0){
					// violation
					out.println("NO");
					return;
				}
			}
		}
		out.println("YES");
		out.println(p);
		for(int i = 0;i < p;i++){
			if(i > 0)out.print(" ");
			out.print(ret[i]);
		}
		out.println();
	}
	
	public int[] convolute(int[] a)
	{
		int m = Integer.highestOneBit(a.length-1)<<2;
		double[][] fa = doFFFT(a, m, false);
		for(int i = 0;i < m;i++){
			double nfa0 = fa[0][i]*fa[0][i]-fa[1][i]*fa[1][i];
			double nfa1 = fa[0][i]*fa[1][i]+fa[1][i]*fa[0][i];
			fa[0][i] = nfa0;
			fa[1][i] = nfa1;
		}
		doFFFT(fa[0], fa[1], true);
		int[] ret = new int[m];
		for(int i = 0;i < m;i++){
			ret[i] = (int)Math.round(fa[0][i]);
		}
		return ret;
	}
	
//	public int[] convolute(int[] a, int[] b)
//	{
//		int m = Integer.highestOneBit(a.length|b.length)<<2;
//		prepareFFT(m);
//		double[][] fa = doFFFT(a, m);
//		double[][] fb = doFFFT(b, m);
//		double[][] fced = new double[2][m];
//		for(int i = 0;i < m;i++){
//			fced[0][i] = (fa[0][i]*fb[0][i]-fa[1][i]*fb[1][i])/m;
//			fced[1][i] = (fa[0][i]*fb[1][i]+fa[1][i]*fb[0][i])/-m;
//		}
//		double[][] ced = doFFFT(fced[0], fced[1]);
//		int[] ret = new int[m];
//		for(int i = 0;i < m;i++){
//			ret[i] = (int)Math.round(ced[0][i]);
//		}
//		return ret;
//	}
	
	public static double[][] doFFFT(int[] srcRe, int n, boolean inverse)
	{
		int m = srcRe.length;
		double[] dstRe = new double[n];
		double[] dstIm = new double[n];
		for(int i = 0;i < m;i++){
			dstRe[i] = srcRe[i];
		}
		
		int h = Integer.numberOfTrailingZeros(n);
		for(int i = 0;i < n;i++){
			int rev = Integer.reverse(i)>>>32-h;
			if(i < rev){
				double d = dstRe[i]; dstRe[i] = dstRe[rev]; dstRe[rev] = d;
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
	
	public static void doFFFT(double[] re, double[] im, boolean inverse)
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
	
	void run() throws Exception
	{
//		int n = 750000, m = 1000000;
//		new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(250000+i + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new EX().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}