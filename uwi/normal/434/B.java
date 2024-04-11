//package round248;
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
	
	int[][] makeup(int[][] a)
	{
		int n = a.length;
		int m = a[0].length;
		int[][] up = new int[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(a[i][j] == 0){
					up[i][j] = 0;
				}else{
					up[i][j] = 1 + (i-1 >= 0 ? up[i-1][j] : 0);
				}
			}
		}
		return up;
	}
	
	int[][] revlr(int[][] a)
	{
		for(int i = 0;i < a.length;i++){
			for(int j = 0, k = a[i].length-1;j < k;j++,k--){
				int d = a[i][j]; a[i][j] = a[i][k]; a[i][k] = d;
			}
		}
		return a;
	}
	
	int[][] trans(int[][] a)
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
	
	int[][] revud(int[][] a)
	{
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			int[] d = a[i]; a[i] = a[j]; a[j] = d;
		}
		return a;
	}
	
	void solve()
	{
		int n = ni(), m = ni(), Q = ni();
		int[][] a = new int[n][];
		for(int i = 0;i < n;i++){
			a[i] = na(m);
		}
		// #1
		int[][] up = makeup(a);
		a = revud(a);
		int[][] down = revud(makeup(a));
		a = revud(a);
		
		a = trans(a);
		int[][] left = trans(makeup(a));
		
		a = revud(a);
		int[][] right = trans(revud(makeup(a)));
		a = revud(a);
		a = trans(a);
		
		for(int z = 0;z < Q;z++){
			int t = ni();
			if(t == 1){
				int r = ni()-1, c = ni()-1;
				a[r][c] ^= 1;
				if(a[r][c] == 1){
					up[r][c] = r-1 >= 0 ? up[r-1][c] + 1 : 1;
					down[r][c] = r+1 < n ? down[r+1][c] + 1 : 1;
					left[r][c] = c-1 >= 0 ? left[r][c-1] + 1 : 1;
					right[r][c] = c+1 < m ? right[r][c+1] + 1 : 1;
					for(int i = r+1;i < n && a[i][c] == 1;i++)up[i][c] += up[r][c];
					for(int i = r-1;i >= 0 && a[i][c] == 1;i--)down[i][c] += down[r][c];
					for(int i = c+1;i < m && a[r][i] == 1;i++)left[r][i] += left[r][c];
					for(int i = c-1;i >= 0 && a[r][i] == 1;i--)right[r][i] += right[r][c];
				}else{
					for(int i = r+1;i < n && a[i][c] == 1;i++)up[i][c] -= up[r][c];
					for(int i = r-1;i >= 0 && a[i][c] == 1;i--)down[i][c] -= down[r][c];
					for(int i = c+1;i < m && a[r][i] == 1;i++)left[r][i] -= left[r][c];
					for(int i = c-1;i >= 0 && a[r][i] == 1;i--)right[r][i] -= right[r][c];
					up[r][c] = 0;
					down[r][c] = 0;
					left[r][c] = 0;
					right[r][c] = 0;
				}
			}else if(t == 2){
				int max = 0;
				int r = ni()-1, c = ni()-1;
				{
					int uph = up[r][c], downh = down[r][c];
					for(int i = c;i < m;i++){
						uph = Math.min(up[r][i], uph);
						downh = Math.min(down[r][i], downh);
						if(uph == 0 || downh == 0)break;
						max = Math.max(max, (uph+downh-1)*(i-c+1));
					}
				}
				{
					int uph = up[r][c], downh = down[r][c];
					for(int i = c;i >= 0;i--){
						uph = Math.min(up[r][i], uph);
						downh = Math.min(down[r][i], downh);
						if(uph == 0 || downh == 0)break;
						max = Math.max(max, (uph+downh-1)*(c-i+1));
					}
				}
				{
					int lefth = left[r][c], righth = right[r][c];
					for(int i = r;i < n;i++){
						lefth = Math.min(left[i][c], lefth);
						righth = Math.min(right[i][c], righth);
						if(lefth == 0 || righth == 0)break;
						max = Math.max(max, (lefth+righth-1)*(i-r+1));
					}
				}
				{
					int lefth = left[r][c], righth = right[r][c];
					for(int i = r;i >= 0;i--){
						lefth = Math.min(left[i][c], lefth);
						righth = Math.min(right[i][c], righth);
						if(lefth == 0 || righth == 0)break;
						max = Math.max(max, (lefth+righth-1)*(r-i+1));
					}
				}
				out.println(max);
			}else{
				throw new RuntimeException();
			}
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