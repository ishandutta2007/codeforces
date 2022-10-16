import java.io.*;
import java.util.*;

public class C {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt(), m = in.nextInt();

        boolean[] was = new boolean[n];
        int sumBefore = 0;

        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = in.nextInt();
        }

        List<Integer> stack = new ArrayList<Integer>();
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int x = in.nextInt() - 1;
            if (was[x]) {
                int pos = stack.indexOf(x);
                for (int t = 0; t < pos; t++) {
                    ans += w[stack.get(t)];
                }
                stack.remove(pos);
            } else {
                was[x] = true;
                ans += sumBefore;
                sumBefore += w[x];
            }
            stack.add(0, x);
        }
        out.println(ans);

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