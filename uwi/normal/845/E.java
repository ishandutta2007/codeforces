//package educational.round27;
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
		int n = ni(), m = ni(), K = ni();
		int[][] co = new int[K][];
		for(int i = 0;i < K;i++){
			co[i] = new int[]{ni()-1, ni()-1};
		}
		int low = -1, high = 1000000007;
		while(high - low > 1){
			int h = high+low>>1;
			if(ok(h, co, n, m)){
				high = h;
			}else{
				low = h;
			}
		}
		out.println(high);
	}
	
	boolean ok(int h, int[][] co, int N, int M)
	{
		int n = co.length;
		int[][] rs = new int[n][];
		for(int i = 0;i < n;i++){
			rs[i] = new int[]{
					Math.max(0, co[i][0]-h), 
					Math.max(0, co[i][1]-h),
					Math.min(N, co[i][0]+h+1), 
					Math.min(M, co[i][1]+h+1)
			};
		}
		int[] imapx;
		{
			int[] xs = new int[2*n+2];
			int p = 0;
			for(int i = 0;i < n;i++){
				xs[p++] = rs[i][0];
				xs[p++] = rs[i][2];
			}
			xs[p++] = 0;
			xs[p++] = N;
			
			imapx = shrinkX(xs);
			for(int i = 0;i < n;i++){
				rs[i][0] = xs[2*i];
				rs[i][2] = xs[2*i+1];
			}
		}
		int[] imapy;
		{
			int[] ys = new int[2*n+2];
			int p = 0;
			for(int i = 0;i < n;i++){
				ys[p++] = rs[i][1];
				ys[p++] = rs[i][3];
			}
			ys[p++] = 0;
			ys[p++] = M;
			imapy = shrinkX(ys);
			for(int i = 0;i < n;i++){
				rs[i][1] = ys[2*i];
				rs[i][3] = ys[2*i+1];
			}
		}
		
		int[][] imos = new int[imapx.length+2][imapy.length+2];
		for(int[] r : rs){
			imos[r[0]+1][r[1]+1]++;
			imos[r[0]+1][r[3]+1]--;
			imos[r[2]+1][r[1]+1]--;
			imos[r[2]+1][r[3]+1]++;
		}
		
		for(int i = 1;i < imapx.length+2;i++){
			for(int j = 1;j < imapy.length+2;j++){
				imos[i][j] += imos[i-1][j] + imos[i][j-1] - imos[i-1][j-1];
			}
		}
//		if(h == 2){
//			tr(imapx);
//			tr(imapy);
//			tr(rs);
//			for(int[] row : imos){
//				tr(row);
//			}
//		}
		
		int minx = Integer.MAX_VALUE;
		int miny = Integer.MAX_VALUE;
		int maxx = -1;
		int maxy = -1;
		for(int i = 1;i < imapx.length;i++){
			for(int j = 1;j < imapy.length;j++){
				if(imos[i][j] == 0){
					minx = Math.min(minx, imapx[i-1]);
					miny = Math.min(miny, imapy[j-1]);
					maxx = Math.max(maxx, imapx[i]-1);
					maxy = Math.max(maxy, imapy[j]-1);
				}
			}
		}
		if(minx > maxx)return true;
		return maxy-miny+1 <= 2*h+1 && maxx-minx+1 <= 2*h+1;
	}
	
	public static int[] shrinkX(int[] a) {
		int n = a.length;
		long[] b = new long[n];
		for (int i = 0; i < n; i++)
			b[i] = (long) a[i] << 32 | i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		ret[0] = (int) (b[0] >> 32);
		for (int i = 0; i < n; i++) {
			if (i > 0 && (b[i] ^ b[i - 1]) >> 32 != 0) {
				p++;
				ret[p] = (int) (b[i] >> 32);
			}
			a[(int) b[i]] = p;
		}
		return Arrays.copyOf(ret, p + 1);
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