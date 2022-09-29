//package round533;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Queue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni(), P = ni();
		int[] s = na(P);
		char[][] map = nm(n,m);
		List<Queue<int[]>> qs = new ArrayList<>();
		for(int i = 0;i < P;i++)qs.add(new ArrayDeque<>());
		int[][] ds = new int[n][m];
		int I = Integer.MAX_VALUE / 2;
		for(int i = 0;i < n;i++){
			Arrays.fill(ds[i], I);
		}
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] >= '0' && map[i][j] <= '9'){
					ds[i][j] = 0;
					qs.get(map[i][j]-'1').add(new int[]{i,j});
				}
			}
		}
		
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		for(int turn = 1;;turn++){
			boolean move = false;
			for(int i = 0;i < P;i++){
				Queue<int[]> q = qs.get(i);
				while(!q.isEmpty()){
					move = true;
					int[] cur = q.peek();
					int r = cur[0], c = cur[1];
					if(ds[r][c] >= turn * s[i])break;
					q.poll();
					for(int k = 0;k < 4;k++){
						int nr = r + dr[k];
						int nc = c + dc[k];
						if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
								map[nr][nc] == '.'){
							ds[nr][nc] = ds[r][c] + 1;
							map[nr][nc] = (char)('1'+i);
							q.add(new int[]{nr, nc});
						}
					}
				}
			}
			if(!move)break;
		}
		
		int[] f = new int[P];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] >= '0' && map[i][j] <= '9'){
					f[map[i][j]-'1']++;
				}
			}
		}
		for(int i =0;i < P;i++){
			out.print(f[i] +" ");
		}
		out.println();
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