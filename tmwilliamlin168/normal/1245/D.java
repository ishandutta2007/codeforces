import java.util.*;
 
 
 
import java.io.*;
 
import java.text.*;
 
public class D1245 {
	static int[] x, y, c, k;
	static int n;
	static ArrayList<Edge> ans;
	static ArrayList<Edge> edgeList;
 
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		ans = new ArrayList<Edge>();
		n = sc.nextInt();
		x = new int[n];
		y = new int[n];
		c = new int [n];
		k=new int [n];
		for (int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
		}
		for (int i = 0; i < n; i++)
			c[i] = sc.nextInt();
		for (int i = 0; i < n; i++)
			k[i] = sc.nextInt();
		edgeList = new ArrayList<Edge>();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				edgeList.add(new Edge(i, j, 1l * (Math.abs(x[i] - x[j]) + Math.abs(y[i] - y[j])) * (k[i] + k[j])));
			}
		}
		for (int i = 0; i < n; i++) {
			edgeList.add(new Edge(i, n, c[i]));
		}
		Collections.sort(edgeList);
		UnionFind uf = new UnionFind(n + 1);
		long mst = 0;
		long con = 0;
		long stat = 0;
		ArrayList<Integer> station = new ArrayList<Integer>();
		for (Edge e : edgeList) {
			if (!uf.isSameSet(e.u, e.v)) {
				uf.unionSet(e.u, e.v);
 
				mst += e.w;
				if (e.v == n) {
					stat++;
					station.add(e.u);
				} else {
					con++;
					ans.add(e);
				}
			}
		}
		pw.println(mst);
		pw.println(stat);
		for(int x : station) {
			pw.print((x+1)+" ");
		}
		pw.println();
		pw.println(con);
		for(Edge e : ans) {
			pw.println((e.u+1)+" "+(e.v+1));
		}
		pw.close();
 
	}
 
	static class UnionFind {
		int[] p, rank, setSize;
		int numSets;
 
		public UnionFind(int N) {
			p = new int[numSets = N];
			rank = new int[N];
			setSize = new int[N];
			for (int i = 0; i < N; i++) {
				p[i] = i;
				setSize[i] = 1;
			}
		}
 
		public int findSet(int i) {
			return p[i] == i ? i : (p[i] = findSet(p[i]));
		}
 
		public boolean isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}
 
		public void unionSet(int i, int j) {
			if (isSameSet(i, j))
				return;
			numSets--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[x] += setSize[y];
			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
 
		public int numDisjointSets() {
			return numSets;
		}
 
		public int sizeOfSet(int i) {
			return setSize[findSet(i)];
		}
	}
 
	static class Edge implements Comparable<Edge> {
		int u, v;
		long w;
 
		public Edge(int a, int b, long c) {
			u = a;
			v = b;
			w = c;
		}
 
		public int compareTo(Edge e) {
			return Long.compare(w, e.w);
		}
	}
 
	static class Scanner {
		StringTokenizer st;
		BufferedReader br;
 
		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}
 
		public Scanner(FileReader r) {
			br = new BufferedReader(r);
		}
 
		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
 
		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
 
		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}
 
		public String nextLine() throws IOException {
			return br.readLine();
		}
 
		public double nextDouble() throws IOException {
			String x = next();
			StringBuilder sb = new StringBuilder("0");
			double res = 0, f = 1;
			boolean dec = false, neg = false;
			int start = 0;
			if (x.charAt(0) == '-') {
				neg = true;
				start++;
			}
			for (int i = start; i < x.length(); i++)
				if (x.charAt(i) == '.') {
					res = Long.parseLong(sb.toString());
					sb = new StringBuilder("0");
					dec = true;
				} else {
					sb.append(x.charAt(i));
					if (dec)
						f *= 10;
				}
			res += Long.parseLong(sb.toString()) / f;
			return res * (neg ? -1 : 1);
		}
 
		public boolean ready() throws IOException {
			return br.ready();
		}
 
	}
}