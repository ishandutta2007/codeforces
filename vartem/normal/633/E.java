import java.io.*;
import java.util.*;

public class E {
    FastScanner in;
    PrintWriter out;

    class SparseTable {
        int[][] table;

        final int LOG = 20;

        public SparseTable(int[] arr) {
            table = new int[LOG][arr.length];
            table[0] = arr.clone();

            for (int l = 1; l < LOG; l++) {
                for (int i = 0; i < arr.length; i++) {
                    table[l][i] = Math.min(table[l - 1][i], table[l - 1][Math.min(arr.length - 1, i + (1 << (l - 1)))]);
                }
            }
        }

        int get(int l, int r) {
            int d = 31 - Integer.numberOfLeadingZeros(r - l + 1);
            return Math.min(table[d][l], table[d][r - (1 << d) + 1]);
        }
    }

    double[] log;

    double logChoose(int n, int k) {
        return log[n] - log[k] - log[n - k];
    }

    void solve() {
        int n = in.nextInt(), k = in.nextInt();
        int[] v = new int[n], c = new int[n];
        for (int i = 0; i < n; i++) {
            v[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
        }

        int[] invV = new int[n];
        for (int i = 0; i < n; i++) {
            invV[i] = -100 * v[i];
        }

        SparseTable tableV = new SparseTable(invV), tableC = new SparseTable(c);

        double[] ans = new double[n];
        for (int i = 0; i < n; i++) {
            int left = i - 1, right = n;
            while (left < right - 1) {
                int mid = (left + right) >>> 1;

                int val1 = -tableV.get(i, mid), val2 = tableC.get(i, mid);
                if (val1 < val2) {
                    left = mid;
                } else {
                    right = mid;
                }
            }

            if (left != i - 1) {
                int val1 = -tableV.get(i, left), val2 = tableC.get(i, left);
                ans[i] = Math.max(ans[i], Math.min(val1, val2));
            }
            if (right != n) {
                int val1 = -tableV.get(i, right), val2 = tableC.get(i, right);
                ans[i] = Math.max(ans[i], Math.min(val1, val2));
            }
        }

        log = new double[n + 1];
        for (int i = 1; i <= n; i++) {
            log[i] = log[i - 1] + Math.log(i);
        }

        double result = 0;
        Arrays.sort(ans);
        for (int i = 0; i < ans.length; i++) {
            int rem = ans.length - i;
            if (rem < k) {
                break;
            }
            double logProb = logChoose(rem - 1, k - 1) - logChoose(n, k);
            result += Math.exp(logProb) * ans[i];
        }
        out.println(result);
    }


    void run() {
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
        new E().run();
    }
}