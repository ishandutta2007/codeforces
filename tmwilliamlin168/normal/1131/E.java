import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author prakharjain
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        EStringMultiplication solver = new EStringMultiplication();
        solver.solve(1, in, out);
        out.close();
    }

    static class EStringMultiplication {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();

            String[] p = new String[n];

            for (int i = 0; i < n; i++) {
                p[i] = in.next();
            }

            long ans = 0;

            for (char ch = 'a'; ch <= 'z'; ch++) {
                int rv = 0;
                long pmax = 0;
                for (int i = 0; i < p[0].length(); i++) {
                    if (p[0].charAt(i) == ch) {
                        rv++;
                        pmax = Math.max(pmax, rv);
                    } else {
                        rv = 0;
                    }
                }

                for (int i = 1; i < n; i++) {
                    int pre = 0;
                    int suf = 0;
                    int max = 0;

                    int len = p[i].length();
                    rv = 0;

                    for (int j = 0; j < len; j++) {
                        if (p[i].charAt(j) == ch) {
                            pre++;
                        } else {
                            break;
                        }
                    }

                    for (int j = len - 1; j >= 0; j--) {
                        if (p[i].charAt(j) == ch) {
                            suf++;
                        } else {
                            break;
                        }
                    }

                    for (int j = 0; j < len; j++) {
                        if (p[i].charAt(j) == ch) {
                            rv++;
                            max = Math.max(max, rv);
                        } else {
                            rv = 0;
                        }
                    }

                    if (pre == len) {
                        pmax = Math.min(1000000000, (pmax + 1) * len + pmax);
                    } else {
                        if (pmax > 0)
                            pmax = Math.max(max, pre + suf + 1);
                        else pmax = max;
                    }
                }

                ans = Math.max(ans, pmax);
            }

            out.println(ans);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public String nextString() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            StringBuilder res = new StringBuilder();
            do {
                if (Character.isValidCodePoint(c)) {
                    res.appendCodePoint(c);
                }
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public String next() {
            return nextString();
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}