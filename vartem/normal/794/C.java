import java.util.*;
import java.io.*;

public class C {

	void solve() {
		char[] a = in.nextToken().toCharArray();
		char[] b = in.nextToken().toCharArray();

		int n = a.length;
		int[] cntA = getChars(a);
		removeStuff(cntA, (n + 1) / 2);

		int[] cntB = getChars(b);
		reverse(cntB);
		removeStuff(cntB, n / 2);
		reverse(cntB);

		char[] result = new char[n];
		go(cntA, cntB, result, 0, n - 1);
		out.println(new String(result));
	}

	void go(int[] a, int[] b, char[] res, int l, int r) {
		int[] tmp;
		boolean reversed = false;
		while (l <= r) {
			int minA = 26, maxA = -1;
			int minB = 26, maxB = -1;
			for (int i = 0; i < 26; i++) {
				if (a[i] > 0) {
					maxA = i;
					if (minA == 26) {
						minA = i;
					}
				}
				if (b[i] > 0) {
					maxB = i;
					if (minB == 26) {
						minB = i;
					}
				}
			}
			
			if (l == r) {
				res[l] = reversed ? ((char) ('z' - minA)) : ((char) ('a' + minA));
				return;
			}
			
			if (minA >= maxB) {
				res[r] = reversed ? ((char) ('z' - maxA)) : ((char) ('a' + maxA));
				r--;
				a[maxA]--;
			} else {
				res[l] = reversed ? ((char) ('z' - minA)) : ((char) ('a' + minA));
				l++;
				a[minA]--;
			}
			
			reverse(a);
			reverse(b);
			reversed ^= true;
			
			tmp = a;
			a = b;
			b = tmp;
		}
	}

	void reverse(int[] a) {
		for (int l = 0, r = a.length - 1; l < r; l++, r--) {
			int tmp = a[l];
			a[l] = a[r];
			a[r] = tmp;
		}
	}

	void removeStuff(int[] a, int k) {
		for (int i = 0; i < a.length; i++) {
			int cur = Math.min(k, a[i]);
			a[i] = cur;
			k -= cur;
		}
	}

	private int[] getChars(char[] a) {
		int[] cnt = new int[26];
		for (char c : a) {
			cnt[c - 'a']++;
		}
		return cnt;
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}