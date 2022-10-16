import java.io.*;
import java.util.*;

public class F {

    int[] chooseK;
    int[] diff;

    final int MAX = 1000000;
    final int MOD = 1_000_000_007;

    int[][] divs;
    int[] mobius = new int[MAX + 1];


    void prepare(int n, int k) {
        int[] deg = new int[MAX + 1];
        for (int i = 1; i <= MAX; i++) {
            for (int j = i; j <= MAX; j += i) {
                deg[j]++;
            }
        }
        divs = new int[MAX + 1][];
        for (int i = 1; i <= MAX; i++) {
            divs[i] = new int[deg[i]];
        }
        for (int i = 1; i <= MAX; i++) {
            for (int j = i; j <= MAX; j += i) {
                divs[j][--deg[j]] = i;
            }
        }
        mobius[1] = 1;
        for (int i = 2; i <= MAX; i++) {
            for (int t : divs[i]) {
                if (t != i) {
                    mobius[i] -= mobius[t];
                }
            }
        }
//        System.err.println(Arrays.toString(Arrays.copyOf(mobius, 100)));

        chooseK = new int[300000 + 1];
        diff = new int[300000 + 1];
        chooseK[k] = 1;
        diff[k] = 1;
        for (int i = k + 1; i <= 300000; i++) {
            chooseK[i] = (int) ((long) chooseK[i - 1] * i % MOD * inv(i - k) % MOD);
            diff[i] = (chooseK[i] - chooseK[i - 1] + MOD) % MOD;
        }
    }

    int inv(int x) {
        int result = 1, n = MOD - 2;
        while (n > 0) {
            if (n % 2 == 1) {
                result = (int) ((1L * result * x) % MOD);
            }
            x = (int) ((1L * x * x) % MOD);
            n >>>= 1;
        }
        return result;
    }

    long answer = 0;
    int[] count = new int[MAX + 1];
    int[] value = new int[MAX + 1];
    int[] newValue = new int[MAX + 1];

    void addNumber(int x) {
        for (int t = 0; t < divs[x].length; t++) {
            int div = divs[x][t];
            newValue[div] = value[div];
        }
        for (int t = 0; t < divs[x].length; t++) {
            int div = divs[x][t];

            count[div]++;
            newValue[div] += diff[count[div]];
            if (newValue[div] >= MOD) {
                newValue[div] -= MOD;
            }
            int sub = (newValue[div] - value[div] + MOD) % MOD;

            for (int i = 0; i < divs[div].length; i++) {

                int div2 = divs[div][i];
                if (div2 == div) {
                    continue;
                }
                newValue[div2] = (newValue[div2] - sub);
                if (newValue[div2] < 0) {
                    newValue[div2] += MOD;
                }
            }
        }

        for (int t = 0; t < divs[x].length; t++) {
            int div = divs[x][t];
            long change = 1L * (newValue[div] - value[div] + MOD) * div;
            answer = (answer + change) % MOD;
            value[div] = newValue[div];
        }
    }

    public void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int q = in.nextInt();
        prepare(n, k);
        for (int i = 0; i < n; i++) {
            addNumber(in.nextInt());
        }
        for (int i = 0; i < q; i++) {
            addNumber(in.nextInt());
            out.println(answer);
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
        new F().run();
    }
}