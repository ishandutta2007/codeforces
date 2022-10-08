import java.io.*;
import java.util.*;

public class Solution implements Runnable {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private void solve() throws IOException {
		int n = nextInt();
		int k = nextInt();
		char[] w = next().toCharArray();
		boolean[] match = new boolean[n + 1];
		char[] tmp = next().toCharArray();
		for (int i = w.length; i <= n; ++i) {
			match[i] = tmp[i - w.length] == '1';
		}
		int[] pf = new int[w.length];
		for (int i = 1; i < w.length; ++i) {
			pf[i] = pf[i - 1];
			while (pf[i] > 0 && w[i] != w[pf[i]]) {
				pf[i] = pf[pf[i] - 1];
			}
			if (w[i] == w[pf[i]]) {
				pf[i]++;
			}
		}
		int[][] au = new int[w.length + 1][k];
		for (int i = 0; i <= w.length; ++i) {
			for (int j = 0; j < k; ++j) {
				char c = (char) ('a' + j);
				int st = i;
				while (st != 0 && (st == w.length || w[st] != c)) {
					st = pf[st - 1];
				}
				if (w[st] == c) {
					++st;
				}
				au[i][j] = st;
			}
		}
		int[][] p = new int[n + 1][w.length + 1];
		char[][] pc = new char[n + 1][w.length + 1];
		for (int i = 0; i <= n; ++i) {
			Arrays.fill(p[i], -1);
		}
		p[0][0] = -2;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= w.length; ++j) {
				if (p[i][j] == -1) {
					continue;
				}
				for (int c = 0; c < k; ++c) {
					int jj = au[j][c];
					if ((jj == w.length) != match[i + 1]) {
						continue;
					}
					p[i + 1][jj] = j;
					pc[i + 1][jj] = (char) ('a' + c);
				}
			}
		}
		int last = -1;
		for (int i = 0; i <= w.length; ++i) {
			if (p[n][i] != -1) {
				last = i;
			}
		}
		if (last == -1) {
			out.println("No solution");
			return;
		}
		StringBuilder ans = new StringBuilder();
		for (int i = n, j = last; i > 0; j = p[i--][j]) {
			ans.append(pc[i][j]);
		}
		out.println(ans.reverse().toString());
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			eat("");
			
			solve();
			
			in.close();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}
	}

	private void eat(String line) {
		st = new StringTokenizer(line);
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

	public static void main(String[] args) {
		new Thread(new Solution()).start();
	}

}