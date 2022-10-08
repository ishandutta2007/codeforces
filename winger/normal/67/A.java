import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		String s = next();
		int[] a = new int[n];
		Arrays.fill(a, 1);
		while (true) {
			boolean changed = false;
			for (int i = 0; i < n - 1; ++i) {
				if (s.charAt(i) == '=') {
					if (a[i] != a[i + 1]) {
						a[i] = a[i + 1] = Math.max(a[i], a[i + 1]);
						changed = true;
					}
				} else if (s.charAt(i) == 'L') {
					if (a[i] <= a[i + 1]) {
						a[i] = a[i + 1] + 1;
						changed = true;
					}
				} else if (s.charAt(i) == 'R') {
					if (a[i + 1] <= a[i]) {
						a[i + 1] = a[i] + 1;
						changed = true;
					}
				} else {
					throw new AssertionError();
				}
			}
			if (!changed) {
				break;
			}
		}
		for (int i = 0; i < n; ++i) {
			out.print(a[i] + " ");
		}
		out.println();
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