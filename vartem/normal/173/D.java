import java.io.*;
import java.util.*;

public class D {

	final String filename = new String("D").toLowerCase();

	ArrayList<Integer>[] graph;

	class Edge {
		int from, to;

		public Edge(int from, int to) {
			this.from = Math.min(from, to);
			this.to = Math.max(from, to);
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + from;
			result = prime * result + to;
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
			Edge other = (Edge) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (from != other.from)
				return false;
			if (to != other.to)
				return false;
			return true;
		}

		private D getOuterType() {
			return D.this;
		}
	}

	void dfs(int u, int col, int[] color) {
		color[u] = col;
		for (int v : graph[u]) {
			if (color[v] == 0) {
				dfs(v, 3 - col, color);
			}
		}
	}

	void solve() throws Exception {
		int n = nextInt();
		int m = nextInt();
		graph = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			graph[i] = new ArrayList<Integer>();
		}
		Set<Edge> edges = new HashSet<Edge>();
		for (int j = 0; j < m; j++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			graph[x].add(y);
			graph[y].add(x);
			edges.add(new Edge(x, y));
		}

		int[] color = new int[n];
		for (int i = 0; i < n; i++) {
			if (color[i] == 0) {
				dfs(i, 1, color);
			}
		}

		int cnt1 = 0, cnt2 = 0;
		for (int i : color) {
			if (i == 1) {
				cnt1++;
			} else {
				cnt2++;
			}
		}

		if (cnt1 % 3 == 0) {
			out.println("YES");
			int[] ans = new int[n];
			int tempNum = 1;
			int tempCount = 0;
			for (int t = 1; t <= 2; t++) {
				for (int i = 0; i < n; i++) {
					if (color[i] == t) {
						ans[i] = tempNum;
						tempCount++;
						if (tempCount == 3) {
							tempNum++;
							tempCount = 0;
						}
					}
				}
			}
			for (int i : ans) {
				out.print(i + " ");
			}
			return;
		}

		if (cnt1 % 3 == 2) {
			for (int i = 0; i < n; i++) {
				color[i] = 3 - color[i];
			}
			int temp = cnt1;
			cnt1 = cnt2;
			cnt2 = temp;
		}

		// cnt1 % 3 == 1
		int findLeft = -1;
		for (int i = 0; i < n; i++) {
			if (color[i] == 1) {
				if (graph[i].size() <= cnt2 - 2) {
					findLeft = i;
					break;
				}
			}
		}

		if (findLeft == -1) {
			int findRight1 = -1, findRight2 = -1;
			for (int i = 0; i < n; i++) {
				if (color[i] == 2) {
					if (graph[i].size() <= cnt1 - 2) {
						if (findRight1 == -1) {
							findRight1 = i;
						} else {
							findRight2 = i;
							break;
						}
					}
				}
			}
			if (findRight2 == -1) {
				out.println("NO");
				return;
			}
			boolean[] mark = new boolean[n];
			mark[findRight1] = mark[findRight2] = true;
			int first1 = -1, first2 = -1, second1 = -1, second2 = -1;
			for (int i = 0; i < n; i++) {
				if (color[i] == 1) {
					if (!edges.contains(new Edge(findRight1, i))) {
						if (first1 == -1) {
							first1 = i;
						} else {
							first2 = i;
							break;
						}
					}
				}
			}

			for (int i = 0; i < n; i++) {
				if (color[i] == 1) {
					if (!edges.contains(new Edge(findRight2, i))) {
						if (second1 == -1) {
							second1 = i;
						} else {
							second2 = i;
							break;
						}
					}
				}
			}

			out.println("YES");
			int[] ans = new int[n];
			int tempNum = 3;
			int tempCount = 0;
			for (int t = 1; t <= 2; t++) {
				for (int i = 0; i < n; i++) {
					if (i == findRight1 || i == first1 || i == first2) {
						continue;
					}
					if (i == findRight2 || i == second1 || i == second2) {
						continue;
					}
					if (color[i] == t) {
						ans[i] = tempNum;
						tempCount++;
						if (tempCount == 3) {
							tempNum++;
							tempCount = 0;
						}
					}
				}
			}
			ans[findRight1] = ans[first1] = ans[first2] = 1;
			ans[findRight2] = ans[second1] = ans[second2] = 2;
			for (int i : ans) {
				out.print(i + " ");
			}
		} else {
			int i1 = -1, i2 = -1;
			for (int i = 0; i < n; i++) {
				if (color[i] == 2) {
					if (!edges.contains(new Edge(findLeft, i))) {
						if (i1 == -1) {
							i1 = i;
						} else {
							i2 = i;
							break;
						}
					}
				}
			}

			out.println("YES");
			int[] ans = new int[n];
			int tempNum = 2;
			int tempCount = 0;
			for (int t = 1; t <= 2; t++) {
				for (int i = 0; i < n; i++) {
					if (i == findLeft || i == i1 || i == i2) {
						continue;
					}
					if (color[i] == t) {
						ans[i] = tempNum;
						tempCount++;
						if (tempCount == 3) {
							tempNum++;
							tempCount = 0;
						}
					}
				}
			}
			ans[findLeft] = ans[i1] = ans[i2] = 1;
			for (int i : ans) {
				out.print(i + " ");
			}
		}
	}

	void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			// in = new BufferedReader(new FileReader("input.txt"));
			// out = new PrintWriter("output.txt");

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	BufferedReader in;
	StringTokenizer st;
	PrintWriter out;

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
		new D().run();
	}

}