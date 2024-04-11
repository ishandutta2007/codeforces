import java.io.*;
import java.util.*;

public class A {

    FastScanner in;
    PrintWriter out;

    void solve() {
        char[] c = in.nextToken().toCharArray();
        char[] d = in.nextToken().toCharArray();
        
        int t = c.length - 1;
        while (c[t] == 'z') {
            c[t] = 'a';
            t--;
        }
        c[t]++;
        
        if (!Arrays.equals(c, d)) {
            out.println(new String(c));
        } else {
            out.println("No such string");
        }
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