//package global9;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	// 2 2 1
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int inv = 0;
		boolean[][] invs = new boolean[n][n];
		for(int i = 0;i < n;i++) {
			for(int j = i+1;j < n;j++) {
				if(a[i] > a[j]) {
					inv++;
					invs[i][j] = true;
				}
			}
		}
		
		out.println(inv);
		int[][] ai = new int[n][];
		for(int k = 0;k < n;k++) {
			ai[k] = new int[] {a[k], k};
		}
		Arrays.sort(ai, (x, y) -> {
			if(x[0] != y[0])return x[0] - y[0];
			return x[1] - y[1];
		});
		
		for(int i = 0;i < n;i++) {
			int[][] h = new int[n][];
			int p = 0;
			for(int k = 0;k < n;k++) {
				if(invs[ai[i][1]][k]) {
					h[p++] = new int[] {a[k], k};
				}
			}
			h = Arrays.copyOf(h, p);
			Arrays.sort(h, (x, y) -> {
				if(x[0] != y[0])return -(x[0] - y[0]);
				return -(x[1] - y[1]);
			});
			
			for(int[] u : h) {
				int l = Math.min(ai[i][1], u[1]);
				int r = Math.max(ai[i][1], u[1]);
				out.println((l+1) + " " + (r+1));
				int d = a[l]; a[l] = a[r]; a[r] = d;
			}
		}
//		tr(pa);
		for(int i = 0;i < n-1;i++) {
			assert a[i] <= a[i+1];
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