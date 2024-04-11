//package round180;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), K = ni();
		boolean[][] map = new boolean[n*2-1][m*2-1];
		for(int i = 0;i < 2*n-1;i++){
			if(i % 2 == 0){
				for(int j = 0;j < m-1;j++){
					map[i][j*2+1] = nc() == 'E';
				}
			}else{
				for(int j = 0;j < m;j++){
					map[i][j*2] = nc() == 'E';
				}
			}
		}
		int all = n*(m-1)+(n-1)*m;
		if(K == 1){
			int e = 0;
			for(int i = 0;i < 2*n-1;i++){
				for(int j = 0;j < 2*m-1;j++){
					if(map[i][j])e++;
				}
			}
			// e/all>=3/4
			if(e*4>=3*all){
				out.println("YES");
				for(int i = 0;i < n;i++){
					for(int j = 0;j < m;j++){
						if(j > 0)out.print(" ");
						out.print(1);
					}
					out.println();
				}
			}else{
				out.println("NO");
			}
		}else{
			boolean trans = false;
			if(n > m){
				trans = true;
				boolean[][] nmap = new boolean[2*m-1][2*n-1];
				for(int i = 0;i < 2*n-1;i++){
					for(int j = 0;j < 2*m-1;j++){
						nmap[j][i] = map[i][j];
					}
				}
				map = nmap;
				int d = n; n = m; m = d;
			}
			
			int[][] col = new int[n][m];
			for(int i = 0;i < n;i++){
				col[i][0] = 1;
				for(int j = 1;j < m;j++){
					if(map[2*i][2*j-1]){
						col[i][j] = col[i][j-1];
					}else{
						col[i][j] = 3-col[i][j-1];
					}
				}
			}
			for(int i = 0;i < n-1;i++){
				int ok = 0;
				for(int j = 0;j < m;j++){
					if(map[2*i+1][2*j]){
						if(col[i][j] == col[i+1][j])ok++;
					}else{
						if(col[i][j] != col[i+1][j])ok++;
					}
				}
				if(ok*2 < m){
					for(int j = 0;j < m;j++){
						col[i+1][j] = 3-col[i+1][j];
					}
				}
			}
			out.println("YES");
			if(trans){
				int[][] ncol = new int[m][n];
				for(int i = 0;i < n;i++){
					for(int j = 0;j < m;j++){
						ncol[j][i] = col[i][j];
					}
				}
				col = ncol;
				int d = n; n = m; m = d;
			}
			
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					if(j > 0)out.print(" ");
					out.print(col[i][j]);
				}
				out.println();
			}
//			check(map, col);
		}
//		tr(map);
	}
	
	void check(boolean[][] map, int[][] col)
	{
		int n = col.length, m = col[0].length;
		int ok = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m-1;j++){
				if(map[2*i][2*j+1]){
					if(col[i][j] == col[i][j+1])ok++;
				}else{
					if(col[i][j] != col[i][j+1])ok++;
				}
			}
		}
		for(int i = 0;i < n-1;i++){
			for(int j = 0;j < m;j++){
				if(map[2*i+1][2*j]){
					if(col[i][j] == col[i+1][j])ok++;
				}else{
					if(col[i][j] != col[i+1][j])ok++;
				}
			}
		}
//		tr(ok, n*(m-1)+(n-1)*m);
		if(ok*4-3*(n*(m-1)+(n-1)*m) < 0){
			throw new AssertionError();
		}
	}
	
	int ap(int x, boolean e)
	{
		if(e){
			return x;
		}else{
			return 3-x;
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
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}