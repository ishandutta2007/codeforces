import java.math.BigInteger;
import java.util.*;
import java.io.*;
import java.lang.Math;
public class run {
    static class fr {
        BufferedReader br;
        StringTokenizer st;

        public fr() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
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
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        int[] readArr(int n) {
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = this.nextInt();
            }
            return a;
        }
    }

    static int sum(int[] a) {
        int s = 0;
        for (int i : a) s += i;
        return s;
    }

    static boolean unique(int n[]) {
        HashSet<Integer> s = new HashSet<>();
        for (int i : n) s.add(i);
        return s.size() > 1;
    }


    public static void main(String args[]) {
        fr s = new fr();
        int n = s.nextInt();
        for (int x = 0; x < n; x++) {
            int size = s.nextInt();
            int d[] = new int[size];
            int mx = 0;
            for (int i = 0; i < size; i++) {
                d[i] = s.nextInt();
                mx = Math.max(d[i], mx);
            }
            if (!unique(d) || size < 2) {
                System.out.println(-1);
                continue;
            }
            int pos = 0;
            if (d[0] == mx && d[1] != d[0]) pos = 1;
            if (d[size - 1] == mx && d[size - 2] != d[size - 1]) pos = size;
            for (int i = 1; i < size - 1; i++) {
                if (d[i] == mx && (d[i] != d[i + 1] || d[i] != d[i - 1])) pos = i + 1;
            }
            System.out.println(pos);
        }
    }
}