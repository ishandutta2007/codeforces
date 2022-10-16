import java.io.*;
import java.util.*;

public class E {
    FastScanner in;
    PrintWriter out;

    class BIT {
        int[] tree;
        public BIT(int n) {
            tree = new int[n];
        }

        int get(int pos) {
            int res =0 ;
            while (pos >= 0) {
                res += tree[pos];
                pos = (pos & (pos + 1)) - 1 ;
            }
            return res;
        }

        void add(int pos, int val) {
            while (pos < tree.length) {
                tree[pos] += val;
                pos |= pos + 1;
            }
        }
    }

    class Query implements  Comparable<Query> {
        int type, time, value, id;

        public Query(int type, int time, int value, int id) {
            this.type = type;
            this.time = time;
            this.value = value;
            this.id = id;
        }

        @Override
        public int compareTo(Query o) {
            if (value != o.value) {
                return Integer.compare(value, o.value);
            }
            return Integer.compare(id, o.id);
        }
    }

    void solve() {
        int n = in.nextInt();

        Query[] a = new Query[n];
        Integer[] times = new Integer[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Query(in.nextInt(), in.nextInt(), in.nextInt(), i);
            times[i] = a[i].time;
        }
        Arrays.sort(times);
        for (int i = 0; i < n; i++) {
            a[i].time = Arrays.binarySearch(times, a[i].time);
        }

        Arrays.sort(a);
        int[] ans = new int[n];
        boolean[] output = new boolean[n];
        BIT tree = new BIT(n);
        for (int start = 0; start < n;) {
            int end = start;
            while (end < n && a[end].value == a[start].value) {
                end++;
            }

            for (int i = start; i < end; i++) {
                if (a[i].type == 1) {
                    tree.add(a[i].time, 1);
                } else if (a[i].type == 2) {
                    tree.add(a[i].time, -1);
                } else {
                    int id = a[i].id;
                    output[id] = true;
                    ans[id] = tree.get(a[i].time);
                }
            }
            for (int i = start; i < end; i++) {
                if (a[i].type == 1) {
                    tree.add(a[i].time, -1);
                } else if (a[i].type == 2) {
                    tree.add(a[i].time, 1);
                }
            }

            start = end;
        }

        for (int i = 0; i < n; i++) {
            if (output[i]) {
                out.println(ans[i]);
            }
        }
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
        new E().runIO();
    }
}