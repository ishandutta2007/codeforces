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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            List<Integer>[] graph = Utils.listArray(n);
            for (int i = 0; i < k; i++) {
                int from = in.nextInt() - 1, to = in.nextInt() - 1;
                graph[from].add(to);
                graph[to].add(from);
            }

            boolean[] used = new boolean[n];
            int[] q = new int[n];
            int comps = 0;
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    used[i] = true;
                    int head = 0, tail = 0;
                    q[tail++] = i;
                    comps++;
                    while (head < tail) {
                        int cur = q[head++];
                        for (int v : graph[cur]) {
                            if (!used[v]) {
                                used[v] = true;
                                q[tail++] = v;
                            }
                        }
                    }
                }
            }
            out.println(k - (n - comps));
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
        BufferedReader br;
        StringTokenizer st;

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
}