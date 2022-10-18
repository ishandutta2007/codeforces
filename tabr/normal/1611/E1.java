import java.lang.reflect.Array;
import java.text.CollationElementIterator;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void solve(InputReader in, PrintWriter out) {
        int n = in.readInt();
        int k = in.readInt();
        int[] x = new int[k];
        for (int i = 0; i < k; i++) {
            x[i] = in.readInt();
            x[i]--;
        }
        int[][] g = new int[n][];
        {
            int[] tmp = new int[n];
            int[] u = new int[n - 1];
            int[] v = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                u[i] = in.readInt();
                v[i] = in.readInt();
                u[i]--;
                v[i]--;
                tmp[u[i]]++;
                tmp[v[i]]++;
            }
            for (int i = 0; i < n; i++) {
                g[i] = new int[tmp[i]];
            }
            for (int i = 0; i < n - 1; i++) {
                g[u[i]][--tmp[u[i]]] = v[i];
                g[v[i]][--tmp[v[i]]] = u[i];
            }
        }
        int[] que = new int[n];
        int id = 1;
        int[] d = new int[n];
        Arrays.fill(d, -1);
        d[0] = 0;
        for (int i = 0; i < n; i++) {
            int v = que[i];
            for (int to : g[v]) {
                if (d[to] == -1) {
                    d[to] = d[v] + 1;
                    que[id++] = to;
                }
            }
        }
        int[] e = new int[n];
        Arrays.fill(e, -1);
        for (int i = 0; i < k; i++) {
            que[i] = x[i];
            e[x[i]] = 0;
        }
        id = k;
        for (int i = 0; i < n; i++) {
            int v = que[i];
            for (int to : g[v]) {
                if (e[to] == -1) {
                    e[to] = e[v] + 1;
                    que[id++] = to;
                }
            }
        }
        boolean[] ok = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (d[i] < e[i]) {
                ok[i] = true;
            } else {
                ok[i] = false;
            }
        }
        id = 1;
        Arrays.fill(que, -1);
        que[0] = 0;
        String ans = "NO";
        for (int i = 0; i < n; i++) {
            int v = que[i];
            if (v == -1) {
                break;
            }
            if (v != 0 && g[v].length == 1) {
                ans = "YES";
            }
            for (int to : g[v]) {
                if (d[to] > d[v] && ok[to]) {
                    que[id++] = to;
                }
            }
        }
        out.println(ans);
    }

    public static void main(String[] args) throws java.lang.Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        int tt = in.readInt();
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

        public String read() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int readInt() {
            return Integer.parseInt(read());
        }

        public long readLong() {
            return Long.parseLong(read());
        }

        public double readDouble() {
            return Double.parseDouble(read());
        }
    }
}