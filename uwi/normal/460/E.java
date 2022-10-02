//package round262;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int[][] hist;
	int W = 35;
	double[][] pps;
	
	void solve()
	{
		int n = ni(), r = ni();
		hist = new int[n][];
		int[][] pps = new int[9000][];
		int p = 0;
		maxd = -1L;
		for(int i = -r;i <= r;i++){
			for(int j = -r;j <= r;j++){
				if(i*i+j*j <= r*r && (r-1)*(r-1) <= i*i+j*j){
					pps[p++] = new int[]{i, j, i*i+j*j};
				}
			}
		}
		Arrays.sort(pps, 0, p, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[2] - b[2]);
			}
		});
		long x = 5000000;
		for(int i = 1;i <= n;i++)x *= i;
		pps = Arrays.copyOf(pps, Math.min(p, (int)Math.pow(x, 1./n)));
		dfs(0, n, r, pps, 0);
		
		out.println(maxd);
		for(int[] o : opt){
			out.println(o[0] + " " + o[1]);
		}
	}
	
	long maxd = -1L;
	int gct = 0;
	int[][] opt = null;
	
	void dfs(int pos, int n, int r, int[][] pps, int ind)
	{
		if(pos == n){
			gct++;
			long d = 0;
			for(int i = 0;i < n;i++){
				for(int j = i+1;j < n;j++){
					d += 
							(hist[i][0]-hist[j][0])*(hist[i][0]-hist[j][0]) +
							(hist[i][1]-hist[j][1])*(hist[i][1]-hist[j][1])
							;
				}
			}
			if(d > maxd){
				maxd = d;
//				tr(maxd);
				opt = Arrays.copyOf(hist, n);
			}
			return;
		}
		
		for(int i = ind;i < pps.length;i++){
			hist[pos] = pps[i];
			dfs(pos+1, n, r, pps, i);
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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