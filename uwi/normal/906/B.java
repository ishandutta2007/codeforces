//package round454;
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
		int n = ni(), m = ni();
		int nn = Math.min(n, m);
		int mm = Math.max(n, m);
		if(nn == 1){
			if(mm == 2 || mm == 3){
				out.println("NO");
				return;
			}
		}
		if(nn == 2){
			if(mm <= 3){
				out.println("NO");
				return;
			}
		}
		if(nn == 3 && mm == 3){
			out.println("YES");
			out.println("1 6 8");
			out.println("9 2 4");
			out.println("5 7 3");
			return;
		}
		
		int[][] a = make(n, m);
		
		if(check(a)){
			out.println("YES");
			for(int[] row : a){
				for(int v : row){
					out.print(v+1 +" ");
				}
				out.println();
			}
			return;
		}
		
		int[][] b = make(m, n);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				int r = b[j][i] / n;
				int c = b[j][i] % n;
				a[i][j] = c*m+r;
			}
		}
		if(check(a)){
			out.println("YES");
			for(int[] row : a){
				for(int v : row){
					out.print(v+1 +" ");
				}
				out.println();
			}
			return;
		}
		
		tr("DEAD");
	}
	
	int[][] make(int n, int m)
	{
		
		int[][] a = new int[n][m];
		if(n == 2){
			for(int i = 0;i < m;i++){
				a[i&1][i] = i;
			}
			for(int i = 0;i < m;i++){
				a[(i+2)%m&1^1][(i+2)%m] = i+m;
			}
			return a;
		}
		int p = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(j % 2 == 1){
					a[i][j] = p++;
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(j % 2 == 0){
					a[i][j] = p++;
				}
			}
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
	
	boolean check(int[][] a)
	{
		for(int i = 0;i < a.length;i++){
			for(int j = 0;j < a[0].length;j++){
				if(j+1 < a[0].length && 
						(Math.abs(a[i][j] - a[i][j+1]) == 1 && a[i][j]/a[0].length == a[i][j+1]/a[0].length ||
						Math.abs(a[i][j] - a[i][j+1]) == a[0].length))return false;
				if(i+1 < a.length && 
						(Math.abs(a[i][j] - a[i+1][j]) == 1 && a[i][j]/a[0].length == a[i+1][j]/a[0].length ||
						Math.abs(a[i][j] - a[i+1][j]) == a[0].length))return false;
			}
		}
//		Set<Integer> set = new HashSet<>();
//		for(int i = 0;i < a.length;i++){
//			for(int j = 0;j < a[0].length;j++){
//				if(a[i][j] < 0 || a[i][j] >= a.length*a[0].length){
//					throw new RuntimeException();
//				}
//				set.add(a[i][j]);
//			}
//		}
//		if(set.size() != a.length*a[0].length)throw new RuntimeException();
		return true;
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