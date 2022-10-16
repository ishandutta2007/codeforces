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
        DTsiklicheskiiSdvig solver = new DTsiklicheskiiSdvig();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class DTsiklicheskiiSdvig {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n);
            int[] b = in.nextIntArray(n);

            if (a[n - 1] != b[n - 1]) {
                out.println("NO");
                return;
            }

            int posA = n - 2;
            int posB = n - 2;
            int[] needSkip = new int[n + 1];
            while (posA >= 0 || posB >= 0) {
                if (posA >= 0 && posB >= 0 && a[posA] == b[posB]) {
                    posA--;
                    posB--;
                    continue;
                }
                if (posB >= 0 && b[posB] == b[posB + 1]) {
                    needSkip[b[posB]]++;
                    posB--;
                    continue;
                }
                if (posA >= 0 && needSkip[a[posA]] > 0) {
                    needSkip[a[posA]]--;
                    posA--;
                    continue;
                }
                out.println("NO");
                return;
            }
            out.println("YES");
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

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }
}