import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        ReaderFastIO in = new ReaderFastIO(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        EYetAnotherBallProblem solver = new EYetAnotherBallProblem();
        solver.solve(1, in, out);
        out.close();
    }

    static class EYetAnotherBallProblem {
        public void solve(int testNumber, ReaderFastIO in, PrintWriter out) {

            int n = in.nextInt();
            long k = in.nextLong();

            if (n > (k * (k - 1))) {
                out.println("NO");
                return;
            }

            int ct = n;
            out.println("YES");
            for (int i = 1; i <= k; i++) {

                for (int j = i + 1; j <= k; j++) {

                    out.println(i + " " + j);
                    ct--;
                    if (ct == 0) return;

                    out.println(j + " " + i);
                    ct--;
                    if (ct == 0) return;
                }

            }

        }

    }

    static class ReaderFastIO {
        BufferedReader br;
        StringTokenizer st;

        public ReaderFastIO() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public ReaderFastIO(InputStream input) {
            br = new BufferedReader(new InputStreamReader(input));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}