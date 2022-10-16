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
        ARekomendatsii solver = new ARekomendatsii();
        solver.solve(1, in, out);
        out.close();
    }

    static class ARekomendatsii {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = in.nextIntArray(n), t = in.nextIntArray(n);
            long ans = 0;

            Value[] vals = new Value[n];
            for (int i = 0; i < n; i++) {
                vals[i] = new Value(i, a[i]);
            }
            Arrays.sort(vals);
            TreeSet<Value> set = new TreeSet<>();
            int pos = 0;
            int curTime = 0;
            long sumInSet = 0;
            while (pos < n || set.size() > 0) {
                int next = pos;
                while (next < n && vals[next].val == curTime) {
                    set.add(new Value(vals[next].ind, t[vals[next].ind]));
                    sumInSet += t[vals[next].ind];
                    next++;
                }

                if (set.size() == 0) {
                    curTime = vals[pos].val;
                } else {
                    curTime++;
                    Value max = set.pollLast();
                    sumInSet -= max.val;
                    ans += sumInSet;
                }
                pos = next;
            }
            out.println(ans);
        }

        class Value implements Comparable<Value> {
            int ind;
            int val;

            public Value(int ind, int val) {
                this.ind = ind;
                this.val = val;
            }

            public int compareTo(Value value) {
                if (val != value.val) {
                    return Integer.compare(val, value.val);
                }
                return Integer.compare(ind, value.ind);
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