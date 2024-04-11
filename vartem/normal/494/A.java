import java.io.*;
import java.util.*;

public class Test {

    FastScanner in;
    PrintWriter out;

    void solve() {
        String s = in.nextToken();
        int balance = 0;
        List<Integer> pos = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                balance++;
            } else if (s.charAt(i) == ')') {
                balance--;
            } else {
                pos.add(i);
            }
        }

        if (balance < pos.size()) {
            out.println(-1);
            return;
        }

        StringBuilder sb = new StringBuilder();
        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '#') {
                if (i == pos.get(pos.size() - 1)) {
                    for (int t = 0; t < balance; t++) {
                        sb.append(')');
                    }
                    ans.add(balance);
                } else {
                    ans.add(1);
                    balance--;
                    sb.append(')');
                }
            } else {
                sb.append(s.charAt(i));
            }
        }

        s = sb.toString();
        balance = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                balance++;
            } else {
                balance--;
                if (balance < 0) {
                    out.println("-1");
                    return;
                }
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            out.println(ans.get(i));
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
        new Test().run();
    }
}