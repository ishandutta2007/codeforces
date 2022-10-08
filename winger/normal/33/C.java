import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
		}
		int[] b = new int[n];
		int min = 0;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += a[i];
			min = Math.min(min, sum);
			b[i] = sum - 2 * min;
		}
//		System.out.println(Arrays.toString(b));
		int ans = b[n - 1];
		min = 0;
		sum = 0;
		for (int i = n - 1; i >= 0; --i) {
			sum += a[i];
			min = Math.min(min, sum);
			int suffix = sum - 2 * min;
			ans = Math.max(ans, suffix + (i == 0 ? 0 : b[i - 1]));
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