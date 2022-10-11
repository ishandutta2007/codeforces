import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;


/*
	br = new BufferedReader(new FileReader("input.txt"));
	pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
	br = new BufferedReader(new InputStreamReader(System.in));
	pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

 */

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	static int[][] grid;
	
	static int[] ret;
	
	static int[] dx = new int[]{1,0};
	static int[] dy = new int[]{0,1};
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			grid = new int[n][n];
			ret = new int[7];
			int a = -1;
			int b = -1;
			boolean zero = false;
			for(int i = 0; i < n; i++)	{
				for(int j = 0; j < n; j++)	{
					grid[i][j] = readInt();
					if(grid[i][j] == 0)	{
						zero = true;
						a = i;
						b = j;
					}
				}
			}
			String minTwo = solve(2);
			String minFive = solve(5);
			String ans = "";
			if(ret[2] >= 1 && ret[5] >= 1 && zero)	{
				for(int i = 0; i < a; i++)	{
					ans += 'D';
				}
				for(int i = 0; i < b; i++)	{
					ans += 'R';
				}
				for(int i = a; i < n-1; i++)	{
					ans += 'D';
				}
				for(int i = b; i < n-1; i++)	{
					ans += 'R';
				}
				pw.println(1);
			}
			else if(ret[2] < ret[5])	{
				ans = minTwo;
				pw.println(ret[2]);
			}
			else	{
				ans = minFive;
				pw.println(ret[5]);
			}
			pw.println(ans);
		}
		pw.close();
	}

	public static String solve(int mod)	{
		int[][] dp = new int[grid.length][grid.length];
		int[][] parent = new int[grid.length][grid.length];
		for (int i = 0; i < dp.length; i++) {
			Arrays.fill(dp[i], 1 << 28);
			Arrays.fill(parent[i], -1);
		}
		dp[0][0] = pow(grid[0][0], mod);
		int n = grid.length;
		for(int i = 0; i < n; i++)	{
			for(int j = 0; j < n; j++)	{
				for(int k = 0; k < dx.length; k++)	{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(nx < n && ny < n && dp[nx][ny] > dp[i][j] + pow(grid[nx][ny], mod))	{
						dp[nx][ny] = dp[i][j] + pow(grid[nx][ny], mod);
						parent[nx][ny] = k;
					}
				}
			}
		}
		int currX = n-1;
		int currY = n-1;
		StringBuilder ans = new StringBuilder();
		while(currX > 0 || currY > 0)	{
			int dir = parent[currX][currY];
			ans.append(dir == 0 ? 'D' : 'R');
			currX -= dx[dir];
			currY -= dy[dir];
		}
		ret[mod] = dp[n-1][n-1];
		return ans.reverse().toString();
	}
	
	
	public static int pow(int a, int b){
		if(a==0)
			return 1;
		int ret = 0;
		while(a%b==0)	{
			ret++;
			a/=b;
		}
		return ret;
	}
	
	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}