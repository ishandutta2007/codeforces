import java.util.*;
import java.io.*;

public class B {

	List<Integer>[] graph;
	int[] match;
	boolean[] used;
	
	boolean dfs(int u) {
		used[u] = true;
		for (int t = 0; t < graph[u].size(); t++) {
			int v = graph[u].get(t);
			if (match[v] == -1 || (!used[match[v]] && dfs(match[v]))) {
				match[v] = u;
				return true;
			}
		}
		return false;
	}
	
	
	void solve() {
		int n = in.nextInt();
		String[] a = new String[n], b = new String[n];
		String[] fst = new String[n], snd = new String[n];
		Set<String> all = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			a[i] = in.nextToken();
			b[i] = in.nextToken();
			fst[i] = a[i].substring(0, 3);
			snd[i] = a[i].substring(0, 2) + b[i].charAt(0);
			all.add(fst[i]);
			all.add(snd[i]);
		}
		
		String[] c = all.toArray(new String[0]);
		graph = new List[n];
		match = new int[c.length];
		Arrays.fill(match, -1);
		used = new boolean[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
			graph[i].add(Arrays.binarySearch(c, snd[i]));
			boolean ok = true;
			for (int j = 0; j < n; j++) {
				if (i != j && fst[i].equals(fst[j])) {
					ok = false;
					break;
				}
			}
			if (ok) {
				graph[i].add(Arrays.binarySearch(c, fst[i]));
			}
		}
//		System.err.println(Arrays.toString(c));
//		System.err.println(Arrays.toString(graph));
		for (int i = 0; i < n; i++) {
			Arrays.fill(used, false);
			if (!dfs(i)) {
				out.println("NO");
				return;
			}
		}
		out.println("YES");
		String[] result = new String[n];
		for (int i = 0; i < c.length; i++) {
			if (match[i] != -1) {
				result[match[i]] = c[i];
			}
		}
		for (String s : result) {
			out.println(s);
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
		new B().run();
	}
}