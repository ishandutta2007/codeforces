import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static int N;
	static UnionFind uf;

	public static void main(String[] args) {
		N = sc.nextInt();
		long[] X = new long[N];
		long[] Y = new long[N];
		for (int i = 0; i < N; i++) {
			X[i] = sc.nextInt();
			Y[i] = sc.nextInt();
		}
		if (N == 2) {
			System.out.println(1);
			System.out.println(1);
			return;
		}
		while (true) {
			boolean h0 = false;
			boolean h1 = false;
			for (int i = 0; i < N; i++) {
				if ((X[i] + Y[i]) % 2 == 0) {
					h0 = true;
				} else {
					h1 = true;
				}
			}
			if (h0 && h1) {
				ArrayList<Integer> g = new ArrayList<>();
				for (int i = 0; i < N; i++) {
					if ((X[i] + Y[i]) % 2 == 0) {
						g.add(i + 1);
					}
				}
				System.out.println(g.size());
				for (int i = 0; i < g.size(); i++) {
					System.out.print(g.get(i) + (i == g.size() - 1 ? "\n" : " "));
				}
				return;
			}
			if (h1) {
				for (int i = 0; i < N; i++) {
					X[i]++;
				}
			}
			h0 = false;
			h1 = false;
			for (int i = 0; i < N; i++) {
				if (X[i] % 2 == 0 && Y[i] % 2 == 0) {
					h0 = true;
				} else {
					h1 = true;
				}
			}
			if (h0 && h1) {
				ArrayList<Integer> g = new ArrayList<>();
				for (int i = 0; i < N; i++) {
					if (X[i] % 2 == 0) {
						g.add(i + 1);
					}
				}
				System.out.println(g.size());
				for (int i = 0; i < g.size(); i++) {
					System.out.print(g.get(i) + (i == g.size() - 1 ? "\n" : " "));
				}
				return;
			}
			if (h1) {
				for (int i = 0; i < N; i++) {
					X[i]++;
					Y[i]++;
				}
			}
			for (int i = 0; i < N; i++) {
				X[i] /= 2;
				Y[i] /= 2;
			}
		}
//		HashMap<Long, ArrayList<Edge>> map = new HashMap<>();
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < i; j++) {
//				long l = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
//				if (map.containsKey(l)) {
//					map.get(l).add(new Edge(i, j));
//				} else {
//					ArrayList<Edge> list = new ArrayList<>();
//					list.add(new Edge(i, j));
//					map.put(l, list);
//				}
//			}
//		}
//		ArrayList<ArrayList<Integer>> g = new ArrayList<>();
//		for (int i = 0; i < N; i++) {
//			g.add(new ArrayList<>());
//		}
//		uf = new UnionFind(N * 2);
//		boolean[] visited = new boolean[N];
//		HashSet<Integer> vs = new HashSet<>();
//		for (ArrayList<Edge> list : map.values()) {
//			if (list.size() == 1) continue;
////			System.err.println(list);
//			for (Edge e : list) {
//				g.get(e.s).add(e.t);
//				g.get(e.t).add(e.s);
//				vs.add(e.s);
//				vs.add(e.t);
//			}
//			for (int v : vs) {
//				if (visited[v]) continue;
//				bfs(g, v, visited);
//			}
//			for (int v : vs) {
//				visited[v] = false;
//			}
//			for (Edge e : list) {
//				g.get(e.s).clear();
//				g.get(e.t).clear();
//			}
//		}
//		ArrayList<Integer> g1 = new ArrayList<>();
//		for (int i = 0; i < N; i++) {
//			if (uf.find(0, i)) {
//				g1.add(i);
//			}
//		}
//		System.out.println(g1.size());
//		for (int i = 0; i < g1.size(); i++) {
//			System.out.print((g1.get(i) + 1) + (i == g1.size() - 1 ? "\n" : " "));
//		}
	}

	static void bfs(ArrayList<ArrayList<Integer>> g, int s, boolean[] visited) {
		visited[s] = true;
		ArrayList<Integer> cur = new ArrayList<>();
		ArrayList<Integer> even = new ArrayList<>();
		ArrayList<Integer> odd = new ArrayList<>();
		cur.add(s);
		for (int i = 0; !cur.isEmpty(); i++) {
			if (i % 2 == 0) {
				even.addAll(cur);
			} else {
				odd.addAll(cur);
			}
			ArrayList<Integer> next = new ArrayList<>();
			for (int c : cur) {
				for (int a : g.get(c)) {
					if (visited[a]) continue;
					visited[a] = true;
					next.add(a);
				}
			}
			cur = next;
		}
		for (int i = 1; i < even.size(); i++) {
			uf.union(even.get(0), even.get(i));
			uf.union(even.get(0) + N, even.get(i) + N);
		}
		for (int i = 1; i < odd.size(); i++) {
			uf.union(odd.get(0), odd.get(i));
			uf.union(odd.get(0) + N, odd.get(i) + N);
		}
		if (!odd.isEmpty()) {
			uf.union(even.get(0), odd.get(0) + N);
			uf.union(even.get(0) + N, odd.get(0));
		}
	}

	static class Edge {
		int s, t;

		public Edge(int s, int t) {
			this.s = s;
			this.t = t;
		}

		@Override
		public String toString() {
			return "Edge{" + "s=" + s + ", t=" + t + '}';
		}
	}

	static class UnionFind {
		int[] set;

		UnionFind(int n) {
			set = new int[n];
			Arrays.fill(set, -1);
		}

		void union(int a, int b) {
			int rtA = root(a);
			int rtB = root(b);
			if (rtA == rtB) {
				return;
			}
			set[rtA] += set[rtB];
			set[rtB] = rtA;
		}

		boolean find(int a, int b) {
			return root(a) == root(b);
		}

		int root(int a) {
			if (set[a] < 0) {
				return a;
			} else {
				set[a] = root(set[a]);
				return set[a];
			}
		}

		int size(int a) {
			return -set[root(a)];
		}
	}


}