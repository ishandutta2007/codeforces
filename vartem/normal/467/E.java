import java.io.*;
import java.util.*;

public class E {

    public class SegmentTree {
        int[][] tree;
        int size;

        public SegmentTree(int[] a) {
            size = a.length;
            tree = new int[4 * size][];
            build(0, size, 0, a);
        }

        private void build(int l, int r, int i, int[] a) {
            tree[i] = Arrays.copyOfRange(a, l, r);
            Arrays.sort(tree[i]);
            if (l + 1 == r) {
                return;
            }

            int m = (l + r) >> 1;
            build(l, m, 2 * i + 1, a);
            build(m, r, 2 * i + 2, a);
        }

        int get(int from, int to, int K) {
            return internalGet(0, size, from, to + 1, 0, K);
        }

        private int internalGet(int left, int right, int l, int r, int i, int K) {
            if (l <= left && right <= r) {
                return find(tree[i], K);
            } else if (right <= l || r <= left) {
                return -1;
            } else {
                int mid = (left + right) >> 1;
                int ans1 = internalGet(left, mid, l, r, 2 * i + 1, K);
                int ans2 = internalGet(mid, right, l, r, 2 * i + 2, K);
                return Math.max(ans1, ans2);
            }
        }

        private int find(int[] a, int k) {
            int l = -1, r = a.length;
            while (l < r - 1) {
                int m = (l + r) >> 1;
                if (a[m] > k) {
                    r = m;
                } else {
                    l = m;
                }
            }
            if (l == -1) {
                return -1;
            }
            return a[l];
        }
    }

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();

        int[] dp = new int[n + 1];
        int[] prev = new int[n + 1];

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        int[] all = a.clone();
        Arrays.sort(all);
        for (int i = 0; i < n; i++) {
            a[i] = Arrays.binarySearch(all, a[i]);
        }

        int[] last = new int[n];
        int[] last2 = new int[n];
        Arrays.fill(last, -1);

        for (int i = 0; i < n; i++) {
            last2[i] = last[a[i]];
            last[a[i]] = i;
        }

        List<Integer>[] occ = new List[n];
        for (int i = 0; i < n; i++) {
            occ[i] = new ArrayList<>();
        }
        SegmentTree st = new SegmentTree(last2);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            prev[i] = i - 1;

            int val = a[i - 1];
            occ[val].add(i - 1);

            if (occ[val].size() >= 4) {
                int prev4 = occ[val].get(occ[val].size() - 4);
                if (dp[prev4] + 1 > dp[i]) {
                    dp[i] = dp[prev4] + 1;
                    prev[i] = prev4;
                }
            }

            if (occ[val].size() >= 2) {
                int from = occ[val].get(occ[val].size() - 2) + 1;
                int to = i - 2;
                if (from <= to) {
                    int pos = st.get(from, to, from - 1);
                    if (pos != -1 && dp[pos] + 1 > dp[i]) {
                        dp[i] = dp[pos] + 1;
                        prev[i] = pos;
                    }
                }
            }
        }

        List<Integer> ans = new ArrayList<>();

        int cur = n;
        while (cur > 0) {
            if (prev[cur] == cur - 1) {
            } else {
                int val2 = all[a[cur - 1]];
                int val1 = all[a[prev[cur]]];
                ans.add(val2);
                ans.add(val1);
                ans.add(val2);
                ans.add(val1);
            }
            cur = prev[cur];
        }

        Collections.reverse(ans);
        out.println(ans.size());
        for (int i = 0; i < ans.size(); i++) {
            out.print(ans.get(i) + " ");
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
        new E().run();
    }
}