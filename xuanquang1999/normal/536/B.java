import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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
        MyScanner in = new MyScanner();

        int n = in.nextInt(), m = in.nextInt();
        String p = in.next();
        int y[] = new int[m];
        for (int i = 0; i < m; ++i)
            y[i] = in.nextInt() - 1;

        //Calculating the prefix function
        int pref[] = new int[p.length()];
        pref[0] = 0;
        int j = 0;
        for (int i = 1; i < p.length(); ++i) {
            while (j > 0 && p.charAt(i) != p.charAt(j))
                j = pref[j - 1];
            if (p.charAt(i) == p.charAt(j))
                ++j;
            pref[i] = j;
        }

        //isPrefix[i] Check if the i-th suffix (0-order) of string p is the same with the i-th prefix
        boolean isPrefix[] = new boolean[p.length()];
        j = p.length();
        while (j > 0) {
            isPrefix[j-1] = true;
            j = pref[j-1];
        }

        //cnt: number of undetermined position in s

        int cnt = n;
        if (m > 0) {
            cnt = y[0] + (n - y[m - 1] - p.length());
            for (int i = 0; i < m - 1; ++i) {
                //Number of common character between y[i] and y[i+1]
                int x = y[i + 1] - y[i];
                if (x >= p.length())
                    cnt += x - p.length();
                else if (!isPrefix[p.length()-x-1]) {
                    System.out.println(0);
                    return;
                }
            }
        }

        int ans = 1;
        for(int i = 0; i < cnt; ++i)
            ans = (int)((ans*26L)%1000000007);
        System.out.println(ans);
    }
}