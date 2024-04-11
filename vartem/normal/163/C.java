import java.io.*;
import java.util.*;

public class Candies {

	final String filename = new String("Candies").toLowerCase();

	final double eps = 1e-10;
	
	class Event implements Comparable<Event> {
		double time;
		int type;

		public Event(double time, int type) {
			this.time = time;
			this.type = type;
		}
		
		@Override
		public int compareTo(Event arg0) {
			if (Math.abs(time - arg0.time) < eps) {
				return type - arg0.type;
			}
			return Double.compare(time, arg0.time);
		}
		
		@Override
		public String toString() {
			return time + " " + type;
		}
	}

	void solve() throws Exception {
		int n = nextInt();
		double l = nextInt();
		double v1 = nextInt();
		double v2 = nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		double[] prob = new double[n + 1];
		List<Event> list = new ArrayList<Event>();
		int balance = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] >= 0 && a[i] + l * v1 / (v2 + v1) < l) {
				list.add(new Event((double) (l - a[i]) / v1 - l / (v2 + v1), -1));
				list.add(new Event((double) (2 * l - a[i]) / v1, 1));
				balance++;
			} else {
				list.add(new Event((double) (2 * l - a[i]) / v1, 1));
				list.add(new Event((double) (3 * l - a[i]) / v1 - l / (v2 + v1), -1));
			}
		}
		
		double fullTime = 2 * l / v1;
		list.add(new Event(0, balance));
		list.add(new Event(fullTime, -2));
		Collections.shuffle(list);
		Collections.sort(list);
		double lastX = 0;
		int curBal = 0;
		
		for (Event e : list) {
			prob[curBal] += (e.time - lastX) / fullTime;
			lastX = e.time;
			curBal += e.type;
			if (e.type == -2) {
				break;
			}
		}
		for (double p : prob) {
			out.println(p);
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
		new Candies().run();
	}

}