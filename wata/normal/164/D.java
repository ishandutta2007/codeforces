import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class D {
	Scanner sc = new Scanner(System.in);
	Random rand = new Random(4324211);
	
	void run() {
		int n = sc.nextInt(), k = sc.nextInt();
//		int n = 1000, k = 30;
		int[] xs = new int[n], ys = new int[n];
		for (int i = 0; i < n; i++) {
			xs[i] = sc.nextInt();
			ys[i] = sc.nextInt();
//			xs[i] = rand.nextInt(3000);
//			ys[i] = rand.nextInt(3000);
		}
		double[][] d = new double[n][n];
		Entry[] es = new Entry[n * (n - 1) / 2];
		int m = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				d[i][j] = d[j][i] = dist(xs[i] - xs[j], ys[i] - ys[j]);
				es[m++] = new Entry(i, j, d[i][j]);
			}
		}
		sort(es);
		int left = 0, right = min(m, (n - 1) * k) + 1;
		while (right - left > 1) {
			int mid = (left + right) / 2;
			G g = new G(n);
			for (int i = 0; i < mid; i++) g.connect(es[i].i, es[i].j);
			if (rec(g, k, new int[k])) left = mid;
			else right = mid;
		}
		G g = new G(n);
		for (int i = 0; i < left; i++) g.connect(es[i].i, es[i].j);
		int[] ans = new int[k];
		rec(g, k, ans);
		for (int i = 0; i < k; i++) {
			if (i > 0) System.out.print(" ");
			System.out.print(ans[i] + 1);
		}
		System.out.println();
	}
	
	class Entry implements Comparable<Entry> {
		int i, j;
		double d;
		Entry(int i, int j, double d) {
			this.i = i;
			this.j = j;
			this.d = d;
		}
		public int compareTo(Entry o) {
			if (d < o.d) return 1;
			if (d > o.d) return -1;
			return 0;
		}
	}
	
	class G {
		int n;
		int[] vs;
		int[] id;
		int[] deg;
		int[][] adj;
		int[][] ps;
		G(int n) {
			this.n = n;
			vs = new int[n];
			id = new int[n];
			deg = new int[n];
			adj = new int[n][2];
			ps = new int[n][2];
			for (int i = 0; i < n; i++) vs[i] = id[i] = i;
		}
		void connect(int u, int v) {
			adj[v] = set(adj[v], deg[v], u);
			adj[u] = set(adj[u], deg[u], v);
			ps[v] = set(ps[v], deg[v], deg[u]);
			ps[u] = set(ps[u], deg[u], deg[v]);
			deg[u]++;
			deg[v]++;
		}
		void remove(int v) {
			if (id[v] < --n) {
				int p = id[v];
				swap(vs, p, n);
				swap(id, vs[p], vs[n]);
			}
			for (int i = 0; i < deg[v]; i++) {
				int u = adj[v][i], p = ps[v][i];
				if (p < --deg[u]) {
					swap(adj[u], p, deg[u]);
					swap(ps[u], p, deg[u]);
					ps[adj[u][p]][ps[u][p]] = p;
					ps[v][i] = deg[u];
				}
			}
		}
		void restore() {
			int v = vs[n++];
			for (int i = 0; i < deg[v]; i++) deg[adj[v][i]]++;
		}
		public String toString() {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < n; i++) {
				int v = vs[i];
				sb.append(v).append(':');
				for (int j = 0; j < deg[v]; j++) sb.append(' ').append(adj[v][j]);
				sb.append('\n');
			}
			return sb.toString();
		}
	}
	
	void swap(int[] is, int a, int b) {
		int t = is[a]; is[a] = is[b]; is[b] = t;
	}
	
	int[] set(int[] is, int i, int v) {
		if (i == is.length) {
			int[] tmp = new int[is.length * 2];
			System.arraycopy(is, 0, tmp, 0, is.length);
			is = tmp;
		}
		is[i] = v;
		return is;
	}
	
	boolean rec(G g, int k, int[] res) {
		if (g.n == 0) {
			for (int i = 0; i < k; i++) res[i] = -1;
			return true;
		}
		int m = 0, w = g.vs[0];
		for (int i = 0; i < g.n; i++) {
			int v = g.vs[i];
			if (k == 0 && g.deg[v] > 0) return false;
			if (g.deg[w] < g.deg[v]) w = v;
			m += g.deg[v];
			if (g.deg[v] == 0) {
				g.remove(v);
				if (rec(g, k, res)) return true;
				g.restore();
				return false;
			} else if (g.deg[v] == 1) {
				res[--k] = g.adj[v][0];
				g.remove(res[k]);
				g.remove(v);
				if (rec(g, k, res)) return true;
				g.restore();
				g.restore();
				return false;
			} else if (g.deg[v] > k) {
				res[--k] = v;
				g.remove(v);
				if (rec(g, k, res)) return true;
				g.restore();
				return false;
			}
		}
		if (m > 2 * k * k) return false;
		res[k - 1] = w;
		g.remove(w);
		if (rec(g, k - 1, res)) return true;
		g.restore();
		int p = k;
		while (g.deg[w] > 0) {
			res[--p] = g.adj[w][0];
			g.remove(res[p]);
		}
		g.remove(w);
		if (rec(g, p, res)) return true;
		g.restore();
		for (int i = p; i < k; i++) g.restore();
		return false;
	}
	
	double dist(double x, double y) {
		return x * x + y * y;
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new D().run();
	}
}