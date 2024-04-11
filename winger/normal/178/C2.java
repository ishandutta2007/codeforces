import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	public void solve() throws IOException {
		int h = nextInt();
		int m = nextInt();
		int g = gcd(h, m);
		long m1 = -1;
		for (long i = 1; i < h / g; ++i) {
			if ((i * (m / g)) % (h / g) == 1) {
				m1 = i;
			}
		}
		if (m1 == -1) {
			throw new AssertionError();
		}
		TreeSet<Integer>[] free = new TreeSet[g];
		HashMap<Integer, Integer> positions = new HashMap<Integer, Integer>();
		for (int i = 0; i < g; ++i) {
			free[i] = new TreeSet<Integer>();
			for (int j = 0; j < h / g; ++j) {
				free[i].add(j);
			}
		}
		int n = nextInt();
		long ans = 0;
		for (int it = 0; it < n; ++it) {
			if ("+".equals(next())) {
				int id = nextInt();
				int hash = nextInt();
				int bucket = hash % g;
				int pos = (int) (((long)hash / g * m1) % (h / g));
				SortedSet<Integer> up = free[bucket].tailSet(pos);
				if (up.isEmpty()) {
					up = free[bucket];
				}
				int newPos = up.first();
				int add = newPos - pos;
				if (add < 0) {
					add += h / g;
				}
				ans += add;
				free[bucket].remove(newPos);
				positions.put(id, bucket + newPos * g);
			} else {
				int id = nextInt();
				int pos = positions.remove(id);
				int bucket = pos % g;
				pos /= g;
				free[bucket].add(pos);
			}
		}
		out.println(ans);
	}

	public void run() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		
		solve();
		
		out.close();
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	static boolean failed = false;
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}