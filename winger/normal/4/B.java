import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		int sum = nextInt();
		int[] u = new int[n];
		int[] v = new int[n];
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			u[i] = nextInt();
			v[i] = nextInt();
			sum -= a[i] = u[i];
		}
		if (sum < 0) {
			out.println("NO");
			return;
		}
		for (int i = 0; i < n; ++i) {
			int d = Math.min(sum, v[i] - a[i]);
			a[i] += d;
			sum -= d;
		}
		if (sum > 0) {
			out.println("NO");
			return;
		}
		out.println("YES");
		for (int i : a) {
			out.print(i + " ");
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