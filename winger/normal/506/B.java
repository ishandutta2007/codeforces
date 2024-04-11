import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class CF506B {

    static ArrayList<Integer>[] edges, redges;
    static boolean[] topcol, compcol, cycle;
    static int[] topsort;
    static int topsortEnd;

    static void topdfs(int i) {
        if (topcol[i]) {
            return;
        }
        topcol[i] = true;
        for (int e : edges[i]) {
            topdfs(e);
        }
        topsort[topsortEnd++] = i;
    }

    static int compdfs(int i) {
        if (compcol[i]) {
            return 0;
        }
        int r = 1;
        compcol[i] = true;
        for (int e : redges[i]) {
            r += compdfs(e);
        }
        return r;
    }

    static boolean compdfs2(int i) {
        if (topcol[i]) {
            return false;
        }
        boolean ret = cycle[i];
        topcol[i] = true;
        for (int e : edges[i]) {
            ret |= compdfs2(e);
        }
        for (int e : redges[i]) {
            ret |= compdfs2(e);
        }
        return ret;
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        edges = new ArrayList[n];
        redges = new ArrayList[n];
        topcol = new boolean[n];
        compcol = new boolean[n];
        topsort = new int[n];
        cycle = new boolean[n];
        for (int i = 0; i < n; ++i) {
            edges[i] = new ArrayList<Integer>();
            redges[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            edges[a].add(b);
            redges[b].add(a);
        }
        for (int i = 0; i < n; ++i) {
            topdfs(i);
        }
        if (topsortEnd != n) {
            throw new AssertionError();
        }
        for (int it = 0; it < n; ++it) {
            int i = topsort[n - it - 1];
            if (!compcol[i]) {
                int size = compdfs(i);
                if (size > 1) {
                    cycle[i] = true;
                }
            }
        }
        Arrays.fill(topcol, false);
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (!topcol[i]) {
                if (!compdfs2(i)) {
                    ans--;
                }
            }
        }
        out.println(ans);
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