//package round293;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		int[][] up = go(map);
		map = revud(map);
		int[][] down = revud(go(map));
		map = revud(map);
		map = trans(map);
		int[][] left = trans(go(map));
		map = revud(map);
		int[][] right = trans(revud(go(map)));
		map = revud(map);
		map = trans(map);
		
		long ret = 0;
		
		// 0
		for(int i = 1;i < m-1;i++){
			if(down[0][i] == 1)ret++;
		}
		for(int i = 1;i < n-1;i++){
			if(right[i][0] == 1)ret++;
		}
		
		// 1
		for(int i = 1;i < n-1;i++){
			for(int j = 1;j < m-1;j++){
				if(left[i][j] == 1 && up[i][j] == 1)ret++;
				if(left[i][j] == 1 && down[i][j] == 1)ret++;
				if(right[i][j] == 1 && up[i][j] == 1)ret++;
				if(right[i][j] == 1 && down[i][j] == 1)ret++;
			}
		}
		
		// 2
		for(int i = 1;i < n-1;i++){
			// up up
			{
				int count = 0;
				for(int j = 1;j < m-1;j++){
					if(j-2 >= 1 && up[i][j-2] == 1 && map[i][j-1] != '#')count++;
					if(map[i][j] == '#')count = 0;
					if(up[i][j] == 1)ret += count;
				}
			}
			// down down
			{
				int count = 0;
				for(int j = 1;j < m-1;j++){
					if(j-2 >= 1 && down[i][j-2] == 1 && map[i][j-1] != '#')count++;
					if(map[i][j] == '#')count = 0;
					if(down[i][j] == 1)ret += count;
				}
			}
			// up down
			{
				int count = 0;
				for(int j = 1;j < m-1;j++){
					if(j-1 >= 1 && up[i][j-1] == 1)count++;
					if(map[i][j] == '#')count = 0;
					if(down[i][j] == 1)ret += count;
				}
			}
			{
				int count = 0;
				for(int j = 1;j < m-1;j++){
					if(j-1 >= 1 && down[i][j-1] == 1)count++;
					if(map[i][j] == '#')count = 0;
					if(up[i][j] == 1)ret += count;
				}
			}
		}
		for(int i = 1;i < m-1;i++){
			// up up
			{
				int count = 0;
				for(int j = 1;j < n-1;j++){
					if(j-2 >= 1 && left[j-2][i] == 1 && map[j-1][i] != '#')count++;
					if(map[j][i] == '#')count = 0;
					if(left[j][i] == 1)ret += count;
				}
			}
			// down down
			{
				int count = 0;
				for(int j = 1;j < n-1;j++){
					if(j-2 >= 1 && right[j-2][i] == 1 && map[j-1][i] != '#')count++;
					if(map[j][i] == '#')count = 0;
					if(right[j][i] == 1)ret += count;
				}
			}
			// up down
			{
				int count = 0;
				for(int j = 1;j < n-1;j++){
					if(j-1 >= 1 && left[j-1][i] == 1)count++;
					if(map[j][i] == '#')count = 0;
					if(right[j][i] == 1)ret += count;
				}
			}
			{
				int count = 0;
				for(int j = 1;j < n-1;j++){
					if(j-1 >= 1 && right[j-1][i] == 1)count++;
					if(map[j][i] == '#')count = 0;
					if(left[j][i] == 1)ret += count;
				}
			}
		}
		out.println(ret);
	}
	
	int[][] go(char[][] map)
	{
		int n = map.length;
		int m = map[0].length;
		int[][] up = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				up[i][j] = map[i][j] == '#' ? 0 : i == 0 ? 1 : up[i-1][j];
			}
		}
		return up;
	}
	
	// count
	//	int[][] br = countBR(b);
	//	revlr(b);
	//	int[][] bl = countBR(b);
	//	revud(b);
	//	int[][] tl = countBR(b);
	//	revlr(b);
	//	int[][] tr = countBR(b);
	//	
	//	revlr(bl);
	//	revud(tr);
	//	revlr(revud(tl));
	//	revud(b);
	
	public static int[][] revlr(int[][] a)
	{
		for(int i = 0;i < a.length;i++){
			for(int j = 0, k = a[i].length-1;j < k;j++,k--){
				int d = a[i][j]; a[i][j] = a[i][k]; a[i][k] = d;
			}
		}
		return a;
	}
	
	public static char[][] revlr(char[][] a)
	{
		for(int i = 0;i < a.length;i++){
			for(int j = 0, k = a[i].length-1;j < k;j++,k--){
				char d = a[i][j]; a[i][j] = a[i][k]; a[i][k] = d;
			}
		}
		return a;
	}
	
	public static int[][] revud(int[][] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			int[] d = a[i]; a[i] = a[j]; a[j] = d;
		}
		return a;
	}
	
	public static char[][] revud(char[][] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			char[] d = a[i]; a[i] = a[j]; a[j] = d;
		}
		return a;
	}
	
	public static int[][] trans(int[][] a)
	{
		int n = a.length, m = a[0].length;
		int[][] t = new int[m][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				t[j][i] = a[i][j];
			}
		}
		return t;
	}
	
	public static char[][] trans(char[][] a)
	{
		int n = a.length, m = a[0].length;
		char[][] t = new char[m][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				t[j][i] = a[i][j];
			}
		}
		return t;
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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