import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
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
        EBloknotexe solver = new EBloknotexe();
        solver.solve(1, in, out);
        out.close();
    }

    static class EBloknotexe {
        FastScanner in;
        PrintWriter out;
        int n;
        int qCount = 0;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            this.in = in;
            this.out = out;
            n = in.nextInt();

            int left = (1 + 1) * n - 2, right = (2000 + 1) * n - 1;
            while (left < right - 1) {
                int mid = (left + right) >>> 1;
                if (ask(mid) == 1) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            int sumL = right - (n - 1);
            long ans = right;
            for (int h = 1; h <= n; h++) {
                int w = (sumL + n - h + h - 1) / h;
                ans = Math.min(ans, (long) w * ask(w));
            }

            out.println("! " + ans);
            out.flush();
        }

        int ask(int w) {
            qCount++;
            out.println("? " + w);
            out.flush();
            int h = in.nextInt();
            if (h == 0) {
                h = Integer.MAX_VALUE;
            }
            return h;
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

    }
}