import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.StringTokenizer;

public class A {

    MyScanner in;
    PrintWriter out;
    final static String filename = "";

    class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner(String filename) {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            try {

                while (st == null || !st.hasMoreTokens())
                    st = new StringTokenizer(br.readLine());
                return st.nextToken();

            } catch (IOException e) {
                e.printStackTrace();
                return null;
            }

        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    int n;

    void solve() throws IOException {
        int a = in.nextInt();
        int b = in.nextInt();
        double r = Math.sqrt(a * a + b * b);
        double angle = Math.atan2(b, a);
        r = r - Math.floor(r / 2) * 2;
        boolean f = true;
        angle += Math.PI * 2;
        angle = angle - Math.floor(angle / (Math.PI)) * Math.PI;
        if ((r > 1 && r < 2 && angle > 0 && angle < (Math.PI / 2))
                || (r > 0 && r < 1 && angle > (Math.PI / 2) && angle < (Math.PI)))
            out.println("white");
        else
            out.println("black");
    }

    void run() {
        try {
            in = new MyScanner(filename + ".in");
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