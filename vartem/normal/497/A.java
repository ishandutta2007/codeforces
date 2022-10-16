import java.io.*;
import java.util.*;

public class A2 {

    FastScanner in;
    PrintWriter out;

    char[][] field;

    boolean[] delete;

//  void go(char[][] field, int l, int r, int col) {
//      if (col == field[0].length) {
//          return;
//      }
//      if (l == r + 1) {
//          return;
//      }
//
//      boolean sorted = true;
//      for (int i = l; i + 1 < r; i++) {
//          if (field[i][col] > field[i + 1][col]) {
//              sorted = false;
//          }
//      }
//      if (!sorted) {
//          delete[col] = true;
//          go(field, l, r, col + 1);
//      } else {
//          for (int i = l; i < r;) {
//              int j = i;
//              while (j < r && field[i][col] == field[j][col]) {
//                  j++;
//              }
//              go(field, i, j, col + 1);
//              i = j;
//          }
//
//      }
//  }

    void solve() {
        int n = in.nextInt(), m = in.nextInt();
        field = new char[n][];
        for (int i = 0; i < n; i++) {
            field[i] = in.nextToken().toCharArray();
        }

        List<Integer>[] l = new List[m + 1], r = new List[m + 1];
        for (int i = 0; i < l.length; i++) {
            l[i] = new ArrayList<>();
            r[i] = new ArrayList<>();
        }
        l[0].add(0);
        r[0].add(n);

        int ans = 0;

        for (int col = 0; col < m; col++) {
            boolean del = false;

            for (int seg = 0; seg < l[col].size(); seg++) {
                int ll = l[col].get(seg), rr = r[col].get(seg);
                for (int i = ll; i + 1 < rr; i++) {
                    if (field[i][col] > field[i + 1][col]) {
                        del = true;
                    }
                }
            }
            if (del) {
                l[col + 1].addAll(l[col]);
                r[col + 1].addAll(r[col]);
                ans++;
                continue;
            }
            
            for (int seg = 0; seg < l[col].size(); seg++) {
                int ll = l[col].get(seg), rr = r[col].get(seg);
                for (int i = ll; i < rr; ) {
                    int j = i;
                    while (j < rr && field[i][col] == field[j][col]) {
                        j++;
                    }
                    l[col + 1].add(i);
                    r[col + 1].add(j);
                    i = j;
                }
            }
        }
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
        new A2().run();
    }
}