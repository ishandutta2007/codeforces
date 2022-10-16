import java.util.*;
import java.io.*;

public class E {

	int MAX_B = 10;
	int MAX_LEN = 60;
	long[][][] dp = new long[MAX_B + 1][][];
	
	void precalc() {
		for (int b = 2; b <= MAX_B; b++) {
			dp[b] = new long[MAX_LEN + 1][1 << b];
			
			dp[b][0][0] = 1;
			for (int l = 0; l < MAX_LEN; l++) {
				for (int mask = 0; mask < 1 << b; mask++) {
					for (int digit = 0; digit < b; digit++) {
						dp[b][l + 1][mask ^ (1 << digit)] += dp[b][l][mask];
					}
				}
			}
		}
	}
	
	long get(long r, int b) {
		if (r == 0) {
			return 0;
		}
		List<Integer> list = new ArrayList<>();
		while (r > 0) {
			list.add((int) (r % b));
			r /= b;
		}
		
		long result = 0;
		for (int l = 1; l < list.size(); l++) {
			for (int digit = 1; digit < b; digit++) {
			result += dp[b][l - 1][1 << digit];
			}
		}
		
		int curMask =0 ;
		for (int pos = list.size() - 1; pos >= 0; pos--) {
			
			for (int digit = 0; digit < list.get(pos); digit++) {
				if (digit == 0 && pos == list.size() - 1) {
					continue;
				}
				result += dp[b][pos][curMask ^ (1 << digit)];
			}
			curMask ^= 1 << list.get(pos);
		}
		if (curMask == 0) {
			result++;
		}
		return result;
	}
	
	void solve() {
		int q = in.nextInt();
		
		precalc();
		
		for (int i = 0; i < q; i++) {
			int b = in.nextInt();
			long l = in.nextLong(), r = in.nextLong();
			out.println(get(r, b) - get(l - 1, b));
		}
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
		new E().run();
	}
}