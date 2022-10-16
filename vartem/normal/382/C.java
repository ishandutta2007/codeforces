import java.io.*;
import java.util.*;

public class C {

    public void solve() {
        int n = in.nextInt();
        Random rng = new Random();
        int[] a=  new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            int pos = rng.nextInt(i + 1);
            int tmp = a[i];
            a[i] = a[pos];
            a[pos] = tmp;
        }
        
        Arrays.sort(a);
        if (n == 1) {
            out.println(-1);
            return;
        }
        Set<Integer> set = new HashSet<>();
        int[] difs = new int[n - 1];
        for (int i = 0; i < n - 1; i++ ){
            difs[i] = a[i + 1] - a[i];
            set.add(difs[i]);
        }
        if (set.size() > 2) {
            out.println(0);
            return;
        }
        if (set.size() == 1) {
            int dif = set.iterator().next();
            Set<Integer> ans = new TreeSet<>();
            ans.add(a[0] - dif);
            ans.add(a[n - 1] + dif);
            if (n == 2 && dif % 2 == 0) {
                ans.add(a[0] + (dif / 2));
            }
            out.println(ans.size());
            for (int i : ans) {
                out.print(i + " ");
            }
            return;
        }
        
        Iterator<Integer> iter = set.iterator();
        int dif1 = iter.next(), dif2 = iter.next();
        if (dif1 > dif2) {
            int tmp = dif1;
            dif1 = dif2;
            dif2 = tmp;
        }
        if (dif2 != dif1 * 2) {
            out.println(0);
            return;
        }
        
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n - 1; i++) {
            if (difs[i] == dif1) {
                count1++;
            } else {
                count2++;
            }
        }
        if (count2 > 1) {
            out.println(0);
            return;
        }
        out.println(1);
        for (int i = 0; i < n - 1; i++) {
            if (difs[i] == dif2) {
                out.println(a[i] + dif1);
            }
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