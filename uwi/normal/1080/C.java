//package round524;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			long m = ni(), n = ni();
			int[] w = na(4);
			int[] b = na(4);
			long[] xs = new long[]{0, n, w[0]-1, w[2], b[0]-1, b[2]};
			long[] ys = new long[]{0, m, w[1]-1, w[3], b[1]-1, b[3]};
			Arrays.sort(xs);
			Arrays.sort(ys);
			xs = uniq(xs);
			ys = uniq(ys);
			int nn = xs.length, mm = ys.length;
			int[][] map = new int[nn-1][mm-1];
			for(int i = Arrays.binarySearch(xs, w[0]-1);i <  Arrays.binarySearch(xs, w[2]);i++){
				for(int j = Arrays.binarySearch(ys, w[1]-1);j <  Arrays.binarySearch(ys, w[3]);j++){
					map[i][j] = 1;
				}
			}
			for(int i = Arrays.binarySearch(xs, b[0]-1);i <  Arrays.binarySearch(xs, b[2]);i++){
				for(int j = Arrays.binarySearch(ys, b[1]-1);j <  Arrays.binarySearch(ys, b[3]);j++){
					map[i][j] = 2;
				}
			}
			long W = 0, B = 0;
			for(int i = 0;i < nn-1;i++){
				for(int j = 0;j < mm-1;j++){
					if(map[i][j] == 1){
						W += (long)(xs[i+1]-xs[i])*(ys[j+1]-ys[j]);
					}else if(map[i][j] == 2){
						B += (long)(xs[i+1]-xs[i])*(ys[j+1]-ys[j]);
					}else{
						long lx = xs[i+1]-xs[i];
						long ly = ys[j+1]-ys[j];
						if(lx % 2 == 0 || ly % 2 == 0){
							W += lx*ly/2;
							B += lx*ly/2;
						}else if((xs[i] + ys[j]) % 2 == 0){
							W += lx*ly/2+1;
							B += lx*ly/2;
						}else{
							W += lx*ly/2;
							B += lx*ly/2+1;
						}
					}
				}
			}
			out.println(W + " " + B);
		}
	}
	
	public static long[] uniq(long[] a)
	{
		int n = a.length;
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || a[i] != a[i-1])a[p++] = a[i];
		}
		return Arrays.copyOf(a, p);
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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