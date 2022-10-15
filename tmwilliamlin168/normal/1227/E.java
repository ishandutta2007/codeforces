import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.io.Closeable;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;
 
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Thread thread = new Thread(null, new TaskAdapter(), "", 1 << 27);
        thread.start();
        thread.join();
    }
 
    static class TaskAdapter implements Runnable {
        @Override
        public void run() {
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            FastInput in = new FastInput(inputStream);
            FastOutput out = new FastOutput(outputStream);
            TaskC solver = new TaskC();
            solver.solve(1, in, out);
            out.close();
        }
    }
 
    static class TaskC {
        LongDeque deque = new LongDeque(1000000);
        int[][] buf;
        int[][] time;
        boolean[][] border;
        int[][] mat;
 
        public void solve(int testNumber, FastInput in, FastOutput out) {
            int n = in.readInt();
            int m = in.readInt();
            mat = new int[n][m];
            buf = new int[n][m];
            time = new int[n][m];
            border = new boolean[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[i][j] = in.readChar() == 'X' ? 1 : 0;
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] == 0) {
                        continue;
                    }
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                        border[i][j] = true;
                        continue;
                    }
                    int cnt = 0;
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            int mi = i + dx;
                            int mj = j + dy;
                            cnt += mat[mi][mj];
                        }
                    }
 
                    if (cnt != 9) {
                        border[i][j] = true;
                    }
                }
            }
 
            int l = 0;
            int r = Math.min(n / 2, m / 2);
            while (l < r) {
                int mid = (l + r + 1) >>> 1;
                if (check(mid)) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
 
            check(l);
            out.println(l);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    out.append(time[i][j] == 0 ? 'X' : '.');
                }
                out.println();
            }
        }
 
        public boolean check(int t) {
            int n = mat.length;
            int m = mat[0].length;
            SequenceUtils.deepFill(time, -1);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!border[i][j]) {
                        continue;
                    }
                    deque.addLast(DigitUtils.asLong(i, j));
                    time[i][j] = 0;
                }
            }
            while (!deque.isEmpty()) {
                long head = deque.removeFirst();
                int x = DigitUtils.highBit(head);
                int y = DigitUtils.lowBit(head);
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int mx = x + dx;
                        int my = y + dy;
                        if (mx < 0 || mx >= n || my < 0 || my >= m || mat[mx][my] == 0 ||
                                time[mx][my] != -1) {
                            continue;
                        }
                        time[mx][my] = time[x][y] + 1;
                        deque.addLast(DigitUtils.asLong(mx, my));
                    }
                }
            }
 
            SequenceUtils.deepFill(buf, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (time[i][j] >= t) {
                        deque.addLast(DigitUtils.asLong(i, j));
                        time[i][j] = 0;
                    } else {
                        time[i][j] = -1;
                    }
                }
            }
 
            while (!deque.isEmpty()) {
                long head = deque.removeFirst();
                int x = DigitUtils.highBit(head);
                int y = DigitUtils.lowBit(head);
                buf[x][y] = 1;
                if (time[x][y] >= t) {
                    continue;
                }
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int mx = x + dx;
                        int my = y + dy;
                        if (time[mx][my] != -1) {
                            continue;
                        }
                        if (mx < 0 || mx >= n || my < 0 || my >= m || mat[mx][my] == 0) {
                            return false;
                        }
                        time[mx][my] = time[x][y] + 1;
                        deque.addLast(DigitUtils.asLong(mx, my));
                    }
                }
            }
 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (buf[i][j] != mat[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        }
 
    }
 
    static class FastInput {
        private final InputStream is;
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;
 
        public FastInput(InputStream is) {
            this.is = is;
        }
 
        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    bufLen = -1;
                }
                if (bufLen == -1) {
                    return -1;
                }
            }
            return buf[bufOffset++];
        }
 
        public void skipBlank() {
            while (next >= 0 && next <= 32) {
                next = read();
            }
        }
 
        public int readInt() {
            int sign = 1;
 
            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }
 
            int val = 0;
            if (sign == 1) {
                while (next >= '0' && next <= '9') {
                    val = val * 10 + next - '0';
                    next = read();
                }
            } else {
                while (next >= '0' && next <= '9') {
                    val = val * 10 - next + '0';
                    next = read();
                }
            }
 
            return val;
        }
 
        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }
 
    }
 
    static class LongDeque {
        long[] data;
        int bpos;
        int epos;
        int cap;
 
        public LongDeque(int cap) {
            this.cap = cap + 1;
            this.data = new long[this.cap];
        }
 
        public boolean isEmpty() {
            return epos == bpos;
        }
 
        private int next(int i) {
            int n = i + 1;
            return n == cap ? 0 : n;
        }
 
        public long removeFirst() {
            int t = bpos;
            bpos = next(bpos);
            return data[t];
        }
 
        public void addLast(long val) {
            data[epos] = val;
            epos = next(epos);
        }
 
        public String toString() {
            StringBuilder builder = new StringBuilder();
            for (int i = bpos; i != epos; i = next(i)) {
                builder.append(data[i]).append(' ');
            }
            return builder.toString();
        }
 
    }
 
    static class SequenceUtils {
        public static void deepFill(Object array, int val) {
            if (!array.getClass().isArray()) {
                throw new IllegalArgumentException();
            }
            if (array instanceof int[]) {
                int[] intArray = (int[]) array;
                Arrays.fill(intArray, val);
            } else {
                Object[] objArray = (Object[]) array;
                for (Object obj : objArray) {
                    deepFill(obj, val);
                }
            }
        }
 
    }
 
    static class DigitUtils {
        private DigitUtils() {
        }
 
        public static long asLong(int high, int low) {
            return (((long) high) << 32) | low;
        }
 
        public static int highBit(long x) {
            return (int) (x >> 32);
        }
 
        public static int lowBit(long x) {
            return (int) x;
        }
 
    }
 
    static class FastOutput implements AutoCloseable, Closeable {
        private StringBuilder cache = new StringBuilder(10 << 20);
        private final Writer os;
 
        public FastOutput(Writer os) {
            this.os = os;
        }
 
        public FastOutput(OutputStream os) {
            this(new OutputStreamWriter(os));
        }
 
        public FastOutput append(char c) {
            cache.append(c);
            return this;
        }
 
        public FastOutput println(int c) {
            cache.append(c).append('\n');
            return this;
        }
 
        public FastOutput println() {
            cache.append('\n');
            return this;
        }
 
        public FastOutput flush() {
            try {
                os.append(cache);
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
            return this;
        }
 
        public void close() {
            flush();
            try {
                os.close();
            } catch (IOException e) {
                throw new UncheckedIOException(e);
            }
        }
 
        public String toString() {
            return cache.toString();
        }
 
    }
}