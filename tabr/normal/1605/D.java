import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        ArrayList[] g = new ArrayList[n];
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n - 1; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            x--;
            y--;
            g[x].add(y);
            g[y].add(x);
        }
        int[] que = new int[n];
        int[] c = new int[n];
        Arrays.fill(c, -1);
        Arrays.fill(que, -1);
        c[0] = 0;
        que[0] = 0;
        for (int i = 0, k = 1; i < n; i++) {
            int v = que[i];
            for (int j = 0; j < g[v].size(); j++) {
                int to = (int) g[v].get(j);
                if (c[to] == -1) {
                    c[to] = 1 - c[v];
                    que[k] = to;
                    k++;
                }
            }
        }
        int[] b = new int[20];
        int s = 0;
        int t = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i - 1] == 1) {
                s++;
            } else if (c[i - 1] == 0) {
                t++;
            }
            int k = i;
            int u = -1;
            while (k > 0) {
                k /= 2;
                u++;
            }
            b[u]++;
        }
        int[] d = new int[n];
        Arrays.fill(d, -1);
        for (int i = 19; i >= 0; i--) {
            if (b[i] == 0) {
                continue;
            }
            if (s > t) {
                s -= b[i];
                for (int j = 0; j < n; j++) {
                    if (c[j] == 1 && d[j] == -1 && b[i] > 0) {
                        d[j] = i;
                        b[i]--;
                    }
                }
            } else {
                t -= b[i];
                for (int j = 0; j < n; j++) {
                    if (c[j] == 0 && d[j] == -1 && b[i] > 0) {
                        d[j] = i;
                        b[i]--;
                    }
                }
            }
        }
        int[] f = new int[20];
        for (int i = 0; i < 20; i++) {
            f[i] = 1 << i;
        }
        for (int i = 0; i < n; i++) {
            assert (d[i] != -1);
            out.print(f[d[i]] + " ");
            f[d[i]]++;
        }
        out.println();
    }

    public static void main(String[] args) throws java.lang.Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        int tt = in.nextInt();
//        int tt = 1;
        for (int qq = 1; qq <= tt; qq++) {
            solve(in, out);
        }
        out.close();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}