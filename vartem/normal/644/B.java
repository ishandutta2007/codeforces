import java.io.*;
import java.util.*;

public class B {
    FastScanner in;
    PrintWriter out;

    class Order {
        int start, duration, id;
        long end = 0;

        public Order(int time, int duration, int id) {
            this.start = time;
            this.duration = duration;
            this.id = id;
        }
    }

    void solve() {
        int n = in.nextInt(), b = in.nextInt();
        Queue<Order> queue = new ArrayDeque<>();
        Order[] orders = new Order[n];
        for (int i = 0; i < n; i++) {
            orders[i] = new Order(in.nextInt(), in.nextInt(), i);
        }

        long busyUntil = 0;
        int ptr = 0;
        while (queue.size() > 0 || ptr < n) {
            while (queue.size() > 0 && (ptr == n || busyUntil <= orders[ptr].start)) {
                Order newBusy = queue.poll();
                busyUntil = newBusy.end = (Math.max(busyUntil, newBusy.start) + newBusy.duration);
            }

            if (ptr < n) {
                if (queue.size() < b) {
                    queue.add(orders[ptr++]);
                } else {
                    orders[ptr++].end = -1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            out.print(orders[i].end + " ");
        }
    }

    void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new B().runIO();
    }
}