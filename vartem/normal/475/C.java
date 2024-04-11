import java.io.*;
import java.util.*;

public class C {

    FastScanner in;
    PrintWriter out;

    int[][] sum(int[][] a) {
        int[][] s = new int[a.length + 1][a[0].length + 1];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                s[i + 1][j + 1] = a[i][j];
                s[i + 1][j + 1] += s[i][j + 1];
                s[i + 1][j + 1] += s[i + 1][j];
                s[i + 1][j + 1] -= s[i][j];
            }
        }
        return s;
    }

    int get(int r1, int c1, int r2, int c2, int[][] s) {
        r1 = Math.max(r1, 0);
        c1 = Math.max(c1, 0);
        return s[r2 + 1][c2 + 1] - s[r1][c2 + 1] - s[r2 + 1][c1] + s[r1][c1];
    }

    void solve() {
        int n = in.nextInt(), m = in.nextInt();

        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            String s = in.nextToken();
            for (int j = 0; j < m; j++) {
                a[i][j] = s.charAt(j) == 'X' ? 1 : 0;
            }
        }

        int min = Integer.MAX_VALUE;
        for (int IT = 0; IT < 2; IT++) {
            int fi = -1, fj = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 1) {
                        fi = i;
                        fj = j;
                        break;
                    }
                }
                if (fi != -1) {
                    break;
                }
            }

            int ni = fi;
            while (ni < n && a[ni][fj] == 1) {
                ni++;
            }
            ni--;
            int height = ni - fi + 1;

            int[] first = new int[n], last = new int[n];
            Arrays.fill(first, m);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] == 1) {
                        first[i] = Math.min(first[i], j);
                        last[i] = Math.max(last[i], j);
                    }
                }
            }

            int width = 1;
            boolean ok = true;
            for (int i = ni + 1; i < n; i++) {
                if (first[i] == m) {
                    break;
                }
                if (first[i] < first[i - 1]) {
                    ok = false;
                    break;
                }
                if (last[i - height] < first[i]) {
                    ok = false;
                    break;
                }
                width = Math.max(width, last[i - height] - first[i] + 1);
            }

            if (ok) {
                int[][] check = new int[n][m];

                for (int i = ni; i < n; i++) {
                    if (first[i] == m) {
                        break;
                    }
                    
                    for (int j = first[i]; j + width - 1 <= last[i - height + 1]; j++) {
                        check[i - height + 1][j] = 1;
                    }
                }
                if (!good(check)) {
                    ok = false;
                }
                
                int[][] sum = sum(check);
                
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        int cnt = get(i - height + 1, j - width + 1, i, j, sum);
                        if (cnt > 1) {
                            cnt = 1;
                        }
                        if (cnt != a[i][j]) {
                            ok = false;
                        }
                    }
                }
                if (ok) {
                    min = Math.min(min, width * height);
                }
            }

            a = transpose(a);
            n = a.length;
            m = a[0].length;
        }
        if (min == Integer.MAX_VALUE) {
            out.println(-1);
        } else {
            out.println(min);
        }
    }

    private boolean good(int[][] check) {
        int sum = 0;
        for (int i = 0; i < check.length; i++) {
            for (int j = 0; j < check[0].length; j++) {
                sum += check[i][j];
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < check.length; i++) {
            for (int j = 0; j < check[0].length; j++) {
                if (check[i][j] == 1) {
                    int curI = i, curJ = j;
                    
                    while (true) {
                        cnt++;
                        boolean down = (curI + 1 < check.length) && (check[curI + 1][curJ] == 1);
                        boolean right = (curJ  + 1 < check[0].length) && (check[curI][curJ + 1] == 1);
                        
                        if (!down && !right) {
                            break;
                        }
                        if (down && right) {
                            return false;
                        }
                        if (down) {
                            curI++;
                        } else {
                            curJ++;
                        }
                    }
                    
                    return sum == cnt;
                }
            }
        }
        return false;
    }

    private int[][] transpose(int[][] a) {
        int[][] b = new int[a[0].length][a.length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                b[j][i] = a[i][j];
            }
        }
        return b;
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