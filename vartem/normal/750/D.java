import java.util.*;
import java.io.*;

public class D {

	int MAX = 320;
	int mid = 160;

	boolean[][][][] field = new boolean[30][8][MAX][MAX];
	boolean[][] vis = new boolean[30][8];

	int[] dx = new int[] { 1, 1, 0, -1, -1, -1, 0, 1 };
	int[] dy = new int[] { 0, 1, 1, 1, 0, -1, -1, -1 };
	int[] a;

	void go(int pos, int dir) {
		if (vis[pos][dir]) {
			return;
		}
		vis[pos][dir] = true;
		boolean[][] f = field[pos][dir];
		for (int i = 1; i <= a[pos]; i++) {
			f[mid + i * dx[dir]][mid + i * dy[dir]] = true;
		}

		if (pos + 1 < a.length) {
			go(pos + 1, (dir + 1) % 8);
			go(pos + 1, (dir + 7) % 8);
			boolean[][] f1 = field[pos + 1][(dir + 1) % 8];
			boolean[][] f2 = field[pos + 1][(dir + 7) % 8];

			int sx = mid + a[pos] * dx[dir];
			int sy = mid + a[pos] * dy[dir];

			for (int i = 0; i < MAX; i++) {
				for (int j = 0; j < MAX; j++) {
					if (f1[i][j] || f2[i][j]) {
						f[sx + i - mid][sy + j - mid] = true;
					}
				}
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}

		go(0, 0);
		int count = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				count += field[0][0][i][j] ? 1 : 0;
			}
		}
		out.println(count);
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new D().run();
	}
}