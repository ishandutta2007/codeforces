import java.io.*;
import java.util.*;

public class Temps {

	final String filename = new String("Temps").toLowerCase();

	class Event implements Comparable<Event> {
		int x, t, id;

		public Event(int x, int t, int id) {
			this.x = x;
			this.t = t;
			this.id = id;
		}

		@Override
		public int compareTo(Event arg0) {
			if (x != arg0.x) {
				return x - arg0.x;
			}
			return t - arg0.t;
		}
	}

	class Segm implements Comparable<Segm> {
		int l, r, id;

		public Segm(int l, int r, int id) {
			super();
			this.l = l;
			this.r = r;
			this.id = id;
		}

		@Override
		public int compareTo(Segm o) {
			if (o.r != r) {
				return r - o.r;
			}
			if (o.l != l) {
				return l - o.l;
			}
			return id - o.id;
		}
	}

	void solve() throws Exception {
		ArrayList<Event> ev = new ArrayList<Temps.Event>();
		int n = nextInt();
		int m = nextInt();
		int x = nextInt();
		int y = nextInt();
		int[] a = new int[n];
		int[] b = new int[m];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
			ev.add(new Event(a[i] - x, -1, i));
			ev.add(new Event(a[i] + y, 1, i));
		}
		TreeSet<Segm> ts = new TreeSet<Temps.Segm>();
		for (int i = 0; i < m; i++) {
			b[i] = nextInt();
			ev.add(new Event(b[i], 0, i));
		}
		int result = 0;
		Collections.sort(ev);
		int[] ans = new int[n];
		Arrays.fill(ans, -1);
		for (Event e : ev) {
			if (e.t == -1) {
				ts.add(new Segm(a[e.id] - x, a[e.id] + y, e.id));
			} else if (e.t == 1) {
				ts.remove(new Segm(a[e.id] - x, a[e.id] + y, e.id));
			} else {
				int id = e.id;
				if (!ts.isEmpty()) {
					Segm best = ts.first();
					if (best != null) {
						ans[best.id] = id;
						result++;
						ts.remove(best);
					}
				}
			}
		}

		out.println(result);
		for (int i = 0; i < n; i++) {
			if (ans[i] != -1) {
				out.println((i + 1) + " " + (ans[i] + 1));
			}
		}
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

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
		new Temps().run();
	}

}