import java.io.*;
import java.util.*;

public class B {

    public void solve() {
        int n = in.nextInt(), t = in.nextInt(), c = in.nextInt();
        Item[] a = new Item[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Item(in.nextInt(), i);
        }

        int ans = 0;
        TreeSet<Item> set = new TreeSet<>();
        for (int i = 0; i < c; i++) {
            set.add(a[i]);
        }
        
        
        if (set.last().val <= t) {
            ans++;
        }
        for (int i = 0; i + c < n; i++) {
            set.remove(a[i]);
            set.add(a[i + c]);
            if (set.last().val <= t) {
                ans++;
            }
        }
        out.println(ans);
    }

    class Item implements Comparable<Item> {
        int val, i;

        public Item(int val, int i) {
            super();
            this.val = val;
            this.i = i;
        }

        @Override
        public int compareTo(Item o) {
            if (val != o.val) {
                return val - o.val;
            }
            return i - o.i;
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
        new B().run();
    }
}