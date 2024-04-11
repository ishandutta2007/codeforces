import java.io.*;
import java.util.*;

public class B {

    public void solve() {
        int a = in.nextInt(), b = in.nextInt();

        int[] p = new int[] { 2, 3, 5 };
        int ans = 0;
        for (int x : p) {
            int a1 = ord(a, x), a2 = ord(b, x);
            
            int min = Math.min(a1, a2);
            for (int t = min; t < a1; t++) {
                a /= x;
                ans++;
            }
            for (int t = min; t < a2; t++) {
                b /= x;
                ans++;
            }
        }

        if (a != b) {
            out.println(-1);
        } else {
            out.println(ans);
        }
    }

    int ord(int a, int k) {
        int r = 0;
        while (a % k == 0) {
            a /= k;
            r++;
        }
        return r;
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
        new B().run();
    }
}