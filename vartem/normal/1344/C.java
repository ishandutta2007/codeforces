import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CZadachaProKvantori solver = new CZadachaProKvantori();
        solver.solve(1, in, out);
        out.close();
    }

    static class CZadachaProKvantori {
        List<Integer>[] graph;
        List<Integer>[] revGraph;
        List<Integer> order;
        int[] comp;
        boolean[] hasLess;
        boolean[] hasMore;

        void dfs(int u) {
            comp[u] = 1;
            for (int t = 0; t < graph[u].size(); t++) {
                int v = graph[u].get(t);
                if (comp[v] == 0) {
                    dfs(v);
                }
            }
            order.add(u);
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            graph = Utils.listArray(n);
            revGraph = Utils.listArray(n);
            for (int i = 0; i < m; i++) {
                int from = in.nextInt() - 1, to = in.nextInt() - 1;
                graph[from].add(to);
                revGraph[to].add(from);
            }
            order = new ArrayList<>();
            comp = new int[n];
            for (int i = 0; i < n; i++) {
                if (comp[i] == 0) {
                    dfs(i);
                }
            }
            Collections.reverse(order);
            int[] pos = new int[n];
            for (int i = 0; i < n; i++) {
                pos[order.get(i)] = i;
            }
            boolean cycle = false;
            for (int i = 0; i < n; i++) {
                for (int j : graph[i]) {
                    cycle |= pos[i] > pos[j];
                }
            }
            if (cycle) {
                out.println(-1);
                return;
            }
            int ans = 0;
            char[] result = new char[n];
            hasLess = new boolean[n];
            hasMore = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (hasLess[i] || hasMore[i]) {
                    result[i] = 'E';
                } else {
                    ans++;
                    result[i] = 'A';
                }
                dfsMark(i, graph, hasLess);
                dfsMark(i, revGraph, hasMore);
            }

            out.println(ans);
            out.println(new String(result));
        }

        private void dfsMark(int u, List<Integer>[] graph, boolean[] mark) {
            mark[u] = true;
            for (int t = 0; t < graph[u].size(); t++) {
                int v = graph[u].get(t);
                if (!mark[v]) {
                    dfsMark(v, graph, mark);
                }
            }
        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }

    static class Utils {
        public static <T> List<T>[] listArray(int size) {
            List<T>[] result = new List[size];
            for (int i = 0; i < size; i++) {
                result[i] = new ArrayList<>();
            }
            return result;
        }

    }
}