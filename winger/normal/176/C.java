import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	int[] dx = {-1, 1, 0, 0};
	int[] dy = {0, 0, -1, 1};
	
	Boolean[][][] d = new Boolean[16][16][1 << 16];
	boolean gen(int x1, int y1, int x2, int y2, int mask) {
		int p1 = x1 * 4 + y1;
		int p2 = x2 * 4 + y2;
		if (p1 == p2) {
			return true;
		}
//		System.err.println(x1 + " " + y1 + " " + x2 + " " + y2);
		if (d[p1][p2][mask] == null) {
			loop: for (int p = 0; p < 16; ++p) {
				if (p == p1 || p == p2) {
					continue;
				}
				if ((mask & (1 << p1)) == 0) {
					for (int dir = 0; dir < 4; ++dir) {
						int x = x1 + dx[dir];
						int y = y1 + dy[dir];
						if ((Math.abs(x - x2) + Math.abs(y - y2)) < (Math.abs(x1 - x2) + Math.abs(y1 - y2)) && gen(x, y, x2, y2, mask | (1 << p))) {
							continue loop;
						}
					}
				}
				if ((mask & (1 << p2)) == 0) {
					for (int dir = 0; dir < 4; ++dir) {
						int x = x2 + dx[dir];
						int y = y2 + dy[dir];
						if ((Math.abs(x1 - x) + Math.abs(y1 - y)) < (Math.abs(x1 - x2) + Math.abs(y1 - y2)) && gen(x1, y1, x, y, mask | (1 << p))) {
							continue loop;
						}
					}
				}
				return d[p1][p2][mask] = false;
			}
			d[p1][p2][mask] = true;
		}
		return d[p1][p2][mask];
	}

	public void solve() throws IOException {
		nextInt();
		nextInt();
		int x0 = nextInt();
		int y0 = nextInt();
		int x2 = nextInt();
		int y2 = nextInt();
		for (int dir = 0; dir < 4; ++dir) {
			int x1 = x0 + dx[dir];
			int y1 = y0 + dy[dir];
			int minx = Math.min(x1, x2);
			int miny = Math.min(y1, y2);
			if (Math.abs(x1 - x2) < 4 && Math.abs(y1 - y2) < 4 && gen(x1 - minx, y1 - miny, x2 - minx, y2 - miny, 0)) {
				out.println("First");
				return;
			}
		}
		out.println("Second");
	}

	public void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		
		solve();
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}