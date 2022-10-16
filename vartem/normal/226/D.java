import java.io.*;
import java.util.*;

public class Table {

	final String filename = new String("Table").toLowerCase();

	void solve() throws Exception {
		int n = nextInt(), m=  nextInt();
		int[][] a = new int[n][m];
		int[] row = new int[n], col = new int[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = nextInt();
				row[i] += a[i][j];
				col[j] += a[i][j];
			}
		}
		
		boolean[] mRow = new boolean[n], mCol = new boolean[m];
		
		while (true) {
			boolean found = false;
			int rowN = -1, colN = -1;
			for (int i = 0; i < n; i++) {
				if (row[i] < 0) {
					found = true;
					rowN = i;
				}
			}
			
			for (int i = 0; i < m; i++) {
				if (col[i] < 0) {
					found = true;
					colN = i;
				}
			}
			
			if (!found) {
				break;
			}
			
			if (rowN != -1) {
				row[rowN] *= -1;
				mRow[rowN] ^= true;
				for (int j = 0; j < m; j++) {
					col[j] -= 2 * a[rowN][j];
					a[rowN][j] *= -1;					
				}
			} else {
				col[colN] *= -1;
				mCol[colN] ^= true;
				for (int j = 0; j < n; j++) {
					row[j] -= 2 * a[j][colN];
					a[j][colN] *= -1;					
				}
			}
		}
		
		print(mRow);
		out.println();
		print(mCol);
	}

	private void print(boolean[] m) {
		int count = 0;
		for (boolean b : m) {
			if (b) {
				count++;
			}
		}
		
		out.print(count + " ");
		for (int i = 0; i < m.length; i++) {
			if (m[i]) {
				out.print((i + 1) + " ");
			}
		}
		
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
		new Table().run();
	}

}