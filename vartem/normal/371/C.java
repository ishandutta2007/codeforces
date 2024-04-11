import java.io.*;
import java.util.*;

public class C {

    String s = "BSC";
    
    public void solve() {
        int[] need = new int[3];
        for (char c : in.nextToken().toCharArray()) {
            need[s.indexOf(c)]++;
        }
        
        int[] have = new int[3];
        int[] price = new int[3];

        for (int i = 0; i < 3; i++) {
            have[i] = in.nextInt();
        }
        for (int j =0 ; j < 3; j++) {
            price[j] = in.nextInt();
        }
        long r = in.nextLong();
        
        long left = -1, right = (long) 1e15;
        while (left < right - 1) {
            long mid = (left + right) >> 1;
            
            long[] a = new long[3];
            for (int i = 0; i < 3; i++) {
                a[i] = mid * need[i];
            }
            long sum = 0;
            for (int i = 0; i < 3; i++) {
                long buy = Math.max(0, a[i] - have[i]);
                sum += buy * price[i];
            }
            if (sum <= r) {
                left = mid;
            } else {
                right = mid;
            }
        }
        out.println(left);
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