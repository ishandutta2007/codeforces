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
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            char[][] s = new char[][]{in.next().toCharArray(), in.next().toCharArray()};
            for (char[] c : s) {
                for (int i = 0; i < c.length; i++) {
                    if (c[i] == 'C') {
                        c[i] = 'B';
                    }
                }
            }
            int q = in.nextInt();

            int[][][] count = new int[2][][];
            int[][] sufA = new int[2][];
            for (int i = 0; i < 2; i++) {
                count[i] = count(s[i]);
                sufA[i] = sufA(s[i]);
            }
            int[][] info = new int[2][3];
            for (int i = 0; i < q; i++) {
                int l1 = in.nextInt() - 1, r1 = in.nextInt();
                int l2 = in.nextInt() - 1, r2 = in.nextInt();

                info[0][0] = count[0][0][r1] - count[0][0][l1];
                info[0][1] = count[0][1][r1] - count[0][1][l1];
                info[0][2] = Math.min(sufA[0][r1 - 1], r1 - l1);

                info[1][0] = count[1][0][r2] - count[1][0][l2];
                info[1][1] = count[1][1][r2] - count[1][1][l2];
                info[1][2] = Math.min(sufA[1][r2 - 1], r2 - l2);
                out.print(can(info[0], info[1]) ? '1' : '0');
            }
        }

        private boolean can(int[] a, int[] b) {
            a[0] -= a[2];
            b[0] -= b[2];
            if (a[2] < b[2]) {
                return false;
            }
            if (a[2] % 3 == b[2] % 3) {
                if (can2(a, b)) {
                    return true;
                }
            }
            a[2]--;
            a[1] += 2;

            a[0] += a[2] - b[2];
            return can2(a, b);
        }

        private boolean can2(int[] a, int[] b) {
            if (a[0] < 0 || a[1] < 0) {
                return false;
            }
            if (a[1] > b[1]) {
                return false;
            }
            if (a[1] % 2 != b[1] % 2) {
                return false;
            }
            if (b[1] > a[1] && (a[0] + a[1] == 0)) {
                return false;
            }
            return true;
        }

        private int[] sufA(char[] chars) {
            int[] a = new int[chars.length];
            for (int i = 0; i < chars.length; i++) {
                if (chars[i] == 'A') {
                    a[i] = (i == 0 ? 0 : a[i - 1]) + 1;
                } else {
                    a[i] = 0;
                }
            }
            return a;
        }

        private int[][] count(char[] chars) {
            int[][] a = new int[2][chars.length + 1];
            for (int i = 0; i < chars.length; i++) {
                a[0][i + 1] += a[0][i];
                a[1][i + 1] += a[1][i];
                a[chars[i] - 'A'][i + 1]++;
            }
            return a;
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
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
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}