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
			int total = m;
			edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			while(m-- > 0) {
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
				edges[b].add(a);
			}
			int[][] dist = new int[n][];
			for(int i = 0; i < n; i++) {
				dist[i] = bfs(i);
			}
			int[][] g = new int[2][3];
			for(int i = 0; i < g.length; i++) {
				for(int j = 0; j < g[i].length; j++) {
					g[i][j] = readInt();
				}
			}
			g[0][0]--; g[0][1]--;
			g[1][0]--; g[1][1]--;
			if(dist[g[0][0]][g[0][1]] > g[0][2]) {
				pw.println(-1);
				continue;
			}
			if(dist[g[1][0]][g[1][1]] > g[1][2]) {
				pw.println(-1);
				continue;
			}
			int ret = total - dist[g[0][0]][g[0][1]] - dist[g[1][0]][g[1][1]];
			for(int a = 0; a < n; a++) {
				for(int b = 0; b < n; b++) {
					int x = dist[g[0][0]][a] + dist[a][b] + dist[b][g[0][1]];
					int y = dist[g[1][0]][a] + dist[a][b] + dist[b][g[1][1]];
					if(x <= g[0][2] && y <= g[1][2]) {
						ret = Math.max(ret, total - dist[g[0][0]][a] - dist[g[1][0]][a] - dist[a][b] - dist[b][g[0][1]] - dist[b][g[1][1]]);
					}
					x = dist[g[0][0]][a] + dist[a][b] + dist[b][g[0][1]];
					y = dist[g[1][1]][a] + dist[a][b] + dist[b][g[1][0]];
					if(x <= g[0][2] && y <= g[1][2]) {
						ret = Math.max(ret, total - dist[g[0][0]][a] - dist[g[1][1]][a] - dist[a][b] - dist[b][g[0][1]] - dist[b][g[1][0]]);
					}
					
				}
			}
			pw.println(ret);
		}
		pw.close();
	}

	static LinkedList<Integer>[] edges;
	public static int[] bfs(int s) {
		int[] dp = new int[edges.length];
		Arrays.fill(dp, 1 << 25);
		dp[s] = 0;
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(s);
		while(!q.isEmpty()) {
			int curr = q.removeFirst();
			for(int out: edges[curr]) {
				if(dp[out] == 1 << 25) {
					dp[out] = dp[curr] + 1;
					q.add(out);
				}
			}
		}
		return dp;
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