import java.io.*;
import java.util.*;

public class C {

    MyScanner in;
    PrintWriter out;
    final static String filename = "";

    class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner(String file) {
            try {
                br = new BufferedReader(new FileReader(file));
                st = new StringTokenizer("");
            } catch (FileNotFoundException e) {
                e.printStackTrace();
                System.exit(1);
            }
        }

        public MyScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
            st = new StringTokenizer("");
        }

        String nextToken() {
            try {
                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(br.readLine());

            } catch (IOException e) {
                e.printStackTrace();
                System.exit(1);
            }

            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(this.nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(this.nextToken());
        }

        long nextLong() {
            return Long.parseLong(this.nextToken());
        }

        void close() throws IOException {
            br.close();
        }
    }

    int[] a;
    int n;
    
    class Point {
        double x;
        double y;
        double z;
        public Point(double a, double b, double c) {
            x = a;
            y = b;
            z = c;
        }
        
        double length() {
            return Math.sqrt(x * x + y * y + z * z);
        }
    }
    
    double get(Point a, Point b, double v) {
        Point c = new Point(b.x - a.x, b.y - a.y, b.z - a.z);
        return c.length() / v;
    }
    
    Point func(Point a, Point b, double k) {
        return new Point(a.x + (b.x - a.x) * k, a.y + (b.y - a.y) * k, a.z + (b.z - a.z) * k);
    }

    void solve() throws IOException {
        n = in.nextInt();
        Point[] a = new Point[n + 1];
        for (int i = 0; i <= n; i++)
            a[i] = new Point(in.nextInt(), in.nextInt(), in.nextInt());
        
        double vp = in.nextDouble();
        double vs = in.nextDouble();
        Point p = new Point(in.nextInt(), in.nextInt(), in.nextInt());
        double t = 0;
        double eps = 1e-10;
        
        if (a[0].x == p.x && a[0].y == p.y && a[0].z == p.z) {
            out.println("YES");
            out.println(0);
            out.println(p.x + " " + p.y + " " + p.z);
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            double dt = get(a[i - 1], a[i], vs);
            double r = get(p, a[i], vp);
            if (t + dt > r - eps) {
                double left = 0;
                double right = dt;
                int cnt = 0;
                while (right - left > eps && cnt < 1000) {
                    cnt++;
                    double h = (left + right) / 2;
                    Point f = func(a[i - 1], a[i], h / dt);
                    double x = get(a[i - 1], f, vs) + t;
                    double y = get(p, f, vp);
                    if (x > y)
                        right = h;
                    else
                        left = h;
                }
                
                double time = (left + right) / 2;
                out.println("YES");
                out.println(t + time);
                Point f = func(a[i - 1], a[i], time / dt);
                out.println(f.x + " " + f.y + " " + f.z);
                return;
            }
            
            t = t + dt;
        }
        
        out.println("NO");
    }

    void run() {
        try {
            in = new MyScanner(System.in);
            out = new PrintWriter(System.out);

            solve();

            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }

    }

    public static void main(String[] args) {
        new C().run();
    }

}