import java.io.*;
import java.util.*;

public class Taxi {

	final String filename = new String("Taxi").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int[] cnt = new int[5];
		for (int i = 0; i < n; i++) {
			cnt[nextInt()]++;
		}
		
		int ans = cnt[4];
		cnt[4] = 0;
		
		ans += cnt[3];
		cnt[1] = Math.max(0, cnt[1] - cnt[3]);
		cnt[3] = 0;
		
		int best = Integer.MAX_VALUE;
		for (int i = 0; i <= cnt[2]; i += 2) {
			int rmn = cnt[2] - i;
			int cur = i / 2;
			
			if (2 * rmn >= cnt[1]) {
				cur += rmn;
			} else {
				cur += rmn + (cnt[1] - 2 * rmn + 3) / 4;
			}
			best = Math.min(best, cur);
		}
		out.println(ans + best);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader("input.txt"));
			//			out = new PrintWriter("output.txt");

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
		new Taxi().run();
	}

}