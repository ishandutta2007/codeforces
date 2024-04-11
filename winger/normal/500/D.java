import java.io.*;
import java.util.ArrayList;

public class CF500D {

    static class Edge {
        int b, i;

        public Edge(int b, int i) {
            this.b = b;
            this.i = i;
        }
    }


    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] l = new int[n - 1];
        ArrayList<Edge>[] edges = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            edges[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            l[i] = in.nextInt();
            edges[a].add(new Edge(b, i));
            edges[b].add(new Edge(a, i));
        }
        int[] n1 = new int[n - 1];
        dfs(0, -1, n1, edges);
        double ans = 0.0;
        double total = 1.0 * n * (n - 1) * (n - 2) / 6.0;
        for (int i = 0; i < n - 1; ++i) {
            ans += l[i] * f(n1[i], n - n1[i]);
        }
        int m = in.nextInt();
        for (int it = 0; it < m; ++it) {
            int i = in.nextInt() - 1;
            int nl = in.nextInt();
            ans += (nl - l[i]) * f(n1[i], n - n1[i]);
            l[i] = nl;
            out.println(ans / total);
        }
    }

    private static double f(int n1, int n2) {
        return n1 * (n1 - 1.0) * n2 + n2 * (n2 - 1.0) * n1;
    }

    private static int dfs(int i, int p, int[] n1, ArrayList<Edge>[] edges) {
        int r = 1;
        for (Edge e : edges[i]) {
            if (e.b != p) {
                r += n1[e.i] = dfs(e.b, i, n1, edges);
            }
        }
        return r;
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringBuilder sb = new StringBuilder();

        public Input(BufferedReader in) {
            this.in = in;
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public String next() throws IOException {
            sb.setLength(0);
            while (true) {
                int c = in.read();
                if (c == -1) {
                    return null;
                }
                if (" \n\r\t".indexOf(c) == -1) {
                    sb.append((char)c);
                    break;
                }
            }
            while (true) {
                int c = in.read();
                if (c == -1 || " \n\r\t".indexOf(c) != -1) {
                    break;
                }
                sb.append((char)c);
            }
            return sb.toString();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}