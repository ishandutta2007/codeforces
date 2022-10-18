import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
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

    }

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();

        int n = sc.nextInt(), m = sc.nextInt(), x = sc.nextInt(), y = sc.nextInt();
        int a[] = new int[n];
        int b[] = new int[m];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();
        for(int i = 0; i < m; ++i)
            b[i] = sc.nextInt();


        ArrayList<Pair> ans = new ArrayList<>();

        int j = 0;
        for(int i = 0; i < n; ++i) {
            while (j < m && b[j] < a[i]-x)
                ++j;
            if (j < m && b[j] <= a[i]+y) {
                ans.add(new Pair(i+1, j+1));
                ++j;
            }
        }

        PrintWriter pw = new PrintWriter(System.out);
        pw.println(ans.size());
        for(Pair p: ans)
            pw.printf("%d %d\n", p.first, p.second);

        pw.close();
    }

    public static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

}