import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class CF494C {

    final static long mod = 1000000007;

    static class Segment implements Comparable<Segment> {
        int i, l, r;
        double p;

        public Segment(int i, int l, int r, double p) {
            this.i = i;
            this.l = l;
            this.r = r;
            this.p = p;
        }

        @Override
        public int compareTo(Segment o) {
            if (r - l == o.r - o.l) {
                return i - o.i;
            }
            return (o.r - o.l) - (r - l);
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        int max = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
            max = Math.max(max, a[i]);
        }
        ArrayList<Segment>[] open = new ArrayList[n];
        ArrayList<Segment>[] close = new ArrayList[n];
        for (int i = 0; i < m; ++i) {
            Segment s = new Segment(i, in.nextInt() - 1, in.nextInt() - 1, in.nextDouble());
            if (open[s.l] == null) {
                open[s.l] = new ArrayList<>();
            }
            if (close[s.r] == null) {
                close[s.r] = new ArrayList<>();
            }
            open[s.l].add(s);
            close[s.r].add(s);
        }
        double[][] st = new double[m + 1][2 * m + 1];
        int stp = 1;
        st[0][0] = 1.0;
        for (int i = 0; i < n; ++i) {
            if (open[i] != null) {
                Collections.sort(open[i]);
                for (Segment s : open[i]) {
                    Arrays.fill(st[stp], 0.0);
                    st[stp][0] = 1.0;
                    stp++;
                }
            }
            int at = a[i] + m - max;
            if (at >= 0 && at < st[stp - 1].length) {
                for (int j = 0; j < at; ++j) {
                    st[stp - 1][at] += st[stp - 1][j];
                    st[stp - 1][j] = 0;
                }
            }
            if (close[i] != null) {
                Collections.sort(close[i]);
                Collections.reverse(close[i]);
                for (Segment s : close[i]) {
                    stp--;
                    for (int j = st[stp].length - 1; j > 0; --j) {
                        st[stp][j] = st[stp][j] * (1.0 - s.p) + st[stp][j - 1] * s.p;
                    }
                    st[stp][0] *= 1.0 - s.p;
                    double sump1 = 0.0, sump2 = 0.0;
                    for (int j = 0; j < st[stp].length; ++j) {
                        double prev = sump1 * sump2;
                        sump1 += st[stp - 1][j];
                        sump2 += st[stp][j];
                        st[stp - 1][j] = sump1 * sump2 - prev;
                    }
                }
            }
        }
        if (stp != 1) {
            throw new AssertionError();
        }
        double ans = 0;
        for (int i = 0; i < st[0].length; ++i) {
            ans += (max + i - m) * st[0][i];
        }
        out.println(ans);
    }

    public static void main(String[] args) throws IOException {
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