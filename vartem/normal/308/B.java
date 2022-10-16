import java.io.*;
import java.util.*;

public class B {

	FastScanner in;
	PrintWriter out;

	void solve() throws IOException {
		this.n = in.nextInt();
		int r = in.nextInt();
		int c = in.nextInt();
		
		String[] words = new String[n];
		int minLen = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			words[i] = in.next();
			minLen = Math.min(minLen, words[i].length());
		}
		if (minLen > c) {
			out.println();
			return;
		}
		
		int[] pref = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] + words[i - 1].length();
		}
		
		int[] maxOne = new int[n];
		int right = -1;
		for (int i = 0; i < n; i++) {
			while (right + 1 < n && (pref[right + 2] - pref[i] + (right + 1 - i)) <= c) {
				right++;
			}
			maxOne[i] = right;
		}
		int[] mul = maxOne.clone();
		int[] cur = maxOne.clone();
		int count = r - 1;
		while (count > 0) {
			if ((count % 2 == 1)) {
				relax(cur, mul);
			}
			
			relax(mul, mul);
			count >>= 1;
		}
		
		int bestI = 0;
		for (int i = 0; i < n; i++) {
			if (cur[i] - i + 1 > cur[bestI] - bestI + 1) {
				bestI = i;
			}
		}
		out.print(words[bestI]);
		int curRow = words[bestI].length();
		for (int i = bestI + 1; i <= cur[bestI]; i++) {
			if (curRow + 1 + words[i].length() <= c) {
				out.print(" " + words[i]);
				curRow += 1 + words[i].length();
			} else {
				out.println();
				out.print(words[i]);
				curRow = words[i].length();
			}
		}
	}
	
	int n;
	
	void relax(int[] a, int[] b) {
		for (int i = 0; i < n; i++) {
			int to = a[i] + 1;
			if (to >= n) {
				to = n - 1;
			}
			a[i] = b[to];
		}
	}

	void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			solve();
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}