import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
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
        int n = sc.nextInt(), b = sc.nextInt();
        int t[] = new int[n];
        int d[] = new int[n];
        for(int i = 0; i < n; ++i) {
            t[i] = sc.nextInt();
            d[i] = sc.nextInt();
        }

        long ans[] = new long[n];
        for(int i = 0; i < n; ++i)
            ans[i] = -1;
        long cur = 0;
        Queue<Integer> q = new LinkedList<>();

        for(int i = 0; i < n; ++i) {
            while (t[i] >= cur && !q.isEmpty()) {
                int j = q.poll();
                cur += d[j];
                ans[j] = cur;
            }
            if (cur < t[i]) {
                cur = t[i]+d[i];
                ans[i] = cur;
            } else if (q.size() < b)
                q.add(i);
        }
        while (!q.isEmpty()) {
            cur += d[q.peek()];
            ans[q.poll()] = cur;
        }

        PrintWriter pw = new PrintWriter(System.out);
        for(int i = 0; i < n; ++i)
            pw.print(ans[i] + " ");
        pw.close();
    }
}