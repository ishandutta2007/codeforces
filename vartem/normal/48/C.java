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
    
    double can1(double t) {
        double g = 2 * t - a[0] * 10;
        for (int i = 1; i < n; i++) {
            if ((a[i] - a[i - 1]) * 10 > g)
                return -1;
            g = g - (a[i] - a[i - 1]) * 10 + t;
        }
        return g;
    }
    
    double can2(double t) {
        double g = 2 * t - a[0] * 10;
        for (int i = 1; i < n; i++) {
            if (g - (a[i] - a[i - 1]) * 10 >= 10)
                return -1;
            g = g - (a[i] - a[i - 1]) * 10 + t;
        }
        return g;
    }
    
    
    void solve() throws IOException {
        n = in.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) 
            a[i] = in.nextInt();
        
        int[] b = new int[n];
        double l = 0;
        double r = 100000 * 1000;
        while (r - l > 1e-8) {
            double h = (l + r) / 2;
            if (Math.abs(can2(h) + 1) < 1e-5)
                r = h;
            else
                l = h;
        }
        
        double max = r;
        
        l = 0;
        r = 100000 * 1000;
        while (r - l > 1e-8) {
            double h = (l + r) / 2;
            if (Math.abs(can1(h) + 1) < 1e-5)
                l = h;
            else
                r = h;
        }
        
        double min = l;
        
        int t1 = (int)(Math.floor(can1(min + 1e-8) / 10));
        int t2 = (int)(Math.floor(can2(max - 1e-8) / 10));
        
        if (t2 > t1) 
            out.println("not unique");
        else {
            out.println("unique");
            out.println(a[n - 1] + t1);
        }
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