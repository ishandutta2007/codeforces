//package round192;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.InputMismatchException;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[][] map = nm(n,n);
		boolean[][] g = new boolean[n][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(map[i][j] == '.'){
					g[i][j] = true;
				}
			}
		}
		boolean ok = true;
		outer:
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(g[i][j]){
					continue outer;
				}
			}
			ok = false;
			break;
		}
		
		if(ok){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					if(g[i][j]){
						out.println((i+1) + " " + (j+1));
						break;
					}
				}
			}
			return;
		}
		
		ok = true;
		outer:
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(g[j][i]){
					continue outer;
				}
			}
			ok = false;
			break;
		}
		
		if(ok){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					if(g[j][i]){
						out.println((j+1) + " " + (i+1));
						break;
					}
				}
			}
			return;
		}
		
		out.println(-1);
	}
	
	public static int[] doBipartiteMatching(boolean[][] g)
	{
		int n = g.length;
		if(n == 0)return new int[0];
		int m = g[0].length;
		if(m == 0)return new int[n];
		int[] im = new int[m];
		Arrays.fill(im, -1);
		BitSet visited = new BitSet();
		int matched = 0;
		for(int i = 0;i < n;i++){
			if(visit(g, i, visited, im)) {
				visited.clear();
				matched++;
			}
		}

		int[] ret = new int[n];
		Arrays.fill(ret, -1);
		for(int i = 0;i < m;i++){
			if(im[i] != -1)ret[im[i]] = i;
		}
		return ret;
	}

	public static boolean visit(boolean[][] g, int cur, BitSet visited, int[] im)
	{
		if(cur == -1)return true;

		for(int i = visited.nextClearBit(0);i != g[cur].length;i = visited.nextClearBit(i+1)){
			if(g[cur][i]){
				visited.set(i);
				if(visit(g, im[i], visited, im)){
					im[i] = cur;
					return true;
				}
			}
		}
		return false;
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
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
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