import java.io.*;
import java.util.*;

public class E {

    public void solve() {
        int n = in.nextInt();
        Item[] x = new Item[n];
        for (int i = 0; i < n; i++) {
            x[i] = new Item(in.nextLong(), i);
        }
        int k = in.nextInt();
        Arrays.sort(x);

        long[] pref = new long[n];
        for (int i = 0; i < n; i++) {
            pref[i] = x[i].x;
            if (i > 0) {
                pref[i] += pref[i - 1];
            }
        }

        long curAns = 0;

        for (int i = 1; i < k; i++) {
            curAns += x[i].x * i - pref[i - 1];
        }

        int best = 0;
        long bestAns = curAns;

        for (int i = k; i < n; i++) {
            long sum = getSum(pref, i - k + 1, i - 1);
            long add = x[i].x * (k - 1) - sum;
            curAns += add;
            long sub = sum - (k - 1) * x[i - k].x;
            curAns -= sub;
        
            if (curAns < bestAns) {
                best = i - k + 1;
                bestAns = curAns;
            }
        }
        
        for (int i = 0; i < k; i++) {
            out.print((x[best + i].id + 1) + " ");
        }
    }

    long getSum(long[] p, int l, int r) {
        long res = p[r];
        if (l > 0) {
            res -= p[l - 1];
        }
        return res;
    }

    class Item implements Comparable<Item> {
        long x;
        int id;

        public Item(long x, int id) {
            super();
            this.x = x;
            this.id = id;
        }

        public int compareTo(Item other) {
            return Long.compare(x, other.x);
        }
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