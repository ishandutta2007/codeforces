import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		if ((n + m) % 2 == 1) {
			out.println(0);
			return;
		}
		int[] countRs = new int[n];
		int[] countCs = new int[m];
		int[] valRs = new int[n];
		int[] valCs = new int[m];
		Arrays.fill(valRs, 1);
		Arrays.fill(valCs, 1);
		for (int i = 0; i < k; ++i) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			int val = nextInt();
			valRs[x] *= val;
			valCs[y] *= val;
			countRs[x]++;
			countCs[y]++;
		}
		int p = nextInt();
		int pow = n * m - n - m + 1 - k;
		for (int i = 0; i < n; ++i) {
			if (countRs[i] == m) {
				pow++;
				if (valRs[i] == 1) {
					out.println(0);
					return;
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			if (countCs[i] == n) {
				pow++;
				if (valCs[i] == 1) {
					out.println(0);
					return;
				}
			}
		}
		out.println(modPow(2, pow, p));
	}

	private long modPow(long x, int pow, long p) {
		long r = 1;
		while (pow > 0) {
			if (pow % 2 == 1) {
				r = (r * x) % p;
			}
			pow /= 2;
			x = (x * x) % p;
		}
		return r;
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