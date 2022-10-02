//package rocket2015;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] a = na(n);
		for(int i = 0;i < n;i++)a[i]--;
		
		double[][][][] m = new double[n][n][n][n];
		
		double q = n*(n+1)/2;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				for(int k = 0;k < n;k++){
					for(int l = k;l < n;l++){
						int ni = i, nj = j;
						if(k <= i && i <= l)ni = l-(ni-k);
						if(k <= j && j <= l)nj = l-(nj-k);
						m[i][j][ni][nj] += 1./q;
					}
				}
			}
		}
		
		double e = 0;
		{
			double[][] pre = new double[n][n];
			double[][] cur = new double[n][n];
			for(int i = 0;i < n;i++){
				for(int j = i+1;j < n;j++){
					if(a[i] < a[j]){
						pre[i][j] = 1.;
					}
				}
			}
			for(int z = 0;z <K;z++){
				for(int i = 0;i < n;i++){
					Arrays.fill(cur[i], 0.);
				}
				for(int i = 0;i < n;i++){
					for(int j = 0;j < n;j++){
						if(pre[i][j] > 0){
							for(int k = 0;k < n;k++){
								for(int l = 0;l < n;l++){
									cur[k][l] += pre[i][j] * m[i][j][k][l];
								}
							}
						}
					}
				}
				double[][] dum = pre; pre = cur; cur = dum;
			}
			for(int k = 0;k < n;k++){
				for(int l = 0;l < k;l++){
					e += pre[k][l];
				}
			}
		}
		{
			double[][] pre = new double[n][n];
			double[][] cur = new double[n][n];
			for(int i = 0;i < n;i++){
				for(int j = i+1;j < n;j++){
					if(a[i] > a[j]){
						pre[i][j] = 1.;
						e += 1;
					}
				}
			}
			for(int z = 0;z <K;z++){
				for(int i = 0;i < n;i++){
					Arrays.fill(cur[i], 0.);
				}
				for(int i = 0;i < n;i++){
					for(int j = 0;j < n;j++){
						if(pre[i][j] > 0){
							for(int k = 0;k < n;k++){
								for(int l = 0;l < n;l++){
									cur[k][l] += pre[i][j] * m[i][j][k][l];
								}
							}
						}
					}
				}
				double[][] dum = pre; pre = cur; cur = dum;
			}
			for(int k = 0;k < n;k++){
				for(int l = 0;l < k;l++){
					e -= pre[k][l];
				}
			}
		}
		out.printf("%.12f\n", e);
	}
	
	public static int encPerm(int[] a) {
		int n = a.length;
		int used = 0;
		int ret = 0;
		for (int i = 0; i < n; i++) {
			ret = ret * (n - i) + a[i]
					- Integer.bitCount(used & ((1 << a[i]) - 1));
			used |= 1 << a[i];
		}
		return ret;
	}
	
	public static int[] decPerm(int c, int n) {
		int[] a = new int[n];
		for (int i = n - 1; i >= 0; c /= n - i, i--) {
			int v = c % (n - i);
			a[i] = v;
			for (int j = i + 1; j <= n - 1; j++) {
				if (v <= a[j])
					a[j]++;
			}
		}
		return a;
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
	
	public static void main(String[] args) throws Exception { new G2().run(); }
	
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