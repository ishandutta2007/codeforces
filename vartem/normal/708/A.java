import java.io.*;
import java.util.*;

public class A {

    public void solve() {
        String s = in.nextToken();
        int start = s.length() - 1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != 'a') {
                start = i;
                break;
            }
        }

        int end = s.length() - 1;
        for (int i = start + 1; i < s.length(); i++) {
            if (s.charAt(i) == 'a') {
                end = i - 1;
                break;
            }
        }

        char[] c = s.toCharArray();
        for (int i = start; i <= end; i++) {
            int code = (c[i] - 'a' + 25) % 26;
            c[i] = (char) (code + 'a');
        }
        out.println(new String(c));
    }

    public void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    FastScanner in;
    PrintWriter out;

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(fileName));
            } catch (FileNotFoundException e) {
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
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