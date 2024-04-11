import java.io.*;
import java.util.*;

public class E {

	final int masks = 3 * 3 * 3 * 3 * 3 * 3;
	int[] precalc = new int[masks];
	int[] lucky = new int[] { 0, 4, 7 };
	{
		for (int i = 0; i < masks; i++) {
			int mask = i;
			for (int j = 0; j < 6; j++) {
				precalc[i] += lucky[mask % 3];
				mask /= 3;
			}
		}
	}

	final int len = 20;
	int[] digits = new int[len];
	boolean[][] can = new boolean[5][len + 1];
	int[][] prevMask = new int[5][len + 1];
	int[][] prevCarry = new int[5][len + 1];
	
	public void solve(long l) {
		int len = 20;

		for (int i = 0; i < len; i++) {
			digits[i] = (int) (l % 10);
			l /= 10;
		}

		for (int i = 0; i < 5; i++) {
			Arrays.fill(can[i], false);
		}
		can[0][0] = true;

		for (int curLen = 0; curLen < len; curLen++) {
			for (int curCarry = 0; curCarry < 5; curCarry++) {
				if (!can[curCarry][curLen]) {
					continue;
				}

				for (int mask = 0; mask < masks; mask++) {
					int sum = precalc[mask] + curCarry;
					if (sum % 10 == digits[curLen]) {
						can[sum / 10][curLen + 1] = true;
						prevMask[sum / 10][curLen + 1] = mask;
						prevCarry[sum / 10][curLen + 1] = curCarry;
					}
				}
			}
		}

		if (!can[0][len]) {
			out.println(-1);
			return;
		}

		int[][] result = new int[6][len + 1];

		int carry = 0;
		for (int curLen = len; curLen > 0; curLen--) {
			int mask = prevMask[carry][curLen];
			
			carry = prevCarry[carry][curLen];
			
			for (int j = 0; j < 6; j++) {
				result[j][curLen - 1] = lucky[mask % 3];
				mask /= 3;
			}
		}
		
		for (int i = 0; i < 6; i++) {
			out.print(getNumber(result[i]));
			if (i == 5) {
				out.println();
			} else {
				out.print(" ");
			}
		}
	}

	private long getNumber(int[] is) {
		long res = 0;
		for (int i = is.length - 1; i >= 0; i--) {
			res = res * 10 + is[i];
		}
		return res;
	}

	FastScanner in;
	PrintWriter out;

	public void run() {
		try {
			in = new FastScanner();
			out = new PrintWriter(System.out);
			int t = in.nextInt();
			for (int i = 0; i < t; i++) {
				solve(in.nextLong());
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String name) {
			try {
				br = new BufferedReader(new FileReader(name));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
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