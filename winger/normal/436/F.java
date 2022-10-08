import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;
import java.util.function.Function;
import java.util.function.ToDoubleFunction;
import java.util.function.ToIntFunction;
import java.util.function.ToLongFunction;

public class cf436F {

    static class Pair implements Comparable<Pair> {
        long a, b;

        Pair(long a, long b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(Pair o) {
            return Long.compare(o.a, a);
        }
    }

    static class Group {
        long[] add;
        long[] k;
        int curx, curs;
        int[] stack;
        long[] stackt;
        int ss;

        Group(int len) {
            add = new long[len];
            k = new long[len];
            stack = new int[len];
            stackt = new long[len];
        }

        void init() {
            curs = 0;
            ss = 0;
            for (int i = 0; i < add.length; ++i) {
                //add[i]+t*k[i]>=add[j]+t*k[j];
                while (ss > 1) {
                    int j = stack[ss - 1];
                    long t = stackt[ss - 1];
                    if (add[i] + t * k[i] >= add[j] + t * k[j]) {
                        --ss;
                    } else {
                        break;
                    }
                }
                stack[ss] = i;
                if (ss > 0) {
                    int j = stack[ss - 1];
                    stackt[ss] = (10000000000L * (k[i] - k[j]) + add[j] - add[i] + (k[i] - k[j] - 1)) / (k[i] - k[j]) - 10000000000L;
                }
                ss++;
            }
        }

        long getMax() {
            while (curs + 1 < ss && stackt[curs + 1] <= curx) {
                ++curs;
            }
            return add[stack[curs]] + curx * k[stack[curs]];
        }
    }

    static class ITree {
        int size;
        Group[] gs;

        ITree(int n) {
            size = 1;
            while (size * size < n) {
                size++;
            }
            gs = new Group[size];
            for (int i = 0; i < size; ++i) {
                gs[i] = new Group(size);
                int gl = i * size;
                int gr = (i + 1) * size;
                for (int j = 0; j < size; ++j) {
                    gs[i].k[j] = gl + j;
                }
                gs[i].init();
            }
        }

        void inc(int r) {
            for (int i = 0; i < size; ++i) {
                int gl = i * size;
                int gr = (i + 1) * size;
                if (gl >= r) {
                    break;
                }
                if (gr <= r) {
                    gs[i].curx++;
                } else {
                    for (int j = gl; j < gr; ++j) {
                        if (j < r) {
                            gs[i].add[j - gl] += j;
                        }
                    }
                    gs[i].init();
                }
            }
        }

        long getMax() {
            long r = 0;
            for (int i = 0; i < size; ++i) {
                r = Math.max(r, gs[i].getMax());
            }
            return r;
        }

        int getP() {
            long r = 0;
            int p = 0;
            for (int i = 0; i < size; ++i) {
                if (gs[i].getMax() > r) {
                    r = gs[i].getMax();
                    p = i * size + gs[i].stack[gs[i].curs];
                }
            }
            return p;
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        long w = in.nextLong();
        Pair[] ps = new Pair[n];
        int maxa = 0, maxb = 0;
        for (int i = 0; i < n; ++i) {
            ps[i] = new Pair(in.nextLong(), in.nextLong());
            maxa = Math.max(maxa, (int)ps[i].a);
            maxb = Math.max(maxb, (int)ps[i].b);
        }
        Arrays.sort(ps);
        ITree t = new ITree(maxa + 1);
        Arrays.sort(ps, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return Long.compare(o1.b, o2.b);
            }
        });
        int count = 0;
        for (int c = 0; c <= maxb + 1; ++c) {
            while (count < n && ps[count].b < c) {
                t.inc((int)ps[count].a + 1);
                ++count;
            }
            BigInteger ans = BigInteger.valueOf(n - count).multiply(BigInteger.valueOf(c)).multiply(BigInteger.valueOf(w));
            int ansp = t.getP();
            out.println(ans.add(BigInteger.valueOf(t.getMax())) + " " + ansp);
        }
    }

    public static void main(String[] args) throws IOException {
        /*
2 1
5 8
1 5

Exception in thread "main" java.lang.AssertionError: 0 6 1 8 7
       */
//        Random rnd = new Random();
//        while (rnd != null) {
//            int n = rnd.nextInt(100000);
//            int w = rnd.nextInt(1000000000);
//            int[] a = new int[n];
//            int[] b = new int[n];
//            int maxb = 0, maxa = 0;
//            StringBuilder sb = new StringBuilder(n + " " + w + "\n");
//            for (int i = 0; i < n; ++i) {
//                a[i] = rnd.nextInt(100000);
//                b[i] = rnd.nextInt(100000);
//                maxa = Math.max(maxb, a[i]);
//                maxb = Math.max(maxb, b[i]);
//                sb.append(a[i] + " " + b[i] + "\n");
//            }
//            StringWriter sw = new StringWriter();
//            solve(new Input(sb.toString()), new PrintWriter(sw));
//            Input in = new Input(sw.toString());
////            for (int c = 0; c <= maxb + 1; ++c) {
////                long ans = in.nextInt();
////                int ansp = in.nextInt();
////                for (int p = 0; p <= maxa; ++p) {
////                    long cur = 0;
////                    for (int i = 0; i < n; ++i) {
////                        if (b[i] >= c) {
////                            cur += w * c;
////                        } else if (a[i] >= p) {
////                            cur += p;
////                        }
////                    }
////                    if (p == ansp && ans != cur) {
////                        System.err.println(sb.toString());
////                        throw new AssertionError("0 " + c + " " + p + " " + ans + " " + cur);
////                    }
////                    if (ans < cur) {
////                        System.err.println(sb.toString());
////                        throw new AssertionError("1 " + c + " " + p + " " + ans + " " + cur);
////                    }
////                }
////            }
//            System.err.print(".");
//            break;
//        }
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    static class Input {
        BufferedReader in;
        StringBuilder sb = new StringBuilder();

        public Input(BufferedReader in) {
            this.in = in;
        }

        public Input(String s) {
            this.in = new BufferedReader(new StringReader(s));
        }

        public String next() throws IOException {
            sb.setLength(0);
            while (true) {
                int c = in.read();
                if (c == -1) {
                    return null;
                }
                if (" \n\r\t".indexOf(c) == -1) {
                    sb.append((char)c);
                    break;
                }
            }
            while (true) {
                int c = in.read();
                if (c == -1 || " \n\r\t".indexOf(c) != -1) {
                    break;
                }
                sb.append((char)c);
            }
            return sb.toString();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}