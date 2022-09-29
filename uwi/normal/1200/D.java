//package round578;
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
		int n = ni(), K = ni();
		char[][] map = nm(n,n);
		int[][] score1 = new int[n+1][n];
		int global = 0;
		for(int j = 0;j < n;j++){
			char[] row = map[j];
			int[] hey = get(row, K);
			if(hey == null){
				global++;
			}else{
				for(int i = 0;i < n;i++){
					score1[Math.max(0, j-K+1)][i] += hey[i];
					score1[j+1][i] -= hey[i];
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 1;j < n;j++){
				score1[j][i] += score1[j-1][i];
			}
		}
		
		map = rot(map);
		
		int[][] score2 = new int[n+1][n];
		for(int j = 0;j < n;j++){
			char[] row = map[j];
			int[] hey = get(row, K);
			if(hey == null){
				global++;
			}else{
				for(int i = 0;i < n;i++){
					score2[Math.max(0, j-K+1)][i] += hey[i];
					score2[j+1][i] -= hey[i];
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 1;j < n;j++){
				score2[j][i] += score2[j-1][i];
			}
		}
		
		int max = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				int v = score1[i][j] + score2[j][i];
				max = Math.max(max, v);
			}
		}
		out.println(global + max);
	}
	
	int[] get(char[] row, int K)
	{
		int n = row.length;
		int firstb = -1;
		int lastb = -1;
		for(int i = 0;i < n;i++){
			if(row[i] == 'B'){
				if(firstb == -1)firstb = i;
				lastb = i;
			}
		}
		if(firstb == -1)return null;
		int[] ret = new int[n];
		for(int i = Math.max(0, lastb - K + 1);i <= firstb;i++){
			ret[i] = 1;
		}
		return ret;
	}
	
	public static char[][] rot(char[][] a)
	{
		int n = a.length, m = a[0].length;
		char[][] b = new char[m][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				b[j][i] = a[i][j];
			}
		}
		return b;
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