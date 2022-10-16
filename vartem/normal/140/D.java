import java.io.*;
import java.util.*;

public class D {

	final String filename = new String("D").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		Arrays.sort(a);
		int[][][] dp = new int[721][n + 1][n + 1];
		int inf = Integer.MAX_VALUE / 3;
		for (int i = 0; i <= 720; i++) {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k <= n; k++) {
					dp[i][j][k] = inf;
				}
			}
		}

		dp[10][0][0] = 0;
		for (int cur = 1; cur <= n; cur++) {
			for (int time = 10; time <= 720; time++) {
				for (int cnt = 0; cnt <= n; cnt++) {

					dp[time][cnt][cur] = dp[time][cnt][cur - 1];

					if (a[cur - 1] <= time && cnt > 0) {
						int prev = dp[time - a[cur - 1]][cnt - 1][cur - 1];
						int pen = time - 360;
						if (pen < 0)
							pen = 0;
						dp[time][cnt][cur] = Math.min(dp[time][cnt][cur], prev
								+ pen);
					}
				}
			}
		}
		
				
		int best = 0;
		for (int cnt = 0; cnt <= n; cnt++) {
			for (int time = 10; time <= 720; time++) {
				if (dp[time][cnt][n] < inf) {
					best = cnt;
				}
			}
		}
		
		out.print(best + " ");
		int min = inf;
		for (int time = 10; time <= 720; time++) {
			if (dp[time][best][n] < min) {
				min = dp[time][best][n];
			}
		}
		if (min == inf) {
			out.println(0);
		} else {
			out.println(min);
		}
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
		new D().run();
	}

}