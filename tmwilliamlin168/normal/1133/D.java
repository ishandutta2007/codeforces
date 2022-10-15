import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Hashtable;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long a[] = new long[n];
            long b[] = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = in.nextLong();
            for (int i = 0; i < n; i++)
                b[i] = in.nextLong();
            long ans = 0;
            Hashtable<Long, Long> table = new Hashtable<>();
            long add = 0;
            for (int i = 0; i < n; i++) {
                long ai = a[i];
                long bi = b[i];
                if (ai == 0 && bi == 0) {
                    add++;
                    continue;
                }
                if (ai != 0) {
                    if (bi == 0)
                        put(table, 0);
                    else {
                        long code = code(-bi, ai);
                        put(table, code);
                    }
                }
            }
            for (long el : table.keySet()) {
                long amount = table.get(el);
                ans = Math.max(ans, amount);
            }
            out.println(ans + add);
        }

        private static void put(Hashtable<Long, Long> table, long el) {
            if (!table.containsKey(el))
                table.put(el, 1L);
            else {
                long amount = table.get(el);
                table.replace(el, amount + 1);
            }
        }

        private static long code(long num, long denom) {
            int c = 0;
            if (num < 0)
                c++;
            if (denom < 0)
                c++;
            num = Math.abs(num);
            denom = Math.abs(denom);
            long gcd = gcd(num, denom);
            num /= gcd;
            denom /= gcd;
            long size = (long) (1e+9);
            long code = (denom - 1) * size + num;
            if (c % 2 == 1)
                code *= -1;
            return code;
        }

        private static long gcd(long a, long b) {
            if (b == 0)
                return a;
            else
                return gcd(b, a % b);
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}