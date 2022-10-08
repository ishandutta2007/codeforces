import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	private long[][] nsBig;
	private int[][] nsLst;

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		int u = nextInt();
		int v = nextInt();
		int[] a = new int[m];
		int[] b = new int[m];
		int[] l = new int[n];
		for (int i = 0; i < m; ++i) {
			a[i] = nextInt() - 1;
			b[i] = nextInt() - 1;
			l[a[i]]++;
			l[b[i]]++;
		}
		final int thr = 2000;
		nsBig = new long[n][];
		nsLst = new int[n][];
		for (int i = 0; i < n; ++i) {
			if (l[i] > thr) {
				nsBig[i] = new long[(n + 63) / 64];
			} else {
				nsLst[i] = new int[l[i]];
			}
			l[i] = 0;
		}
		for (int i = 0; i < m; ++i) {
			if (nsBig[a[i]] != null) {
				nsBig[a[i]][b[i] / 64] |= 1L << (b[i] % 64);
			} else {
				nsLst[a[i]][l[a[i]]] = b[i];
			}
			if (nsBig[b[i]] != null) {
				nsBig[b[i]][a[i] / 64] |= 1L << (a[i] % 64);
			} else {
				nsLst[b[i]][l[b[i]]] = a[i];
			}
			l[a[i]]++;
			l[b[i]]++;
		}
		for (int i = 0; i < n; ++i) {
			if (nsLst[i] != null) {
				Arrays.sort(nsLst[i]);
			}
		}
		col = new boolean[n];
		for (int i = 0; i < m; ++i) {
			int common = 0;
			if (nsBig[a[i]] != null && nsBig[b[i]] != null) {
				for (int j = 0; j < nsBig[a[i]].length; ++j) {
					common += Long.bitCount(nsBig[a[i]][j] & nsBig[b[i]][j]);
				}
			} else if (nsBig[a[i]] != null) {
				for (int j : nsLst[b[i]]) {
					if (contains(a[i], j)) {
						common++;
					}
				}
			} else if (nsBig[b[i]] != null) {
				for (int j : nsLst[a[i]]) {
					if (contains(b[i], j)) {
						common++;
					}
				}
			} else {
				for (int j1 = 0, j2 = 0; j1 < nsLst[a[i]].length && j2 < nsLst[b[i]].length; ) {
					int cmp = nsLst[a[i]][j1] - nsLst[b[i]][j2];
					if (cmp == 0) {
						j1++;
						j2++;
						common++;
					} else if (cmp < 0) {
						j1++;
					} else {
						j2++;
					}
				}
			}
			if (Math.max(0, u - (l[a[i]] - common - 1)) + Math.max(0, v - (l[b[i]] - common - 1)) <= common) {
				printAns(a[i], b[i], u, v, Math.max(0, u - (l[a[i]] - common - 1)), Math.max(0, v - (l[b[i]] - common - 1)));
				return;
			}
			if (Math.max(0, u - (l[b[i]] - common - 1)) +  Math.max(0, v - (l[a[i]] - common - 1)) <= common) {
				printAns(b[i], a[i], u, v, Math.max(0, u - (l[b[i]] - common - 1)), Math.max(0, v - (l[a[i]] - common - 1)));
				return;
			}
		}
		out.println("NO");
	}

	private void printAns(int i, int j, int u, int v, int uc, int vc) {
		out.println("YES");
		out.println((i + 1) + " " + (j + 1));
		printNs(i, j, u, uc);
		printNs(j, i, v, vc);
	}
	
	boolean[] col;

	private void printNs(int i, int j, int u, int uc) {
		for (int t = 0; u > 0; ++t) {
			if (contains(i, t) && j != t) {
				if (contains(j, t)) {
					if (!col[t] && uc > 0) {
						out.print((t + 1) + " ");
						--u;
						--uc;
						col[t] = true;
					}
				} else {
					if (u > 0) {
						out.print((t + 1) + " ");
						--u;
					}
				}
			}
		}
		out.println();
	}

	private boolean contains(int i, int j) {
		if (nsBig[i] != null) {
			return (nsBig[i][j / 64] & (1L << (j % 64))) != 0;
		}
		return Arrays.binarySearch(nsLst[i], j) >= 0;
	}

	public void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		
		solve();
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}