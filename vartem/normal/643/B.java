import java.io.*;
import java.util.*;

public class B {

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        int a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();
        if (n == 4 || k < n - 1 + 2) {
            out.println(-1);
            return;
        }

        List<Integer> fst = new ArrayList<>();
        fst.add(a);
        fst.add(c);
        for (int i = 1; i <= n; i++) {
            if (i == a || i == b || i == c || i == d) {
                continue;
            }
            fst.add(i);
        }
        fst.add(d);
        fst.add(b);

        List<Integer> snd = new ArrayList<>();
        snd.add(c);
        snd.add(a);
        for (int i = 2; i < fst.size() - 2; i++) {
            snd.add(fst.get(i));
        }
        snd.add(b);
        snd.add(d);

        print(fst);
        print(snd);
    }

    private void print(List<Integer> snd) {
        for (int i : snd) {
            out.print(i + " ");
        }
        out.println();
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
        new B().run();
    }
}