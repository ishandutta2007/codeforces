import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = 200;
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
		}
		int[] b = new int[n];
		int[] bLen = new int[n];
		for (int i = n - 1; i >= 0; --i) {
			if (i + a[i] >= n) {
				b[i] = i;
				bLen[i] = 0;
			} else if ((i + a[i]) / k == i / k) {
				b[i] = b[i + a[i]];
				bLen[i] = bLen[i + a[i]] + 1;
			} else {
				b[i] = i + a[i];
				bLen[i] = 1;
			}
		}
		for (int it = 0; it < m; ++it) {
			int t = nextInt();
			if (t == 0) {
				int pos = nextInt() - 1;
				a[pos] = nextInt();
				int bucket = (pos / k) * k;
				for (int i = Math.min(n - 1, bucket + k - 1); i >= bucket; --i) {
					if (i + a[i] >= n) {
						b[i] = i;
						bLen[i] = 0;
					} else if (i + a[i] < bucket + k) {
						b[i] = b[i + a[i]];
						bLen[i] = bLen[i + a[i]] + 1;
					} else {
						b[i] = i + a[i];
						bLen[i] = 1;
					}
				}
			} else {
				int i = nextInt() - 1;
				int len = 1;
				while (b[i] != i) {
					len += bLen[i];
					i = b[i];
				}
				out.println((i + 1) + " " + len);
			}
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