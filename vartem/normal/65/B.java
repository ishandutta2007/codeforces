import java.io.*;
import java.util.*;

public class B {

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
    
    int dif(int a, int b) {
        int ans = 0;
        while (a > 0 && b > 0) {
            int t = a % 10;
            int g = b % 10;
            if (t != g)
                ans++;
            a /= 10;
            b /= 10;
        }
        return ans;
    }
    
    void solve() throws IOException {
        n = in.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            
        }
        
        int last = 1000;
        for (int i = 0; i < n; i++) {
            boolean f = false;
            for (int j = last; j <= 2011; j++) {
                if (dif(a[i], j) <= 1) {
                    a[i] = j;
                    f = true;
                    break;
                }
            }
            
            if (!f) {
                out.println("No solution");
                return;
            }
            last = a[i];
        }
        
        for (int i = 0; i < n; i++)
            out.println(a[i]);
        
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