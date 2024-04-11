//package round212;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		outer:
		for(int i = 0;i < n;i++){
			char[][] map = nm(8,8);
			int[][] ks = new int[2][];
			int kp = 0;
			for(int j = 0;j < 8;j++){
				for(int k = 0;k < 8;k++){
					if(map[j][k] == 'K'){
						map[j][k] = '.';
						ks[kp++] = new int[]{j, k};
					}
				}
			}
			
			Queue<int[]> q = new ArrayDeque<int[]>();
			boolean[][][][] ved = new boolean[8][8][8][8];
			q.add(new int[]{ks[0][0], ks[0][1], ks[1][0], ks[1][1]});
			int[] dr = { 2, 2, -2, -2 };
			int[] dc = { 2, -2, 2, -2 };
			ved[ks[0][0]][ks[0][1]][ks[1][0]][ks[1][1]] = true;
			while(!q.isEmpty()){
				int[] cur = q.poll();
				int r1 = cur[0], c1 = cur[1];
				int r2 = cur[2], c2 = cur[3];
				if(r1 == r2 && c1 == c2 && map[r1][c1] == '.'){
					out.println("YES");
					continue outer;
				}
				for(int k = 0;k < 4;k++){
					int nr1 = r1 + dr[k], nc1 = c1 + dc[k];
					if(nr1 >= 0 && nr1 < 8 && nc1 >= 0 && nc1 < 8){
						for(int l = 0;l < 4;l++){
							int nr2 = r2 + dr[l], nc2 = c2 + dc[l];
							if(nr2 >= 0 && nr2 < 8 && nc2 >= 0 && nc2 < 8){
								if(!ved[nr1][nc1][nr2][nc2]){
									ved[nr1][nc1][nr2][nc2] = true;
									q.add(new int[]{nr1, nc1, nr2, nc2});
								}
							}
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