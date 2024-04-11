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
			int n = readInt();
			int m = readInt();
			boolean[][] g = new boolean[n][n];
			int[] deg = new int[n];
			for(int i = 0; i < n; i++) {
				Arrays.fill(g[i], true);
				g[i][i] = false;
				deg[i] = n-1;
			}
			while(m-- > 0) {
				int x = readInt();
				int y = readInt();
				x--;
				y--;
				g[x][y] = false;
				g[y][x] = false;
				deg[x]--;
				deg[y]--;
			}
			char[] ret = new char[n];
			Arrays.fill(ret, 'b');
			int[] color = new int[n];
			boolean bad = false;
			for(int i = 0; i < n; i++) {
				if(color[i] != 0) continue;
				if(deg[i] == 0) continue;
				LinkedList<Integer> q = new LinkedList<Integer>();
				q.add(i);
				color[i] = -1;
				while(!q.isEmpty()) {
					int curr = q.removeFirst();
					if(color[curr] < 0) ret[curr] = 'a';
					else ret[curr] = 'c';
					for(int a = 0; a < n; a++) {
						if(g[curr][a]) {
							if(color[a] == color[curr]) {
								bad = true;
								break;
							}
							if(color[a] == 0) {
								color[a] = -color[curr];
								q.add(a);
							}
						}
					}
				}
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					int diff = Math.abs(ret[i] - ret[j]);
					if((diff == 2) != g[i][j]) {
						bad = true;
					}
				}
			}
			if(bad) {
				pw.println("No");
				continue;
			}
			pw.println("Yes");
			pw.println(new String(ret));
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