import java.io.*;
import java.util.*;

public class A {

    public void solve() {
        int n = in.nextInt(), k = in.nextInt(), q = in.nextInt();
        Map<Integer, Integer> tById = new HashMap<>();
        TreeSet<Integer> curTs = new TreeSet<>();
        int[] ts = new int[n];
        for (int i = 0; i < n; i++) {
            ts[i] = in.nextInt();
        }
        for (int i = 0; i < q; i++) {
            int type = in.nextInt();
            int id = in.nextInt() - 1;
            if (type == 1) {
                curTs.add(ts[id]);
            } else {
                id = ts[id];
                if (!curTs.contains(id)) {
                    out.println("NO");
                    continue;
                }
                Integer fst = curTs.last();
                boolean ok = false;
                for (int j = 0; j < k && j < curTs.size(); j++) {
                    if (fst == id) {
                        out.println("YES");
                        ok = true;
                        break;
                    } else {
                        fst = curTs.lower(fst);
                    }
                }
                if (!ok) {
                    out.println("NO");
                }
            }
        }
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