import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.nio.CharBuffer;
import java.io.IOException;
import java.nio.charset.CharsetDecoder;
import java.nio.charset.StandardCharsets;
import java.nio.ByteBuffer;
import java.io.UncheckedIOException;
import java.util.Objects;
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
        NWasteSorting solver = new NWasteSorting();
        solver.solve(1, in, out);
        out.close();
    }

    static class NWasteSorting {
        public void solve(int testNumber, LightScanner2 in, LightWriter2 out) {
            out.setBoolLabel(LightWriter2.BoolLabel.YES_NO_ALL_UP);
            int testCases = in.ints();
            outer:
            for (int testCase = 1; testCase <= testCases; testCase++) {
                long[] c = in.longs(3);
                for (int i = 0; i < 3; i++) {
                    c[i] -= in.longs();
                }
                long[] a = in.longs(2);
                for (int i = 0; i < 3; i++) {
                    if (c[i] < 0) {
                        out.noln();
                        continue outer;
                    }
                }
                for (int i = 0; i < 2; i++) {
                    long d = Math.min(c[i], a[i]);
                    c[i] -= d;
                    a[i] -= d;
                }
                out.ans(a[0] + a[1] <= c[2]).ln();
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

        public String string() {
            loadToken();
            return builder.toString();
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

        public long longs() {
            skip();
            load(20);
            int b = buf[ptr++];
            boolean negate;
            if (b == '-') {
                negate = true;
                b = buf[ptr++];
            } else negate = false;
            long x = 0;
            for (; !isTokenSeparator(b); b = buf[ptr++]) {
                if ('0' <= b && b <= '9') x = x * 10 + b - '0';
                else throw new NumberFormatException("Unexpected character '" + b + "'");
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
        private static final int BUF_THRESHOLD = 1024;
        private final OutputStream out;
        private final byte[] buf = new byte[BUF_SIZE];
        private int ptr;
        private boolean autoflush = false;
        private boolean breaked = true;
        private LightWriter2.BoolLabel boolLabel = LightWriter2.BoolLabel.YES_NO_FIRST_UP;

        public LightWriter2(OutputStream out) {
            this.out = out;
        }

        public LightWriter2(Writer out) {
            this.out = new LightWriter2.WriterOutputStream(out);
        }

        public void setBoolLabel(LightWriter2.BoolLabel label) {
            this.boolLabel = Objects.requireNonNull(label);
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

        public LightWriter2 print(char c) {
            allocate(1);
            buf[ptr++] = (byte) c;
            breaked = false;
            return this;
        }

        public LightWriter2 print(String s) {
            byte[] bytes = s.getBytes();
            int n = bytes.length;
            if (n <= BUF_THRESHOLD) {
                allocate(n);
                System.arraycopy(bytes, 0, buf, ptr, n);
                ptr += n;
                return this;
            }
            try {
                out.write(buf, 0, ptr);
                ptr = 0;
                out.write(bytes);
                out.flush();
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter2 ans(String s) {
            if (!breaked) print(' ');
            breaked = false;
            return print(s);
        }

        public LightWriter2 ans(boolean b) {
            return ans(boolLabel.transfer(b));
        }

        public LightWriter2 noln() {
            return ans(false).ln();
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

        public enum BoolLabel {
            YES_NO_FIRST_UP("Yes", "No"),
            YES_NO_ALL_UP("YES", "NO"),
            YES_NO_ALL_DOWN("yes", "no"),
            Y_N_ALL_UP("Y", "N"),
            POSSIBLE_IMPOSSIBLE_FIRST_UP("Possible", "Impossible"),
            POSSIBLE_IMPOSSIBLE_ALL_UP("POSSIBLE", "IMPOSSIBLE"),
            POSSIBLE_IMPOSSIBLE_ALL_DOWN("possible", "impossible"),
            FIRST_SECOND_FIRST_UP("First", "Second"),
            FIRST_SECOND_ALL_UP("FIRST", "SECOND"),
            FIRST_SECOND_ALL_DOWN("first", "second"),
            ALICE_BOB_FIRST_UP("Alice", "Bob"),
            ALICE_BOB_ALL_UP("ALICE", "BOB"),
            ALICE_BOB_ALL_DOWN("alice", "bob"),
            ;
            private final String positive;
            private final String negative;

            BoolLabel(String positive, String negative) {
                this.positive = positive;
                this.negative = negative;
            }

            private String transfer(boolean f) {
                return f ? positive : negative;
            }

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
        public abstract String string();

        public long longs() {
            return Long.parseLong(string());
        }

        public final long[] longs(int length) {
            long[] res = new long[length];
            Arrays.setAll(res, ignored -> longs());
            return res;
        }

        public abstract void close();

    }
}