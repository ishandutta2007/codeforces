import java.io.*;
import java.util.*;

public class Photos {

	class Pair implements Comparable<Pair> {
		int x, i;
		public Pair(int x, int i) {
			this.x = x;
			this.i = i;
		}
		
		@Override
		public int compareTo(Pair o) {
			return o.x - this.x;
		}
	}
	
	int[] s;
	int[] cnt;
	Pair[] a;
	int m;
	
	
	void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		a = new Pair[m];
		for (int i = 0; i < m; i++)
			a[i] = new Pair(nextInt(), i + 1);
		Arrays.sort(a);
		int[] ans = new int[n];
		ans[0] = 0;
		a[0].x--;
		for (int i = 1; i < n; i++) {
			int min = Integer.MIN_VALUE;
			int t = -1;
			for (int j = 0; j < m; j++) 
				if (j == ans[i - 1] || ((i == n - 1) && (j == ans[0]))) {
					continue;
				} else {
					if (min < a[j].x) {
						min = a[j].x;
						t = j;
					}
				}
			
			if (t == -1 || min <= 0) {
				out.println(-1);
				return;
			}
			
			ans[i] = t;
			a[t].x--;
		}
		System.err.println(Arrays.toString(ans));
		for (int i = 0; i < n; i++)
			out.print(a[ans[i]].i + " " );
	}


	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

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
	final String filename = new String("Photos").toLowerCase();

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
		new Photos().run();
	}

}