import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        GPesniSiren solver = new GPesniSiren();
        solver.solve(1, in, out);
        out.close();
    }

    static class GPesniSiren {
        int mod = 1000000007;
        long mod2 = (long) mod * mod;
        boolean[] hasPref = new boolean[1_001_000];
        boolean[] hasSuf = new boolean[1_001_000];
        int[] pref = new int[2_001_000];

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), q = in.nextInt();
            char[][] s = new char[n + 1][];
            s[0] = in.next().toCharArray();
            char[] t = in.next().toCharArray();
            int cur = 0;
            while (cur < t.length && s[cur].length < 1e6) {
                int len = s[cur].length;
                s[cur + 1] = new char[len * 2 + 1];
                System.arraycopy(s[cur], 0, s[cur + 1], 0, len);
                s[cur + 1][len] = t[cur];
                System.arraycopy(s[cur], 0, s[cur + 1], len + 1, s[cur].length);
                cur++;
            }

            int[] ans = new int[q];
            int[] pow2 = new int[n + 1];
            pow2[0] = 1;
            for (int i = 1; i <= n; i++) {
                pow2[i] = 2 * pow2[i - 1] % mod;
            }
            List<Event>[] events = Utils.listArray(n + 1);
            int[][] weights = new int[q][];
            for (int query = 0; query < q; query++) {
                int k = in.nextInt();
                char[] c = in.next().toCharArray();
                int start = 0;
                while (start <= n && s[start].length < c.length) {
                    start++;
                }
                if (start <= k) {
                    ans[query] = (int) ((long) pow2[k - start] * count(c, s[start]) % mod);
                    weights[query] = getWeights(c, s[start]);
                    events[start].add(new Event(query, mod - pow2[k - start]));
                    events[k].add(new Event(query, 1));
                }
            }

            int[] curWeights = new int[26];
            for (int i = 0; i <= n; i++) {
                for (Event e : events[i]) {
                    int[] tmpW = weights[e.query];
                    long add = 0;
                    for (int j = 0; j < 26; j++) {
                        add += e.coef * tmpW[j] % mod * curWeights[j] % mod;
                        if (add >= mod2) {
                            add -= mod2;
                        }
                    }
                    ans[e.query] = (int) ((ans[e.query] + add) % mod);
                }
                if (i == n) {
                    break;
                }
                for (int j = 0; j < 26; j++) {
                    curWeights[j] *= 2;
                    if (curWeights[j] >= mod) {
                        curWeights[j] -= mod;
                    }
                }
                curWeights[t[i] - 'a']++;
            }
            for (int i : ans) {
                out.println(i % mod);
            }
        }

        private int[] getWeights(char[] query, char[] s) {
            int[] weights = new int[26];
            Arrays.fill(hasPref, 0, query.length, false);
            Arrays.fill(hasSuf, 0, query.length, false);
            { // query # s
                int k = kmpLoop(query, s);
                while (true) {
                    hasPref[k] = true;
                    if (k == 0) {
                        break;
                    }
                    k = pref[k - 1];
                }
            }
            { // s # query
                buildPref(s);
                int k = kmpLoop(s, query);
                while (true) {
                    hasSuf[k] = true;
                    if (k == 0) {
                        break;
                    }
                    k = pref[k - 1];
                }
            }
            for (int i = 0; i < query.length; i++) {
                if (hasPref[i] && hasSuf[query.length - i - 1]) {
                    weights[query[i] - 'a']++;
                }
            }
            return weights;
        }

        private int kmpLoop(char[] query, char[] s) {
            int k = 0;
            for (char c : s) {
                while (k > 0 && c != query[k]) {
                    k = pref[k - 1];
                }
                if (c == query[k]) {
                    k++;
                }
                if (k == query.length) {
                    k = pref[k - 1];
                }
            }
            return k;
        }

        private int count(char[] query, char[] s) {
            buildPref(query);
            int result = 0;
            int k = 0;
            for (char c : s) {
                while (k > 0 && c != query[k]) {
                    k = pref[k - 1];
                }
                if (c == query[k]) {
                    k++;
                }
                if (k == query.length) {
                    result++;
                    k = pref[k - 1];
                }
            }
            return result;
        }

        private void buildPref(char[] query) {
            pref[0] = 0;
            for (int i = 1; i < query.length; i++) {
                int k = pref[i - 1];
                while (k > 0 && query[i] != query[k]) {
                    k = pref[k - 1];
                }
                if (query[i] == query[k]) {
                    k++;
                }
                pref[i] = k;
            }
        }

        class Event {
            int query;
            long coef;

            public Event(int query, int coef) {
                this.query = query;
                this.coef = coef;
            }

        }

    }

    static class FastScanner {
        public BufferedReader br;
        public StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                    throw new UnknownError();
                }
                if (line == null) {
                    throw new UnknownError();
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }

    static class Utils {
        public static <T> List<T>[] listArray(int size) {
            List<T>[] result = new List[size];
            for (int i = 0; i < size; i++) {
                result[i] = new ArrayList<>();
            }
            return result;
        }

    }
}