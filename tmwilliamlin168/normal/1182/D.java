import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class CF1182D {
    public static void main(String[] args) throws Exception {
        boolean local = System.getProperty("ONLINE_JUDGE") == null;
        boolean async = false;

        Charset charset = Charset.forName("ascii");

        FastIO io = local ? new FastIO(new FileInputStream("D:\\DATABASE\\TESTCASE\\Code.in"), System.out, charset) : new FastIO(System.in, System.out, charset);
        Task task = new Task(io, new Debug(local));

        if (async) {
            Thread t = new Thread(null, task, "dalt", 1 << 27);
            t.setPriority(Thread.MAX_PRIORITY);
            t.start();
            t.join();
        } else {
            task.run();
        }

        if (local) {
            io.cache.append("\n\n--memory -- \n" + ((Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) >> 20) + "M");
        }

        io.flush();
    }

    public static class Task implements Runnable {
        final FastIO io;
        final Debug debug;
        int inf = (int) 1e8;

        public Task(FastIO io, Debug debug) {
            this.io = io;
            this.debug = debug;
        }

        @Override
        public void run() {
            solve();
        }

        public void solve() {
            n = io.readInt();
            nodes = new Node[n + 1];
            for (int i = 1; i <= n; i++) {
                nodes[i] = new Node();
                nodes[i].id = i;
            }
            for (int i = 1; i < n; i++) {
                Node a = nodes[io.readInt()];
                Node b = nodes[io.readInt()];
                a.next.add(b);
                b.next.add(a);
            }

            if (n == 1) {
                io.cache.append(n);
                return;
            }

            if (!handle(findFirst()) && !handle(findLast())) {
                io.cache.append(-1);
            }

        }

        public Node findFirst() {
            for (int i = 1; i <= n; i++) {
                if (nodes[i].next.size() == 1) {
                    return nodes[i];
                }
            }
            return null;
        }

        public Node findLast() {
            for (int i = n; i >= 1; i--) {
                if (nodes[i].next.size() == 1) {
                    return nodes[i];
                }
            }
            return null;
        }

        public boolean handle(Node leaf) {
            for (int i = 1; i <= n; i++) {
                nodes[i].last = null;
                nodes[i].dist = 0;
                nodes[i].isStraight = false;
            }

            markDist(leaf, null, 0);

            Node farthest = leaf;
            for (int i = 1; i <= n; i++) {
                if (farthest.dist < nodes[i].dist) {
                    farthest = nodes[i];
                }
            }

            if (farthest.dist % 2 == 1) {
                if (isValid(farthest, null, 0, new int[n])) {
                    io.cache.append(farthest.id);
                } else if (isValid(leaf, null, 0, new int[n])) {
                    io.cache.append(leaf.id);
                } else {
                    return false;
                }
                return true;
            }

            Node center = farthest;
            while (center.dist != farthest.dist / 2) {
                center = center.last;
            }

            if (isValid(center, null, 0, new int[n])) {
                io.cache.append(center.id);
                return true;
            }

            for(Node node : center.next) {
                markStraightLeaf(node, 1, center);
            }

            Map<Integer, List<Node>> map = Arrays.stream(nodes, 1, n + 1)
                    .filter(x -> x.isStraight)
                    .collect(Collectors.groupingBy(x -> x.dist));


            if (map.size() > 2) {
                return false;
            }

            for (List<Node> list : map.values()) {
                if (list.size() != 1) {
                    continue;
                }
                if (isValid(list.get(0), null, 0, new int[n])) {
                    io.cache.append(list.get(0).id);
                    return true;
                }
            }

            return false;
        }

        public void markStraightLeaf(Node root, int d, Node father) {
            if (root.next.size() == 1) {
                root.isStraight = true;
                root.dist = d;
                return;
            }
            if (root.next.size() != 2) {
                return;
            }
            for (Node node : root.next) {
                if (node == father) {
                    continue;
                }
                markStraightLeaf(node, d + 1, root);
            }
        }

        public boolean isValid(Node root, Node father, int d, int[] rankOfDepth) {
            if (rankOfDepth[d] == 0) {
                rankOfDepth[d] = root.next.size();
            }
            if (rankOfDepth[d] != root.next.size()) {
                return false;
            }
            for (Node node : root.next) {
                if (node == father) {
                    continue;
                }
                if (!isValid(node, root, d + 1, rankOfDepth)) {
                    return false;
                }
            }
            return true;
        }

        int n;
        Node[] nodes;

        public void markDist(Node root, Node father, int d) {
            root.dist = d;
            root.last = father;
            for (Node node : root.next) {
                if (node == father) {
                    continue;
                }
                markDist(node, root, d + 1);
            }
        }
    }

    public static class Node {
        List<Node> next = new ArrayList<>(2);
        boolean isStraight;
        int dist;
        Node last;
        int id;
    }

    public static class FastIO {
        public final StringBuilder cache = new StringBuilder();
        private final InputStream is;
        private final OutputStream os;
        private final Charset charset;
        private StringBuilder defaultStringBuf = new StringBuilder(1 << 8);
        private byte[] buf = new byte[1 << 13];
        private int bufLen;
        private int bufOffset;
        private int next;

        public FastIO(InputStream is, OutputStream os, Charset charset) {
            this.is = is;
            this.os = os;
            this.charset = charset;
        }

        public FastIO(InputStream is, OutputStream os) {
            this(is, os, Charset.forName("ascii"));
        }

        private int read() {
            while (bufLen == bufOffset) {
                bufOffset = 0;
                try {
                    bufLen = is.read(buf);
                } catch (IOException e) {
                    throw new RuntimeException(e);
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

        public long readLong() {
            int sign = 1;

            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+' ? 1 : -1;
                next = read();
            }

            long val = 0;
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

        public double readDouble() {
            boolean sign = true;
            skipBlank();
            if (next == '+' || next == '-') {
                sign = next == '+';
                next = read();
            }

            long val = 0;
            while (next >= '0' && next <= '9') {
                val = val * 10 + next - '0';
                next = read();
            }
            if (next != '.') {
                return sign ? val : -val;
            }
            next = read();
            long radix = 1;
            long point = 0;
            while (next >= '0' && next <= '9') {
                point = point * 10 + next - '0';
                radix = radix * 10;
                next = read();
            }
            double result = val + (double) point / radix;
            return sign ? result : -result;
        }

        public String readString(StringBuilder builder) {
            skipBlank();

            while (next > 32) {
                builder.append((char) next);
                next = read();
            }

            return builder.toString();
        }

        public String readString() {
            defaultStringBuf.setLength(0);
            return readString(defaultStringBuf);
        }

        public int readLine(char[] data, int offset) {
            int originalOffset = offset;
            while (next != -1 && next != '\n') {
                data[offset++] = (char) next;
                next = read();
            }
            return offset - originalOffset;
        }

        public int readString(char[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (char) next;
                next = read();
            }

            return offset - originalOffset;
        }

        public int readString(byte[] data, int offset) {
            skipBlank();

            int originalOffset = offset;
            while (next > 32) {
                data[offset++] = (byte) next;
                next = read();
            }

            return offset - originalOffset;
        }

        public char readChar() {
            skipBlank();
            char c = (char) next;
            next = read();
            return c;
        }

        public void flush() {
            try {
                os.write(cache.toString().getBytes(charset));
                os.flush();
                cache.setLength(0);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        public boolean hasMore() {
            skipBlank();
            return next != -1;
        }
    }

    public static class Debug {
        private boolean allowDebug;

        public Debug(boolean allowDebug) {
            this.allowDebug = allowDebug;
        }

        public void assertTrue(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (!flag) {
                fail();
            }
        }

        public void fail() {
            throw new RuntimeException();
        }

        public void assertFalse(boolean flag) {
            if (!allowDebug) {
                return;
            }
            if (flag) {
                fail();
            }
        }

        private void outputName(String name) {
            System.out.print(name + " = ");
        }

        public void debug(String name, int x) {
            if (!allowDebug) {
                return;
            }

            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, long x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, double x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, int[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, long[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, double[] x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.toString(x));
        }

        public void debug(String name, Object x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println("" + x);
        }

        public void debug(String name, Object... x) {
            if (!allowDebug) {
                return;
            }
            outputName(name);
            System.out.println(Arrays.deepToString(x));
        }
    }
}