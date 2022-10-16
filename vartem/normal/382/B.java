import java.io.*;
import java.util.*;

public class B {

    public void solve() {
        long a = in.nextLong();
        int b = in.nextInt(), w = in.nextInt(), x = in.nextInt();
        long c = in.nextLong();

        long left = -1, right = (long) 1e15;
        int curB = b;
        boolean[] used = new boolean[10000];
        int[] vals = new int[10000];
        int counter = 0;
        int curAs = 0;
        while (!used[curB]) {
            used[curB] = true;
            if (curB < x) {
                curB += w;
                curAs++;
            }
            curB -= x;
            counter++;
            vals[counter] = curAs;
        }
            
        while (left < right - 1) {
            long mid = (left + right) >> 1;
            
            long rmn = mid / counter;
            int mod = (int) (mid % counter);
            long subAs = rmn * vals[counter] + vals[mod];
            
            if (c - mid <= a - subAs) {
                right = mid;
            } else {
                left = mid;
            }
        }
        out.println(right);
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