import java.io.*;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        int ans = 0;
        Set<Long> vis = new HashSet<>();
        Map<Long, Integer> multiset = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (!multiset.containsKey(a[i])) {
                multiset.put(a[i], 0);
            }
            multiset.put(a[i], multiset.get(a[i]) + 1);
        }

        long MAX = (long) 1e10;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                long mask = 1L * MAX * a[i] + a[j];
                if (vis.contains(mask)) {
                    continue;
                }
                vis.add(mask);

                int cur = 2;
                add(multiset, a[i], -1);
                add(multiset, a[j], -1);

                long a1 = a[i], a2 = a[j];
                while (true) {
                    long a3 = a1 + a2;
                    if (multiset.containsKey(a3) && multiset.get(a3) > 0) {
                        cur++;
                        add(multiset, a3, -1);
                        a1 = a2;
                        a2 = a3;
                    } else {
                        break;
                    }
                }
                ans = Math.max(ans, cur);
                a1 = a[i];
                a2 = a[j];
                add(multiset, a1, 1);
                add(multiset, a2, 1);
                for (int t = 2; t < cur; t++) {
                    long a3 = a1 + a2;
                    add(multiset, a3, 1);
                    a1 = a2;
                    a2 = a3;
                }
            }
        }
        out.println(ans);
    }

    private void add(Map<Long, Integer> multiset, long i, int delta) {
        multiset.put(i, multiset.get(i) + delta);
    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new D().runIO();
    }
}