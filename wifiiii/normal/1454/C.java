import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        SC sc = new SC();
        int t = sc.nextInt();
        while(t > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            int[] cnt = new int[n];
            boolean[] vis = new boolean[n];
            for(int i = 0; i < n; ++i) {
                a[i] = sc.nextInt() - 1;
            }
            for(int i = 0; i < n; ++i) {
                vis[a[i]] = true;
                if(i + 1 < n && a[i] == a[i+1]) continue;
                else cnt[a[i]] += 1;
            }
            cnt[a[0]]--;
            cnt[a[n-1]]--;
            int ans = n;
            for(int i = 0; i < n; ++i) {
                if(vis[i]) {
                    ans = Math.min(ans, cnt[i] + 1);
                }
            }
            System.out.println(ans);
            t--;
        }
    }

    public static class SC {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public SC() {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }
        public String next() {
            while(tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}