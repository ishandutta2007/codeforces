import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Random;

public class cf436E {

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int w = in.nextInt();
        final int[] a = new int[n];
        final int[] b = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            b[i] = in.nextInt();
        }
        Comparator<Integer> ca = new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return a[o1] < a[o2] ? -1 : a[o1] > a[o2] ? +1 : 0;
            }
        };
        Comparator<Integer> cb = new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return b[o1] < b[o2] ? -1 : b[o1] > b[o2] ? +1 : 0;
            }
        };
        Comparator<Integer> cba = new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return b[o1] - a[o1] < b[o2] - a[o2] ? -1 : b[o1] - a[o1] > b[o2] - a[o2] ? +1 : 0;
            }
        };
        PriorityQueue<Integer> pa = new PriorityQueue<Integer>(ca);
        PriorityQueue<Integer> pa1 = new PriorityQueue<Integer>(ca.reversed());
        PriorityQueue<Integer> pb = new PriorityQueue<Integer>(cb);
        PriorityQueue<Integer> pba = new PriorityQueue<Integer>(cba);
        PriorityQueue<Integer> pba1 = new PriorityQueue<Integer>(cba.reversed());
        int[] c = new int[n];
        for (int i = 0; i < n; ++i) {
            pa.add(i);
            pb.add(i);
        }
        long ans = 0;
        for (int it = 0; it < w; ++it) {
            long nextA = pa.isEmpty() ? Long.MAX_VALUE : a[pa.peek()];
            long nextBA = pba.isEmpty() ? Long.MAX_VALUE : b[pba.peek()] - a[pba.peek()];
            long nextBA1 = pa1.isEmpty() || pb.isEmpty() ? Long.MAX_VALUE : b[pb.peek()] - a[pa1.peek()];
            long nextBA2 = pba1.isEmpty() || pb.isEmpty() ? Long.MAX_VALUE : b[pb.peek()] - (b[pba1.peek()] - a[pba1.peek()]);
            if (nextA <= nextBA && nextA <= nextBA1 && nextA <= nextBA2) {
                int i = pa.poll();
                if (c[i] != 0) {
                    throw new AssertionError();
                }
                c[i] = 1;
                ans += a[i];
                pa1.add(i);
                pba.add(i);
            } else if (nextBA <= nextA && nextBA <= nextBA1 && nextBA <= nextBA2) {
                int i = pba.poll();
                if (c[i] != 1) {
                    throw new AssertionError();
                }
                c[i] = 2;
                pba1.add(i);
                ans += b[i] - a[i];
            } else if (nextBA1 <= nextA && nextBA1 <= nextBA && nextBA1 <= nextBA2) {
                int i = pb.poll();
                int j = pa1.poll();
                if (c[i] != 0 || c[j] != 1) {
                    throw new AssertionError();
                }
                c[i] = 2;
                c[j] = 0;
                ans += b[i] - a[j];
                pba1.add(i);
                pa.add(j);
                pb.add(j);
            } else if (nextBA2 <= nextA && nextBA2 <= nextBA && nextBA2 <= nextBA1) {
                int i = pb.poll();
                int j = pba1.poll();
                if (c[i] != 0 || c[j] != 2) {
                    throw new AssertionError();
                }
                c[i] = 2;
                c[j] = 1;
                ans += b[i] - (b[j] - a[j]);
                pba1.add(i);
                pa1.add(j);
                pba.add(j);
            } else {
                throw new AssertionError();
            }
            while (!pa.isEmpty() && c[pa.peek()] != 0) {
                pa.poll();
            }
            while (!pb.isEmpty() && c[pb.peek()] != 0) {
                pb.poll();
            }
            while (!pba.isEmpty() && c[pba.peek()] != 1) {
                pba.poll();
            }
            while (!pa1.isEmpty() && c[pa1.peek()] != 1) {
                pa1.poll();
            }
            while (!pba1.isEmpty() && c[pba1.peek()] != 2) {
                pba1.poll();
            }
        }
        out.println(ans);
        for (int i = 0; i < n; ++i) {
            out.print(c[i]);
        }
        out.println();
    }

    public static void main(String[] args) throws IOException {
//        Random rnd = new Random();
//        while (rnd != null) {
//            int n = rnd.nextInt(10) + 1;
//            int w = rnd.nextInt(2 * n + 1);
//            int[] a = new int[n];
//            int[] b = new int[n];
//            StringBuilder sb = new StringBuilder(n + " " + w + "\n");
//            for (int i = 0; i < n; ++i) {
//                do {
//                    a[i] = rnd.nextInt(1000000000);
//                    b[i] = rnd.nextInt(1000000000);
//                } while (a[i] > b[i]);
//                sb.append(a[i] + " " + b[i] + "\n");
//            }
//            StringWriter sw = new StringWriter();
//            solve(new Input(sb.toString()), new PrintWriter(sw));
//            long ans = new Input(sw.toString()).nextLong();
//            long ansSlow = solveSlow(n, w, a, b);
//            if (ans != ansSlow) {
//                System.err.println(sb);
//                throw new AssertionError(ans + " " + ansSlow);
//            }
//            System.err.print(".");
//        }
        PrintWriter out = new PrintWriter(System.out);
        solve(new Input(new BufferedReader(new InputStreamReader(System.in))), out);
        out.close();
    }

    private static long solveSlow(int n, int w, int[] a, int[] b) {
        return rec(0, w, a, b);
    }

    private static long rec(int i, int w, int[] a, int[] b) {
        if (w <= 0) {
            return 0;
        }
        if (i == a.length) {
            return 1000000000000000000L;
        }
        long r = 1000000000000000000L;
        for (int c = 0; c <= 2; ++c) {
            r = Math.min(r, (c == 0 ? 0 : c == 1 ? a[i] : b[i]) + rec(i + 1, w - c, a, b));
        }
        return r;
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