import java.io.*;
import java.util.*;

public class C {

    MyScanner in;
    PrintWriter out;
    final static String filename = new String("C").toLowerCase();

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

    boolean[] a;
    int n;
    
    void go(int l, int n, int m) {
        if (a[l] == true)
            return;
        
        a[l] = true;
        int l1 = l + (m - 1) * 2;
        l1 = (l1 + 6 * (2 * (n - 1))) % (2 * (n - 1));
        
        if (l1 >= n)
            l1 = 2 * n - 2 - l1;
        
        go(l1, n, m);
        
        l1 = l - (m - 1) * 2;
        l1 = (l1 + 6 * (2 * (n - 1))) % (2 * (n - 1));
        
        if (l1 >= n)
            l1 = 2 * n - 2 - l1;
        
        go(l1, n, m);

    }
    

    void solve() throws IOException {
        n = in.nextInt();
        int m = in.nextInt();
        if (m > n) {
            int t = m;
            m = n;
            n = t;
        }
        a = new boolean[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == true)
                continue;
            ans++;
            go(i, n, m);
        }
        out.println(ans);
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