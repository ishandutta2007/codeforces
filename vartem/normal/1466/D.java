import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        DTrinadtsatiiPodvigGerakla solver = new DTrinadtsatiiPodvigGerakla();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class DTrinadtsatiiPodvigGerakla {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] w = in.nextIntArray(n);
            Vertex[] v = new Vertex[n];
            for (int i = 0; i < n; i++) {
                v[i] = new Vertex(w[i], 0);
            }
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                v[a].deg++;
                v[b].deg++;
            }
            Arrays.sort(v, (o1, o2) -> -Integer.compare(o1.i, o2.i));

            long[] result = new long[n];
            for (int i = 0; i < n; i++) {
                result[1] += w[i];
            }
            out.print(result[1] + " ");
            int ptr = 0;
            for (int k = 2; k < n; k++) {
                while (v[ptr].deg == 1) {
                    ptr++;
                }
                v[ptr].deg--;
                result[k] = result[k - 1] + v[ptr].i;
                out.print(result[k] + " ");
            }
            out.println();

        }

        class Vertex {
            int i;
            int deg;

            public Vertex(int i, int deg) {
                this.i = i;
                this.deg = deg;
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

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }
}