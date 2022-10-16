import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
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
        GObrashenieStrokIStolbcov solver = new GObrashenieStrokIStolbcov();
        solver.solve(1, in, out);
        out.close();
    }

    static class GObrashenieStrokIStolbcov {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = in.nextInt();
                }
            }
            if (n == 1) {
                out.println("YES");
                out.println(0);
                for (int j = 0; j < m; j++) {
                    out.print(a[0][j]);
                }
                out.println();
                return;
            }

            if (m == 1) {
                out.println("YES");
                for (int j = 0; j < n; j++) {
                    out.print(a[j][0]);
                }
                out.println();
                out.println(0);
                return;
            }

            int[][] b = new int[n - 1][m - 1];
            int[][] c = new int[n - 1][m - 1];
            int cntDiff = 0;
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m - 1; j++) {
                    b[i][j] = a[i][j] ^ a[i + 1][j] ^ a[i + 1][j + 1] ^ a[i][j + 1];
                    if (b[i][j] != 0) {
                        cntDiff++;
                    }
                }
            }

            for (int pos = n * m; pos >= 0; pos--) {
                if (cntDiff == 0) {
                    printAnswer(a, pos, out);
                    return;
                }
                if (pos == 0) {
                    continue;
                }

                int row = (pos - 1) / m, col = (pos - 1) % m;
                for (int i = row; i >= row - 1; i--) {
                    for (int j = col; j >= col - 1; j--) {
                        if (0 <= i && i < n - 1 && 0 <= j && j < m - 1) {
                            c[i][j] ^= 1;
                            if (c[i][j] != b[i][j]) {
                                cntDiff++;
                            } else {
                                cntDiff--;
                            }
                        }
                    }
                }
            }
            out.println("NO");
        }

        private void printAnswer(int[][] a, int pos, PrintWriter out) {
            System.err.println(pos);
            int n = a.length, m = a[0].length;
            int[] row = new int[n], col = new int[m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int val = (i * m + j < pos) ? 0 : 1;
                    if ((a[i][j] ^ row[i] ^ col[j]) != val) {
                        if (i == 0) {
                            col[j] ^= 1;
                        } else {
                            row[i] ^= 1;
                        }
                    }
                }
            }

            out.println("YES");
            for (int i : row) {
                out.print(i);
            }
            out.println();
            for (int i : col) {
                out.print(i);
            }
            out.println();
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

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
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}