import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Stack;
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
        public static int n;
        public static int id;
        public static int dfsCnt;
        public static int num[];
        public static int low[];
        public static int comp[];
        public static int degNew[];
        public static ArrayList<Integer> graph[];
        public static boolean avail[];
        public static Stack<Integer> st;

        public void DFS(int u) {
            st.push(u);
            low[u] = num[u] = ++dfsCnt;
            for (int v : graph[u]) {
                if (!avail[v])
                    continue;
                if (num[v] == 0) {
                    DFS(v);
                    low[u] = Math.min(low[u], low[v]);
                } else
                    low[u] = Math.min(low[u], num[v]);
            }

            if (low[u] == num[u]) {
                int v;
                do {
                    v = st.pop();
                    comp[v] = id;
                    avail[v] = false;
                } while (v != u);
                ++id;
            }
        }

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            n = in.nextInt();
            int m = in.nextInt(), s = in.nextInt();
            --s;
            graph = new ArrayList[n];
            for (int u = 0; u < n; ++u)
                graph[u] = new ArrayList<>();

            for (int i = 0; i < m; ++i) {
                int u = in.nextInt(), v = in.nextInt();
                --u;
                --v;
                graph[u].add(v);
            }

            num = new int[n];
            low = new int[n];
            comp = new int[n];
            avail = new boolean[n];
            for (int u = 0; u < n; ++u)
                avail[u] = true;
            id = dfsCnt = 0;
            st = new Stack<>();

            for (int u = 0; u < n; ++u)
                if (avail[u]) DFS(u);

            degNew = new int[id];
            for (int u = 0; u < n; ++u)
                for (int v : graph[u]) 
                    if (comp[u] != comp[v]) ++degNew[comp[v]];

            int ans = 0;
            for (int i = 0; i < id; ++i)
                if (degNew[i] == 0) ++ans;
            if (degNew[comp[s]] == 0) --ans;
            out.println(ans);
        }

    }
}