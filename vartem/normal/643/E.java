import java.io.*;
import java.util.*;

public class E {

    final int MAX = 85;

    double[][] prob;
    int[] parent;
    int n;

    public void solve() {
        int q = in.nextInt();
        int[] t = new int[q], v = new int[q];
        n = 1;
        for (int i = 0; i < q; i++) {
            t[i] = in.nextInt();
            v[i] = in.nextInt() - 1;
            if (t[i] == 1) {
                n++;
            }
        }

        parent = new int[n];
        parent[0] = -1;
        prob = new double[n][MAX];
        Arrays.fill(prob[0], 1);
        int last = 0;
        for (int i = 0; i < q; i++) {
            if (t[i] == 1) {
                last++;
                parent[last] = v[i];
            }
        }

        last = 0;
        for (int i = 0; i < q; i++) {
            if (t[i] == 1) {
                last++;
                addVertex(last);
            } else {
                double result = 0;
                double[] pr = prob[v[i]];
                for (int j = 0; j < MAX; j++) {
                    result += 1 - pr[j];
                }
                out.println(result);
            }
        }
    }

    private void addVertex(int v) {
        Arrays.fill(prob[v], 1);

        int p = parent[v];
        double last = 1;
        for (int i = 0; i < MAX; i++) {
            if (p == -1) {
                break;
            }
            double tmp = prob[p][i];
            prob[p][i] /= (0.5 + 0.5 * last);
            last = tmp;
            p = parent[p];
        }
        p = parent[v];

        last = 0;
        for (int i = 0; i < MAX; i++) {
            if (p == -1) {
                break;
            }
            prob[p][i] *= (0.5 + 0.5 * last);
            last = prob[p][i];
            p = parent[p];
        }
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
        new E().run();
    }
}