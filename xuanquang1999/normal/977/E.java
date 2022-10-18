import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author xuanquang1999
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        ArrayList<Integer>[] g;
        boolean[] visited;
        boolean isCycle;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();

            g = new ArrayList[n];
            visited = new boolean[n];

            for (int u = 0; u < n; ++u) {
                visited[u] = false;
                g[u] = new ArrayList<>();
            }

            for (int i = 0; i < m; ++i) {
                int u = in.nextInt();
                --u;
                int v = in.nextInt();
                --v;
                g[u].add(v);
                g[v].add(u);
            }

            int ans = 0;
            for (int u = 0; u < n; ++u) {
                if (!visited[u]) {
                    isCycle = true;
                    DFS(u);
                    if (isCycle) {
                        ++ans;
                    }
                }
            }

            System.out.println(ans);
        }

        public void DFS(int u) {
            visited[u] = true;
            if (g[u].size() != 2) {
                isCycle = false;
            }
            for (int v : g[u]) {
                if (!visited[v]) {
                    DFS(v);
                }
            }
        }

    }
}