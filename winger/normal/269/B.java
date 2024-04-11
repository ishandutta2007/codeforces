import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CF269B {

    static class Plant implements Comparable<Plant> {
        int t;
        double pos;

        Plant(int t, double pos) {
            this.t = t;
            this.pos = pos;
        }

        @Override
        public int compareTo(Plant o) {
            return Double.compare(pos, o.pos);
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        Plant[] ps = new Plant[n];
        for (int i = 0; i < n; ++i) {
            ps[i] = new Plant(in.nextInt() - 1, in.nextDouble());
        }
        Arrays.sort(ps);
        int[][] d = new int[n + 1][m + 1];
        for (int[] ar : d) {
            Arrays.fill(ar, 1000000000);
        }
        d[0][0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i < n) {
                    d[i + 1][j] = Math.min(d[i + 1][j], d[i][j] + (ps[i].t == j ? 0 : 1));
                }
                d[i][j + 1] = Math.min(d[i][j + 1], d[i][j]);
            }
        }
        out.println(d[n][m]);
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