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
        DStressfulTraining solver = new DStressfulTraining();
        solver.solve(1, in, out);
        out.close();
    }

    static class DStressfulTraining {
        long[] a;
        long[] b;
        long[] c;
        int n;
        int k;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();

            k = in.nextInt();

            a = in.nextLongArray(n);

            b = in.nextLongArray(n);

            c = new long[n];

            for (int i = 0; i < n; i++) {
                c[i] = ((a[i] + b[i]) / b[i]);
            }


//        lst = new SimpleLazySegmentTree(c, n);
//
//        lst.build(0, 0, n - 1);
//
//        pqru = new PointQueryRangeUpdate(a, n);
//
//        pqru.build(0, 0, n - 1);

            long lo = 0;
            long hi = (long) 2e12;

            long ans = hi + 1;
            while (lo <= hi) {
                long mid = lo + (hi - lo) / 2;

                boolean poss = solve(mid);

                if (poss) {
                    ans = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            if (ans == (long) 2e12 + 1) {
                ans = -1;
            }

            out.println(ans);
        }

        boolean solve(long charger) {

//        lst = new SimpleLazySegmentTree(c, n);
//
//        lst.build(0, 0, n - 1);

//        pqru = new PointQueryRangeUpdate(a, n);
//
//        pqru.build(0, 0, n - 1);

//        PriorityQueue<ele> pq = new PriorityQueue<>((e1, e2) -> (int) Math.signum(e1.cc - e2.cc));
//
//        for (int i = 0; i
//                < n; i++) {
//            pq.add(new ele(i, c[i]));
//        }
//
//        int[] sel = new int[n + 1];
//
//        long x = 0;
//        for (int i = 0; i < k; i++) {
//            //SimpleLazySegmentTree.res res = lst.query(0, 0, n - 1, 0, n - 1);
//
//            ele pe = pq.poll();
//
//            int ind = pe.ind;
//
//            if (pe.cc + x <= 0) {
//                return false;
//            }
////            if (ind > 0)
////            {
////                pqru.update(0, 0, n - 1, 0, ind - 1, );
////            }
//
//            sel[ind]++;
//
////            if (ind > 0) {
////                lst.update(0, 0, n - 1, 0, ind - 1, -1);
////            }
//
//            long val = a[ind];
//
//            val -= (i + 1) * b[ind];
//
//            val += sel[ind] * charger;
//
//            long cc = (val + b[ind]) / b[ind];
////            lst.updateSinle(0, 0, n - 1, ind, ind, cc);
////
////            if (ind < n - 1) {
////                lst.update(0, 0, n - 1, ind + 1, n - 1, -1);
////            }
//
//            pq.add(new ele(pe.ind, cc + (i + 1)));
//
//            x--;
//        }
//
//        return true;

            int[] need = new int[k];

            int totused = 0;
            for (int i = 0; i < n; i++) {
                long st = 0;

                long cv = a[i];
                while (totused <= k && st < k) {
                    long hours = (cv + b[i]) / b[i];

                    if (st + hours >= k)
                        break;

                    if (hours <= 1) {
                        if (hours == 1) {
                            totused++;
                            cv += charger;
                            need[(int) st]++;
                            continue;
                        } else {
                            return false;
                        }
                    }

                    st += (hours - 1);

                    cv -= (hours - 1) * b[i];
                }
            }

            if (totused > k)
                return false;

            long needsum = 0;
            for (int i = 0; i < k; i++) {
                needsum += need[i];

                if (needsum > (i + 1))
                    return false;
            }

            return true;
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

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
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

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public long[] nextLongArray(int n) {
            long[] array = new long[n];
            for (int i = 0; i < n; ++i) array[i] = nextLong();
            return array;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}