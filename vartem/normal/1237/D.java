import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.io.FileNotFoundException;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Comparator;
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
        DSbalansirovanniiPleilist solver = new DSbalansirovanniiPleilist();
        solver.solve(1, in, out);
        out.close();
    }

    static class DSbalansirovanniiPleilist {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[3 * n];
            Value[] v = new Value[a.length];
            for (int i = 0; i < n; i++) {
                a[i] = a[i + n] = a[i + 2 * n] = in.nextInt();
                v[i] = new Value(a[i], i);
                v[i + n] = new Value(a[i + n], i + n);
                v[i + 2 * n] = new Value(a[i + n], i + 2 * n);
            }

            TreeSet<Integer> inserted = new TreeSet<>();
            Arrays.sort(v, Comparator.comparing(value -> -value.val));
            int j = 0;
            int[] prev = new int[3 * n];
            for (int i = 0; i < v.length; i++) {
                while (j < v.length && v[j].val > 2 * v[i].val) {
                    inserted.add(v[j].pos);
                    j++;
                }
                Integer p = inserted.lower(v[i].pos);
                prev[v[i].pos] = (p == null) ? -1 : p;
            }
            boolean all = true;
            for (int i = 0; i < prev.length; i++) {
                all &= prev[i] == -1;
            }
            if (all) {
                for (int i = 0; i < n; i++) {
                    out.print("-1 ");
                }
                out.println();
                return;
            }
            j = 0;
            for (int i = 0; i < n; i++) {
                while (j < prev.length && prev[j] < i) {
                    j++;
                }
                out.print((j - i) + " ");
            }
            out.println();
        }

        class Value {
            int val;
            int pos;

            public Value(int val, int pos) {
                this.val = val;
                this.pos = pos;
            }

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

    }
}