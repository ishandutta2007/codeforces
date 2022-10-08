import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	void solve() throws IOException {
		int n = nextInt();
		for (int i = 0; i < n; ++i) {
			nextInt();
		}
		int[] min = new int[n];
		Arrays.fill(min, 1000000000);
		int m = nextInt();
		for (int i = 0; i < m; ++i) {
			int a = nextInt() - 1;
			int b = nextInt() - 1;
			int c = nextInt();
			min[b] = Math.min(min[b], c);
		}
		int ans = 0;
		boolean root = false;
		for (int i = 0; i < n; ++i) {
			if (min[i] == 1000000000) {
				if (root) {
					out.println(-1);
					return;
				} else {
					root = true;
				}
			} else {
				ans += min[i];
			}
		}
		out.println(ans);
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