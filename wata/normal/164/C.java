import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	void run() {
		int n = sc.nextInt(), k = sc.nextInt();
		int[] ss = new int[n], ts = new int[n], cs = new int[n];
		TreeSet<Integer> set = new TreeSet<Integer>();
		for (int i = 0; i < n; i++) {
			ss[i] = sc.nextInt();
			ts[i] = ss[i] + sc.nextInt();
			cs[i] = sc.nextInt();
			set.add(ss[i]);
			set.add(ts[i]);
		}
		set.add(0);
		set.add(2100000001);
		int[] ps = toi(set.toArray(new Integer[0]));
		for (int i = 0; i < n; i++) {
			ss[i] = Arrays.binarySearch(ps, ss[i]);
			ts[i] = Arrays.binarySearch(ps, ts[i]);
		}
		int m = ps.length;
		V[] vs = new V[m];
		for (int i = 0; i < m; i++) vs[i] = new V();
		for (int i = 0; i < m - 1; i++) vs[i].add(vs[i + 1], k, 0);
		E[] es = new E[n];
		for (int i = 0; i < n; i++) {
			es[i] = vs[ss[i]].add(vs[ts[i]], 1, -cs[i]);
		}
		minCostFlow(vs, vs[0], vs[m - 1], k);
		for (int i = 0; i < n; i++) {
			if (i > 0) System.out.print(" ");
			if (es[i].cap == 0) System.out.print(1);
			else System.out.print(0);
		}
		System.out.println();
	}
	
	int[] toi(Integer[] Is) {
		int n = Is.length;
		int[] is = new int[n];
		for (int i = 0; i < n; i++) is[i] = Is[i];
		return is;
	}
	
	long INF = 1L << 50;
	
	long minCostFlow(V[] vs, V s, V t, int flow) {
		boolean b = true;
		while (b) {
			b = false;
			for (V v : vs) for (E e : v.es) {
				if (e.cap > 0 && e.to.h > v.h + e.cost) {
					e.to.h = v.h + e.cost;
					b = true;
				}
			}
		}
		long res = 0;
		while (flow > 0) {
			for (V v : vs) v.min = INF;
			for (V v : vs) v.fixed = false;
			PriorityQueue<E> que = new PriorityQueue<E>();
			s.min = 0;
			que.offer(new E(s, 0, 0));
			while (!que.isEmpty()) {
				V v = que.poll().to;
				if (v.fixed) continue;
				v.fixed = true;
				for (E e : v.es) if (e.cap > 0 && !e.to.fixed) {
					long tmp = v.min + e.cost + v.h - e.to.h;
					if (e.to.min > tmp) {
						e.to.min = tmp;
						e.to.prev = e;
						que.offer(new E(e.to, 0, e.to.min));
					}
				}
			}
			if (t.min == INF) throw null;
			for (V v : vs) v.h += v.min;
			int d = flow;
			for (E e = t.prev; e != null; e = e.rev.to.prev) {
				d = min(d, e.cap);
			}
			flow -= d;
			res += d * t.h;
			for (E e = t.prev; e != null; e = e.rev.to.prev) {
				e.cap -= d;
				e.rev.cap += d;
			}
		}
		return res;
	}
	class V {
		ArrayList<E> es = new ArrayList<E>();
		E prev;
		boolean fixed;
		long min, h;
		E add(V to, int cap, int cost) {
			E e = new E(to, cap, cost), rev = new E(this, 0, -cost);
			e.rev = rev; rev.rev = e;
			es.add(e); to.es.add(rev);
			return e;
		}
	}
	class E implements Comparable<E> {
		V to;
		E rev;
		int cap;
		long cost;
		E(V to, int cap, long cost) {
			this.to = to;
			this.cap = cap;
			this.cost = cost;
		}
		public int compareTo(E o) {
			return Long.signum(cost - o.cost);
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}