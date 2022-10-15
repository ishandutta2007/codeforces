import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author prakharjain
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        F2SpanningTreeWithOneFixedDegree solver = new F2SpanningTreeWithOneFixedDegree();
        solver.solve(1, in, out);
        out.close();
    }

    static class F2SpanningTreeWithOneFixedDegree {
        List[] g;
        boolean[] vis;
        Set<Integer> set = new HashSet<>();
        List<edge> ans = new ArrayList<>();

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();

            int m = in.nextInt();

            int d = in.nextInt();

            g = new List[n];

            in.readUndirectedGraph(g, n, m, 1);

            int[] deg = new int[n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < g[i].size(); j++) {
                    int v = (int) g[i].get(j);

                    deg[v]++;
                }
            }

            if (deg[0] < d) {
                out.println("NO");
                return;
            }

            vis = new boolean[n];

            DsuInteger dsu = new DsuInteger(n);

            for (int i = 0; i < n; i++) {
                dsu.createSet(i);
            }

            for (int i = 1; i < n; i++) {
                for (int j = 0; j < g[i].size(); j++) {
                    int v = (int) g[i].get(j);

                    if (v != 0) {
                        dsu.mergeSets(i, v);
                    }
                }
            }

            Set<Integer> cu = new HashSet<>();

            for (int j = 0; j < g[0].size(); j++) {
                int v = (int) g[0].get(j);

                int s1 = dsu.findSet(v);

                if (!cu.contains(s1)) {
                    cu.add(s1);
                    set.add(v);
                }
            }

            if (set.size() > d) {
                out.println("NO");
                return;
            }

            if (set.size() < d) {
                for (int j = 0; j < g[0].size(); j++) {
                    int v = (int) g[0].get(j);

                    if (!set.contains(v) && set.size() < d) {
                        set.add(v);
                    }
                }
            }

            dfs(0, d);

            out.println("YES");
            for (edge edge : ans) {
                out.println((edge.u + 1) + " " + (edge.v + 1));
            }
        }

        void dfs(int u, int d) {
//        vis[u] = true;
//        for (int j = 0; j < g[u].size(); j++) {
//            int v = (int) g[u].get(j);
//
//            if (!vis[v]) {
//                ans.add(new edge(u, v));
//                dfs(v);
//            }
//        }

            ArrayDeque<Integer> q = new ArrayDeque<>();

            q.addLast(u);
            vis[u] = true;

            while (!q.isEmpty()) {
                int pe = q.removeFirst();

                int max = g[pe].size();

                if (pe != 0) {
                    for (int j = 0; j < max; j++) {
                        int v = (int) g[pe].get(j);

                        if (!vis[v]) {
                            vis[v] = true;
                            q.addLast(v);
                            ans.add(new edge(pe, v));
                        }
                    }
                } else {
                    for (int num : set) {
                        int v = num;

                        if (!vis[v]) {
                            vis[v] = true;
                            q.addLast(v);
                            ans.add(new edge(pe, v));
                        }
                    }
                }
            }
        }

        class DsuInteger {
            int[] parent;
            int[] rank;
            int[] size;
            int n;

            public DsuInteger(int n) {
                this.n = n;
                this.parent = new int[n];
                this.rank = new int[n];
                this.size = new int[n];
            }

            int createSet(int x) {
                parent[x] = x;
                rank[x] = 0;
                size[x] = 1;
                return x;
            }

            int findSet(int x) {
                int par = parent[x];
                if (x != par) {
                    parent[x] = findSet(par);
                    return parent[x];
                }
                return par;
            }

            int mergeSets(int x, int y) {
                int rx = findSet(x);
                int ry = findSet(y);

                if (rx == ry) {
                    return rx;
                }

                int fp = -1;

                if (rank[rx] > rank[ry]) {
                    parent[ry] = rx;
                    fp = rx;
                } else {
                    parent[rx] = ry;
                    fp = ry;
                }

                size[fp] = size[rx] + size[ry];

                if (rank[rx] == rank[ry]) {
                    rank[ry] = rank[ry] + 1;
                }

                return fp;
            }

        }

        class edge {
            int u;
            int v;

            public edge(int u, int v) {
                this.u = u;
                this.v = v;
            }

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public void readUndirectedGraph(List[] g, int numOfVertices, int numOfEdges, int offset) {
            for (int i = 0; i < numOfVertices; i++) {
                g[i] = new ArrayList();
            }

            for (int i = 0; i < numOfEdges; i++) {
                int u = nextInt() - offset;
                int v = nextInt() - offset;

                if (u == v)
                    continue;

                g[u].add(v);
                g[v].add(u);
            }
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}