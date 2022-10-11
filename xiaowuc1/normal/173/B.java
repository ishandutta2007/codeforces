import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import com.sun.org.apache.bcel.internal.generic.LLOAD;


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
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int r = readInt();
			int c = readInt();
			ArrayList<Integer>[] rows = new ArrayList[r];
			for (int i = 0; i < rows.length; i++) {
				rows[i] = new ArrayList<Integer>();
			}
			ArrayList<Integer>[] cols = new ArrayList[c];
			for (int i = 0; i < cols.length; i++) {
				cols[i] = new ArrayList<Integer>();
			}
			for(int i = 0; i < r; i++)	{
				String str = nextToken();
				for(int j = 0; j < c; j++)	{
					if(str.charAt(j) == '#')	{
						rows[i].add(j);
						cols[j].add(i);
					}
				}
			}
			if(rows[0].isEmpty() || rows[r-1].isEmpty())	{
				pw.println(-1);
			}
			else	{
				boolean[] rowDone = new boolean[r];
				boolean[] colDone = new boolean[c];
				int[][] dp = new int[r][c];
				for (int i = 0; i < dp.length; i++) {
					Arrays.fill(dp[i], 1 << 25);
				}
				int ret = -1;
				LinkedList<Vertex> q = new LinkedList<Vertex>();
				for(int out: rows[r-1])	{
					q.add(new Vertex(r-1, out, 1));
					dp[r-1][out] = 1;
				}
				while(ret == -1 && !q.isEmpty())	{
					Vertex curr = q.poll();
					if(!colDone[curr.y]){
						colDone[curr.y] = true;
						for(int row: cols[curr.y])	{
							if(row == 0)	{
								ret = curr.w+1;
								break;
							}
							if(dp[row][curr.y] > 1 + curr.w)	{
								dp[row][curr.y] = 1 + curr.w;
								q.add(new Vertex(row, curr.y, 1 + curr.w));
							}
						}
					}
					if(!rowDone[curr.x])	{
						rowDone[curr.x] = true;
						for(int col: rows[curr.x])	{
							if(dp[curr.x][col] > 1 + curr.w)	{
								dp[curr.x][col] = 1 + curr.w;
								q.add(new Vertex(curr.x, col, 1 + curr.w));
							}
						}
					}
				}
				pw.println(ret);
			}
		}
		pw.close();
	}

	static class Vertex	implements Comparable<Vertex> {
		public int x,y,w;

		public Vertex(int x, int y, int w) {
			super();
			this.x = x;
			this.y = y;
			this.w = w;
		}

		public int compareTo(Vertex curr)	{
			return w - curr.w;
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