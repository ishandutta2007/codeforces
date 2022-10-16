import java.io.*;
import java.util.*;

public class B {

    MyScanner in;
    PrintWriter out;
    final static String filename = new String("B").toLowerCase();

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
        int m = in.nextInt() - 1;
        int k = in.nextInt() - 1;
        String dir = in.nextToken();
        dir = in.nextToken();
        int d = 0;
        if (dir.equals("head"))
            d = -1;
        else
            d = 1;
        String s = in.nextToken();
        int l = s.length();
        char[] c = s.toCharArray();
        for (int i = 0; i < l; i++) {
                        
            k += d;
            if (m + d >= 0 && m + d < n)
                m += d;
            
            if (c[i] == '1') {
                if (d == -1)
                    m = n - 1;
                else
                    m = 0;
            }
            
            if (k == 0 || k == n - 1)
                d *= -1;
            
            if (k == m) {
                out.println("Controller " + (i + 1));
                return;
            }
        }
        out.println("Stowaway");
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
        new B().run();
    }

}