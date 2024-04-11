import java.io.*;
import java.util.Arrays;

public class CF626D {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        double[] p = new double[5001];
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                p[a[j] - a[i]] += 2.0 / n / (n - 1);
            }
        }
        double[] p2 = new double[10001];
        for (int i = 1; i <= 5000; ++i) {
            for (int j = 1; j <= 5000; ++j) {
                p2[i + j] += p[i] * p[j];
            }
        }
        double ans = 0, sum = 0;
        for (int i = 1; i <= 5000; ++i) {
            ans += sum * p[i];
            sum += p2[i];
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