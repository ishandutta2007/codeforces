import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;

	public void solve() throws IOException {
		int k = nextInt();
		String s = next();
		int n = nextInt();
		ArrayList<Integer>[] ds = new ArrayList[26];
		for (int i = 0; i < 26; ++i) {
			ds[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < n; ++i) {
			int x = nextInt() - 1;
			ds[next().charAt(0) - 'a'].add(x);
		}
		final int size = 262144;
		int[] tree = new int[2 * size - 1];
		for (int i = 0; i < 26; ++i) {
			Arrays.fill(tree, 0);
			ArrayList<Integer> newDs = new ArrayList<Integer>();
			for (int j : ds[i]) {
				int l = 0, r = size - 1, x = 0;
				int left = 0;
				while (l < r) {
					int mid = (l + r) / 2;
					if (j <= mid - tree[2 * x + 1] - left) {
						r = mid;
						x = 2 * x + 1;
					} else {
						left += tree[2 * x + 1];
						l = mid + 1;
						x = 2 * x + 2;
					}
					tree[x]++;
				}
				newDs.add(l);
			}
			Collections.sort(newDs);
			ds[i] = newDs;
		}
		int[] count = new int[26];
		int[] p = new int[26];
		for (int it = 0; it < k; ++it) {
			for (int i = 0; i < s.length(); ++i) {
				char c = s.charAt(i);
				if (p[c - 'a'] < ds[c - 'a'].size() && count[c - 'a'] == ds[c - 'a'].get(p[c - 'a'])) {
					p[c - 'a']++;
				} else {
					out.print(c);
				}
				count[c - 'a']++;
			}
		}
		out.println();
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
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}