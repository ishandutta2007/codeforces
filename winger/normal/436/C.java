import java.io.*;
import java.util.Arrays;

public class cf436C {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int h = in.nextInt();
        int w = in.nextInt();
        int n = in.nextInt();
        int c = in.nextInt();
        char[][][] data = new char[n][h][];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < h; ++j) {
                data[i][j] = in.next().toCharArray();
            }
        }
        int[][] g = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                g[j][i] = g[i][j] = Math.min(h * w, hd(data[i], data[j]) * c);
            }
        }
        boolean[] col = new boolean[n];
        col[0] = true;
        int[] dists = new int[n];
        int[] ansx = new int[n];
        int[] ansp = new int[n];
        ansx[0] = 0;
        ansp[0] = -1;
        int ans = w * h;
        for (int i = 0; i < n; ++i) {
            dists[i] = g[0][i];
        }
        for (int it = 1; it < n; ++it) {
            int next = -1;
            for (int i = 0; i < n; ++i) {
                if (!col[i] && (next == -1 || dists[i] < dists[next])) {
                    next = i;
                }
            }
            ans += dists[next];
            ansx[it] = next;
            if (dists[next] == h * w) {
                ansp[it] = -1;
            } else {
                ansp[it] = -2;
                for (int i = 0; i < n; ++i) {
                    if (col[i] && dists[next] == g[i][next]) {
                        ansp[it] = i;
                        break;
                    }
                }
                if (ansp[it] == -2) {
                    throw new AssertionError();
                }
            }
            col[next] = true;
            for (int j = 0; j < n; ++j) {
                dists[j] = Math.min(dists[j], g[next][j]);
            }
        }
        out.println(ans);
        for (int i = 0; i < n; ++i) {
            out.println((ansx[i] + 1) + " " + (ansp[i] + 1));
        }
    }

    static int hd(char[][] a, char[][] b) {
        int r = 0;
        for (int i = 0; i < a.length; ++i) {
            for (int j = 0; j < a[0].length; ++j) {
                if (a[i][j] != b[i][j]) {
                    r++;
                }
            }
        }
        return r;
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