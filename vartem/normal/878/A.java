import java.io.*;
import java.util.*;

public class A {

	void solve() {
		int n = in.nextInt();
		int res0 = 0, res1 = 1023;
		for (int i = 0; i < n; i++) {
			char c = in.nextToken().charAt(0);
			int val = in.nextInt();
			if (c == '|') {
				res0 |= val;
				res1 |= val;
			} else if (c == '&') {
				res0 &= val;
				res1 &= val;
			} else {
				res0 ^= val;
				res1 ^= val;
			}
		}
		
		int xor = 0, or = 0, and = 1023;
		for (int bit = 0; bit < 10; bit++) {
			int bit0 = (res0 >> bit) & 1;
			int bit1 = (res1 >> bit) & 1;
			if (bit0 == 0 ) {
				if (bit1 == 0) { 
					and ^= 1 << bit; 
				} else {
					// pass
				}
			} else {
				if (bit1 == 0) {
					xor ^= 1 << bit;
				} else {
					or |= 1 << bit;
				}
			}
		}
		out.println(3);
		out.println("^ " + xor);
		out.println("| " + or);
		out.println("& " + and);
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

		public FastScanner(String file) {
			try {
				br = new BufferedReader(new FileReader(file));
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

		public boolean hasMoreTokens() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String line = br.readLine();
					if (line == null) {
						return false;
					}
					st = new StringTokenizer(line);
				} catch (IOException e) {
					return false;
				}
			}
			return true;
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

		public int[] nextIntArray(int length) {
			int[] array = new int[length];
			for (int i = 0; i < length; i++) {
				array[i] = nextInt();
			}
			return array;
		}
	}

	public static void main(String[] args) {
		new A().run();
	}
}