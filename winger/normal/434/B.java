import java.io.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author winger
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static class F {
        boolean[][] f;
        int[][] a;

        F(int n, int m) {
            f = new boolean[n][m];
            a = new int[n][m];
        }

        void init() {
            for (int i = 0; i < a.length; ++i) {
                rebuild(i);
            }
        }

        private void rebuild(int i) {
            int prev = 0;
            for (int j = a[0].length - 1; j >= 0; --j) {
                a[i][j] = prev = f[i][j] ? prev + 1 : 0;
            }
        }

        void xor(int i, int j) {
            f[i][j] ^= true;
            rebuild(i);
        }

        int get(int i, int j) {
            if (!f[i][j]) {
                return 0;
            }
            int l = i, r = i;
            int ans = a[i][j];
            for (int w = a[i][j]; w >= 1; --w) {
                while (l > 0 && a[l - 1][j] >= w) {
                    --l;
                }
                while (r < a.length - 1 && a[r + 1][j] >= w) {
                    ++r;
                }
                ans = Math.max(ans, (r - l + 1) * w);
            }
            return ans;
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int q = in.nextInt();
        F f1 = new F(n, m), f2 = new F(m, n), f3 = new F(n, m), f4 = new F(m, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                f1.f[i][j] = f2.f[j][n - i - 1] = f3.f[n - i - 1][m - j - 1] = f4.f[m - j - 1][i] = in.nextInt() == 1;
            }
        }
        f1.init();
        f2.init();
        f3.init();
        f4.init();
        for (int it = 0; it < q; ++it) {
            if (in.nextInt() == 1) {
                int i = in.nextInt() - 1;
                int j = in.nextInt() - 1;
                f1.xor(i, j);
                f2.xor(j, n - i - 1);
                f3.xor(n - i - 1, m - j - 1);
                f4.xor(m - j - 1, i);
            } else {
                int i = in.nextInt() - 1;
                int j = in.nextInt() - 1;
                int ans = f1.get(i, j);
                ans = Math.max(ans, f2.get(j, n - i - 1));
                ans = Math.max(ans, f3.get(n - i - 1, m - j - 1));
                ans = Math.max(ans, f4.get(m - j - 1, i));
                out.println(ans);
            }
        }
    }

}

class FastScanner {
        Reader in;
        StringBuilder sb = new StringBuilder();

        public FastScanner(InputStream in) {
            this.in = new InputStreamReader(in);
        }

        public FastScanner(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public String next() {
            try {
                sb.setLength(0);
                while (true) {
                    int c = in.read();
                    if (c == -1) {
                        return null;
                    }
                    if (" \n\r\t".indexOf(c) == -1) {
                        sb.append((char) c);
                        break;
                    }
                }
                while (true) {
                    int c = in.read();
                    if (c == -1 || " \n\r\t".indexOf(c) != -1) {
                        break;
                    }
                    sb.append((char) c);
                }
                return sb.toString();
            } catch (IOException e) {
                throw new AssertionError(e);
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

}