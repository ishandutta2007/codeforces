import java.io.*;
import java.util.*;

public class A {

	final String filename = new String("a").toLowerCase();

	ArrayList<Long> divs;

	Boolean[] win;
	Long[] move;

	boolean get(int pos) {
		if (win[pos] != null) {
			return win[pos];
		}

		long cur = divs.get(pos);
		win[pos] = false;
		boolean hasMoves = false;
		for (int i = 1; i < pos; i++) {
			if (cur % divs.get(i) == 0) {
				hasMoves = true;
				if (get(i) == false) {
					win[pos] = true;
					move[pos] = divs.get(i);
					return true;
				}
			}
		}
		if (!hasMoves) {
			win[pos] = true;
			move[pos] = 0L;
		}
		return win[pos];
	}

	void solve() throws Exception {
		long p = nextLong();
		if (p == 1) {
			out.println(1);
			out.println(0);
			return;
		}

		divs = new ArrayList<Long>();
		for (long i = 1; i * i <= p; i++) {
			if (p % i == 0) {
				divs.add(i);
				if (i * i != p) {
					divs.add(p / i);
				}
			}
		}
		Collections.sort(divs);
		win = new Boolean[divs.size()];
		move = new Long[divs.size()];
		boolean res = get(divs.size() - 1);
		if (res == false) {
			out.println(2);
		} else {
			out.println(1);
			out.println(move[divs.size() - 1]);
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
		new A().run();
	}

}