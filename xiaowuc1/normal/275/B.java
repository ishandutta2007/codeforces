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
	
	static boolean[][] grid;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int r = readInt();
			int c = readInt();
			grid = new boolean[r][c];
			int[][] dist = new int[r][c];
			for (int i = 0; i < grid.length; i++) {
				String str = nextToken();
				for (int j = 0; j < grid[i].length; j++) {
					grid[i][j] = str.charAt(j) == 'B';
				}
			}
			boolean win = true;
			for (int i = 0; win && i < grid.length; i++) {
				for (int j = 0; win && j < grid[i].length; j++) {
					if(grid[i][j])	{
						dist = new int[r][c];
						for (int k = 0; k < dist.length; k++) {
							Arrays.fill(dist[k], 1 << 25);
						}
						dist[i][j] = 0;
						LinkedList<State> q = new LinkedList<State>();
						q.add(new State(i,j));
						while(!q.isEmpty())	{
							State curr = q.removeFirst();
							if(dist[curr.x][curr.y] == 2)
								continue;
							for(int k = 0; k < dx.length; k++)	{
								int currX = curr.x + dx[k];
								int currY = curr.y + dy[k];
								while(valid(currX, currY))	{
									if(dist[curr.x][curr.y] + 1 < dist[currX][currY])	{
										dist[currX][currY] = dist[curr.x][curr.y] + 1;
										q.addLast(new State(currX, currY));
									}
									currX += dx[k];
									currY += dy[k];
								}
							}
						}
						boolean can = true;
						for (int k = 0; can && k < grid.length; k++) {
							for (int k2 = 0; can && k2 < grid[k].length; k2++) {
								if(grid[k][k2] && dist[k][k2] > 2)	{
									can = false;
								}
							}
						}
						win = can;
					}
				}
			}
			pw.println(win ? "YES" : "NO");
		}
		pw.close();
	}

	private static boolean valid(int x, int y) {
		return x >= 0 && x < grid.length && y >= 0 && y < grid[x].length && grid[x][y];
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