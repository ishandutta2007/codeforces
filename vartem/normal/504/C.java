import java.io.*;
import java.util.*;

public class C {

    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] count = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
            count[a[i]]++;
        }

        int cnt = 0;
        int odd = -1;
        for (int i = 0; i < n; i++) {
            if (count[i] % 2 == 1) {
                cnt++;
                odd = i;
            }
        }
        if (cnt > 1) {
            out.println(0);
            return;
        }

        int len = 0;
        while (len < n && a[len] == a[n - len - 1]) {
            len++;
        }

        long ans = 0;
        if (len == n) {
            ans = 1L * n * (n + 1) / 2;
            out.println(ans);
            return;
        }

        for (int IT = 0; IT < 2; IT++) {

            int pos = len;
            int left = pos - 1, right = n;

            while (left < right - 1) {
                int mid = (left + right) >>> 1;

                boolean ok = true;
                int i = pos, j = mid;
                Arrays.fill(count, 0);
                for (int t = i; t <= j; t++) {
                    count[a[t]]++;
                }

                int cntOdd = 0;
                for (int t = 0; t < n; t++) {
                    if (count[t] % 2 == 1) {
                        cntOdd++;
                    }
                }

                for (int l = 0, r = a.length - 1; l < r; l++, r--) {
                    if (l < i && r > j || r < i || j < l) {
                        if (a[l] != a[r]) {
                            ok = false;
                        }
                    } else if (i <= l && r <= j) {
                        if (n % 2 == 1 && cntOdd > 1 || n % 2 == 0 && cntOdd > 0) {
                            ok = false;
                        }
                    } else if (l < i && r <= j) {
                        if (count[a[l]] == 0) {
                            ok = false;
                        }
                        if (count[a[l]] % 2 == 1) {
                            cntOdd--;
                        }
                        count[a[l]]--;
                        if (count[a[l]] % 2 == 1) {
                            cntOdd++;
                        }

                    } else {
                        if (count[a[r]] == 0) {
                            ok = false;
                        }
                        if (count[a[r]] % 2 == 1) {
                            cntOdd--;
                        }
                        count[a[r]]--;
                        if (count[a[r]] % 2 == 1) {
                            cntOdd++;
                        }
                    }
                }
                if (ok) {
                    right = mid;
                } else {
                    left = mid;
                }
            }

            ans += 1L * (len + 1) * (n - right);
            for (int l = 0, r = n - 1; l < r; l++, r--) {
                int tmp = a[l];
                a[l] = a[r];
                a[r] = tmp;
            }
        }

        ans -= 1L * (len + 1) * (len + 1);
        out.println(ans);
    }

    void run() {
        in = new FastScanner();
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String nextToken() {
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
        new C().run();
    }
}