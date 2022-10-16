import java.util.*;
import java.io.*;

public class D {

	List<Integer>[] graph;

	void solve() {
		int n = in.nextInt(), m = in.nextInt();
		graph = new List[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<>();
			graph[i].add(i);
		}
		for (int i = 0; i < m; i++) {
			int fromm = in.nextInt() - 1, to = in.nextInt() - 1;
			graph[fromm].add(to);
			graph[to].add(fromm);
		}
		int start = 0;
		if (graph[0].size() == n) {
			for (int i = 0; i < n; i++) {
				Collections.sort(graph[i]);
			}
			for (int j = 1; j < n; j++) {
				if (!graph[j].equals(graph[0])) {
					start = j;
					break;
				}
			}
		}
		
		int[] dist = new int[n], q = new int[n];
		int[] distFirst = new int[n], distSecond = new int[n];
		int INF = Integer.MAX_VALUE;
		
		Arrays.fill(dist, INF);
		dist[start] = 0;
		int head = 0, tail = 0;
		q[tail++] = start;
		while (head < tail) {
			int cur = q[head++];
			for (int t : graph[cur]) {
				if (dist[t] == INF) {
					dist[t] = dist[cur] + 1;
					q[tail++] = t;
				}
			}
		}
		
		int newStart = q[n - 1];
		Arrays.fill(distFirst, INF);
		distFirst[newStart] = 0;
		head = 0;
		tail = 0;
		q[tail++] = newStart;
		while (head < tail) {
			int cur = q[head++];
			for (int t : graph[cur]) {
				if (distFirst[t] == INF) {
					distFirst[t] = distFirst[cur] + 1;
					q[tail++] = t;
				}
			}
		}
		int diam = distFirst[q[n - 1]];
		
		newStart = q[n - 1];
		Arrays.fill(distSecond, INF);
		distSecond[newStart] = 0;
		head = 0;
		tail = 0;
		q[tail++] = newStart;
		while (head < tail) {
			int cur = q[head++];
			for (int t : graph[cur]) {
				if (distSecond[t] == INF) {
					distSecond[t] = distSecond[cur] + 1;
					q[tail++] = t;
				}
			}
		}
		
		int[] mark = new int[n];
		for (int i = 0; i < n; i++) {
			if (distFirst[i] == diam) {
				mark[i] = diam;
			} else if (distSecond[i] == diam) {
				mark[i] = 0;
			} else {
				
				mark[i] = distFirst[i];
			}
		}
		
		int[] cnt = new int[n];
		int[] cntAdj = new int[n], cntIn = new int[n];
		for (int i = 0; i < n; i++) {
			cnt[mark[i]]++;
			for (int j : graph[i]) {
				if (i < j) {
					if (mark[i] == mark[j]) {
						cntIn[mark[i]]++;
					} else {
						if (Math.abs(mark[i] - mark[j]) > 1) {
							out.println("NO");
							return;
						}
						cntAdj[Math.min(mark[i], mark[j])]++;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (cntIn[i] != 1L * cnt[i] * (cnt[i] - 1) / 2) {
				out.println("NO");
				return;
			}
		}
		for (int i = 0; i < n-  1; i++) {
			if (cntAdj[i] != 1L * cnt[i] * cnt[i + 1]) {
				out.println("NO");
				return;
			}
		}
		out.println("YES");
		for (int i = 0; i < n; i++) {
			out.print((mark[i] + 1) + " ");
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