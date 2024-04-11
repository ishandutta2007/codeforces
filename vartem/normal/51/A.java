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
    
    boolean eq(String s1, String s2, String p1, String p2) {
        boolean ans = false;
        
        if (s1.equals(p1) && s2.equals(p2))
            ans = true;
        
        if (s1.charAt(0) == p1.charAt(1) &&
            s1.charAt(1) == p2.charAt(1) &&
            s2.charAt(1) == p2.charAt(0) &&
            s2.charAt(0) == p1.charAt(0))
            ans = true;
        
        if (s1.charAt(0) == p2.charAt(1) &&
                s1.charAt(1) == p2.charAt(0) &&
                s2.charAt(1) == p1.charAt(0) &&
                s2.charAt(0) == p1.charAt(1))
                ans = true;
        
        if (s1.charAt(0) == p2.charAt(0) &&
                s1.charAt(1) == p1.charAt(0) &&
                s2.charAt(1) == p1.charAt(1) &&
                s2.charAt(0) == p2.charAt(1))
                ans = true;
        
        return ans;
    }

    void solve() throws IOException {
        n = in.nextInt();
        String[] a1 = new String[n];
        String[] a2 = new String[n];
        int cnt = 0;    
        for (int i = 0; i < n; i++) {
            a1[i] = in.nextToken();
            a2[i] = in.nextToken();
            boolean t = false;
            for (int j = 0; j < i; j++)
                if (eq(a1[i], a2[i], a1[j], a2[j]))
                    t = true;
            if (!t)
                cnt++;
            if (i < n - 1) {
                String trash = in.nextToken();
            }
        }
        
        out.println(cnt);

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