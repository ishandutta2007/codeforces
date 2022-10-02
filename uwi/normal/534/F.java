//package round298;
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
		int[] row = na(n);
		int[] col = na(m);
		char[][] map = new char[n][m];
		for(int i = 0;i < n;i++){
			Arrays.fill(map[i], '?');
		}
		dfs(0, 0, 0, new int[n], map, row, col);
		
		check(map, row, col);
		
		for(int i = 0;i < n;i++){
			out.println(new String(map[i]));
		}
//		tr(ved);
	}
	
	void check(char[][] map, int[] row, int[] col)
	{
		int n =map.length, m = map[0].length;
		
		for(int i = 0;i < n;i++){
			int lrow = 0;
			for(int j = 0;j < m;j++){
				if(map[i][j] == '*' && (j == 0 || map[i][j-1] == '.'))lrow++;
			}
			if(lrow != row[i])throw new RuntimeException();
		}
		for(int i = 0;i < m;i++){
			int lcol = 0;
			for(int j = 0;j < n;j++){
				if(map[j][i] == '*' && (j == 0 || map[j-1][i] == '.'))lcol++;
			}
			if(lcol != col[i])throw new RuntimeException();
		}
	}
	
//	int ved = 0;
	
	boolean dfs(int r, int c, int rdis, int[] rc, char[][] map, int[] row, int[] col)
	{
		if(c == map[0].length){
			for(int i = 0;i < map.length;i++){
				if(rc[i] != row[i]){
					return false;
				}
			}
			return true;
		}
		if(r == map.length){
			if(rdis != col[c])return false;
			return dfs(0, c+1, 0, rc, map, row, col);
		}
		
//		ved++;
		
		int n = map.length, m = map[0].length;
		
		{
			map[r][c] = '.';
			boolean go = true;
			if((n-1-r+1)/2 + rdis < col[c]){
				go = false;
			}
			
			if(go){
				int vir = rc[r];
				int prev = 0, xx = 0;
				for(int i = c+1;i < m;i++){
					if(col[i] == 0){
						xx = 0;
					}else if(col[i] == 3){
						if((r&1) == 0){
							xx = 1;
						}else{
							xx = 0;
						}
					}else{
						xx = prev^1;
					}
					if(prev == 0 && xx == 1)vir++;
					prev = xx;
				}
				if(vir < row[r]){
					go = false;
				}
			}
			if(go){
				int vir = rc[r];
				int prev = 0, xx = 0;
				for(int i = c+1;i < m;i++){
					if(col[i] == 0){
						xx = 0;
					}else if(col[i] == 3){
						if((r&1) == 0){
							xx = 1;
						}else{
							xx = 0;
						}
					}else{
						xx = prev;
					}
					if(prev == 0 && xx == 1)vir++;
					prev = xx;
				}
				if(vir > row[r]){
					go = false;
				}
			}
//			if((m-1-c+1)/2 + rc[r] < row[r]){
//				go = false;
//			}
			if(go && dfs(r+1, c, rdis, rc, map, row, col))return true;
		}
		
		{
			map[r][c] = '*';
			boolean go = true;
			int nrdis = rdis;
			if(r == 0 || map[r-1][c] == '.'){
				if(rdis + 1 > col[c]){
					go = false;
				}else{
					nrdis++;
				}
			}
			boolean pl = false;
			if(c == 0 || map[r][c-1] == '.'){
				if(rc[r] + 1 > row[r]){
					go = false;
				}else{
					rc[r]++;
					pl = true;
				}
			}
			if((n-1-r)/2 + nrdis < col[c]){
				go = false;
			}
			
			if(go){
				int vir = rc[r];
				int prev = 1, xx = 0;
				for(int i = c+1;i < m;i++){
					if(col[i] == 0){
						xx = 0;
					}else if(col[i] == 3){
						if((r&1) == 0){
							xx = 1;
						}else{
							xx = 0;
						}
					}else{
						xx = prev^1;
					}
					if(prev == 0 && xx == 1)vir++;
					prev = xx;
				}
				if(vir < row[r]){
					go = false;
				}
			}
			if(go){
				int vir = rc[r];
				int prev = 1, xx = 0;
				for(int i = c+1;i < m;i++){
					if(col[i] == 0){
						xx = 0;
					}else if(col[i] == 3){
						if((r&1) == 0){
							xx = 1;
						}else{
							xx = 0;
						}
					}else{
						xx = prev;
					}
					if(prev == 0 && xx == 1)vir++;
					prev = xx;
				}
				if(vir > row[r]){
					go = false;
				}
			}
//			if((m-1-c)/2 + rc[r] < row[r]){
//				go = false;
//			}
			if(go && dfs(r+1, c, nrdis, rc, map, row, col))return true;
			if(pl){
				rc[r]--;
			}
		}
		
		
		map[r][c] = '?';
		return false;
	}
	
	void run() throws Exception
	{
//		int n = 5, m = 20;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(m/3) + " ");
//		}
//		for (int i = 0; i < m; i++) {
//			sb.append(gen.nextInt(3) + " ");
//		}
//		INPUT = sb.toString();
		
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