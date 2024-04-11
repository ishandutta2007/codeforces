import java.io.*;
import java.util.*;

public class Solution implements Runnable {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	char[][] rotate(char[][] f) {
		int n = f.length;
		int m = f[0].length;
		char[][] ret = new char[m][n];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ret[j][n - i - 1] = f[i][j];
			}
		}
		return ret;
	}
	
	String toString(char[][] f) {
		StringBuilder sb = new StringBuilder();
		for (char[] ar : f) {
			sb.append(ar).append("|");
		}
		return sb.toString();
	}
	
	private void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		char[][] f = new char[n][m];
		for (int i = 0; i < n; ++i) {
			f[i] = next().toCharArray();
		}
		int count = 0, minx = -1, miny = -1;
		for (int x = 1; x <= n; ++x) {
			loop: for (int y = 1; y <= m; ++y) {
				if (n % x != 0 || m % y != 0) {
					continue;
				}
				HashSet<String> set = new HashSet<String>();
				for (int i = 0; i < n; i += x) {
					for (int j = 0; j < m; j += y) {
						char[][] piece = new char[x][y];
						for (int ii = 0; ii < x; ++ii) {
							for (int jj = 0; jj < y; ++jj) {
								piece[ii][jj] = f[i + ii][j + jj];
							}
						}
						String min = null;
						for (int r = 0; r < 4; ++r) {
							String s = toString(piece);
							if (min == null || s.compareTo(min) < 0) {
								min = s;
							}
							piece = rotate(piece);
						}
						if (set.contains(min)) {
							continue loop;
						}
						set.add(min);
					}
				}
				count++;
				if (minx == -1 || (x * y < minx * miny || x * y == minx * miny && x < minx)) {
					minx = x;
					miny = y;
				}
			}
		}
		out.println(count);
		out.println(minx + " " + miny);
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