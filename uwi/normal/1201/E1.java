//package round577;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class E1 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static int[] DRK = {-2,-2,-1,-1,1,1,2,2};
	static int[] DCK = {-1,1,-2,2,-2,2,-1,1};
	
	void solve()
	{
		int n = ni(), m = ni();
		int r1 = ni()-1, c1 = ni()-1;
		int r2 = ni()-1, c2 = ni()-1;
		
		int[][][][][] dp = new int[2][n][m][n][m];
		int[][][][][][] prev = new int[2][n][m][n][m][2];
		Queue<int[]> q = new ArrayDeque<>();
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(Math.abs(n/2-1-i) + Math.abs(m/2-1-j) == 3 && 
						Math.abs(n/2-1-i) != 3 && Math.abs(m/2-1-j) != 3){
				}else{
					q.add(new int[]{1, n/2-1, m/2-1, i, j});
					dp[1][n/2-1][m/2-1][i][j] = 1;
					prev[1][n/2-1][m/2-1][i][j][0] = -1;
				}
				
				if(Math.abs(n/2-i) + Math.abs(m/2-1-j) == 3 && 
						Math.abs(n/2-i) != 3 && Math.abs(m/2-1-j) != 3){
				}else{
					q.add(new int[]{0, i, j, n/2, m/2-1});
					dp[0][i][j][n/2][m/2-1] = -1;
					prev[0][i][j][n/2][m/2-1][0] = -1;
				}
				q.add(new int[]{1, i, j, i, j});
				q.add(new int[]{0, i, j, i, j});
				dp[1][i][j][i][j] = 1;
				dp[0][i][j][i][j] = -1;
				prev[1][i][j][i][j][0] = -1;
				prev[0][i][j][i][j][0] = -1;
			}
		}
		while(!q.isEmpty()){
			int[] cur = q.poll();
			if(cur[0] == 1){
				int val = dp[cur[0]][cur[1]][cur[2]][cur[3]][cur[4]];
				inner:
				for(int k = 0;k < 8;k++){
					int nr = cur[1] + DRK[k];
					int nc = cur[2] + DCK[k];
					if(nr >= 0 && nr < n && nc >= 0 && nc < m){
						if(dp[0][nr][nc][cur[3]][cur[4]] == 0){
							if(val == 1){
								dp[0][nr][nc][cur[3]][cur[4]] = 1;
								prev[0][nr][nc][cur[3]][cur[4]][0] = cur[1];
								prev[0][nr][nc][cur[3]][cur[4]][1] = cur[2];
								q.add(new int[]{0, nr, nc, cur[3], cur[4]});
							}else{
								for(int u = 0;u < 8;u++){
									int nnr = nr + DRK[u];
									int nnc = nc + DCK[u];
									if(nnr >= 0 && nnr < n && nnc >= 0 && nnc < m){
										if(dp[1][nnr][nnc][cur[3]][cur[4]] != -1){
											continue inner;
										}
									}
								}
								dp[0][nr][nc][cur[3]][cur[4]] = -1;
								q.add(new int[]{0, nr, nc, cur[3], cur[4]});
							}
						}
					}
				}
			}else{
				int val = dp[cur[0]][cur[1]][cur[2]][cur[3]][cur[4]];
				inner:
				for(int k = 0;k < 8;k++){
					int nr = cur[3] + DRK[k];
					int nc = cur[4] + DCK[k];
					if(nr >= 0 && nr < n && nc >= 0 && nc < m){
						if(dp[1][cur[1]][cur[2]][nr][nc] == 0){
							if(val == -1){
								dp[1][cur[1]][cur[2]][nr][nc] = -1;
								q.add(new int[]{1, cur[1], cur[2], nr, nc});
								prev[1][cur[1]][cur[2]][nr][nc][0] = cur[3];
								prev[1][cur[1]][cur[2]][nr][nc][1] = cur[4];
							}else{
								for(int u = 0;u < 8;u++){
									int nnr = nr + DRK[u];
									int nnc = nc + DCK[u];
									if(nnr >= 0 && nnr < n && nnc >= 0 && nnc < m){
										if(dp[0][cur[1]][cur[2]][nnr][nnc] != 1){
											continue inner;
										}
									}
								}
								dp[1][cur[1]][cur[2]][nr][nc] = 1;
								q.add(new int[]{1, cur[1], cur[2], nr, nc});
							}
						}
					}
				}
			}
		}
		
//		for(int i = 0;i < 2;i++){
//			for(int j = 0;j < n;j++){
//				for(int k = 0; k < m;k++){
//					for(int l = 0;l < n;l++){
//						for(int u = 0;u < m;u++){
//							if(dp[i][j][k][l][u] == 0){
//								tr(i, j, k, l, u);
//							}
//						}
//					}
//				}
//			}
//		}
//		if(true)return;
		
		if(dp[0][r1][c1][r2][c2] == 1){
			out.println("WHITE");
			out.flush();
			while(true){
				int[] pre = prev[0][r1][c1][r2][c2];
				if(pre[0] == -1)break;
				out.println((pre[0]+1) + " " + (pre[1]+1));
				out.flush();
				r1 = pre[0]; c1 = pre[1];
				if(r1 == n/2-1 && c1 == m/2-1){
					boolean ok = true;
					for(int k = 0;k < 8;k++){
						if(r2 + DRK[k] == r1 && c2 + DCK[k] == c1){
							ok = false;
						}
					}
					if(ok)break;
				}
				if(r1 == r2 && c1 == c2)break;
				r2 = ni()-1; c2 = ni()-1;
			}
		}else{
			out.println("BLACK");
			out.flush();
			while(true){
				r1= ni()-1; c1 = ni()-1;
				int[] pre = prev[1][r1][c1][r2][c2];
				if(pre[0] == -1)break;
				out.println((pre[0]+1) + " " + (pre[1]+1));
				out.flush();
				r2 = pre[0]; c2 = pre[1];
				if(r2 == n/2 && c2 == m/2-1){
					boolean ok = true;
					for(int k = 0;k < 8;k++){
						if(r2 + DRK[k] == r1 && c2 + DCK[k] == c1){
							ok = false;
						}
					}
					if(ok)break;
				}
				if(r1 == r2 && c1 == c2)break;
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
	
	public static void main(String[] args) throws Exception { new E1().run(); }
	
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