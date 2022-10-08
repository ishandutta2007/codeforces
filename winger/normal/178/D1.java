import java.io.*;
import java.util.*;

public class Solution {


	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	private HashMap<Integer, Integer> idMap;
	
	private int[][] ans;
	private int[] ar;
	private int[] count;

	static class Element {
		int used, sum;
		int xs, ys;
		boolean[][] f;
		
		Element(int n) {
			f = new boolean[n][n];
		}
		
		void add(int x, int y) {
			xs ^= x;
			ys ^= y;
			f[x][y] = true;
		}
	}
	
	static class Row extends Element {
		Row(int n, int x) {
			super(n);
			for (int i = 0; i < n; ++i) {
				add(x, i);
			}
		}
	}
	
	static class Col extends Element {
		Col(int n, int y) {
			super(n);
			for (int i = 0; i < n; ++i) {
				add(i, y);
			}
		}
	}
	
	static class D1 extends Element {
		D1(int n) {
			super(n);
			for (int i = 0; i < n; ++i) {
				add(i, i);
			}
		}
	}
	
	static class D2 extends Element {
		D2(int n) {
			super(n);
			for (int i = 0; i < n; ++i) {
				add(i, n - i - 1);
			}
		}
	}
	
	List<Element> es;
	private HashSet<Integer> ps;
	
	boolean set(int x, int y, int val, int s, int n) {
		if (ans[x][y] != -1) {
			throw new AssertionError();
		}
		if (count[val] == 0) {
			return false;
		}
		count[val]--;
		ans[x][y] = val;
		for (Element e : es) {
			if (e.f[x][y]) {
				e.xs ^= x;
				e.ys ^= y;
				e.sum += ar[val];
				e.used++;
			}
		}
		if (rec(s, n)) {
			return true;
		}
		for (Element e : es) {
			if (e.f[x][y]) {
				e.xs ^= x;
				e.ys ^= y;
				e.sum -= ar[val];
				e.used--;
			}
		}
		ans[x][y] = -1;
		count[val]++;
		return false;
	}
	
	boolean rec(int s, int n) {
		for (Element e : es) {
			if (e.used == n && e.sum != s || e.used + 2 == n && !ps.contains(s - e.sum)) {
				return false;
			}
			if (e.used + 1 == n) {
				Integer val = idMap.get(s - e.sum);
				if (val != null) {
					return set(e.xs, e.ys, val, s, n);
				}
			}
		}
		int x = 0, y = 0;
		while (x < n && ans[x][y] != -1) {
			y++;
			if (y == n) {
				x++;
				y = 0;
			}
		}
		if (x == n) {
			out.println(s);
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					out.print(ar[ans[i][j]] + " ");
				}
				out.println();
			}
			return true;
		}
		for (int i = 0; i < idMap.size(); ++i) {
			if (set(x, y, i, s, n)) {
				return true;
			}
		}
		return false;
	}

	public void solve() throws IOException {
		int n = nextInt();
		ar = new int[n * n];
		count = new int[n * n];
		idMap = new HashMap<Integer, Integer>();
		int sum = 0;
		for (int i = 0; i < n * n; ++i) {
			int x = nextInt();
			sum += x;
			if (!idMap.containsKey(x)) {
				ar[idMap.size()] = x;
				idMap.put(x, idMap.size());
			}
			count[idMap.get(x)]++;
		}
		ps = new HashSet<Integer>();
		for (int i = 0; i < idMap.size(); ++i) {
			for (int j = 0; j <= i; ++j) {
				ps.add(ar[i] + ar[j]);
			}
		}
		int s = sum / n;
		ans = new int[n][n];
		for (int[] ar : ans) {
			Arrays.fill(ar, -1);
		}
		es = new ArrayList<Element>();
		for (int i = 0; i < n; ++i) {
			es.add(new Row(n, i));
			es.add(new Col(n, i));
		}
		es.add(new D1(n));
		es.add(new D2(n));
		if (!rec(s, n)) {
			throw new AssertionError();
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