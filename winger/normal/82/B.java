
import java.io.*;
import java.util.*;

public class Solution implements Runnable {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	public void solve() throws IOException {
		int n = nextInt();
		int m = n * (n - 1) / 2;
		int[][] a = new int[m][];
		for (int i = 0; i < m; ++i) {
			a[i] = new int[nextInt()];
			for (int j = 0; j < a[i].length; ++j) {
				a[i][j] = nextInt();
			}
		}
		BitSet[] sets = new BitSet[201];
		for (int i = 1; i <= 200; ++i) {
			sets[i] = new BitSet(m);
		}
		for (int i = 0; i < m; ++i) {
			for (int j : a[i]) {
				sets[j].set(i);
			}
		}
		HashMap<BitSet, Integer> map = new HashMap<BitSet, Integer>();
		ArrayList<Integer>[] ans = new ArrayList[n];
		for (int i = 0; i < n; ++i) {
			ans[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= 200; ++i) {
			if (sets[i].isEmpty()) {
				continue;
			}
			if (!map.containsKey(sets[i])) {
				map.put(sets[i], map.size());
			}
			ans[map.get(sets[i])].add(i);
		}
		if (n == 2) {
			ans[1].add(ans[0].remove(ans[0].size() - 1));
		}
		for (int i = 0; i < n; ++i) {
			out.print(ans[i].size() + " ");
			for (int j : ans[i]) {
				out.print(j + " ");
			}
			out.println();
		}
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			eat("");
			
			solve();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			failed = true;
		}
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
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Thread th = new Thread(new Solution());
		th.start();
		try {
			th.join();
		} catch (InterruptedException iex) {
		}
		if (failed) {
			throw new RuntimeException();
		}
	}
	
}