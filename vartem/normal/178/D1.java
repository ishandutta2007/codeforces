import java.io.*;
import java.util.*;

public class D {

	final String filename = new String("D").toLowerCase();

	int n, sum;
	int[] a;
	boolean[][] used;
	int[][] matrix;
	int[] row, col, cntRow, cntCol;
	int d1, d2;
	int c1, c2;
//	int[] partSums;
	int nn;

//	int largest(int k) {
//		if (k == 0) {
//			return 0;
//		}
//		return partSums[nn - 1] - partSums[nn - 1 - k];
//	}

//	int smallest(int start, int count) {
//		if (count == 0) {
//			return 0;
//		}
//		int ans = partSums[start + count - 1];
//		if (start > 0) {
//			ans -= partSums[start - 1];
//		}
//		return ans;
//	}

	void go(int p) {
		if (p == n * n) {
			for (int i = 0; i < n; i++) {
				if (row[i] != sum || col[i] != sum) {
					return;
				}
			}
			if (d1 != sum || d2 != sum) {
				return;
			}
			out.println(sum);
			for (int k = 0; k < n; k++) {
				for (int t = 0; t < n; t++) {
					out.print(matrix[k][t] + " ");
				}
				out.println();
			}
			out.close();
			System.exit(0);
		}
		for (int i = 0; i < n; i++) {
			if (cntRow[i] == n - 1) {
				boolean ret = true;
				for (int j = p; j < nn; j++) {
					if (row[i] + a[j] == sum) {
						ret = false;
					}
				}
				if (ret) {
					return;
				}
			}
			if (cntCol[i] == n - 1) {
				boolean ret = true;
				for (int j = p; j < nn; j++) {
					if (col[i] + a[j] == sum) {
						ret = false;
					}
				}
				if (ret) {
					return;
				}
			}
		}
		if (c1 == n - 1) {
			boolean ret = true;
			for (int j = p; j < nn; j++) {
				if (d1 + a[j] == sum) {
					ret = false;
				}
			}
			if (ret) {
				return;
			}
		}
		if (c2 == n - 1) {
			boolean ret = true;
			for (int j = p; j < nn; j++) {
				if (d2 + a[j] == sum) {
					ret = false;
				}
			}
			if (ret) {
				return;
			}
		}
//		for (int i = 0; i < n; i++) {
//			int rmn = n - cntRow[i];
//			if (row[i] + smallest(p, rmn) > sum || row[i] + largest(rmn) < sum) {
//				return;
//			}
//			rmn = n - cntCol[i];
//			if (col[i] + smallest(p, rmn) > sum || col[i] + largest(rmn) < sum) {
//				return;
//			}
//		}
//		{
//			int rmn = n - c1;
//			if (d1 + smallest(p, rmn) > sum || d1 + largest(rmn) < sum) {
//				return;
//			}
//			rmn = n - c2;
//			if (d2 + smallest(p, rmn) > sum || d2 + largest(rmn) < sum) {
//				return;
//			}
//		}
		for (int i = 0; i < n; i++) {
			if (cntRow[i] == n - 1 && row[i] + a[p] == sum) {
				for (int j = 0; j < n; j++) {
					if (!used[i][j]) {
						matrix[i][j] = a[p];
						used[i][j] = true;
						cntRow[i]++;
						cntCol[j]++;
						row[i] += a[p];
						col[j] += a[p];
						if (i == j) {
							d1 += a[p];
							c1++;
						}
						if (i + j == n - 1) {
							d2 += a[p];
							c2++;
						}

						go(p + 1);

						if (i == j) {
							d1 -= a[p];
							c1--;
						}
						if (i + j == n - 1) {
							d2 -= a[p];
							c2--;
						}

						matrix[i][j] = 0;
						used[i][j] = false;
						cntRow[i]--;
						cntCol[j]--;
						row[i] -= a[p];
						col[j] -= a[p];
						return;
					}
				}
			}
		}
		
		for (int j = 0; j < n; j++) {
			if (cntCol[j] == n - 1 && col[j] + a[p] == sum) {
				for (int i = 0; i < n; i++) {
					if (!used[i][j]) {
						matrix[i][j] = a[p];
						used[i][j] = true;
						cntRow[i]++;
						cntCol[j]++;
						row[i] += a[p];
						col[j] += a[p];
						if (i == j) {
							d1 += a[p];
							c1++;
						}
						if (i + j == n - 1) {
							d2 += a[p];
							c2++;
						}

						go(p + 1);

						if (i == j) {
							d1 -= a[p];
							c1--;
						}
						if (i + j == n - 1) {
							d2 -= a[p];
							c2--;
						}

						matrix[i][j] = 0;
						used[i][j] = false;
						cntRow[i]--;
						cntCol[j]--;
						row[i] -= a[p];
						col[j] -= a[p];
						return;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!used[i][j]) {
					matrix[i][j] = a[p];
					used[i][j] = true;
					cntRow[i]++;
					cntCol[j]++;
					row[i] += a[p];
					col[j] += a[p];
					boolean ok = true;
					int rmn = n - cntRow[i];
//					if (row[i] + smallest(p + 1, rmn) > sum
//							|| row[i] + largest(rmn) < sum) {
//						ok = false;
//					}
					rmn = n - cntCol[j];
//					if (col[j] + smallest(p + 1, rmn) > sum
//							|| col[j] + largest(rmn) < sum) {
//						ok = false;
//					}
					if (i == j) {
						d1 += a[p];
						c1++;
						rmn = n - c1;
//						if (d1 + smallest(p, rmn) > sum || d1 + largest(rmn) < sum) {
//							ok = false;
//						}
					}
					if (i + j == n - 1) {
						d2 += a[p];
						c2++;
						rmn = n - c2;
//						if (d2 + smallest(p, rmn) > sum || d2 + largest(rmn) < sum) {
//							ok = false;
//						}
					}
					if (ok) {
						go(p + 1);
					}

					if (i == j) {
						d1 -= a[p];
						c1--;
					}
					if (i + j == n - 1) {
						d2 -= a[p];
						c2--;
					}
					matrix[i][j] = 0;
					used[i][j] = false;
					cntRow[i]--;
					cntCol[j]--;
					row[i] -= a[p];
					col[j] -= a[p];
				}
			}
		}
	}

	void shuffle(int[] a) {
		List<Integer> list = new ArrayList<Integer>();
		for (int i : a) {
			list.add(i);
		}
		Collections.shuffle(list);
		for (int i = 0; i < a.length; i++) {
			a[i] = list.get(i);
		}
	}
	
	void solve() throws Exception {
		n = nextInt();
		nn = n * n;
		a = new int[n * n];
		sum = 0;
		matrix = new int[n][n];
//		partSums = new int[n * n];
		for (int i = 0; i < n * n; i++) {
			a[i] = nextInt();
			sum += a[i];
		}
		Arrays.sort(a);	
//		for (int i = 0; i < n * n; i++) {
//			partSums[i] = a[i];
//			if (i > 0) {
//				partSums[i] += partSums[i - 1];
//			}
//		}
		sum /= n;
		if (n == 1) {
			out.println(sum);
			out.println(a[0]);
			return;
		}
		shuffle(a);
		d1 = d2 = 0;
		c1 = c2 = 0;
		matrix = new int[n][n];
		row = new int[n];
		col = new int[n];
		cntRow = new int[n];
		cntCol = new int[n];
		used = new boolean[n][n];
		go(0);
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");
			long time = System.currentTimeMillis();
			solve();
			System.err.println(System.currentTimeMillis() - time);
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
		new D().run();
	}

}