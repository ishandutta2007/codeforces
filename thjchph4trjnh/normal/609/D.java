import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	static PrintWriter out;

	static double EPS = 1e-9;
	static int INF = (int) 1e9;
	static long LINF = (long) 1e18;
	static int MOD = (int) 1e9 + 7;
	static double PI = 2 * Math.acos(0);
	
	static void solve() {
		int n = Input.nextInt();
		int m = Input.nextInt();
		int k = Input.nextInt();
		int s = Input.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = Input.nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = Input.nextInt();
		}
		int[] t = new int[m];
		int[] c = new int[m];
		for (int i = 0; i < m; i++) {
			t[i] = Input.nextInt();
			c[i] = Input.nextInt();
		}
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			int amin = INF, bmin = INF;
			for (int i = 0; i < mid; i++) {
				amin = Math.min(amin, a[i]);
				bmin = Math.min(bmin, b[i]);
			}
			ArrayList<Pair> pr = new ArrayList<>();
			for (int i = 0; i < m; i++) {
				if (t[i] == 1) {
					pr.add(new Pair(1L * amin * c[i], i));
				}
				else {
					pr.add(new Pair(1L * bmin * c[i], i));
				}
			}
			Collections.sort(pr);
			long tot = 0;
			for (int i = 0; i < k; i++) {
				tot += pr.get(i).fi;
			}
			if (tot > s) l = mid + 1; else r = mid;
		}
		int amin = INF, bmin = INF;
		int aidx = 0, bidx = 0;
		for (int i = 0; i < l; i++) {
			if (amin > a[i]) {
				amin = a[i];
				aidx = i;
			}
			if (bmin > b[i]) {
				bmin = b[i];
				bidx = i;
			}
		}
		ArrayList<Pair> pr = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			if (t[i] == 1) {
				pr.add(new Pair(1L * amin * c[i], i));
			}
			else {
				pr.add(new Pair(1L * bmin * c[i], i));
			}
		}
		Collections.sort(pr);
		long tot = 0;
		for (int i = 0; i < k; i++) {
			tot += pr.get(i).fi;
		}
		if (tot > s) {
			out.print(-1);
		}
		else {
			out.println(l);
			for (int i = 0; i < k; i++) {
				int idx = pr.get(i).se;
				out.print(idx + 1);
				out.print(" ");
				if (t[idx] == 1) {
					out.println(aidx + 1);
				}
				else {
					out.println(bidx + 1);
				}
			}
		}
	}

	static class Pair implements Comparable<Pair> {
		long fi;
		int se;
		public Pair(long fi, int se) {
			this.fi = fi;
			this.se = se;
		}
		public int compareTo(Pair oth) {
			if (fi > oth.fi) return 1;
			if (fi < oth.fi) return -1;
			if (se > oth.se) return 1;
			if (se < oth.se) return -1;
			return 0;
		}
	}
	
	public static void main(String[] args) {
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	static class Input {
		static StringTokenizer token = null;
		static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		static BufferedReader in;
//		static {
//			try {
//				in = new BufferedReader(new FileReader("in.txt"));
//			} catch (IOException e) {
//			}
//		}

		static int nextInt() {
			return Integer.parseInt(nextString());
		}

		static long nextLong() {
			return Long.parseLong(nextString());
		}

		static double nextDouble() {
			return Double.parseDouble(nextString());
		}

		static String nextString() {
			try {
				while (token == null || !token.hasMoreTokens()) {
					token = new StringTokenizer(in.readLine());
				}
			} catch (IOException e) {
			}
			return token.nextToken();
		}
	}
}