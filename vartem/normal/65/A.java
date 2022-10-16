import java.io.*;
import java.util.*;

public class A {

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
    int inf = Integer.MAX_VALUE;

    void solve() throws IOException {
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        int d = in.nextInt();
        int e = in.nextInt();
        int f = in.nextInt();
        double t1 = 0;
        double t2 = 0;
        double t3 = 0;
        
        if (b != 0)
            t1 = (a * 1.0 / b);
        if (d != 0)
            t2 = (c * 1.0 / d);
        if (f != 0)
            t3 = (e * 1.0 / f);
        
        if (b != 0 && d != 0 && f != 0) {
            if (t1 * t2 * t3 > 1 - 1e-9)
                out.println("Hermione");
            else
                out.println("Ron");
        } else {
            if (d == 0) {
                out.println("Hermione");
                return;
            }
            
            if (c == 0) {
                out.println("Ron");
                return;
            }
            
            if (b == 0) {
                out.println("Hermione");
                return;
            }
            
            if (a == 0) {
                out.println("Ron");
                return;
            }
            
            if (f == 0) {
                out.println("Hermione");
                return;
            }
            
            if (e == 0) {
                out.println("Ron");
                return;
            }
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
        new A().run();
    }

}