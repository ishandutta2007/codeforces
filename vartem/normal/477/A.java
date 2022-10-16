import java.io.*;
import java.util.*;

public class A {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int mod = 1000000007;
        int a = in.nextInt(), b = in.nextInt();
        
        int sum = 0;
        
        for (int rem = 1; rem < b; rem++) {
            long firstDiv = rem, lastDiv = (1L * rem * a) % mod;
            long cnt = a;
            
            long add = (firstDiv + lastDiv) * cnt % mod * (mod + 1) / 2 % mod;
            add %= mod;
            add *= b;
            add %= mod;
            long add2 = cnt * rem;
            add2 %= mod;
            
            sum += add;
            if (sum >= mod) {
                sum -= mod;
            }
            sum += add2;
            if (sum >= mod) {
                sum -= mod;
            }
        }
        out.println(sum);
    }

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
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
        new A().run();
    }
}