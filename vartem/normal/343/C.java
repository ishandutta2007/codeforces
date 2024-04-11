import java.io.*;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		long[] h = new long[n], p = new long[m];
		for (int i = 0; i < n; i++) {
			h[i] = in.nextLong();
		}
		for (int j= 0 ; j < m; j++) {
			p[j] = in.nextLong();
		}
		
		long left = -1, right = (long) 1e11;
		while (left < right - 1) {
			long mid = (left + right) >> 1;
			
			int last = 0;
			boolean ok = true;
			for (int i = 0; i < n; i++) {
				if (last == m) {
					break;
				}
				long needPos = p[last];
				long curPos = h[i];
				long dist = curPos - needPos;
				
				if (Math.abs(dist) > mid) {
					continue;
				}
				if (needPos > curPos) {
					long maxGo = curPos + mid;
					while (last < m && p[last] <= maxGo) {
						last++;
					}
				} else {
					long maxGo = Math.max(mid - 2 * dist, (mid - dist) / 2);
					maxGo += curPos;
					while (last < m && p[last] <= maxGo) {
						last++;
					}
				}
			}
			
			if (last < m) {
				ok = false;
			}
			
			if (ok) {
				right = mid;
			} else {
				left = mid;
			}
		
		}
		out.println(right);
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

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
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
		new C().run();
	}
}