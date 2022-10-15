import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
 
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author beginner1010
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
        final int Max = (int) (2 * (1e5) + 10);
        long[] tree;
 
        long read(int idx) {
            if (idx == 0)
                return 0;
            long res = 0;
            while (idx > 0) {
                res += tree[idx];
                idx -= (idx & (-idx));
            }
            return res;
        }
 
        void update(int idx, int value) {
            while (idx < Max) {
                tree[idx] += value;
                idx += (idx & (-idx));
            }
            return;
        }
 
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            tree = new long[Max];
            for (int i = 1; i <= n; i++) {
                update(i, i);
            }
 
            long[] s = new long[n];
            for (int i = 0; i < n; i++) {
                s[i] = in.nextLong();
            }
 
            int[] ans = new int[n];
            for (int i = n - 1; i >= 0; i--) {
                int lo = 1;
                int hi = n + 1;
                while (lo < hi) {
                    int mid = (lo + hi + 1) >> 1;
                    if (read(mid - 1) <= s[i]) {
                        lo = mid;
                    } else {
                        hi = mid - 1;
                    }
                }
                update(lo, -lo);
                ans[i] = lo;
            }
            for (int i = 0; i < n; i++) {
                if (i > 0)
                    out.print(" ");
                out.print(ans[i]);
            }
            out.println();
        }
 
    }
 
    static class InputReader {
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputStream stream;
 
        public InputReader(InputStream stream) {
            this.stream = stream;
        }
 
        private boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        private int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }
 
        public int nextInt() {
            int c = read();
            while (isWhitespace(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isWhitespace(c));
            return res * sgn;
        }
 
        public long nextLong() {
            int c = read();
            while (isWhitespace(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isWhitespace(c));
            return res * sgn;
        }
 
    }
}