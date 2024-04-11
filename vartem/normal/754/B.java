import java.util.*;
import java.io.*;

public class B {

	void solve() {
		char[][] a = new char[4][4];
		for (int i = 0; i < 4; i++) {
			a[i] = in.nextToken().toCharArray();
		}

		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++) {
				if (a[i][j] == '.') {
					a[i][j] = 'x';
					if (win(a)) {
						out.println("YES");
						return;
					}
					a[i][j] = '.';
				}
			}
		}
		out.println("NO");
	}

	int[] dx = new int[] { 0, 1, 1, 1 };
	int[] dy = new int[] { 1, 1, 0, -1 };

	boolean win(char[][] a) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int dir = 0; dir < 4; dir++) {
					boolean ok = true;
					for (int t = 0; t < 3; t++) {
						int ni = i + dx[dir] * t, nj = j + dy[dir] * t;
						ok &= 0 <= ni && ni < 4 && 0 <= nj && nj < 4 && a[ni][nj] == 'x';
					}
					if (ok) {
						return true;
					}
				}
			}
		}
		return false;
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
		new B().run();
	}
}