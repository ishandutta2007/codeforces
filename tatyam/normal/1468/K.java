import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.CharBuffer;
import java.io.IOException;
import java.nio.charset.CharsetDecoder;
import java.nio.charset.StandardCharsets;
import java.nio.ByteBuffer;
import java.util.HashSet;
import java.io.UncheckedIOException;
import java.nio.charset.Charset;
import java.io.Writer;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner2 in = new LightScanner2(inputStream);
        LightWriter2 out = new LightWriter2(outputStream);
        KTheRobot solver = new KTheRobot();
        solver.solve(1, in, out);
        out.close();
    }

    static class KTheRobot {
        public void solve(int testNumber, LightScanner2 in, LightWriter2 out) {
            int testCases = in.ints();
            outer:
            for (int testCase = 1; testCase <= testCases; testCase++) {
                HashSet<KTheRobot.P> ps = new HashSet<>();
                char[] s = in.chars();
                {
                    int px = 0, py = 0;
                    for (char c : s) {
                        if (c == 'D') py--;
                        if (c == 'U') py++;
                        if (c == 'L') px--;
                        if (c == 'R') px++;
                        if (px != 0 || py != 0) ps.add(new KTheRobot.P(px, py));
                    }
                }

                for (KTheRobot.P p : ps) {
                    int px = 0, py = 0;
                    for (char c : s) {
                        int nx = px, ny = py;
                        if (c == 'D') ny--;
                        if (c == 'U') ny++;
                        if (c == 'L') nx--;
                        if (c == 'R') nx++;
                        if (p.x == nx && p.y == ny) continue;
                        px = nx;
                        py = ny;
                    }
                    if (px == 0 && py == 0) {
                        out.ans(p.x).ans(p.y).ln();
                        continue outer;
                    }
                }
                out.ans(0).ans(0).ln();
            }
        }

        private static class P {
            final int x;
            final int y;

            public P(int x, int y) {
                this.x = x;
                this.y = y;
            }

            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;

                KTheRobot.P p = (KTheRobot.P) o;

                if (x != p.x) return false;
                return y == p.y;
            }

            public int hashCode() {
                int result = x;
                result = 31 * result + y;
                return result;
            }

        }

    }

    static class LightScanner2 extends LightScannerAdapter {
        private static final int BUF_SIZE = 16 * 1024;
        private final InputStream stream;
        private final StringBuilder builder = new StringBuilder();
        private final byte[] buf = new byte[BUF_SIZE];
        private int ptr;
        private int len;

        public LightScanner2(InputStream stream) {
            this.stream = stream;
        }

        private int read() {
            if (ptr < len) return buf[ptr++];
            reload();
            if (len == -1) return -1;
            return buf[ptr++];
        }

        private void reload() {
            try {
                ptr = 0;
                len = stream.read(buf);
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
        }

        private void load(int n) {
            if (ptr + n <= len) return;
            System.arraycopy(buf, ptr, buf, 0, len - ptr);
            len -= ptr;
            ptr = 0;
            try {
                int r = stream.read(buf, len, BUF_SIZE - len);
                if (r == -1) return;
                len += r;
                if (len != BUF_SIZE) buf[len] = '\n';
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
        }

        private void skip() {
            while (len != -1) {
                while (ptr < len && isTokenSeparator(buf[ptr])) ptr++;
                if (ptr < len) return;
                reload();
            }
            throw new NoSuchElementException("EOF");
        }

        private void loadToken() {
            builder.setLength(0);
            skip();
            for (int b = read(); !isTokenSeparator(b); b = read()) {
                builder.appendCodePoint(b);
            }
        }

        public char[] chars() {
            loadToken();
            char[] res = new char[builder.length()];
            builder.getChars(0, builder.length(), res, 0);
            return res;
        }

        public int ints() {
            skip();
            load(12);
            int b = buf[ptr++];
            boolean negate;
            if (b == '-') {
                negate = true;
                b = buf[ptr++];
            } else negate = false;
            int x = 0;
            for (; !isTokenSeparator(b); b = buf[ptr++]) {
                if ('0' <= b && b <= '9') x = x * 10 + b - '0';
                else throw new NumberFormatException("Unexpected character '" + ((char) b) + "'");
            }
            return negate ? -x : x;
        }

        public void close() {
            try {
                stream.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }

        private static boolean isTokenSeparator(int b) {
            return b < 33 || 126 < b;
        }

    }

    static class LightWriter2 implements AutoCloseable {
        private static final int BUF_SIZE = 16 * 1024;
        private final OutputStream out;
        private final byte[] buf = new byte[BUF_SIZE];
        private int ptr;
        private boolean autoflush = false;
        private boolean breaked = true;

        public LightWriter2(OutputStream out) {
            this.out = out;
        }

        public LightWriter2(Writer out) {
            this.out = new LightWriter2.WriterOutputStream(out);
        }

        private void allocate(int n) {
            if (ptr + n <= BUF_SIZE) return;
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            if (BUF_SIZE < n) throw new IllegalArgumentException("Internal buffer exceeded");
        }

        public void close() {
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
                out.flush();
                out.close();
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
        }

        private static int countDigits(int l) {
            if (l >= 1000000000L) return 10;
            if (l >= 100000000L) return 9;
            if (l >= 10000000L) return 8;
            if (l >= 1000000L) return 7;
            if (l >= 100000L) return 6;
            if (l >= 10000L) return 5;
            if (l >= 1000L) return 4;
            if (l >= 100L) return 3;
            if (l >= 10L) return 2;
            return 1;
        }

        public LightWriter2 ans(int x) {
            allocate(12);
            if (!breaked) buf[ptr++] = ' ';
            breaked = false;

            if (x < 0) {
                buf[ptr++] = '-';
                x = -x;
            }
            int n = countDigits(x);
            for (int i = ptr + n - 1; ptr <= i; i--) {
                buf[i] = (byte) (x % 10 + '0');
                x /= 10;
            }
            ptr += n;

            return this;
        }

        public LightWriter2 ln() {
            allocate(1);
            buf[ptr++] = '\n';
            breaked = true;
            if (autoflush) {
                try {
                    out.flush();
                } catch (IOException ex) {
                    throw new UncheckedIOException(ex);
                }
            }
            return this;
        }

        private static class WriterOutputStream extends OutputStream {
            final Writer writer;
            final CharsetDecoder decoder;

            WriterOutputStream(Writer writer) {
                this.writer = writer;
                this.decoder = StandardCharsets.UTF_8.newDecoder();
            }

            public void write(int b) throws IOException {
                writer.write(b);
            }

            public void write(byte[] b) throws IOException {
                writer.write(decoder.decode(ByteBuffer.wrap(b)).array());
            }

            public void write(byte[] b, int off, int len) throws IOException {
                writer.write(decoder.decode(ByteBuffer.wrap(b, off, len)).array());
            }

            public void flush() throws IOException {
                writer.flush();
            }

            public void close() throws IOException {
                writer.close();
            }

        }

    }

    static abstract class LightScannerAdapter implements AutoCloseable {
        public abstract void close();

    }
}