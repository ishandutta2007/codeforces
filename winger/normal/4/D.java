import java.io.*;
import java.util.*;

public class Solution {
	
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	static class Rect implements Comparable<Rect> {
		int h, w;
		int id;
		
		public Rect(int h, int w, int id) {
			super();
			this.h = h;
			this.w = w;
			this.id = id;
		}

		@Override
		public int compareTo(Rect o2) {
			return h - o2.h;
		}
	}
	
	void solve() throws IOException {
		int n = nextInt();
		Rect[] rs = new Rect[n + 1];
		rs[0] = new Rect(nextInt(), nextInt(), 0);
		for (int i = 1; i <= n; ++i) {
			rs[i] = new Rect(nextInt(), nextInt(), i);
		}
		Arrays.sort(rs, 1, n + 1);
		int[] d = new int[n + 1];
		int[] p = new int[n + 1];
		Arrays.fill(p, -1);
		Arrays.fill(d, -1000000000);
		d[0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (rs[j].h < rs[i].h && rs[j].w < rs[i].w && d[j] + 1 > d[i]) {
					d[i] = d[j] + 1;
					p[i] = j;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (d[i] > d[ans]) {
				ans = i;
			}
		}
		out.println(d[ans]);
		ArrayList<Integer> a = new ArrayList<Integer>();
		for (int i = ans; i > 0; i = p[i]) {
			a.add(rs[i].id);
		}
		Collections.reverse(a);
		for (int i : a) {
			out.print(i + " ");
		}
		out.println();
	}

	Solution() throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		eat("");
		
		solve();
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
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
		new Solution();
	}
}