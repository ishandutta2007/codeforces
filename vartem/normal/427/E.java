import java.io.*;
import java.util.*;

public class E {

    public void solve() {
        int n = in.nextInt(), m = in.nextInt();

        long[] x = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
        }
        long sumL = 0, sumR = 0;

        int sizeL = 0, sizeR = n - 1;
        int countL = 0, countR = 0;

        for (int i = n - 1; i > 0; i -= m) {
            sumR += x[i];
            countR++;
        }

        long best = x[0];
        long bestCost = (x[0] * countL - sumL) + (sumR - x[0] * countR);

        for (int i = 1; i < n;i++) {
            sizeR--;

            if (sizeR % m == 0) {
                sumR -= x[i];
                countR--;
            }

            if (sizeL % m == 0) {
                countL++;
                sumL += x[i - 1];
            }
            sizeL++;

            long cur = x[i];
            long curCost = (x[i] * countL - sumL) + (sumR - x[i] * countR);
            if (curCost < bestCost) {
                best = cur;
                bestCost = curCost;
            }
        }

        out.println(2 * bestCost);
    }

    FastScanner in;
    PrintWriter out;

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String name) {
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new E().run();
    }
}