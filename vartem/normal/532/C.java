import java.io.*;
import java.util.*;

public class C {

	FastScanner in;
	PrintWriter out;
	

	void solve() {
		int r1 = in.nextInt(), c1 = in.nextInt(), r2 = in.nextInt(), c2 = in.nextInt();
		out.println(smart(r1, c1, r2, c2) ? "Polycarp" : "Vasiliy");
//		for (int r1 = 0; r1 <= 10; r1++) {
//			for (int c1 = 0; c1 <= 10; c1++ ){
//				if (r1 == 0 && c1 == 0) {
//					continue;
//				}
//				
//				for (int r2 = 0; r2 <= 6; r2++) {
//					for (int c2 = 0; c2 <= 6; c2++) {
//						if (r2 == 0 && c2 == 0) {
//							continue;
//						}
//						if (r2 == r1 && c2 == c1) {
//							continue;
//						}
//						
//						if (stupid(r1, c1, r2, c2) != smart(r1, c1, r2, c2)) {
//							System.err.println(r1 + " " + c1 + " " + r2 + " " + c2);
//						}
//					}
//				}
//			}
//		}
	}

	int[][][][][] win;
	
	boolean smart(int r1, int c1, int r2, int c2) {
		if (r1 + c1 <= Math.max(r2, c2)) {
			return true;
		}
		if (r1 <= r2 && c1 <= c2) {
			return true;
		}
		return false;
	}
	
	boolean stupid(int r1, int c1, int r2, int c2) {
		win = new int[2][r1 + 1][c1 + 1][r2 + 1][c2 + 1];
		return go(win, 0, r1, c1, r2, c2) == 1;
	}

	int go(int[][][][][] win, int turn, int r1, int c1, int r2, int c2) {
		if (win[turn][r1][c1][r2][c2] != 0) {
			return win[turn][r1][c1][r2][c2];
		}

		int canWin = -1;
		if (turn == 0) {
			{
				int nr1 = r1 - 1, nc1 = c1;
				if (nr1 >= 0 && (nr1 != r2 || nc1 != c2)) {
					if (nr1 == 0 && nc1 == 0) {
						canWin = 1;
					} else {
						canWin = Math.max(canWin,
								-go(win, 1 - turn, nr1, nc1, r2, c2));
					}
				}
			}
			{
				int nr1 = r1, nc1 = c1 - 1;
				if (nc1 >= 0 && (nr1 != r2 || nc1 != c2)) {
					if (nr1 == 0 && nc1 == 0) {
						canWin = 1;
					} else {
						canWin = Math.max(canWin,
								-go(win, 1 - turn, nr1, nc1, r2, c2));
					}
				}
			}
		} else {
			{
				int nr2 = r2 - 1, nc2 = c2;
				if (nr2 >= 0 && (nr2 != r1 || nc2 != c1)) {
					if (nr2 == 0 && nc2 == 0) {
						canWin = 1;
					} else {
						canWin = Math.max(canWin,
								-go(win, 1 - turn, r1, c1, nr2, nc2));
					}
				}
			}
			{
				int nr2 = r2 - 1, nc2 = c2 - 1;
				if (nr2 >= 0 && nc2 >= 0 && (nr2 != r1 || nc2 != c1)) {
					if (nr2 == 0 && nc2 == 0) {
						canWin = 1;
					} else {
						canWin = Math.max(canWin,
								-go(win, 1 - turn, r1, c1, nr2, nc2));
					}
				}
			}
			{
				int nr2 = r2, nc2 = c2 - 1;
				if (nc2 >= 0 && (nr2 != r1 || nc2 != c1)) {
					if (nr2 == 0 && nc2 == 0) {
						canWin = 1;
					} else {
						canWin = Math.max(canWin,
								-go(win, 1 - turn, r1, c1, nr2, nc2));
					}
				}
			}
		}
		return win[turn][r1][c1][r2][c2] = canWin;
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