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
import java.util.ArrayList;
import java.io.UncheckedIOException;
import java.util.List;
import java.nio.charset.Charset;
import java.io.Writer;
import java.util.Comparator;
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
        JRoadReform solver = new JRoadReform();
        solver.solve(1, in, out);
        out.close();
    }

    static class JRoadReform {
        private static final long INF = 1_000_000_000_000_000_000L;

        public void solve(int testNumber, LightScanner2 in, LightWriter2 out) {
            int testCases = in.ints();
            for (int testCase = 1; testCase <= testCases; testCase++) {
                int n = in.ints(), m = in.ints();
                long k = in.longs(), max = 0;
                IntUnionFind uf = new IntUnionFind(n);
                List<JRoadReform.Edge> edges = new ArrayList<>(m);
                for (int i = 0; i < m; i++) {
                    int x = in.ints() - 1, y = in.ints() - 1;
                    long c = in.longs();
                    if (c <= k) {
                        max = Math.max(max, c);
                        uf.union(x, y);
                    } else {
                        edges.add(new JRoadReform.Edge(x, y, c));
                    }
                }
                edges.sort(Comparator.comparing(edge -> edge.c));

                long ans = INF;
                if (uf.size() == 1) {
                    ans = Math.min(ans, k - max);
                    if (!edges.isEmpty()) ans = Math.min(ans, edges.get(0).c - k);
                } else {
                    long res = 0;
                    for (JRoadReform.Edge e : edges) {
                        if (uf.find(e.x) != uf.find(e.y)) {
                            uf.union(e.x, e.y);
                            res += e.c - k;
                        }
                    }
                    ans = Math.min(ans, res);
                }
                out.ans(ans).ln();
            }
        }

        private static class Edge {
            final int x;
            final int y;
            final long c;

            Edge(int x, int y, long c) {
                this.x = x;
                this.y = y;
                this.c = c;
            }

        }

    }

    static class LightScanner2 extends LightScannerAdapter {
        private static final int BUF_SIZE = 16 * 1024;
        private final InputStream stream;
        private final byte[] buf = new byte[BUF_SIZE];
        private int ptr;
        private int len;

        public LightScanner2(InputStream stream) {
            this.stream = stream;
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

    static final class IntUnionFind {
        private int groups;
        private final int[] nodes;
        private final int[] rank;

        public IntUnionFind(int n) {
            groups = n;
            nodes = new int[n];
            Arrays.fill(nodes, -1);
            rank = new int[n];
        }

        public int find(int i) {
            int ans = nodes[i];
            if (ans < 0) {
                return i;
            } else {
                return nodes[i] = find(ans);
            }
        }

        public int size() {
            return groups;
        }

        public int union(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) {
                return -1;
            } else if (rank[x] < rank[y]) {
                nodes[y] += nodes[x];
                nodes[x] = y;
            } else if (rank[x] == rank[y]) {
                rank[x]++;
                nodes[x] += nodes[y];
                nodes[y] = x;
            } else {
                nodes[x] += nodes[y];
                nodes[y] = x;
            }
            groups--;
            return x;
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

        private static int countDigits(long l) {
            if (l >= 1000000000000000000L) return 19;
            if (l >= 100000000000000000L) return 18;
            if (l >= 10000000000000000L) return 17;
            if (l >= 1000000000000000L) return 16;
            if (l >= 100000000000000L) return 15;
            if (l >= 10000000000000L) return 14;
            if (l >= 1000000000000L) return 13;
            if (l >= 100000000000L) return 12;
            if (l >= 10000000000L) return 11;
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

        public LightWriter2 ans(long x) {
            allocate(24);
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