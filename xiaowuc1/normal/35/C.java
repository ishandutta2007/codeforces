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

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new FileReader("input.txt"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int r = readInt();
			int c = readInt();
			int n = readInt();
			int[][] dist = new int[r][c];
			for(int i = 0; i < r; i++) {
				Arrays.fill(dist[i], 1 << 25);
			}
			LinkedList<State> q = new LinkedList<State>();
			while(n-- > 0) {
				q.add(new State(readInt()-1, readInt()-1));
				dist[q.peekLast().x][q.peekLast().y] = 0;
			}
			int[] dx = new int[]{-1,1,0,0};
			int[] dy = new int[]{0,0,-1,1};
			State ret = q.peekLast();
			while(!q.isEmpty()) {
				State curr = q.removeFirst();
				ret = curr;
				for(int k = 0; k < dx.length; k++) {
					int nx = curr.x + dx[k];
					int ny = curr.y + dy[k];
					if(nx >= 0 && nx < r && ny >= 0 && ny < c && dist[nx][ny] > 1 + dist[curr.x][curr.y]) {
						dist[nx][ny] = 1 + dist[curr.x][curr.y];
						q.add(new State(nx, ny));
					}
				}
			}
			pw.println(ret.x+1 + " " + (ret.y+1));
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