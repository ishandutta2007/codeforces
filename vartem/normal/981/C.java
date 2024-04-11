import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            List<Integer>[] tree = Utils.listArray(n);
            int[] deg = new int[n];
            for (int i = 0; i < n - 1; i++) {
                int from = in.nextInt() - 1, to = in.nextInt() - 1;
                tree[from].add(to);
                tree[to].add(from);
                deg[from]++;
                deg[to]++;
            }
            int root = -1;
            List<Integer> leaves = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (deg[i] == 1) {
                    leaves.add(i);
                } else {
                    if (deg[i] > 2) {
                        if (root != -1) {
                            out.println("No");
                            return;
                        }
                        root = i;
                    }
                }
            }
            if (root == -1) {
                root = 0;
                leaves.remove((Integer) root);
            }
            out.println("Yes");
            if (leaves.size() % 2 == 1) {
                leaves.add(root);
            }
            out.println(leaves.size() / 2);
            for (int i = 0; i < leaves.size(); i += 2) {
                out.println((leaves.get(i) + 1) + " " + (leaves.get(i + 1) + 1));
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