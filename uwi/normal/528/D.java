//package round296;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		char[] s = ns(n);
		char[] t = ns(m);
		boolean[] ret = new boolean[n-m+1];
		Arrays.fill(ret, true);
		for(char c : "ATGC".toCharArray()){
			int[] imos = new int[n+1];
			for(int i = 0;i < n;i++){
				if(s[i] == c){
					imos[Math.max(i-K, 0)]++;
					imos[Math.min(n, i+K+1)]--;
				}
			}
			for(int i = 1;i <= n;i++){
				imos[i] += imos[i-1];
			}
			for(int i = 0;i <= n;i++){
				if(imos[i] > 1)imos[i] = 1;
			}
			
			int ap = 0;
			int[] tt = new int[m];
			for(int i = 0;i < m;i++){
				if(t[i] == c){
					tt[m-1-i] = 1;
					ap++;
				}
			}
			if(ap == 0)continue;
			
//			tr(c);
//			tr(imos);
//			tr(tt);
			long[] v = convolute(imos, tt);
//			tr(v);
			for(int i = 0;i < n-m+1;i++){
				if(v[i+m-1] != ap){
					ret[i] = false;
				}
			}
		}
		int re = 0;
		for(int i = 0;i < n-m+1;i++){
			if(ret[i])re++;
		}
		out.println(re);
	}
	
	public static long[] convolute(int[] a, int[] b)
	{
		int m = Integer.highestOneBit(Math.max(Math.max(a.length, b.length)-1, 1))<<2;
		double[][] fa = fft(a, m, false);
		double[][] fb = a == b ? fa : fft(b, m, false);
		for(int i = 0;i < m;i++){
			double nfa0 = fa[0][i]*fb[0][i]-fa[1][i]*fb[1][i];
			double nfa1 = fa[0][i]*fb[1][i]+fa[1][i]*fb[0][i];
			fa[0][i] = nfa0;
			fa[1][i] = nfa1;
		}
		fft(fa[0], fa[1], true);
		long[] ret = new long[m];
		for(int i = 0;i < m;i++){
			ret[i] = Math.round(fa[0][i]);
		}
		return ret;
	}
	
	public static double[][] fft(int[] srcRe, int n, boolean inverse)
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