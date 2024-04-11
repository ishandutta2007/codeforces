import java.io.*;
import java.util.*;

public class C {

	class State {
		int[] a;
		State prev;
		public State(int[] b, State p) {
			a = b.clone();
			prev = p;
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + Arrays.hashCode(a);
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (!Arrays.equals(a, other.a))
				return false;
			return true;
		}
		private C getOuterType() {
			return C.this;
		}	
	}
	
	int ans = 0;
	
	String reg(int t) {
		return "e" + (char)('a' + t) + "x";
	}
	
	String get(int m, int i, int j, int k) {
		String temp = (k == 1) ? "" : (String) (k + "*");
		return "lea " + reg(m) + ", [" + reg(i) + " + " + temp + reg(j) + "]";
	}
	
	String get(int m, int i, int k) {
		return "lea " + reg(m) + ", [" + k + "*" + reg(i) + "]";
	}
	
	void print(State c) {
		if (c.prev == null) {
			out.println(ans);
		} else {
			ans++;
			print(c.prev);
			int m = c.a.length - 1;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					for (int k = 1; k <= 8; k *= 2) {
						int g = c.a[i] + c.a[j] * k;
						if (g == c.a[m]) {
							out.println(get(m, i, j, k));
							return;
						}
					}
				}
			}
			
			for (int i = 0; i < m; i++) {
				for (int k = 1; k <= 8; k *= 2) {
					int g = c.a[i] * k;
					if (g == c.a[m]) {
						out.println(get(m, i, k));
						return;
					}
				}
			}
		}
	}
	
	void solve(int n) throws Exception {
		int[] a = new int[]{1};
		ans = 0;
		ArrayDeque<State> ad = new ArrayDeque<C.State>();
		ad.add(new State(a, null));
		while (!ad.isEmpty()) {
			State c = ad.poll();
			int max = c.a[c.a.length - 1];
			if (max == n) {
				print(c);
				return;
			}
			TreeSet<Integer> ts = new TreeSet<Integer>();
			int m = c.a.length;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					for (int k = 1; k <= 8; k *= 2) {
						int g = c.a[i] + c.a[j] * k;
						if (g > max)
							ts.add(g);
					}
				}
			}
			
			for (int i = 0; i < m; i++) {
				for (int k = 1; k <= 8; k *= 2) {
					int g = c.a[i] * k;
					if (g > max)
						ts.add(g);
				}
			}
			int[] f = new int[m + 1];
			for (int i = 0; i < m; i++)
				f[i] = c.a[i];
			for (int i : ts) {
				f[m] = i;
				ad.add(new State(f, c));
			}
		}
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			//			in = new BufferedReader(new FileReader(filename + ".in"));
			//			out = new PrintWriter(filename + ".out");

//			for (int i = 0; i < 255; i++) {
//				long t1 = System.currentTimeMillis();
//				solve(i + 1);
//				System.err.println(System.currentTimeMillis() - t1);
//			}
			solve(nextInt());
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;
	final String filename = new String("C").toLowerCase();

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
		new C().run();
	}

}