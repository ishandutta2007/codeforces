import java.io.*;
import java.util.*;

public class C {
    
    class Item implements Comparable<Item> {
        int val, i;

        public Item(int val, int i) {
            super();
            this.val = val;
            this.i = i;
        }
        
        @Override
        public int compareTo(Item o) {
            return val - o.val;
        }
    }

    public void solve() {
        int n = in.nextInt();
        Item[] a = new Item[n];
        for (int i =0 ; i < n; i++) {
            a[i] = new Item(in.nextInt(), i);
        }
        Arrays.sort(a);
        
        int last = 0;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int newA = Math.max(last + 1, a[i].val);
            last = newA;
            ans[a[i].i] = newA;
        }
        for (int i = 0; i < n; i++) {
            out.print(ans[i] + " ");
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
        new C().run();
    }
}