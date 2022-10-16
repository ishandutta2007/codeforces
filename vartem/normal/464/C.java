import java.io.*;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;

	final long MOD = (long) (1e9 + 7);
	
	void solve() {
		String init = in.nextToken();
		int n = in.nextInt() + 1;
		
		char[] left = new char[n];
		String[] right = new String[n];
		for (int i = 1; i < n; i++) {
			String q = in.nextToken();
			left[i] = q.charAt(0);
			right[i] = q.substring(3);
		}
		left[0] = '0';
		right[0] = init;
		
		long[] len = new long[n], rem = new long[n];
		
		int[] last = new int[10];
		Arrays.fill(last, n);
		
		for (int i = n - 1; i >= 0; i--) {
			for (int t = 0; t < right[i].length(); t++) {
				char c = right[i].charAt(t);
				if (last[c - '0'] == n) {
					len[i] = (len[i] + 1) % (MOD - 1);
					rem[i] = (rem[i] * 10 + c - '0') % MOD;
				} else {
					
					int item = last[c - '0'];
					len[i] = (len[i] + len[item]) % (MOD - 1);
					rem[i] = (rem[i] * pow(10, len[item]) + rem[item]) % MOD;
				}
			}
			last[left[i] - '0'] = i;
		}
		
		out.println(rem[0]);
	}

	private long pow(long x, long l) {
		long ans = 1;
		while (l > 0) {
			if ((l & 1) == 1) {
				ans = (ans * x) % MOD;
			}
			x = (x * x) % MOD;
			l >>>= 1;
		}
		return ans;
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
		new C().run();
	}
}