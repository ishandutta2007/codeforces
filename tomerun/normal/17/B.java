import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {
	static Scanner sc = new Scanner(System.in);
	static int[] Q;

	public static void main(String[] args) throws Exception {
		int N = sc.nextInt();
		if (N == 1) {
			System.out.println(0);
			return;
		}
		Q = new int[N];
		for (int i = 0; i < N; ++i) {
			Q[i] = sc.nextInt();
		}
		int M = sc.nextInt();
		sc.nextLine();
		ArrayList<Edge> edges = new ArrayList<Edge>(M);
		for (int i = 0; i < M; ++i) {
			String[] line = sc.nextLine().split(" ");
			int a = Integer.parseInt(line[0]) - 1;
			int b = Integer.parseInt(line[1]) - 1;
			int c = Integer.parseInt(line[2]);
			edges.add(new Edge(a, b, c));
		}
		PriorityQueue<Edge> que = new PriorityQueue<Edge>();
		que.addAll(edges);
		UnionFind uf = new UnionFind(N);
		int all = 0;
		boolean[] suped = new boolean[N];
		while (!que.isEmpty()) {
			Edge cur = que.poll();
			if (suped[cur.sub]) continue;
			if (uf.find(cur.sup, cur.sub)) continue;
			uf.union(cur.sup, cur.sub);
			suped[cur.sub] = true;
			all += cur.cost;
			if (uf.size(cur.sup) == N) {
				System.out.println(all);
				return;
			}
		}
		System.out.println("-1");
	}

	static class UnionFind {
		int[] set;

		UnionFind(int n) {
			set = new int[n];
			Arrays.fill(set, -1);
		}

		void union(int a, int b) {
			int rtA = root(a);
			int rtb = root(b);
			if (rtA == rtb) {
				return;
			}
			set[rtA] += set[rtb];
			set[rtb] = rtA;
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

	static class Edge implements Comparable<Edge> {
		int sup;
		int sub;
		int cost;

		Edge(int a, int b, int c) {
			this.sup = a;
			this.sub = b;
			this.cost = c;
		}

		public int compareTo(Edge o) {
			return this.cost - o.cost;
		}
	}

}