import java.io.*;
import java.util.*;

public class D {

    int b;

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        int localB = in.nextInt(), localC = in.nextInt();
        this.b = Math.min(localB, 5 * localC);

        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = in.nextInt();
        }
        long result = Long.MAX_VALUE;
        Pair[] a = new Pair[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Pair(0, 0);
        }
        PriorityQueue<Pair> pairs = new PriorityQueue<>();
        for (int xmod5 = 0; xmod5 < 5; xmod5++) {
            for (int i = 0; i < n; i++) {
                int mod = ((t[i] % 5) + 5) % 5;
                if (mod <= xmod5) {
                    a[i].a = (xmod5 - mod) * localC;
                } else {
                    a[i].a = (xmod5 - mod + 5) * localC;
                }
                a[i].s = (t[i] + a[i].a / localC - xmod5) / 5;
            }
            Arrays.sort(a, new Comparator<Pair>() {
                @Override
                public int compare(Pair o1, Pair o2) {
                    return Long.compare(o1.s, o2.s);
                }
            });
            pairs.clear();
            long valSum = 0;
            for (int i = 0; i < n; i++) {
                pairs.add(a[i]);
                valSum += a[i].a - b * a[i].s;
                if (pairs.size() > k) {
                    Pair polled = pairs.poll();
                    valSum -= polled.a - b * polled.s;
                }
                if (pairs.size() == k) {
                    long curRes = b * a[i].s * k + valSum;
                    result = Math.min(result, curRes);
                }
            }
        }
        out.println(result);
    }

    class Pair implements Comparable<Pair> {
        long a, s;

        public Pair(long a, long s) {
            this.a = a;
            this.s = s;
        }

        @Override
        public int compareTo(Pair o) {
            return -Long.compare(a - b * s, o.a - b * o.s);
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "a=" + a +
                    ", s=" + s +
                    '}';
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
        new D().run();
    }
}