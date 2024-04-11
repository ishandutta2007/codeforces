import java.awt.*;
import java.awt.event.*;
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

	static int[] dx = new int[]{-1,1,0,0};
	static int[] dy = new int[]{0,0,-1,1};
	
	static char[][] grid;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int r = readInt();
			int c = readInt();
			grid = new char[r][c];
			int[][] dist = new int[r][c];
			for(int a = 0; a < r; a++)	{
				Arrays.fill(dist[a], 1 << 25);
			}
			for(int i = 0; i < r; i++)	{
				grid[i] = nextToken().toCharArray();
			}
			ArrayList<Op> ret = new ArrayList<Op>();
			for(int i = 0; i < r; i++)	{
				for(int j = 0; j < c; j++)	{
					if(valid(i,j))	{
						
						dist[i][j] = 0;
						grid[i][j] = '#';
						LinkedList<State> q = new LinkedList<State>();
						LinkedList<State> rev = new LinkedList<State>();
						q.add(new State(i,j));
						while(!q.isEmpty())	{
							State curr = q.removeFirst();
							ret.add(new Op('B', curr.x, curr.y));
							for(int k = 0; k < dx.length; k++)	{
								if(valid(curr.x + dx[k], curr.y + dy[k]) && dist[curr.x+dx[k]][curr.y+dy[k]] > dist[curr.x][curr.y] + 1)	{
									dist[curr.x+dx[k]][curr.y+dy[k]] = dist[curr.x][curr.y] + 1;
									grid[curr.x+dx[k]][curr.y+dy[k]] = '#';
									q.addLast(new State(curr.x+dx[k],curr.y+dy[k]));
									rev.addFirst(new State(curr.x+dx[k], curr.y+dy[k]));
								}
							}
						}
						while(!rev.isEmpty())	{
							State curr = rev.removeFirst();
							ret.add(new Op('D', curr.x, curr.y));
							ret.add(new Op('R', curr.x, curr.y));
						}
					}
				}
			}
			pw.println(ret.size());
			for(Op out: ret)	{
				pw.println(out);
			}
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
	
	public static boolean valid(int x, int y)	{
		return x >= 0 && x < grid.length && y >= 0 && y < grid[x].length && grid[x][y] == '.';
	}
	
	static class Op{
		public char ch;
		public int x,y;
		public Op(char ch, int x, int y) {
			super();
			this.ch = ch;
			this.x = x;
			this.y = y;
		}
		public String toString()	{
			return ch + " " + (x+1) + " " + (y+1);
		}
	}
	
	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
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
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}