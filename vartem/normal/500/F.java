import java.io.*;
import java.util.*;

public class F {

    FastScanner in;
    PrintWriter out;

    int MAX = 20100;
    int MAX2 = 4000;
    int INF = Integer.MIN_VALUE / 2;

    class Event implements Comparable<Event> {
        int time, type;
        int cost, hap;

        Event pair;

        public Event(int time, int type, int cost, int hap) {
            super();
            this.time = time;
            this.type = type;
            this.cost = cost;
            this.hap = hap;
        }

        @Override
        public int compareTo(Event o) {
            return type - o.type;
        }
    }

    int[][] buf;

    void solve(int l, int r, int level) {
        int[] cur = buf[level];
        int[] next = buf[level + 1];

        if (l + 1 == r) {
            for (int x = 0; x < open[l].size(); x++) {
                Event e = open[l].get(x);
                update(cur, e.cost, e.hap);
            }
            for (int x = 0; x < close[l].size(); x++) {
                Event e = close[l].get(x);
                update(cur, e.cost, e.hap);
            }
            for (int t = 0; t < qs[l].size(); t++) {
                Event e = qs[l].get(t);
                e.hap = cur[e.cost];
            }
            return;
        }

        int m = (l + r) >> 1;

        System.arraycopy(cur, 0, next, 0, cur.length);
        for (int t = m; t < r; t++) {
            for (int x = 0; x < close[t].size(); x++) {
                Event e = close[t].get(x);
                if (e.pair.time < l) {
                    update(next, e.cost, e.hap);
                }
            }
        }
        solve(l, m, level + 1);

        System.arraycopy(cur, 0, next, 0, cur.length);
        for (int t = l; t < m; t++) {
            for (int x = 0; x < open[t].size(); x++) {
                Event e = open[t].get(x);
                if (e.pair.time >= r) {
                    update(next, e.cost, e.hap);
                }
            }
        }
        solve(m, r, level + 1);

    }

    private void update(int[] next, int cost, int hap) {
        for (int t = MAX2; t >= cost; t--) {
            if (next[t - cost] + hap > next[t]) {
                next[t] = next[t - cost] + hap;
            }
        }
    }

    List<Event>[] open, close, qs;

    void solve() {
        int n = in.nextInt(), p = in.nextInt();

        open = new List[MAX];
        close = new List[MAX];
        qs = new List[MAX];
        for (int i = 0; i < qs.length; i++) {
            open[i] = new ArrayList<F.Event>();
            close[i] = new ArrayList<F.Event>();
            qs[i] = new ArrayList<F.Event>();
        }

        int[] c = new int[n], h = new int[n], t = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
            h[i] = in.nextInt();
            t[i] = in.nextInt() - 1;

            Event e1 = new Event(t[i], -1, c[i], h[i]);
            Event e2 = new Event(t[i] + p - 1, 1, c[i], h[i]);
            open[e1.time].add(e1);
            close[e2.time].add(e2);
            e1.pair = e2;
            e2.pair = e1;
        }

        int q = in.nextInt();
        int[] a = new int[q], b = new int[q];
        Event[] ans = new Event[q];
        for (int i = 0; i < q; i++) {
            a[i] = in.nextInt() - 1;
            b[i] = in.nextInt();

            Event e = new Event(a[i], 0, b[i], 0);
            ans[i] = e;
            qs[e.time].add(e);
        }

        buf = new int[20][MAX2 + 1];

        solve(0, MAX, 0);

        for (int i = 0; i < q; i++) {
            out.println(ans[i].hap);
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
        new F().run();
    }
}