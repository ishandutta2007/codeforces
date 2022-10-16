import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        E3SortirovkaSliyaniem solver = new E3SortirovkaSliyaniem();
        solver.solve(1, in, out);
        out.close();
    }

    static class E3SortirovkaSliyaniem {
        char[] c;
        int ptr;

        private void mergeSort(int l, int r) {
            if (r - l <= 1) {
                return;
            }
            int m = (l + r) >> 1;
            mergeSort(l, m);
            mergeSort(m, r);
            int i = l, j = m;
            while (i < m && j < r) {
                if (ptr < c.length) {
                    if (c[ptr++] == '0') {
                        i++;
                    } else {
                        j++;
                    }
                } else {
                    i++;
                }
            }
        }

        private void restoreAnswer(int[] a, int[] b, int l, int r) {
            if (r - l <= 1) {
                return;
            }
            int m = (l + r) >> 1;
            restoreAnswer(a, b, l, m);
            restoreAnswer(a, b, m, r);
            int i = l, j = m, k = l;
            while (i < m && j < r) {
                if (c[ptr++] == '0') {
                    b[k++] = a[i++];
                } else {
                    b[k++] = a[j++];
                }
            }
            while (i < m) {
                b[k++] = a[i++];
            }
            while (j < r) {
                b[k++] = a[j++];
            }
            System.arraycopy(b, l, a, l, r - l);
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            c = in.next().toCharArray();
            int left = 0, right = (int) 1e5;
            while (left < right - 1) {
                int mid = (left + right) >> 1;
                this.ptr = 0;
                mergeSort(0, mid);
                if (this.ptr < c.length) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            {
                this.ptr = 0;
                mergeSort(0, right);
                if (this.ptr != c.length) {
                    throw new AssertionError();
                }
                this.ptr = 0;
            }

            int n = right;
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = i;
            }
            int[] b = new int[n];
            restoreAnswer(a, b, 0, n);
            int[] result = new int[n];
            for (int i = 0; i < n; i++) {
                result[a[i]] = i + 1;
            }
            out.println(n);
            for (int i = 0; i < n; i++) {
                out.print(result[i] + " ");
            }
            out.println();
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
}