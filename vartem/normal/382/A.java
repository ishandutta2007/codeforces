import java.io.*;
import java.util.*;

public class A {

    String[] split(String s) {
        String[] res = new String[2];
        res[0] = res[1] = "";
        int i = 0;
        while (s.charAt(i) != '|') {
            res[0] += s.charAt(i++);
        }
        i++;
        while (i < s.length()) {
            res[1] += s.charAt(i++);
        }
        return res;
    }
    
    public void solve() {
        String[] s = split(in.nextToken());
        String t = in.nextToken();

        while (t.length() > 0) {
            if (s[0].length() < s[1].length()) {
                s[0] += t.charAt(0);
            } else {
                s[1] += t.charAt(0);
            }
            t = t.substring(1);
        }
        if (s[0].length() == s[1].length()) {
            out.println(s[0] + "|" + s[1]);
        } else {
            out.println("Impossible");
        }
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
        new A().run();
    }
}