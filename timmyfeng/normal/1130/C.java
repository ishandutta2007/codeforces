import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main {
	static String[] grid;
	static int[][] color;
	static int n;

	static void dfs(int r, int c, int cur) {
		if (r < 0 || r >= n || c < 0 || c >= n || color[r][c] != 0 || grid[r].charAt(c) == '1')
			return;

		color[r][c] = cur;

		dfs(r + 1, c, cur);
		dfs(r - 1, c, cur);
		dfs(r, c + 1, cur);
		dfs(r, c - 1, cur);
	}

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);

		n = in.nextInt();
		int r1 = in.nextInt() - 1;
		int c1 = in.nextInt() - 1;
		int r2 = in.nextInt() - 1;
		int c2 = in.nextInt() - 1;

		grid = new String[n];
		for (int i = 0; i < n; ++i) {
			grid[i] = in.next();
		}

		int cnt = 0;
		color = new int[n][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (color[i][j] == 0) {
					++cnt;
					dfs(i, j, cnt);
				}
			}
		}

		int ans = 2 * n * n;
		for (int i1 = 0; i1 < n; ++i1) {
			for (int j1 = 0; j1 < n; ++j1) {
				for (int i2 = 0; i2 < n; ++i2) {
					for (int j2 = 0; j2 < n; ++j2) {
						if (color[i1][j1] == color[r1][c1] && color[i2][j2] == color[r2][c2]) {
							ans = min(ans, (i2 - i1) * (i2 - i1) + (j2 - j1) * (j2 - j1));
						}
					}
				}
			}
		}
		out.println(ans);

		out.close();
	}
}

class InputReader {
	public BufferedReader read;
	public StringTokenizer token;

	public InputReader(InputStream str) {
		read = new BufferedReader(new InputStreamReader(str), 1 << 15);
	}

	public String next() {
		while (token == null || !token.hasMoreTokens()) {
			try {
				token = new StringTokenizer(read.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return token.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
}