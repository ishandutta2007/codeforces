import java.io.*;
import java.util.*;

public class E {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		String s = in.nextToken(), t = in.nextToken();

		int pref = 0, suf = n - 1;
		while (s.charAt(pref) == t.charAt(pref)) {
			pref++;
		}

		while (s.charAt(suf) == t.charAt(suf)) {
			suf--;
		}

		s = s.substring(pref, suf + 1);
		t = t.substring(pref, suf + 1);

		Set<String> ans = new HashSet<>();
		{
			String check1 = s + t.charAt(t.length() - 1);
			String check2 = s.charAt(0) + t;
			if (check1.equals(check2)) {
				ans.add(check1);
			}
		}
		{
			String check1 = t + s.charAt(t.length() - 1);
			String check2 = t.charAt(0) + s;
			if (check1.equals(check2)) {
				ans.add(check1);
			}
		}
		out.println(ans.size());
	}

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
				e.printStackTrace();
			}
		}

		String nextToken() {
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
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new E().run();
	}
}