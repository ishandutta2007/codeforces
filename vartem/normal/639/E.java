import java.io.*;
import java.util.*;

public class E {

    public void solve() {
        int n = in.nextInt();
        long[] p = new long[n], t = new long[n];
        Frac[] a = new Frac[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt();
        }
        long T = 0;
        for (int j = 0; j < n; j++) {
            t[j] = in.nextInt();
            T += t[j];
        }
        for (int i = 0; i < n; i++) {
            a[i] = new Frac(p[i], t[i]);
        }
        Arrays.sort(a);
        Pair[] pairs = new Pair[n];
        for (int i = 0; i < n; i++) {
            pairs[i] = new Pair(a[i].p);
        }
        Pair[] unsorted = pairs.clone();
        Arrays.sort(pairs);
        double left = 0, right = 1;
        for (int IT = 0; IT < 50; IT++) {
            double c = (left + right) / 2;
            long sum = 0;

            for (int i = 0; i < n; ) {
                int j = i;
                long curSum = 0;
                while (j < n && a[i].compareTo(a[j]) == 0) {
                    curSum += a[j].t;
                    j++;
                }

                for (int k = i; k < j; k++) {
                    unsorted[k].min = (1 - c * (sum + curSum) / T) * a[k].p;
                    unsorted[k].max = (1 - c * (sum + a[k].t) / T) * a[k].p;
                }
                sum += curSum;
                i = j;
            }
            boolean ok = true;
            double curMax = 0;
            for (int i = 0; i < n; ) {
                int j = i;
                while (j < n && pairs[i].key == pairs[j].key) {
                    j++;
                }

                for (int k = i; k < j; k++) {
                    if (pairs[k].min < curMax) {
                        ok = false;
                    }
                }
                for (int k = i; k < j; k++) {
                    curMax = Math.max(curMax, pairs[k].max);
                }
                i = j;
            }
            if (ok) {
                left = c;
            } else {
                right = c;
            }
        }
        out.println((left + right) / 2);
    }

    class Pair implements Comparable<Pair> {
        long key;
        double min, max;

        public Pair(long key) {
            this.key = key;
        }

        @Override
        public int compareTo(Pair o) {
            return Long.compare(key, o.key);
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "key=" + key +
                    ", min=" + min +
                    ", max=" + max +
                    '}';
        }
    }

    class Frac implements Comparable<Frac> {
        long p, t;

        public Frac(long p, long t) {
            this.p = p;
            this.t = t;
        }

        @Override
        public int compareTo(Frac o) {
            int cmp = -Long.signum(this.p * o.t - this.t * o.p);
            return cmp;
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