import java.io.*;
import java.util.*;

public class A {

	final String filename = new String("A").toLowerCase();

	void solve() throws Exception {
		int n = nextInt();
		long l1 = 0, r1 = 0, l2 = 0, r2 = 0;
		// L -> y + x; R -> y - x;
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			long newL1 = l1, newR1 = r1, newL2 = l2, newR2 = r2;
			if (s.length() == 2) {
				if (s.equals("UR")) {
					newL1++; newL2++;
					newR1--; newR2++;
				} else if (s.equals("DR")) {
					newR1--; newR2--;
					newL1--; newL2++;
				} else if (s.equals("UL")) {
					newL1--; newL2++;
					newR1++; newR2++;
				} else {
					newL1--; newL2--;
					newR1--; newR2++;
				}
			} else {
				newL1--; newR1--;
				newL2++; newR2++;
			}
			l1 = newL1;
			l2 = newL2;
			r1 = newR1;
			r2 = newR2;
			System.err.println(l1 + " " + r1 + " " + l2 + " " + r2);
			
		}
		long sq = (((r2 - r1) / 2) + 1) * (((l2 - l1) / 2) + 1);
		out.println(sq);
	}
	
	void naive() throws Exception {
		int n=  nextInt();
		boolean[][] a = new boolean[20][20];
		a[10][10] = true;
		for (int IT = 0; IT < n; IT++) {
			String s = nextToken();
			boolean[][]  b = new boolean[20][20];
			if (s.indexOf('U') >= 0) {
				for (int i = 0; i < 19; i++) {
					for (int j = 0; j < 20; j++) {
						b[i][j] |= a[i + 1][j];
					}
				}
			} 
			if (s.indexOf('D') >= 0) {
				for (int i = 0; i < 19; i++) {
					for (int j = 0; j < 20; j++) {
						b[i + 1][j] |= a[i][j];
					}
				}
			}
			
			if (s.indexOf('L') >= 0) {
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 19; j++) {
						b[i][j] |= a[i][j + 1];
					}
				}
			} 
			if (s.indexOf('R') >= 0) {
				for (int i = 0; i < 20; i++) {
					for (int j = 0; j < 19; j++) {
						b[i][j + 1] |= a[i][j];
					}
				}
			}
			a = b;
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 20; j++) {
					if (a[i][j]) {
						out.print('o');
					} else {
						out.print('.');
					}
				}
				out.println();
			}
			out.println();
		}

	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader("input.txt"));
			//			out = new PrintWriter("output.txt");
//			naive();
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
		new A().run();
	}

}