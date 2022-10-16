import java.io.*;
import java.util.*;

public class D {

	boolean isLucky(int a) {
		while (a > 0) {
			int m = a % 10;
			if (m != 4 && m != 7)
				return false;
			a /= 10;
		}
		return true;
	}
	
	class Pair implements Comparable<Pair> {
		int ind, x;
		public Pair(int v, int i) {
			x = v; ind = i;
		}
		
		@Override
		public int compareTo(Pair arg0) {
			if (x != arg0.x)
				return x - arg0.x;
			else
				return ind - arg0.ind;
		}
		
		@Override
		public String toString() {
			return x + " " + ind;
		}
	}
	
	Pair[] ans;
	int cnt;
	
	void add(int x, int y) {
		if (x != y) {
			ans[cnt++] = new Pair(x + 1, y + 1);
		}
	}
	
	void swap(Pair a, Pair b) {
		int tmp = a.x;
		a.x = b.x;
		b.x = tmp;
		
		tmp = a.ind;
		a.ind = b.ind;
		b.ind = tmp;
	}
	
	void solve() throws Exception {
		int n = nextInt();
		Pair[] a = new Pair[n];
		boolean[] l = new boolean[n];
		Pair[] b = new Pair[n];
		TreeMap<Pair, Integer> need = new TreeMap<Pair, Integer>();
		TreeMap<Pair, Integer> have = new TreeMap<Pair, Integer>();
		int m = -1;
		for (int i = 0; i < n; i++) {
			a[i] = new Pair(nextInt(), i);
			b[i] = new Pair(a[i].x, i);
			if (isLucky(a[i].x)) {
				l[i] = true;
				m = i;
			}
			have.put(new Pair(a[i].x, i), i);
		}
		Arrays.sort(b);
		int[] place = new int[n];
		for (int i = 0; i < n; i++) {
			need.put(b[i], b[i].ind);
		}
		if (m == -1) {
			boolean ok = true;
			for (int i = 0; i < n - 1; i++) {
				if (a[i].x > a[i + 1].x)
					ok = false;
			}
			if (!ok) {
				out.println(-1);
			} else {
				out.println(0);
			}
			return;
		}
		ans = new Pair[2 * n];
		cnt = 0;
		for (int i = 0; i < n; i++) {
			Pair h = a[i];
			int to = have.get(b[i]);
			if (to == i)
				continue;
			
			Pair ai = b[i];
			Pair lu = a[m];
			add(i, m);
			add(i, to);
			swap(a[i], a[m]);
			swap(a[i], a[to]);
			
			have.put(a[i], i);
			have.put(a[m], m);
			have.put(a[to], to);
			
			m = to;
		}
//		System.err.println(Arrays.toString(a));
		out.println(cnt);
		for (int i = 0; i < cnt; i++) {
			out.println(ans[i].x + " " + ans[i].ind);
		}
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader(filename + ".in"));
			//			out = new PrintWriter(filename + ".out");

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
	final String filename = new String("D").toLowerCase();

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