import java.io.*;
import java.util.Arrays;
import java.util.Random;

public class VCFC {

    static class Station implements Comparable<Station> {
        long x, cost;

        public Station(long x, long cost) {
            this.x = x;
            this.cost = cost;
        }

        @Override
        public int compareTo(Station o) {
            return Long.compare(x, o.x);
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        long d = in.nextInt();
        long cap = in.nextInt();
        int n = in.nextInt();
        Station[] st = new Station[n + 1];
        for (int i = 0; i < n; ++i) {
            st[i] = new Station(in.nextInt(), in.nextInt());
        }
        st[n] = new Station(d, 0);
        Arrays.sort(st);
        long[] qCap = new long[n + 2];
        long[] qCost = new long[n + 2];
        int qs = 0, qe = 1;
        long qCapAdd = cap, curFuel = 0, curx = 0;
        long ans = 0;
        for (Station s : st) {
            while (curx + curFuel < s.x) {
                if (qs == qe) {
                    out.println(-1);
                    return;
                }
                long delta = Math.min(qCap[qs] + qCapAdd, s.x - curx - curFuel);
                ans += delta * qCost[qs];
                curFuel += delta;
                qCapAdd -= delta;
                while (qs < qe && qCap[qs] + qCapAdd <= 0) {
                    qs++;
                }
            }
            curFuel -= s.x - curx;
            curx = s.x;
            while (qs < qe && qCost[qe - 1] > s.cost) {
                if (qCap[qe - 1] + qCapAdd > cap - curFuel) {
                    throw new AssertionError();
                }
                qe--;
            }
            qCap[qe] = cap - curFuel - qCapAdd;
            qCost[qe] = s.cost;
            qe++;
        }
        out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

//        Random rnd = new Random();
//        while (rnd != null) {
//            int d = rnd.nextInt(10) + 1;
//            int cap = rnd.nextInt(10) + 1;
//            int n = rnd.nextInt(Math.min(d, 3));
//            StringBuilder sb = new StringBuilder(d + " " + cap + " " + n + "\n");
//            boolean[] col = new boolean[d];
//            for (int i = 0; i < n; ++i) {
//                int at;
//                do {
//                    at = rnd.nextInt(d - 1) + 1;
//                } while (col[at]);
//                col[at] = true;
//                sb.append(at + " " + rnd.nextInt(10) + "\n");
//            }
//            System.err.print(".");
//            solve(new Input(sb.toString()), out);
//        }

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