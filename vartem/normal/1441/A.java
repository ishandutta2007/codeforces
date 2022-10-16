import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.io.FileNotFoundException;
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
        AVosstanovlenieOperatsii solver = new AVosstanovlenieOperatsii();
        solver.solve(1, in, out);
        out.close();
    }

    static class AVosstanovlenieOperatsii {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int t = in.nextInt();
            while (t-- > 0) {
                int n = in.nextInt(), k = in.nextInt();
                int[] a = in.nextIntArray(n);
                int[] pos = new int[n];
                for (int i = 0; i < n; i++) {
                    pos[a[i] - 1] = i;
                }
                int[] b = in.nextIntArray(k);
                boolean[] used = new boolean[n];
                for (int i = 0; i < k; i++) {
                    used[b[i] - 1] = true;
                }
                int ans = 1;
                int mod = 998244353;
                TreeSet<Integer> free = new TreeSet<>();
                for (int i = 0; i < n; i++) {
                    free.add(i);
                }
                for (int i = 0; i < k; i++) {
                    int p = pos[b[i] - 1];
                    int cnt = 0;
                    Integer left = free.lower(p), right = free.higher(p);
                    if (left != null && !used[a[left] - 1]) {
                        cnt++;
                    }
                    if (right != null && !used[a[right] - 1]) {
                        cnt++;
                    }
                    ans = (ans * cnt) % mod;
                    used[b[i] - 1] = false;
                }
                out.println(ans);
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
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }
}