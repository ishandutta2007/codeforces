import java.io.*;
import java.util.*;

public class I {

    final double EPS = 0;

    class Point {
        double x, y, z;

        public Point(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public Point(Point a, Point b) {
            x = b.x - a.x;
            y = b.y - a.y;
            z = b.z - a.z;
        }

        double length() {
            return Math.sqrt(x * x + y * y + z * z);
        }

        void normalize() {
            double coef = length();
            x /= coef;
            y /= coef;
            z /= coef;
        }

        Point vectMul(Point other) {
            double newX = y * other.z - z * other.y;
            double newY = z * other.x - x * other.z;
            double newZ = x * other.y - y * other.x;
            return new Point(newX, newY, newZ);
        }

        double scalMul(Point other) {
            return x * other.x + y * other.y + z * other.z;
        }

        @Override
        public String toString() {
            return "Point{" +
                    "x=" + x +
                    ", y=" + y +
                    ", z=" + z +
                    '}';
        }
    }

    class Line {
        double a, b, c;

        public Line(Point a, Point b) {
            this.a = b.y - a.y;
            this.b = a.x - b.x;
            this.c = -(this.a * a.x + this.b * a.y);
        }

        double dist(Point p) {
            return a * p.x + b * p.y + c;
        }

        Point intersect(Line other) {
            double d = a * other.b - b * other.a;
            if (Math.abs(d) < EPS) {
                return null;
            }
            double dx = (-c) * other.b - b * (-other.c);
            double dy = a * (-other.c) - (-c) * other.a;
            return new Point(dx / d, dy / d, 0);
        }
    }


    public void solve() {
        int n = in.nextInt();
        Point[] a = new Point[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Point(in.nextDouble(), in.nextDouble(), in.nextDouble());
        }
        int m = in.nextInt();
        Point[] b = new Point[m];
        for (int i = 0; i < m; i++) {
            b[i] = new Point(in.nextDouble(), in.nextDouble(), in.nextDouble());
        }


        for (int i = 1; i < n; i++) {
            a[i] = new Point(a[0], a[i]);
        }
        for (int i = 0; i < m; i++) {
            b[i] = new Point(a[0], b[i]);
        }
        a[0] = new Point(0, 0, 0);


        Point v1 = new Point(a[0], a[n - 1]);
        Point v2 = new Point(a[0], a[1]);
        System.err.println(v1 + " " + v2);
        Point norm = v1.vectMul(v2);
//        norm.normalize();
        System.err.println(norm);

        v1.normalize();
        v2 = norm.vectMul(v1);
        v2.normalize();

        System.err.println(v1 + " " + v2);
        {
            boolean samePlane = true;
            for (int i = 0; i < m; i++) {
                double orDist = new Point(a[0], b[i]).scalMul(norm);
                if (Math.abs(orDist) > EPS) {
                    samePlane = false;
                }
            }

            if (samePlane) {
                out.println("NO");
                return;
            }
        }

        List<Event> events = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            Point first = b[i], second = b[(i + 1) % b.length];

            double dist1 = dist(first, a[0], norm), dist2 = dist(second, a[0], norm);
            boolean swap = false;
            if (dist1 > dist2) {
                swap = true;
                double tmp = dist1;
                dist1 = dist2;
                dist2 = tmp;

                Point tmpp = first;
                first = second;
                second = tmpp;
            }

            if (dist1 <= EPS && dist2 > EPS) {
                double ratio = (0 - dist1) / (dist2 - dist1);

                Point inter = new Point(first.x * (1 - ratio) + second.x * ratio,
                        first.y * (1 - ratio) + second.y * ratio,
                        first.z * (1 - ratio) + second.z * ratio);
                inter = project(inter, a[0], v1, v2);
                events.add(new Event(inter, swap ? 1 : -1));
            }
//            if (dist1 >= d && dist2 < d) {
//                double ratio = (d - dist1) / (dist2 - dist1);
//
//                Point inter = new Point(first.x * (1 - ratio) + second.x * ratio,
//                        first.y * (1 - ratio) + second.y * ratio,
//                        first.z * (1 - ratio) + second.z * ratio);
//                inter = project(inter, a[0], v1, v2);
//                events.add(new Event(inter, -1));
//            }
        }
//        if (events.size() % 2 != 0) {
//            throw new AssertionError();
//        }
        if (events.size() == 0) {
            out.println("NO");
            return;
        }
        // events.size() >= 2

        Line line = new Line(events.get(0).p, events.get(1).p);

        for (int i = 1; i < n; i++) {
            a[i] = project(a[i], a[0], v1, v2);
        }
        a[0] = new Point(0, 0, 0);

        for (int i = 0; i < n; i++) {
            Point first = a[i], second = a[(i + 1) % n];
            double dist1 = line.dist(first), dist2 = line.dist(second);
            if (dist1 > dist2) {
                double tmp = dist1;
                dist1 = dist2;
                dist2 = tmp;
            }

            if (dist1 <= EPS && EPS < dist2) {
                Line secondLine = new Line(first, second);
                Point inter = line.intersect(secondLine);
                events.add(new Event(inter, 0));
            }
        }
//        for (Event e : events) {
//            System.err.println(e);
//        }
        final Point direction = new Point(-line.b, line.a, 0);
        Collections.sort(events, (o1, o2) -> Double.compare(direction.scalMul(o1.p), direction.scalMul(o2.p)));
//        System.err.println("!!!");
//        for (Event e : events) {
//            System.err.println(e);
//        }

        int result = 0;
        boolean inside = false;
        for (Event e : events) {
            if (e.type == 0) {
                inside ^= true;
            } else {
                if (inside) {
                    result += e.type;
                }
            }
        }
        out.println(result == 0 ? "NO" : "YES");
    }

    class Event {
        Point p;
        int type;

        public Event(Point p, int type) {
            this.p = p;
            this.type = type;
        }

        @Override
        public String toString() {
            return "Event{" +
                    "p=" + p +
                    ", type=" + type +
                    '}';
        }
    }

    double dist(Point p, Point origin, Point norm) {
        return new Point(origin, p).scalMul(norm);
    }


    Point project(Point p, Point origin, Point v1, Point v2) {
        Point vec = new Point(origin, p);
        return new Point(vec.scalMul(v1), vec.scalMul(v2), 0);
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
        new I().run();
    }
}