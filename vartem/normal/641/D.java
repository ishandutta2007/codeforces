import java.io.*;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    double[] solveQuad(double a, double b, double c) {
        double d = b * b - 4 * a * c;
        if (d < -1e-10) {
            throw new AssertionError();
        }
        d = Math.sqrt(Math.max(d, 0));
        return new double[] {(-b - d) / 2 / a, (-b + d) / 2 / a};
    }

    double[] findSolution(double sum, double prod) {
        return solveQuad(1, -sum, prod);
    }

    void solve() {
        int n = in.nextInt();
        double[] max = new double[n], min = new double[n];

        double[] pA = new double[n], pB = new double[n];
        for (int i = 0; i < n; i++) {
            max[i] = in.nextDouble();
        }
        for (int i = 0; i < n; i++) {
            min[i] = in.nextDouble();
        }

        double a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            double sum = min[i] + max[i] + a + b;
            double prod = max[i] + a * b;
            double[] sols = findSolution(sum, prod);

            pA[i] = sols[0] - a;
            pB[i] = sols[1] - b;

            a += pA[i];
            b += pB[i];
        }

        for (int i =0; i < n; i++) {
            out.print(pA[i] + " ");
        }
        out.println();
        for (int i =0; i < n; i++) {
            out.print(pB[i] + " ");
        }
        out.println();

    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new D().runIO();
    }
}