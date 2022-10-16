import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.FileNotFoundException;
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
        CISchastlivoDolgoZhiliIOni solver = new CISchastlivoDolgoZhiliIOni();
        solver.solve(1, in, out);
        out.close();
    }

    static class CISchastlivoDolgoZhiliIOni {
        int[] perm;
        boolean[] used;
        int[] last;

        int f(int a, int[] perm) {
            int result = 0;
            for (int i = 0; i < 6; i++) {
                result |= ((a >> perm[i]) & 1) << i;
            }
            return result;
        }

        void go(int pos) {
            if (pos == 6) {
                if (f(2, perm) == 2 && f(5, perm) == 24 && f(35, perm) == 50) {
                    last = perm.clone();
                    System.err.println(Arrays.toString(perm));
                }
                return;
            }
            for (int i = 0; i < 6; i++) {
                if (!used[i]) {
                    used[i] = true;
                    perm[pos] = i;
                    go(pos + 1);
                    used[i] = false;
                }
            }
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            perm = new int[6];
            used = new boolean[6];
            go(0);
            out.println(f(in.nextInt(), last));
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

    }
}