import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		char[][] f = new char[8][];
		int xw = -1, yw = -1;
		for (int i = 0; i < 8; ++i) {
			f[i] = next().toCharArray();
			for (int j = 0; j < 8; ++j) {
				if (f[i][j] == 'W') {
					xw = i;
					yw = j;
				}
			}
		}
		if (xw == -1 && yw == -1) {
			out.println(8);
		} else {
			int ans = 0;
			for (int x = 0; x < 8; ++x) {
				if (f[x][yw] == 'B') {
					++ans;
				}
			}
			for (int y = 0; y < 8; ++y) {
				if (f[xw][y] == 'B') {
					++ans;
				}
			}
			out.println(ans);
		}
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
		solve();
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
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
		new Solution();
	}
}