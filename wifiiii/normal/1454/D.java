import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        SC sc = new SC();
        int t = sc.nextInt();
        while(t > 0) {
            long n = sc.nextLong(), N = n;
            HashMap<Long, Integer> mp = new HashMap<>();
            for(long i = 2; i * i <= n; ++i) {
                if(n % i == 0) {
                    int cnt = 0;
                    while(n % i == 0) {
                        ++cnt;
                        n /= i;
                    }
                    mp.put(i, cnt);
                }
            }
            if(n > 1) mp.put(n, 1);
            long x = 0;
            int mx = 0;
            for(long p : mp.keySet()) {
                if(mp.get(p) > mx) {
                    mx = mp.get(p);
                    x = p;
                }
            }
            System.out.println(mx);
            for(int i = 1; i < mx; ++i) {
                System.out.print(x + " ");
                N /= x;
            }
            System.out.println(N);
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