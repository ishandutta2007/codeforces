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
        DFirecrackers solver = new DFirecrackers();
        solver.solve(1, in, out);
        out.close();
    }

    static class DFirecrackers {
        public void solve(int testNumber, LightScanner2 in, LightWriter2 out) {
            int testCases = in.ints();
            for (int testCase = 1; testCase <= testCases; testCase++) {
                long n = in.longs();
                int m = in.ints();
                long a = in.longs() - 1, b = in.longs() - 1;
                if (a > b) {
                    a = n - 1 - a;
                    b = n - 1 - b;
                }
                long life = a, close = b - a;
                long[] s = in.longs(m);
                IntroSort.sort(s);

                int exp = (int) Math.min(m, close - 1);
                int ans = 0;
                int cur = 0;
                for (int i = 0; i < exp; i++) {
                    long time = close + life - exp + i;
                    if (cur < m && time >= s[cur]) {
                        ans++;
                        cur++;
                    }
                }
                out.ans(ans).ln();
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

    static final class BitMath {
        private BitMath() {
        }

        public static int count(int v) {
            return Integer.bitCount(v);
        }

        public static int msb(int v) {
            if (v == 0) {
                throw new IllegalArgumentException("Bit not found");
            }
            v |= (v >> 1);
            v |= (v >> 2);
            v |= (v >> 4);
            v |= (v >> 8);
            v |= (v >> 16);
            return count(v) - 1;
        }

    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static void swap(long[] a, int x, int y) {
            long t = a[x];
            a[x] = a[y];
            a[y] = t;
        }

    }

    static class IntroSort {
        private static int INSERTIONSORT_THRESHOLD = 16;

        private IntroSort() {
        }

        static void sort(long[] a, int low, int high, int maxDepth) {
            while (high - low > INSERTIONSORT_THRESHOLD) {
                if (maxDepth-- == 0) {
                    HeapSort.sort(a, low, high);
                    return;
                }
                int cut = QuickSort.step(a, low, high);
                sort(a, cut, high, maxDepth);
                high = cut;
            }
            InsertionSort.sort(a, low, high);
        }

        public static void sort(long[] a) {
            if (a.length <= INSERTIONSORT_THRESHOLD) {
                InsertionSort.sort(a, 0, a.length);
            } else {
                sort(a, 0, a.length, 2 * BitMath.msb(a.length));
            }
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

    static class InsertionSort {
        private InsertionSort() {
        }

        static void sort(long[] a, int low, int high) {
            for (int i = low; i < high; i++) {
                for (int j = i; j > low && a[j - 1] > a[j]; j--) {
                    ArrayUtil.swap(a, j - 1, j);
                }
            }
        }

    }

    static class HeapSort {
        private HeapSort() {
        }

        private static void heapfy(long[] a, int low, int high, int i, long val) {
            int child = 2 * i - low + 1;
            while (child < high) {
                if (child + 1 < high && a[child] < a[child + 1]) {
                    child++;
                }
                if (val >= a[child]) {
                    break;
                }
                a[i] = a[child];
                i = child;
                child = 2 * i - low + 1;
            }
            a[i] = val;
        }

        static void sort(long[] a, int low, int high) {
            for (int p = (high + low) / 2 - 1; p >= low; p--) {
                heapfy(a, low, high, p, a[p]);
            }
            while (high > low) {
                high--;
                long pval = a[high];
                a[high] = a[low];
                heapfy(a, low, high, low, pval);
            }
        }

    }

    static class QuickSort {
        private QuickSort() {
        }

        private static void med(long[] a, int low, int x, int y, int z) {
            if (a[z] < a[x]) {
                ArrayUtil.swap(a, low, x);
            } else if (a[y] < a[z]) {
                ArrayUtil.swap(a, low, y);
            } else {
                ArrayUtil.swap(a, low, z);
            }
        }

        static int step(long[] a, int low, int high) {
            int x = low + 1, y = low + (high - low) / 2, z = high - 1;
            if (a[x] < a[y]) {
                med(a, low, x, y, z);
            } else {
                med(a, low, y, x, z);
            }

            int lb = low + 1, ub = high;
            while (true) {
                while (a[lb] < a[low]) {
                    lb++;
                }
                ub--;
                while (a[low] < a[ub]) {
                    ub--;
                }
                if (lb >= ub) {
                    return lb;
                }
                ArrayUtil.swap(a, lb, ub);
                lb++;
            }
        }

    }

    static interface Verified {
    }
}