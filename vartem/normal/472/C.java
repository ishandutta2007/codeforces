import java.io.*;
import java.util.*;

public class C {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        String[] a = new String[n], b = new String[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = in.nextToken();
            b[i] = in.nextToken();
            if (a[i].compareTo(b[i]) > 0) {
                String tmp = a[i];
                a[i] = b[i];
                b[i] = tmp;
            }
        }
        
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt() - 1;
        }
        
        String last = "";
        
        for (int i = 0; i < n; i++) {
            int id = p[i];
            if (a[id].compareTo(last) >= 0) {
                last = a[id];
            } else if (b[id].compareTo(last) >= 0) {
                last = b[id];
            } else {
                out.println("NO");
                return;
            }
        }
        out.println("YES");
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
        new C().run();
    }
}