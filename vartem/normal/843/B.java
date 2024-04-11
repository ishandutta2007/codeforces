import java.util.*;
import java.io.*;

public class B {

	Random rng = new Random();
	
	void solve() {
		int n = in.nextInt();
		int start = in.nextInt();
		int x = in.nextInt();

		Set<Integer> qs = new TreeSet<>();
		int MAX = 1000;
		while (qs.size() < MAX && qs.size() < n) {
			qs.add(rng.nextInt(n) + 1);
		}
		
		List<Integer> q = new ArrayList<>(qs);
		Collections.sort(q);
		
		int[] res = new int[q.size()];
		for (int i = 0; i < q.size(); i++) {
			res[i] = query(q.get(i))[0];
		}
		
		int startVal = query(start)[0];
		if (startVal >= x) {
			out.println("! " + startVal);
			out.flush();
			return;
		}
		
		for (int i = 0; i < q.size(); i++) {
			if (res[i] < x) {
				if (res[i] > startVal) {
					start = q.get(i);
					startVal = res[i];
				}
			}
		}
		
		int next = query(start)[1];
		while (true) {
			if (next == -1) {
				out.println("! -1");
				out.flush();
				return;
			}
			
			int[] a = query(next);
			if (a[0] >= x) {
				out.println("! " + a[0]);
				out.flush();
				return;
			}
			next = a[1];
		}
	}
	
	int[] query(int pos) {
		out.println("? " + pos);
		out.flush();
		int value = in.nextInt();
		int next = in.nextInt();
		return new int[] {value, next};
	}

	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}