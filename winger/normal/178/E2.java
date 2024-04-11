import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	long count;
	long sumx;
	long sumy;
	
	double mind, maxd;

	private void cDfs(int i, int j, boolean[][] b, boolean[][] col) {
		if (i < 0 || i >= b.length || j < 0 || j >= b.length || !b[i][j] || col[i][j]) {
			return;
		}
		col[i][j] = true;
		count++;
		sumx += i;
		sumy += j;
		for (int d = 0; d < 4; ++d) {
			cDfs(i + dx[d], j + dy[d], b, col);
		}
	}

	private void dDfs(int i, int j, boolean[][] b, boolean[][] col) {
		double x = (double)(i * count - sumx) / count;
		double y = (double)(j * count - sumy) / count;
		double dist = Math.sqrt(x * x + y * y);
		boolean out = i < 0 || i >= b.length || j < 0 || j >= b.length;
		if (!out && b[i][j]) {
			b[i][j] = false;
			maxd = Math.max(maxd, dist);
			for (int d = 0; d < 4; ++d) {
				dDfs(i + dx[d], j + dy[d], b, col);
			}
		} else {
			if (out || !col[i][j]) {
				mind = Math.min(mind, dist);
			}
		}
	}

	public void solve() throws IOException {
		int n = nextInt();
		boolean[][] a = new boolean[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = nextInt() == 1;
			}
		}
//		boolean[][] b = new boolean[n][n];
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < n; ++j) {
//				int count = 0, total = 0;
//				for (int dx = -1; dx <= 1; ++dx) {
//					for (int dy = -1; dy <= 1; ++dy) {
//						if (i + dx >= 0 && i+ dx < n && j + dy >= 0 && j + dy < n) {
//							total++;
//							if (a[i + dx][j + dy]) {
//								count++;
//							}
//						}
//					}
//				}
//				b[i][j] = count * 3 >= total;
//			}
//		}
		boolean[][] b = a;
		boolean[][] col = new boolean[n][n];
		int ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (b[i][j]) {
					count = 0;
					sumx = 0;
					sumy = 0;
					cDfs(i, j, b, col);
					if (count < 100) {
						continue;
					}
					mind = Double.POSITIVE_INFINITY;
					maxd = 0.;
					dDfs(i, j, b, col);
//					System.err.println(mind + " " + maxd);
					if (maxd / mind < (Math.sqrt(2.) + 1) / 2.) {
						ans1++;
					} else {
						ans2++;
					}
				}
			}
		}
		out.println(ans1 + " " + ans2);
	}
	
	int[] dx = {-1, 1, 0, 0};
	int[] dy = {0, 0, -1, 1};

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
//			in = new BufferedReader(new FileReader("medium_1.in"));
			out = new PrintWriter(System.out);
			eat("");
			
			solve();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
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
		new Thread(null, new Solution(), "vasya", 64000000).start();
	}
	
}