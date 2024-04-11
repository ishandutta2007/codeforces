import java.io.*;
import java.util.*;

public class C {

    class Point {
        long x ,y;

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    long vectMul(Point a, Point b, Point c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    long dist2(Point a, Point b) {
        long dx = a.x - b.x, dy = a.y - b.y;
        return dx * dx + dy * dy;
    }

    public void solve() {
        int n = in.nextInt();
        Point[] a = new Point[n];
        for (int i  =0 ;i < n; i++) {
            a[i] = new Point(in.nextLong(), in.nextLong());
        }

        int id1 = 1;
        for (int j = 1; j < n; j++) {
            if (dist2(a[0], a[j]) < dist2(a[0], a[id1])) {
                id1 = j;
            }
        }

        int best = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == id1) {
                continue;
            }
            long vm = Math.abs(vectMul(a[0], a[id1], a[i]));
            if (vm == 0) {
                continue;
            }
            if (best == -1 || vm < Math.abs(vectMul(a[0], a[id1], a[best]))) {
                best = i;
            }
        }
        out.println(("1 " + (id1 + 1) + " " + (best + 1)));
    }

    public void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new C().run();
    }
}