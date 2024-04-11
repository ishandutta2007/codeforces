import java.io.*;
import java.util.*;

public class F {

	final String filename = new String("F").toLowerCase();

	final int MAX = 100 * 500 + 1;
	final int ALPHA = 26;
	
	int[][] next = new int[MAX][ALPHA];
	int[] depth = new int[MAX];
	int[] count = new int[MAX];
	int countV ;
	
	void init() {
		countV = 1;
		for (int[] i : next) {
			Arrays.fill(i, -1);
		}
		Arrays.fill(count, 0);
		Arrays.fill(depth, 0);
	}
	
	void add(String s) {
		int curV = 0;
		count[0]++;
		for (int i = 0; i < s.length(); i++) {
			int c = (int) (s.charAt(i) - 'a');
			if (next[curV][c] == -1) {
				next[curV][c] = countV;
				depth[countV] = depth[curV] + 1;
				countV++;
			}
			curV = next[curV][c];
			count[curV]++;
		}
	}
	
	int k;
	
	int[] get(int v) {
		int[] res = new int[k + 1];
		for (int i = 0; i < ALPHA; i++) {
			if (next[v][i] != -1) {
				int[] b = get(next[v][i]);
				int[] newRes = new int[k + 1];
				for (int j = 0; j <= k && j <= count[v]; j++) {
					for (int t = 0; t <= j && t <= count[next[v][i]]; t++) {
						newRes[j] = Math.max(newRes[j], res[j - t] + b[t] + t * (t - 1) / 2);
					}
				}
				res = newRes;
			}
		}
		return res;
	}
	
	int solve(int n, int k, String[] s) throws Exception {
		this.k = k;
		init();
		Arrays.sort(s);
		for (String t : s) {
			add(t);
		}
		return get(0)[k];
	}

	int lcp(String a, String b) {
		int l = 0;
		while (l < a.length() && l < b.length() && a.charAt(l) == b.charAt(l)) {
			l++;
		}
		return l;
	}

	int solveStupid(int n, int k, String[] s) throws Exception {
		Arrays.sort(s);
		int best = 0;
		int[] a = new int[k];
		int[][] lcp = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				lcp[i][j] = lcp(s[i], s[j]);
			}
		}
		for (int mask = 0; mask < 1 << n; mask++) {
			if (Integer.bitCount(mask) != k) {
				continue;
			}
			int temp = 0;
			int cur = 0;
			for (int i = 0; i < n; i++) {
				if ((mask & (1 << i)) != 0) {
					a[temp++] = i;
					for (int j = 0; j < temp - 1; j++) {
						cur += lcp[a[j]][i];
					}
				}
			}
			best = Math.max(best, cur);
		}
		return best;
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

//			int n = 10;
//			int len = 6;
//			String[] s = new String[n];
//			Random rnd = new Random(123);
//			for (int IT = 0; IT < 100; IT++) {
//				int k = rnd.nextInt(n) + 1;
//				for (int i = 0; i < n; i++) {
//					char[] c = new char[len];
//					for (int j = 0; j < len; j++) {
//						c[j] = (char) (rnd.nextInt(4) + 'a');
//					}
//					s[i] = new String(c);
//				}
//				int ans2 = solve(n, k, s);
//				int ans1 = solveStupid(n, k, s);
//				if (ans1 != ans2) {
//					System.err.println(n + " " + k);
//					System.err.println(ans1 + " " + ans2);
//					System.err.println(Arrays.toString(s));
//				}
//			}
			
			int n=  nextInt();
			int k = nextInt();
			String[] s = new String[n];
			for (int i = 0; i < s.length; i++) {
				s[i] = nextToken();
			}
			out.println(solve(n, k, s));
			
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
		new F().run();
	}

}