import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
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
        TaskG1 solver = new TaskG1();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG1 {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt(), q = in.nextInt();
            int[] a = in.nextIntArray(n);
            int max = 200000 + 1;
            int[] first = new int[max], last = new int[max], count = new int[max];
            for (int i = 0; i < n; i++) {
                if (count[a[i]] == 0) {
                    first[a[i]] = i;
                }
                last[a[i]] = i;
                count[a[i]]++;
            }
            int maxRight = 0;
            int curMax = 0;
            int lastLeft = 0;
            int ans = 0;
            for (int i = 0; i < n; i++) {
                maxRight = Math.max(last[a[i]], maxRight);
                curMax = Math.max(count[a[i]], curMax);
                if (maxRight == i) {
                    ans += i - lastLeft + 1 - curMax;
                    curMax = 0;
                    lastLeft = i + 1;
                }
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