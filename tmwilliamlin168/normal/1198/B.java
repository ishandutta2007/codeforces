import java.io.*;
import java.nio.CharBuffer;
import java.util.NoSuchElementException;
 
public class P1199D {
 
    public static void main(String[] args) {
        SimpleScanner scanner = new SimpleScanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);
 
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = scanner.nextInt();
        int q = scanner.nextInt();
        int[] last = new int[n];
        int[] bit = new int[q];
        for (int i = 0; i < q; ++i) {
            int c = scanner.nextInt();
            if (c == 1) {
                int idx = scanner.nextInt() - 1;
                int v = scanner.nextInt();
                a[idx] = v;
                last[idx] = i;
            } else {
                int v = scanner.nextInt();
                bitUpdate(bit, q - i - 1, v);
            }
        }
        for (int i = 0; i < n; ++i) {
            writer.print(Math.max(a[i], bitQuery(bit, q - last[i] - 1)) + " ");
        }
        writer.close();
    }
 
    private static int bitQuery(int[] bit, int x) {
        int max = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1)
            max = Math.max(max, bit[x]);
        return max;
    }
 
    private static void bitUpdate(int[] bit, int x, int val) {
        for (; x < bit.length; x = x | (x + 1))
            bit[x] = Math.max(bit[x], val);
    }
 
    private static class SimpleScanner {
 
        private static final int BUFFER_SIZE = 10240;
 
        private Readable in;
        private CharBuffer buffer;
        private boolean eof;
 
        SimpleScanner(InputStream in) {
            this.in = new BufferedReader(new InputStreamReader(in));
            buffer = CharBuffer.allocate(BUFFER_SIZE);
            buffer.limit(0);
            eof = false;
        }
 
 
        private char read() {
            if (!buffer.hasRemaining()) {
                buffer.clear();
                int n;
                try {
                    n = in.read(buffer);
                } catch (IOException e) {
                    n = -1;
                }
                if (n <= 0) {
                    eof = true;
                    return '\0';
                }
                buffer.flip();
            }
            return buffer.get();
        }
 
        void checkEof() {
            if (eof)
                throw new NoSuchElementException();
        }
 
        char nextChar() {
            checkEof();
            char b = read();
            checkEof();
            return b;
        }
 
        String next() {
            char b;
            do {
                b = read();
                checkEof();
            } while (Character.isWhitespace(b));
            StringBuilder sb = new StringBuilder();
            do {
                sb.append(b);
                b = read();
            } while (!eof && !Character.isWhitespace(b));
            return sb.toString();
        }
 
        int nextInt() {
            return Integer.valueOf(next());
        }
 
        long nextLong() {
            return Long.valueOf(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}