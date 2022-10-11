import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;
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

	static char[][] grid;
	
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int r = readInt();
			int c = readInt();
			grid = new char[r][c];
			int total = 0;
			for(int i = 0; i < r; i++) {
				String s = nextToken();
				for(int j = 0; j < c; j++) {
					grid[i][j] = s.charAt(j);
					if(grid[i][j] == '#') {
						total++;
					}
				}
			}
			if(total <= 2) {
				pw.println("-1");
				continue;
			}
			int ret = 2;
			int[] dx = new int[]{-1,1,0,0};
			int[] dy = new int[]{0,0,-1,1};
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					if(grid[i][j] == '.') continue;
					grid[i][j] = '.';
					LinkedList<State> q = new LinkedList<State>();
					boolean[][] seen = new boolean[r][c];
					for(int a = 0; a < r; a++) {
						for(int b = 0; b < c && q.isEmpty(); b++) {
							if(grid[a][b] == '#') {
								q.add(new State(a, b));
								seen[a][b] = true;
							}
						}
					}
					int count = 0;
					while(!q.isEmpty()) {
						State curr = q.removeFirst();
						count++;
						for(int k = 0; k < dx.length; k++) {
							int nx = curr.x + dx[k];
							int ny = curr.y + dy[k];
							if(nx >= 0 && nx < r && ny >= 0 && ny < c && !seen[nx][ny] && grid[nx][ny] == '#') {
								q.add(new State(nx, ny));
								seen[nx][ny] = true;
							}
						}
					}
					if(count + 1 < total) {
						ret = 1;
					}
					grid[i][j] = '#';
				}
			}
			pw.println(ret);
		}
		exitImmediately();
	}

	static class State {
		public int x,y;

		public State(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
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