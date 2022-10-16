import java.io.*;
import java.util.*;

public class PalindromicPairs {

	final String filename = new String("PalindromicPairs").toLowerCase();

	void solve() throws Exception {
		String text = in.readLine();
		int n = text.length();
		long[] count = new long[n + 1];
		System.err.println(Arrays.toString(countOdd(text)));
		for (int i = 0; i < n; i++) {
			String ss = text.substring(i);
			count[i] = sum(countEven(ss)) + sum(countOdd(ss));
		}
		count[n] = 0;

		long result = 0;
		for (int i = 0; i < n; i++) {
			int l = i, r = i;
			while (l >= 0 && r < n && text.charAt(l) == text.charAt(r)) {
				result += count[r + 1];
				l--;
				r++;
			}
		}
		
		for (int i = 1; i < n; i++) {
			int l = i - 1, r = i;
			while (l >= 0 && r < n && text.charAt(l) == text.charAt(r)) {
				result += count[r + 1];
				l--;
				r++;
			}
		}
		
		out.println(result);	
	}

	private long sum(int[] s) {
		long ans = 0;
		for (int i : s) {
			ans += i;
		}
		return ans;
	}

	private int[] countEven(String text) {
		int n = text.length();
		int[] count = new int[n];
		count[0] = 0;
		int l = 0, r = 0;
		for (int i = 1; i < n; i++) {
			int s = 0;
			if (r >= i) {
				s = Math.min(r - i, count[l + (r - i)]);
			}
			while (i - s - 1 >= 0 && i + s < n
					&& text.charAt(i - s - 1) == text.charAt(i + s)) {
				s++;
			}
			count[i] = s;
			if (i + s - 1 > r) {
				r = i + s - 1;
				l = i - s + 1;
			}
		}
		return count;
	}

	private int[] countOdd(String text) {
		int n = text.length();
		int[] count = new int[n];
		count[0] = 1;
		int l = 0, r = 1;
		for (int i = 1; i < n; i++) {
			int s = 1;
			if (r > i) {
				s = Math.min(r - i, count[l + (r - i)]);
			}
			while (i - s >= 0 && i + s < n
					&& text.charAt(i - s) == text.charAt(i + s)) {
				s++;
			}
			count[i] = s;
			if (i + s > r) {
				r = i + s;
				l = i - s;
			}
		}
		return count;
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

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
		new PalindromicPairs().run();
	}

}