import java.io.*;
import java.util.*;

public class D {

	int k;
	
	class Creature {
		long[] table;
		public Creature(int idx) {
			table = new long[1 << (k - 6)];
			for (int i = 0; i < 1 << k; i++) {
				if ((i & (1 << idx)) != 0) {
					table[i >> 6] |= 1L << (i & 63);
				}
			}
		}
		
		boolean get(int i) {
			return ((table[i >> 6] >> (i & 63)) & 1) != 0;
		}
		public Creature(long[] table) { 
			this.table = table;
		}

		@Override
		public String toString() {
			String s = "";
			for (int i = 0; i < 1 << k; i++) {
				s += get(i) ? 1 : 0;
			}
			return s;
		}
		
		
	}
	
	Creature min(Creature a, Creature b) {
		long[] table=  new long[1 << (k - 6)];
		for (int i = 0; i < table.length; i++) {
			table[i] = a.table[i] | b.table[i];
		}
		return new Creature(table);
	}
	
	Creature max(Creature a, Creature b) {
		long[] table=  new long[1 << (k - 6)];
		for (int i = 0; i < table.length; i++) {
			table[i] = a.table[i] & b.table[i];
		}
		return new Creature(table);
	}
	
	List<Creature> cs = new ArrayList<>();
	
	void solve() {
		int n = in.nextInt();
		int realK = in.nextInt();
		k = Math.max(realK, 6);
		int q = in.nextInt();

		int[][] init = new int[n][k];
		for (int i = 0; i < realK; i++) {
			for (int j = 0; j < n; j++) {
				init[j][i] = in.nextInt();
			}
		}
		
		for (int i = 0; i < realK; i++) {
			cs.add(new Creature(i));
		}
//		System.err.println(cs);
		
		for (int query = 0; query < q; query++) {
			int type = in.nextInt();
			int x = in.nextInt() - 1, y = in.nextInt() - 1;
			if (type == 1) {
				cs.add(max(cs.get(x), cs.get(y)));
			} else if (type == 2) {
				cs.add(min(cs.get(x), cs.get(y)));
			} else {
				int left = 0, right = 1 << 30;
				Creature cr = cs.get(x);
				int[] ar = init[y];
				while (left < right - 1) {
					int mid = (left + right) >>> 1;
					int mask = 0;
					for (int i = 0; i < k; i++) {
						if (mid >= ar[i]) {
							mask |= 1 << i;
						}
					}
					if (cr.get(mask)) {
						right = mid;
					} else {
						left = mid;
					}
				}
				out.println(right);
			}
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
		new D().run();
	}
}