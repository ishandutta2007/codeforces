//package round501;
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
		int n = ni(), m = ni();
		char[][] map = nm(n, m);
		int[][][] lens = makeAll(map);
		
		int[][] downs = new int[n+2][m+2];
		int[][] rights = new int[n+2][m+2];
		String[] all = new String[n*m];
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int d = 999999;
				for(int k = 0;k < 4;k++){
					d = Math.min(d, lens[k][i][j]);
				}
				if(d >= 2){
					all[p++] = (i+1) + " " + (j+1) + " " + (d-1);
					downs[i-d+1][j]++;
					downs[i+d][j]--;
					rights[i][j-d+1]++;
					rights[i][j+d]--;
				}
			}
		}
		for(int j = 0;j < m;j++){
			for(int i = 0;i < n;i++){
				downs[i+1][j] += downs[i][j];
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				rights[i][j+1] += rights[i][j];
			}
		}
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(downs[i][j] + rights[i][j] == 0){
					if(map[i][j] == '*'){
						out.println(-1);
						return;
					}
				}
			}
		}
		
		out.println(p);
		for(int i = 0;i < p;i++){
			out.println(all[i]);
		}
	}
	
	public static int[][] down(char[][] map)
	{
		int n = map.length, m = map[0].length;
		int[][] ret = new int[n][m];
		for(int i = n-1;i >= 0;i--){
			for(int j = 0;j < m;j++){
				ret[i][j] = i == n-1 ? 1 : ret[i+1][j] + 1;
				if(map[i][j] == '.')ret[i][j] = 0;
			}
		}
		return ret;
	}

	public static char[][] rot(char[][] a)
	{
		int n = a.length, m = a[0].length;
		char[][] b = new char[m][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				b[j][n-1-i] = a[i][j];
			}
		}
		return b;
	}
	
	public static int[][] rot(int[][] a)
	{
		int n = a.length, m = a[0].length;
		int[][] b = new int[m][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				b[j][n-1-i] = a[i][j];
			}
		}
		return b;
	}

	public static int[][][] makeAll(char[][] a)
	{
		int[][][] ret = new int[4][][];
		ret[0] = down(a);
		a = rot(a);
		ret[1] = rot(rot(rot(down(a))));
		a = rot(a);
		ret[2] = rot(rot(down(a)));
		a = rot(a);
		ret[3] = rot(down(a));
		// a = rot(a);
		return ret;
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