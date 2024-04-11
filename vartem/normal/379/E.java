import java.io.*;
import java.util.*;

public class E {

    class Point {
        double x, y;

        public Point(double x, double y) {
            super();
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Point [x=" + x + ", y=" + y + "]";
        }

    }

    public boolean under(Point p, Point a, Point b) {
        return (p.x - a.x) * (b.y - a.y) - (p.y - a.y) * (b.x - a.x) > 1e-10;
    }

    final int SIZE = 100_000;
    Point[] pts = new Point[SIZE];
    Point[] newPts = new Point[SIZE];

    double area(int size) {
        double area = 0;
        for (int i = 0; i < size - 1; i++) {
            area += (pts[i + 1].y + pts[i].y) * (pts[i + 1].x - pts[i].x) / 2;
        }
        return area;
    }

    Point intersect(Point a, Point b, double y0, double y1) {
        double num = (b.y - a.y) * a.x + (b.x - a.x) * (y0 - a.y);
        double denom = (b.y - a.y) - (b.x - a.x) * (y1 - y0);
        double x = num / denom;
        double y = y0 + (y1 - y0) * x;
        return new Point(x, y);
    }

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        int[][] y = new int[n][k + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                y[i][j] = in.nextInt();
            }
        }
        double[] ans = new double[n];

        for (int j = 0; j < k; j++) {

            ans[0] += (y[0][j] + y[0][j + 1]) / 2.0;
            int size = 2;
            pts[0] = new Point(0, y[0][j]);
            pts[1] = new Point(1, y[0][j + 1]);

            double curArea = area(size);
            boolean[] under = new boolean[1000];
            for (int i = 1; i < n; i++) {
                Arrays.fill(under, false);
                Point from = new Point(0, y[i][j]);
                Point to = new Point(1, y[i][j + 1]);
                int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;

                for (int t = 0; t < size; t++) {
                    if (under(pts[t], from, to)) {
                        under[t] = true;
                        min = Math.min(t, min);
                        max = Math.max(t, max);
                    }
                }

                if (min != Integer.MAX_VALUE) {
                    int newSize;
                    if (min == 0 && max == size - 1) {
                        newSize = 2;
                        newPts[0] = from;
                        newPts[1] = to;
                    } else if (min == 0) {
                        newSize = 1;
                        newPts[0] = from;
                        Point inter1 = pts[max], inter2 = pts[max + 1];
                        newPts[newSize++] = intersect(inter1, inter2, y[i][j], y[i][j + 1]);
                        for (int t = max + 1; t < size; t++) {
                            newPts[newSize++] = pts[t];
                        }
                        size = newSize;

                    } else if (max == size - 1) {
                        newSize = 0;
                        for (int t = 0; t < min; t++) {
                            newPts[newSize++] = pts[t];
                        }

                        Point inter1 = pts[min - 1], inter2 = pts[min];
                        newPts[newSize++] = intersect(inter1, inter2, y[i][j], y[i][j + 1]);
                        newPts[newSize++] = to;
                        size = newSize;
                    } else {
                        newSize = 0;
                        for (int t = 0; t < size; t++) {
                            if (under[t]) {
                                if (!under[t - 1]) {
                                    newPts[newSize++] = intersect(pts[t - 1], pts[t], y[i][j],
                                            y[i][j + 1]);
                                }
                            } else {
                                if (t > 0 && under[t - 1]) {
                                    newPts[newSize++] = intersect(pts[t - 1], pts[t], y[i][j],
                                            y[i][j + 1]);
                                }
                                newPts[newSize++] = pts[t];
                            }
                        }
                    }
                    System.arraycopy(newPts, 0, pts, 0, newSize);
                    size = newSize;
                    double newArea = area(size);
                    ans[i] += newArea - curArea;
                    curArea = newArea;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            out.println(ans[i]);
        }
    }

    FastScanner in;
    PrintWriter out;

    public void run() {
        try {
            in = new FastScanner();
            out = new PrintWriter(System.out);
            solve();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String name) {
            try {
                br = new BufferedReader(new FileReader(name));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

        public long nextLong() {
            return Long.parseLong(nextToken());
        }

        public double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        new E().run();
    }
}