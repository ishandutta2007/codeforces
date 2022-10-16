import java.io.*;
import java.util.*;

public class Friends {

	final String filename = new String("Friends").toLowerCase();

	
	class Pair implements Comparable<Pair> {
		String a, b;
		public Pair(String a, String b) {
			if (a.compareTo(b) < 0) {
				this.a = a;
				this.b = b;
			} else {
				this.a = b;
				this.b = a;
			}
		}
		
		@Override
		public int compareTo(Pair arg0) {
			int t = a.compareTo(arg0.a);
			if (t != 0) {
				return t;
			}
			return b.compareTo(arg0.b);
		}
	}
	
	void solve() throws Exception {
		int n = nextInt();
		int dif = nextInt();
		Set<Pair> friends = new TreeSet<Pair>();
		String[] a = new String[n], b = new String[n];
		int[] time = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextToken();
			b[i] = nextToken();
			time[i] = nextInt();
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (time[j] - time[i] <= dif && time[j] - time[i] > 0 && a[i].equals(b[j]) && a[j].equals(b[i])) {
					friends.add(new Pair(a[i], b[i]));
				}
			}
		}
		
		out.println(friends.size());
		for (Pair i : friends) {
			out.println(i.a + " " + i.b);
		}
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader("input.txt"));
			//			out = new PrintWriter("output.txt");

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
		new Friends().run();
	}

}