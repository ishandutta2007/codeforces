import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class DBS {

    FastScanner in;
    PrintWriter out;

    int MAX = 2000;

    void solve() {
        int m = in.nextInt();

        BitSet[] a = new BitSet[m];
        BitSet[] b = new BitSet[m];
        for (int i = 0; i < m; i++) {
            a[i] = new BitSet(MAX);
            b[i] = new BitSet(m);

            BigInteger big = new BigInteger(in.nextToken());
            for (int j = 0; j < MAX; j++) {
                a[i].set(j, big.testBit(j));
            }
            b[i].set(i, true);
        }

        int col = 0;
        for (int i = 0; i < m; i++) {

            int nonZero = -1;
            for (int j = 0; j < MAX; j++) {
                if (a[i].get(j)) {
                    nonZero = j;
                    break;
                }
            }

            if (nonZero == -1) {
                int cnt = 0;
                for (int j = 0; j < m; j++) {
                    if (b[i].get(j) && i != j) {
                        cnt++;
                    }
                }
                StringBuilder sb = new StringBuilder();
                sb.append(cnt);
                for (int j = 0; j < m; j++) {
                    if (b[i].get(j) && i != j) {
                        sb.append(' ').append(j);
                    }
                }
                out.println(sb);
                continue;
            }
            out.println(0);

            for (int t = 0; t < m; t++) {
                boolean tmp = a[t].get(col);
                a[t].set(col, a[t].get(nonZero));
                a[t].set(nonZero, tmp);
            }

            for (int t = i + 1; t < m; t++) {
                if (a[t].get(col)) {
                    a[t].xor(a[i]);
                    b[t].xor(b[i]);
                }
            }

            col++;
        }
    }

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
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
        new DBS().run();
    }
}