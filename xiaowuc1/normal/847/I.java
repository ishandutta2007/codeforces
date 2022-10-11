import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int r = readInt();
			int c = readInt();
			int base = readInt();
			int thresh = readInt();
			long[][] dp = new long[r][c];
			char[][] grid = new char[r][c];
			for(int i = 0; i < r; i++) {
				String s = nextToken();
				for(int j = 0; j < c; j++) {
					grid[i][j] = s.charAt(j);
				}
			}
			int[] dx = new int[]{-1,1,0,0};
			int[] dy = new int[]{0,0,-1,1};
			int[][] seen = new int[r][c];
			int index = 0;
			int[] iii = new int[r*c];
			int[] jjj = new int[r*c];
			int[] aaa = new int[r*c];
			int ret = 0;
			boolean[][] done = new boolean[r][c];
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					index++;
					if(grid[i][j] < 'A' || grid[i][j] > 'Z') {
						continue;
					}
					seen[i][j] = index;
					int lhs = 0;
					int rhs = 0;
					iii[rhs] = i;
					jjj[rhs] = j;
					aaa[rhs] = (grid[i][j] - 'A' + 1) * base;
					rhs++;
					while(lhs < rhs && ret != r*c) {
						int ii = iii[lhs];
						int jj = jjj[lhs];
						int now = aaa[lhs];
						lhs++;
						dp[ii][jj] += now;
						if(!done[ii][jj] && dp[ii][jj] > thresh) {
							ret++;
							done[ii][jj] = true;
						}
						if(now == 1) continue;
						for(int k = 0; k < dx.length; k++) {
							int nx = ii + dx[k];
							int ny = jj + dy[k];
							if(nx < 0 || nx >= r || ny < 0 || ny >= c || seen[nx][ny] == index) continue;
							if(grid[nx][ny] == '*') continue;
							seen[nx][ny] = index;
							iii[rhs] = nx;
							jjj[rhs] = ny;
							aaa[rhs] = now/2;
							rhs++;
						}
					}
				}
			}
			pw.println(ret);
		}
		pw.close();
	}

	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		if(!br.ready()) {
			exitImmediately();
		}
		st = null;
		return br.readLine();
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}