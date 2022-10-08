import java.io.*;
import java.util.*;

public class CF269C {

    static class Edge {
        int b, c;

        Edge(int b, int c) {
            this.b = b;
            this.c = c;
        }
    }

    static class Node implements Comparable<Node> {
        int i, val;

        Node(int i, int val) {
            this.i = i;
            this.val = val;
        }

        @Override
        public int compareTo(Node o) {
            return val - o.val;
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        List<Edge>[] edges = new List[n];
        for (int i = 0; i < n; ++i) {
            edges[i] = new ArrayList<Edge>();
        }
        int[] cs = new int[n];
        int[] a = new int[m];
        int[] b = new int[m];
        for (int i = 0; i < m; ++i) {
            a[i] = in.nextInt() - 1;
            b[i] = in.nextInt() - 1;
            int c = in.nextInt();
            cs[a[i]] += c;
            cs[b[i]] += c;
            edges[a[i]].add(new Edge(b[i], c));
            edges[b[i]].add(new Edge(a[i], c));
        }
        for (int i = 1; i < n - 1; ++i) {
            if (cs[i] % 2 != 0) {
                throw new AssertionError();
            }
            cs[i] /= 2;
        }
        int[] order = new int[n];
        Arrays.fill(order, -1);
        cs[0] = 0;
        PriorityQueue<Node> q = new PriorityQueue<Node>();
        for (int i = 0; i < n; ++i) {
            q.add(new Node(i, cs[i]));
        }
        int o = 0;
        while (!q.isEmpty()) {
            Node node = q.poll();
            if (order[node.i] != -1) {
                continue;
            }
            if (node.val != 0) {
                throw new AssertionError();
            }
            order[node.i] = o++;
            for (Edge e : edges[node.i]) {
                if (order[e.b] == -1) {
                    cs[e.b] -= e.c;
                    q.add(new Node(e.b, cs[e.b]));
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            out.println(order[a[i]] < order[b[i]] ? 0 : 1);
        }
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringTokenizer st;

        public Input(BufferedReader in) {
            this.in = in;
            eat("");
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public void eat(String str) {
            st = new StringTokenizer(str);
        }

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null) {
                    return null;
                }
                eat(line);
            }
            return st.nextToken();
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