import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
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
        BUluchsheniyaVPoslednyuyuMinutu solver = new BUluchsheniyaVPoslednyuyuMinutu();
        solver.solve(1, in, out);
        out.close();
    }

    static class BUluchsheniyaVPoslednyuyuMinutu {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int t = in.nextInt();
            while (t-- > 0) {
                int n = in.nextInt();
                int[] a = in.nextIntArray(n);
                int[] count = new int[2 * n + 1];
                for (int i : a) {
                    count[i - 1]++;
                }
                int ans = 0;
                int carry = 0;
                for (int i = 0; i < count.length; i++) {
                    if (count[i] == 0) {
                        if (carry > 0) {
                            ans++;
                        }
                        carry = 0;
                    } else {
                        ans++;
                        if (count[i] > 1 || count[i] == 1 && carry == 1) {
                            carry = 1;
                        } else {
                            carry = 0;
                        }
                    }
                }
                out.println(ans);
            }
        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

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
                    throw new UnknownError();
                }
                if (line == null) {
                    throw new UnknownError();
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }
}