import java.io.*;
import java.util.Arrays;

public class CF626G {

    static class ITree {
        double[] max;
        int[] maxi;

        int size;

        ITree(double[] ar) {
            size = 1;
            while (size < ar.length) {
                size *= 2;
            }
            max = new double[2 * size - 1];
            Arrays.fill(max, Double.NEGATIVE_INFINITY);
            maxi = new int[2 * size - 1];
            for (int i = 0; i < ar.length; ++i) {
                max[size - 1 + i] = ar[i];
                maxi[size - 1 + i] = i;
            }
            for (int i = size - 2; i >= 0; --i) {
                relax(i);
            }
        }

        void set(int i, double val) {
            i += size - 1;
            max[i] = val;
            while (i > 0) {
                i = (i - 1) / 2;
                relax(i);
            }
        }

        private void relax(int i) {
            if (max[2 * i + 1] > max[2 * i + 2]) {
                max[i] = max[2 * i + 1];
                maxi[i] = maxi[2 * i + 1];
            } else {
                max[i] = max[2 * i + 2];
                maxi[i] = maxi[2 * i + 2];
            }
        }
    }

    static class Lot {
        int cost, cnt0, cnt;

        double cur() {
            return 1.0 * cost * cnt / (cnt + cnt0);
        }

        double next() {
            return cnt == cnt0 ? Double.NEGATIVE_INFINITY : 1.0 * cost * (cnt + 1) / (cnt + 1 + cnt0);
        }

        double prev() {
            return cnt == 0 ? Double.NEGATIVE_INFINITY : 1.0 * cost * (cnt - 1) / (cnt - 1 + cnt0);
        }
    }

    public static void solve(Input in, PrintWriter out) throws IOException {
        int n = in.nextInt();
        int t = in.nextInt();
        int q = in.nextInt();
        Lot[] lots = new Lot[n];
        for (int i = 0; i < n; ++i) {
            lots[i] = new Lot();
        }
        for (int i = 0; i < n; ++i) {
            lots[i].cost = in.nextInt();
        }
        double[] prevs = new double[n];
        double[] nexts = new double[n];
        for (int i = 0; i < n; ++i) {
            lots[i].cnt0 = in.nextInt();
            prevs[i] = lots[i].prev() - lots[i].cur();
            nexts[i] = lots[i].next() - lots[i].cur();
        }
        ITree tPrev = new ITree(prevs);
        ITree tNext = new ITree(nexts);
        double sumCur = 0.0;
        int cnt = 0;
        while (cnt < t) {
            int i = tNext.maxi[0];
            Lot min = lots[i];
            if (min.cnt == min.cnt0) {
                break;
            }
            sumCur += min.next() - min.cur();
            min.cnt++;
            cnt++;
            tPrev.set(i, min.prev() - min.cur());
            tNext.set(i, min.next() - min.cur());
        }
        for (int it = 0; it < q; ++it) {
            int delta = 3 - 2 * in.nextInt();
            int i = in.nextInt() - 1;
            Lot lot = lots[i];
            sumCur -= lot.cur();
            cnt -= lot.cnt;
            lot.cnt0 += delta;
            lot.cnt = 0;
            tNext.set(i, Double.NEGATIVE_INFINITY);
            tPrev.set(i, Double.NEGATIVE_INFINITY);
            if (n > 1) {
                double x = tNext.max[0];
                int bl = -1, br = lot.cnt0;
                while (bl + 1 < br) {
                    lot.cnt = (bl + br) / 2;
                    if (lot.next() - lot.cur() > x) {
                        bl = lot.cnt;
                    } else {
                        br = lot.cnt;
                    }
                }
                lot.cnt = br;
            }
            sumCur += lot.cur();
            cnt += lot.cnt;
            tPrev.set(i, lot.prev() - lot.cur());
            tNext.set(i, lot.next() - lot.cur());
            while (cnt < t) {
                i = tNext.maxi[0];
                Lot min = lots[i];
                if (min.cnt == min.cnt0) {
                    break;
                }
                sumCur += min.next() - min.cur();
                min.cnt++;
                cnt++;
                tPrev.set(i, min.prev() - min.cur());
                tNext.set(i, min.next() - min.cur());
            }
            while (cnt > t) {
                i = tPrev.maxi[0];
                Lot min = lots[i];
                sumCur += min.prev() - min.cur();
                min.cnt--;
                cnt--;
                tPrev.set(i, min.prev() - min.cur());
                tNext.set(i, min.next() - min.cur());
            }
            if (tNext.max[0] + tPrev.max[0] > 1e-6) {
                throw new AssertionError();
            }
            out.println(sumCur);
        }
    }

    public static void main(String[] args) throws IOException {
        PrintWriter out = new PrintWriter(System.out);

//        Random rnd = new Random();
//        while (rnd != null) {
//            int n = 10;
//            int q = 1;
//            StringBuilder sb = new StringBuilder(n + " " + (rnd.nextInt(10) + 1) + " " + q + "\n");
//            for (int i = 0; i < n; ++i) {
//                sb.append((rnd.nextInt(10) + 1) + " ");
//            }
//            int[] cnt = new int[n];
//            sb.append("\n");
//            for (int i = 0; i < n; ++i) {
//                cnt[i] = 1;
//                sb.append(cnt[i] + " ");
//            }
//            sb.append("\n");
//            for (int it = 0; it < q; ++it) {
//                int i = rnd.nextInt(n);
//                int t = cnt[i] == 1 || rnd.nextBoolean() ? 1 : 2;
//                cnt[i] += 3 - 2 * t;
//                sb.append(t + " " + (i + 1) + "\n");
//            }
//            System.err.println(sb);
////            System.err.print(".");
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