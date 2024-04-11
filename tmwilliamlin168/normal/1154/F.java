import java.io.*;
import java.util.*;

/*
Solution Sketch:
*/

public class shovels {

	static final boolean stdin = true;
	static final String filename = "";
	static FastScanner br;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {

		if (stdin) {
			br = new FastScanner();
			pw = new PrintWriter(new OutputStreamWriter(System.out));
		}

		else {
			br = new FastScanner(filename + ".in");
			pw = new PrintWriter(new FileWriter(filename + ".out"));
		}

		X solver = new X();
		solver.solve(br, pw);
	}

	static class X {
		public void solve(FastScanner br, PrintWriter pw) throws IOException {
			int n = br.nextInt(); int m = br.nextInt(); int k = br.nextInt();
			ArrayList<Integer> a = new ArrayList<Integer>();
			Pair[] d = new Pair[m];
			for(int i = 0; i < n; i++) {
				a.add(br.nextInt());
			}
			for(int i = 0; i < m; i++) {
				d[i] = new Pair(br.nextInt(), br.nextInt());
			}
			Collections.sort(a);
//			for(int cur : a) {
//				pw.print(cur + " ");
//			}
//			
//			pw.println();
			int[] pre = new int[n+1];
			pre[1] = a.get(0);
			for(int i = 1; i <= a.size(); i++) {
				pre[i] = pre[i-1] + a.get(i-1);
//				pw.print(pre[i] + " ");
			}
//			pw.println();
			int[] dp = new int[k+1];
			Arrays.fill(dp, Integer.MAX_VALUE);
			dp[0] = 0;
			for(int i = 1; i <= k; i++) {
				int min = dp[i-1] + a.get(i-1);
				for(int j = 0; j < m; j++) {
					if(i - d[j].f >= 0) {
						min = Math.min(min, dp[i-d[j].f] + (pre[i] - pre[i-(d[j].f-d[j].s)]));
					}
				}
				dp[i] = min;
//				pw.print(dp[i] + " ");
			}
//			pw.println();
			pw.println(dp[k]);
			pw.close();
		}
		public static class Pair{
			int f, s;
			public Pair(int f, int s) {
				this.f = f;
				this.s = s;
			}
		}

	}

	//fastscanner class
	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
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

}