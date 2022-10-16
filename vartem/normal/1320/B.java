import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Queue;
import java.io.FileReader;
import java.util.ArrayDeque;
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
        BSistemaNavigatsii solver = new BSistemaNavigatsii();
        solver.solve(1, in, out);
        out.close();
    }

    static class BSistemaNavigatsii {
        List<Integer>[] graph;
        List<Integer>[] revGraph;
        int INF = (int) 1e9;

        int[] dist(List<Integer>[] graph, int start) {
            int n = graph.length;
            int[] dist = new int[n];
            Arrays.fill(dist, INF);
            Queue<Integer> q = new ArrayDeque<>();
            q.add(start);
            dist[start] = 0;
            while (!q.isEmpty()) {
                int cur = q.poll();
                for (int to : graph[cur]) {
                    if (dist[to] == INF) {
                        dist[to] = dist[cur] + 1;
                        q.add(to);
                    }
                }
            }
            return dist;
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
            int k = in.nextInt();
            int[] path = in.nextIntArray(k);
            for (int i = 0; i < k; i++) {
                path[i]--;
            }
            int[] d1 = dist(graph, path[0]);
            int[] d2 = dist(revGraph, path[k - 1]);
            int[] countEdges = new int[n];
            for (int from = 0; from < n; from++) {
                for (int to : graph[from]) {
                    if (d2[from] == d2[to] + 1) {
                        countEdges[from]++;
                    }
                }
            }

            int min = 0, max = 0;
            for (int i = 0; i < k - 1; i++) {
                int from = path[i], to = path[i + 1];

                if (d2[from] != d2[to] + 1) {
                    min++;
                    max++;
                } else {
                    if (countEdges[from] > 1) {
                        max++;
                    }
                }
            }
            out.println(min + " " + max);
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

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }
}