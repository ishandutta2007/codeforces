import java.io.*;
import java.util.*;

public class C {

    double[] T, u, v, dp, newDp;

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        double[] t = new double[n];
        for (int i = 0; i < n; i++) {
            t[i] = in.nextInt();
        }

        T = new double[n + 1];
        u = new double[n + 1];
        v = new double[n + 1];

        for (int i = 1; i <= n; i++) {
            u[i] = u[i - 1] + t[i - 1];
            v[i] = v[i - 1] + 1.0 / t[i - 1];
            T[i] = T[i - 1] + u[i] / t[i - 1];
        }

        dp = new double[n + 1];
        newDp = new double[n + 1];
        Arrays.fill(dp, Long.MAX_VALUE);
        dp[0] = 0;
        as = new double[n + 1];
        bs = new double[n + 1];

        for (int IT = 0; IT < k; IT++) {
            size = 0;
            addLine(u[0], T[0] - u[0] * v[0] - dp[0]);
            for (int i = 1; i <= n; i++) {
                newDp[i] = T[i] - getMax(v[i]);
                addLine(u[i], T[i] - u[i] * v[i] - dp[i]);
            }
            System.arraycopy(newDp, 0, dp, 0, dp.length);
            Arrays.fill(newDp, 0);
        }
        out.println(dp[n]);
    }

    double getMax(double v) {
        int left = 0, right = size - 1;
        while (left < right) {
            int mid = (left + right) >>> 1;
            double x = intersection(as[mid], bs[mid], as[mid + 1], bs[mid + 1]);
            if (v < x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return as[left] * v + bs[left];
    }

    int size;
    double[] as, bs;

    void addLine(double a, double b) {
        while (size > 1) {
            double x1 = intersection(as[size - 2], bs[size - 2], as[size - 1], bs[size - 1]);
            double x2 = intersection(as[size - 1], bs[size - 1], a, b);
            if (x1 < x2) {
                break;
            } else {
                size--;
            }
        }
        as[size] = a;
        bs[size] = b;
        size++;
    }

    double intersection(double a1, double b1, double a2, double b2) {
        return (b2 - b1) / (a1 - a2);
    }


    double getValue(int left, int right) {
//        System.err.println(left + " " + right + " " + (T[right] - T[left] - u[left] * (v[right] - v[left]) + dp[left]));
        return T[right] - T[left] - u[left] * (v[right] - v[left]) + dp[left];
    }

    public void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new C().run();
    }
}