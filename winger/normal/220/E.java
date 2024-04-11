import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	void add(int[] ar, int i, int v) {
		while (i < ar.length) {
			ar[i] += v;
			i = i | (i + 1);
		}
	}
	
	int get(int[] ar, int i) {
		int v = 0;
		while (i >= 0) {
			v += ar[i];
			i = (i & (i + 1)) - 1;
		}
		return v;
	}

	public void solve() throws IOException {
		int n = nextInt();
		long k = nextLong();
		int[] a = new int[n];
		for (int i = 0; i < n; ++i) {
			a[i] = nextInt();
		}
		{
			int[] tmp = a.clone();
			Arrays.sort(tmp);
			HashMap<Integer, Integer> nv = new HashMap<Integer, Integer>();
			for (int i = 0; i < n; ++i) {
				if (i == 0 || tmp[i] != tmp[i - 1]) {
					nv.put(tmp[i], nv.size());
				}
			}
			for (int i = 0; i < n; ++i) {
				a[i] = nv.get(a[i]);
			}
		}
		int[] ft1 = new int[n];
		int[] ft2 = new int[n];
		int r = n;
		long invs = 0;
		while (r > 0) {
			--r;
			invs += get(ft2, a[r] - 1);
			add(ft2, a[r], 1);
		}
		long ans = 0;
		for (int l = 0; l < n; ++l) {
			invs += l - get(ft1, a[l]);
			invs += get(ft2, a[l] - 1);
			add(ft1, a[l], 1);
			while ((r < n) && (r <= l || invs > k)) {
				invs -= (l + 1) - get(ft1, a[r]);
				invs -= get(ft2, a[r] - 1);
				add(ft2, a[r], -1);
				++r;
			}
			ans += n - r;
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
	
	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		new Solution().run();
	}
	
}