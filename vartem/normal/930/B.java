import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            char[] c = in.next().toCharArray();
            int[] count = new int[26];
            for (char ch : c) {
                count[ch - 'a']++;
            }
            double ans = 0;
            int n = c.length;
            int[][][] a = new int[26][26][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) {
                        continue;
                    }
                    int d = (j - i);
                    if (d < 0) {
                        d += n;
                    }
                    a[c[i] - 'a'][c[j] - 'a'][d]++;
                }
            }
            for (int i = 0; i < 26; i++) {
                double max = 0;
                for (int j = 1; j < n; j++) {
                    int cnt = 0;
                    for (int t = 0; t < 26; t++) {
                        if (a[i][t][j] == 1) {
                            cnt++;
                        }
                    }
                    max = Math.max(max, cnt);
                }
                ans += 1.0 * max / n;
            }
            out.println(ans);
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
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

    }
}