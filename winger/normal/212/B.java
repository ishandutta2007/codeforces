import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;


	public void solve() throws IOException {
		String s = next();
//		Random rnd = new Random();
//		StringBuilder sb = new StringBuilder();
//		for (int i = 0; i < 1000000; ++i) {
//			sb.append((char)('a' + rnd.nextInt(26)));
//		}
//		s = sb.toString();
//		System.err.println("here");
		int n = s.length();
		final int[] ar = new int[26];
		Integer[] ids = new Integer[26];
		for (int i = 0; i < 26; ++i) {
			ids[i] = i;
		}
		Comparator<Integer> cmp = new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return ar[o1] - ar[o2];
			}
		};
		int[] cs = new int[26 * n];
		int csc = 0;
		int[] cur = new int[26];
		Arrays.fill(cur, n);
		for (int i = n - 1; i >= 0; --i) {
			int u = s.charAt(i) - 'a';
			for (int v = 0; v < 26; ++v) {
				ar[v] = cur[v];
			}
			Arrays.sort(ids, cmp);
			int mask = 0;
			for (int v : ids) {
				if (v == u || ar[v] == n) {
					break;
				}
				mask |= 1 << v;
				cs[csc++] = mask;
			}
			cur[s.charAt(i) - 'a'] = i;
		}
		{
			for (int v = 0; v < 26; ++v) {
				ar[v] = cur[v];
			}
			Arrays.sort(ids, cmp);
			int mask = 0;
			for (int v : ids) {
				if (ar[v] == n) {
					break;
				}
				mask |= 1 << v;
				cs[csc++] = mask;
			}
		}
		Arrays.sort(cs, 0, csc);
//		cs = Arrays.copyOf(cs, csc);System.err.println(Arrays.toString(cs));
		int m = nextInt();
		for (int i = 0; i < m; ++i) {
			int q = 0;
			for (char c : next().toCharArray()) {
				q |= 1 << (c - 'a');
			}
			int l = -1, r = csc;
			while (l < r - 1) {
				int x = (l + r) / 2;
				if (cs[x] < q) {
					l = x;
				} else {
					r = x;
				}
			}
			int bot = r;
			l = -1; r = csc;
			while (l < r - 1) {
				int x = (l + r) / 2;
				if (cs[x] <= q) {
					l = x;
				} else {
					r = x;
				}
			}
			int top = r;
			out.println(top - bot);
		}
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