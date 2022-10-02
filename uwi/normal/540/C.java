//package round301;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		int sr = ni()-1, sc = ni()-1;
		int gr = ni()-1, gc = ni()-1;
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		if(sr == gr && sc == gc){
			for(int k = 0;k < 4;k++){
				int nr = sr + dr[k], nc = sc + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == '.'){
					out.println("YES");
					return;
				}
			}
			out.println("NO");
			return;
		}
		if(map[gr][gc] == 'X'){
			map[gr][gc] = '.';
			Queue<int[]> q = new ArrayDeque<int[]>();
			q.add(new int[]{sr, sc});
			boolean[][] ved = new boolean[n][m];
			ved[sr][sc] = true;
			while(!q.isEmpty()){
				int[] cur = q.poll();
				int r = cur[0], c = cur[1];
				for(int k = 0;k < 4;k++){
					int nr = r + dr[k], nc = c + dc[k];
					if(nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == '.' && !ved[nr][nc]){
						ved[nr][nc] = true;
						q.add(new int[]{nr, nc});
					}
				}
			}
			if(ved[gr][gc]){
				out.println("YES");
			}else{
				out.println("NO");
			}
		}else{
			map[gr][gc] = 'X';
			for(int adir = 0;adir < 4;adir++){
				int ar = gr + dr[adir], ac = gc + dc[adir];
				if(ar >= 0 && ar < n && ac >= 0 && ac < m && map[ar][ac] == '.' || ar == sr && ac == sc){
					for(int ddir = 0;ddir < 4;ddir++){
						if(adir == ddir)continue;
						int br = gr + dr[ddir], bc = gc + dc[ddir];
						if(br >= 0 && br < n && bc >= 0 && bc < m && map[br][bc] == '.'){
							map[br][bc] = 'X';
							Queue<int[]> q = new ArrayDeque<int[]>();
							q.add(new int[]{sr, sc});
							boolean[][] ved = new boolean[n][m];
							ved[sr][sc] = true;
							while(!q.isEmpty()){
								int[] cur = q.poll();
								int r = cur[0], c = cur[1];
								for(int k = 0;k < 4;k++){
									int nr = r + dr[k], nc = c + dc[k];
									if(nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == '.' && !ved[nr][nc]){
										ved[nr][nc] = true;
										q.add(new int[]{nr, nc});
									}
								}
							}
							if(ved[ar][ac]){
								out.println("YES");
								return;
							}
							map[br][bc] = '.';
						}
					}
				}
			}
			out.println("NO");
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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