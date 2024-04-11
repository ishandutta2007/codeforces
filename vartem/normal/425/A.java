import java.io.*;
import java.util.*;

public class A {

    public void solve() {
        int n = in.nextInt(), k = in.nextInt();
        Item[] a = new Item[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Item(in.nextInt(), i);
        }
        Item[] b = a.clone();
        Arrays.sort(b);

        int max = Integer.MIN_VALUE;

        for (int l = 0; l < n; l++) {
            int sum = 0;

            TreeSet<Item> setIn = new TreeSet<>(), setOut = new TreeSet<>();
            for (int i = 0; i < n; i++) {
                setOut.add(a[i]);
            }

            for (int r = l; r < n; r++) {
                setIn.add(a[r]);
                setOut.remove(a[r]);
                sum += a[r].val;
                
                int newSum = sum;
                max = Math.max(max, newSum);
                if (setIn.isEmpty() || setOut.isEmpty()) {
                    continue;
                }
                Item i1 = setIn.first(), i2 = setOut.last();
                for (int j = 0; j < k; j++) {
                    if (i1 == null || i2 == null) {
                        break;
                    }
                    
                    newSum += i2.val - i1.val;
                    max = Math.max(max, newSum);
                    i1 = setIn.higher(i1);
                    i2 = setOut.lower(i2);
                }
            }
        }
        out.println(max);
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
                return Integer.compare(val, o.val);
            }
            return Integer.compare(i, o.i);
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