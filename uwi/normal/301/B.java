//package round182;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), d = ni();
		int[] a = new int[n];
		for(int i = 2;i <= n-1;i++){
			a[i-1] = ni();
		}
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni(), ni()};
		}
		int[] from = new int[n*(n-1)];
		int[] to = new int[n*(n-1)];
		int[] w = new int[n*(n-1)];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				from[p] = i; to[p] = j; w[p] = d*(Math.abs(co[i][0]-co[j][0])+Math.abs(co[i][1]-co[j][1]))-a[j]; p++;
				from[p] = j; to[p] = i; w[p] = d*(Math.abs(co[i][0]-co[j][0])+Math.abs(co[i][1]-co[j][1]))-a[i]; p++;
			}
		}
		int[] bf = bf(from, to, w, n, 0);
		out.println(bf[n-1]);
	}
	
	public static int[] bf(int[] from, int[] to, int[] w, int n, int start)
	{
		int[] d = new int[n];
		Arrays.fill(d, Integer.MAX_VALUE / 2);
		d[start] = 0;
		int m = from.length;
		
		for(int r = 0;r < n-1;r++){
			boolean updated = false;
			for(int j = 0;j < m;j++){
				if(d[from[j]] + w[j] < d[to[j]]){
					d[to[j]] = d[from[j]] + w[j];
					updated = true;
				}
			}
			if(!updated)break;
		}
		for(int i = 0;i < m;i++){
			if(d[from[i]] + w[i] < d[to[i]]){
				return null;
			}
		}
		
		return d;
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
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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