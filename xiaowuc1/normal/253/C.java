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

	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new FileReader("input.txt"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int[] len = new int[n];
			int[][] grid = new int[n][];
			int[][] dp = new int[n][];
			for (int i = 0; i < len.length; i++) {
				len[i] = readInt();
				grid[i] = new int[len[i]+1];
				dp[i] = new int[len[i]+1];
				Arrays.fill(dp[i], 1 << 25);
			}
			int sR = readInt()-1;
			int sC = readInt()-1;
			int eR = readInt()-1;
			int eC = readInt()-1;
			dp[sR][sC] = 0;
			LinkedList<State> q = new LinkedList<State>();
			q.add(new State(sR,sC));
			while(!q.isEmpty())	{
				State curr = q.removeFirst();
				for(int k = 0; k < dx.length; k++)	{
					int nx = curr.x + dx[k];
					if(nx < 0 || nx >= n)	{
						continue;
					}
					int ny = Math.max(0, Math.min(len[nx], curr.y + dy[k]));
					if(dp[nx][ny] > 1 + dp[curr.x][curr.y])	{
						dp[nx][ny] = 1 + dp[curr.x][curr.y];
						q.addLast(new State(nx,ny));
					}
				}
			}
			pw.println(dp[eR][eC]);
		}
		pw.close();
	}

	static class State	{
		public int x,y;

		public State(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
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