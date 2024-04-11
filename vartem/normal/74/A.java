import java.io.*;
import java.util.*;

public class A {

    MyScanner in;
    PrintWriter out;
    final static String filename = new String("Temp").toLowerCase();

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

    void solve() throws IOException {
        n = in.nextInt();
        String s = "";
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            String r = in.nextToken();
            int h = in.nextInt();
            int uh = in.nextInt();
            int res = 100 * h - uh * 50;
            for (int j = 0; j < 5; j++)
                res += in.nextInt();
            if (res > max) {
                max = res;
                s = r;
            }
        }
        
        out.println(s);
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