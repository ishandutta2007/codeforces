import java.io.*;
import java.util.StringTokenizer;

public class CF269A {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = in.nextInt();
            int a = in.nextInt();
            ans = Math.max(ans, k + 1);
            while (ans <= k + 31 && a > 1L << (2 * (ans - k))) {
                ++ans;
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