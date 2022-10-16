import java.util.*;
import java.io.*;

public class D {

	class Segment implements Comparable<Segment> {
		int l, r, id;
		public Segment(int l, int r, int id) {
			this.l = l;
			this.r = r;
			 this.id = id;
		}
		
		@Override
		public int compareTo(Segment o) {
			return Integer.compare(r, o.r);
		}
	}
	
	void solve() {
		int n = in.nextInt(), k = in.nextInt();
		Segment[] a = new Segment[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Segment(in.nextInt(), in.nextInt(), i);
		}
		
		Arrays.sort(a, new Comparator<Segment>() {
			@Override
			public int compare(Segment o1, Segment o2) {
				return Integer.compare(o1.l, o2.l);
			}
		});
		
		int ans = 0;
		int bestL = n - 1;
		
		PriorityQueue<Segment> q = new PriorityQueue<>();
		
		for (int i = 0; i < n; i++) {
			q.add(a[i]);
			if (q.size() > k) {
				q.poll();
			}
			if (q.size() == k) {
				if (ans < q.peek().r - a[i].l + 1) {
					ans = q.peek().r - a[i].l + 1;
					bestL = i;
				}
			}
		}
		
		q.clear();
		
		for (int i = 0; i < n; i++) {
			q.add(a[i]);
			if (q.size() > k) {
				q.poll();
			}
			if (i == bestL) {
				out.println(ans);
				for (Segment s : q) {
					out.print((s.id + 1) + " ");
				}
				return;
			}
		}
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
		new D().run();
	}
}