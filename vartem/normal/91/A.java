import java.io.*;
import java.util.*;

public class Temp {

	void solve() throws Exception {
		String s1 = nextToken();
		String s2 = nextToken();
		int n = s1.length();
		int m = s2.length();
		int[][] next = new int[n + 1][26];
		for (int i = 0; i <= n; i++)
			Arrays.fill(next[i], -1);
		int[] first = new int[26];
		for (int i = 0; i < 26; i++)
			first[i] = s1.indexOf('a' + i);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < 26; j++) {
				if (s1.charAt(i) == 'a' + j)
					next[i][j] = i;
				else {
					if (i == n - 1) {
						next[i][j] = -1;
					} else {
						next[i][j] = next[i + 1][j];
					}
				}
			}
		}
		int last = -1;
		int ans = 1;
		for (int i = 0; i < m; i++) {
			last = next[last + 1][s2.charAt(i) - 'a'];
			if (last == -1) {
				ans++;
				last = first[s2.charAt(i) - 'a'];
			}
			
			if (last == -1) {
				ans = -1;
				break;
			}
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader(filename + ".in"));
			// out = new PrintWriter(filename + ".out");

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("Temp").toLowerCase();

	String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

	public static void main(String[] args) {
		new Temp().run();
	}

}