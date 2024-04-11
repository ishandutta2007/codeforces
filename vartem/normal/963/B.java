import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        List<Integer>[] tree;
        int[] size;
        int[] up;
        int[] parent;

        void dfs(int u, int p) {
            size[u] = 1;
            parent[u] = p;
            for (int t = 0; t < tree[u].size(); t++) {
                int v = tree[u].get(t);
                if (v != p) {
                    dfs(v, u);
                    size[u] ^= size[v];
                }
            }
            up[u] = size[u] ^ 1;
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            size = new int[n];
            parent = new int[n];
            up = new int[n];
            tree = new List[n];
            for (int i = 0; i < n; i++) {
                tree[i] = new ArrayList<>();
            }
            if (n % 2 == 0) {
                out.println("NO");
                return;
            }
            for (int i = 0; i < n; i++) {
                int p = in.nextInt();
                if (p != 0) {
                    tree[i].add(p - 1);
                    tree[p - 1].add(i);
                }
            }
            dfs(0, -1);
            Queue<Integer> q = new ArrayDeque<>();
            List<Integer> ans = new ArrayList<>();
            int[] remDeg = new int[n];
            int[] countOdd = new int[n];
            for (int i = 0; i < n; i++) {
                remDeg[i] = tree[i].size();
                for (int j : tree[i]) {
                    if (j != parent[i]) {
                        countOdd[i] += size[j];
                    } else {
                        countOdd[i] += up[i];
                    }
                }
                if (remDeg[i] % 2 == 0 && countOdd[i] == remDeg[i]) {
                    q.add(i);
                }
            }
            boolean[] used = new boolean[n];
            while (!q.isEmpty()) {
                int cur = q.poll();
                used[cur] = true;
                ans.add(cur);
                for (int i : tree[cur]) {
                    if (used[i]) {
                        continue;
                    }
                    remDeg[i]--;
                    if (parent[i] == cur) {
                        countOdd[i] -= (size[i] ^ 1);
                    } else {
                        countOdd[i] -= size[cur];
                    }
                    if (remDeg[i] % 2 == 0 && countOdd[i] == remDeg[i]) {
                        q.add(i);
                    }
                }
            }
            if (ans.size() != n) {
                out.println("NO");
            } else {
                out.println("YES");
                for (int i : ans) {
                    out.println(i + 1);
                }
            }
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
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
}