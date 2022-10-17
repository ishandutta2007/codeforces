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
            for(int i = 0; i < n; ++i) {
                a[i] = sc.nextInt() - 1;
                cnt[a[i]] += 1;
            }
            int ans = -1, mn = n;
            for(int i = 0; i < n; ++i) {
                if(cnt[a[i]] == 1 && a[i] < mn) {
                    mn = a[i];
                    ans = i + 1;
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