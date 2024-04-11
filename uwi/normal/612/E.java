//package educational.round04;
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
		int n = ni();
		int[] f = na(n);
		for(int i = 0;i < n;i++)f[i]--;
		
		int[][] cys = splitIntoCycles(f);
		int[] ff = new int[n+1];
		for(int[] c : cys){
			ff[c.length]++;
		}
		for(int i = 0;i <= n;i++){
			if(i % 2 == 0 && ff[i] % 2 == 1){
				out.println(-1);
				return;
			}
		}
		
		int[][] prev = new int[n+1][];
		int[] g = new int[n];
		Arrays.fill(g, -1);
		for(int[] c : cys){
			if(c.length % 2 == 1){
				for(int i = 0, j = (c.length+1)/2;i < c.length;i++,j++){
					if(j == c.length)j = 0;
					g[c[i]] = c[j];
				}
			}else if(prev[c.length] == null){
				prev[c.length] = c;
			}else{
				for(int i = 0, j = 1;i < c.length;i++,j++){
					if(j == c.length)j = 0;
					g[c[i]] = prev[c.length][i];
					g[prev[c.length][i]] = c[j];
				}
				prev[c.length] = null;
			}
		}
		for(int i = 0;i < n;i++){
			out.print((g[i]+1) + " ");
		}
	}
	
	public static int[][] splitIntoCycles(int[] f)
	{
		int n = f.length;
		int[][] cycles = new int[n][];
		boolean[] ved = new boolean[n];
		int[] row = new int[n];
		int q = 0;
		for(int i = 0;i < n;i++){
			if(!ved[i]){
				int p = 0;
				for(int cur = i;!ved[cur];cur = f[cur]){
					ved[cur] = true;
					row[p++] = cur;
				}
				cycles[q++] = Arrays.copyOf(row, p);
			}
		}
		return Arrays.copyOf(cycles, q);
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