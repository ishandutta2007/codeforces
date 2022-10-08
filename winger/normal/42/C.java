import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int[] a = new int[4];
		for (int i = 0; i < 4; ++i) {
			a[i] = nextInt();
		}
		loop: while (true) {
			boolean all1 = true;
			for (int i : a) {
				all1 &= i == 1;
			}
			if (all1) {
				break;
			}
			for (int i = 0; i < 4; ++i) {
				if (a[i] % 2 == 0 && a[(i + 1) & 3] % 2 == 0) {
					a[i] /= 2;
					a[(i + 1) & 3] /= 2;
					out.println("/" + (i + 1));
					continue loop;
				}
			}
			for (int i = 0; i < 4; ++i) {
				if (a[i] % 2 == a[(i + 1) & 3] % 2 && (a[i] != 1 || a[(i + 1) & 3] != 1)) {
					a[i]++;
					a[(i + 1) & 3]++;
					out.println("+" + (i + 1));
					continue loop;
				}
			}
			int t = 0;
			while (a[t] == 1 && a[(t + 1) & 3] == 1) {
				++t;
			}
			a[t]++;
			a[(t + 1) & 3]++;
			out.println("+" + (t + 1));
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