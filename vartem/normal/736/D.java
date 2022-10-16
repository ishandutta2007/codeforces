import java.util.*;
import java.io.*;

public class D {

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		int[][] pos = new int[n][n];
		BitSet[] matrix = new BitSet[n], inverse = new BitSet[n];
		for (int i = 0; i < n; i++) {
			matrix[i] = new BitSet(n);
			inverse[i] = new BitSet(n);
			inverse[i].set(i);
		}
		int[] rs = new int[m], cs = new int[m];
		for (int i = 0; i < m; i++) {
			int r = in.nextInt() - 1, c = in.nextInt() - 1;
			rs[i] = r;
			cs[i] = c;
			pos[r][c] = i + 1;
			matrix[r].set(c);
		}
		
		for (int col = 0; col < n; col++) {
			int row = -1;
			for (int j = col; j < n; j++) {
				if (matrix[j].get(col)) {
					row = j;
					break;
				}
			}
			
			{
				BitSet tmp = matrix[col];
				matrix[col] = matrix[row];
				matrix[row] = tmp;
			}
			{
				BitSet tmp = inverse[col];
				inverse[col] = inverse[row];
				inverse[row] = tmp;
			}
			
			for (int i = 0; i < n; i++) {
				if (i != col && matrix[i].get(col)) {
					matrix[i].xor(matrix[col]);
					inverse[i].xor(inverse[col]);
				}
			}
		}
//		System.err.println(Arrays.toString(inverse));
		for (int i = 0; i < m; i++) {
			out.println(inverse[cs[i]].get(rs[i]) ? "NO" : "YES");
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
		new D().run();
	}
}