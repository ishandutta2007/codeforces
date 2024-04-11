import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        InputStream inStream = System.in;
        OutputStream outStream = System.out;
        InputReader in = new InputReader(inStream);
        PrintWriter out = new PrintWriter(outStream);
        Solver solver = new Solver();
        solver.solve(in, out);
        out.close();
    }

    static class Solver {
        static final int N = 50000;
        static long a[] = new long[N];
        static boolean isPrime[] = new boolean[1000006];
        static long primes[] = new long[228];
        static int pw[][] = new int[N][20];
        static int fin[] = new int[20];
        static long prec[][] = new long[100][100];

        static long gcd(long x, long y){
            return x > 0 ? gcd(y%x, x) : y;
        }

        static void sieve(){
            Arrays.fill(isPrime, true);
            for(int i = 2; i < 1000006; i++){
                if(!isPrime[i]){
                    continue;
                }
                for(int j = i + i; j < 1000006; j += i){
                    isPrime[j] = false;
                }
            }
        }

        public static void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long k = in.nextLong();
            //int n = 1000;
            //long k = 963761198400L;
            if(k == 1){
                int pos = -1;
                for(int i = 0; i < n; i++){
                    a[i] = in.nextLong();
                    if(pos == -1 || a[i] < a[pos])
                        pos = i;
                }
                out.println(1);
                out.println(pos + 1);
                return;
            }
            int sz = 0;
            int totp = 0;
            sieve();
            long rem = k;
            for (int i = 2; i < 1000006; i++) {
                if(isPrime[i] && rem%i == 0){
                    primes[totp] = i;
                    while(rem%i == 0){
                        rem /= i;
                    }
                    ++totp;
                }
            }
            if(rem > 1){
                primes[totp] = rem;
                ++totp;
            }
            long tmp = k;
            for(int j = 0; j < totp; j++){
                while(k%primes[j] == 0){
                    k /= primes[j];
                    ++fin[j];
                }
            }
            k = tmp;
            sz = 1;
            for(int j = 0; j < totp; j++)
                sz *= (fin[j] + 1);
            for(int t = 0; t < totp; t++){
                prec[t][0] = 1;
                for(int i = 1; i <= fin[t]; i++){
                    prec[t][i] = prec[t][i - 1] * primes[t];
                }
            }
            int[][] dp = new int[n + 1][sz];
            long[][] sum = new long[n + 1][sz];
            int[][] prv = new int[n + 1][sz];
            for(int i = 0; i < n + 1; i++){
                for(int j = 0; j < sz; j++){
                    dp[i][j] = 1488;
                }
            }
            dp[0][0] = 0;
            for(int i = 0; i < sz; i++){
                int cid = i;
                for(int t = totp - 1; t >= 0; t--){
                    pw[i][t] = cid%(fin[t] + 1);
                    cid /= fin[t] + 1;
                }
            }
            for(int i = 0; i < n; i++){
                a[i] = in.nextLong();
                //a[i] = k;
                long old = a[i];
                a[i] = gcd(a[i], k);
                int[] apw = new int[totp];
                for(int t = 0; t < totp; t++){
                    while(a[i]%primes[t] == 0){
                        a[i] /= primes[t];
                        ++apw[t];
                    }
                }
                for(int j = 0; j < sz; j++){
                    dp[i + 1][j] = dp[i][j];
                    sum[i + 1][j] = sum[i][j];
                    prv[i + 1][j] = j;
                }
                for(int j = 0; j < sz; j++){
                    int pos = 0;
                    int mul = 1;
                    for(int t = totp - 1; t >= 0; t--){
                        int curr = pw[j][t] + apw[t];
                        curr = curr > fin[t] ? fin[t] : curr;
                        pos += curr * mul;
                        mul *= fin[t] + 1;
                    }
                    if(dp[i + 1][pos] > dp[i][j] + 1 || (dp[i + 1][pos] == dp[i][j] + 1 && sum[i + 1][pos] > sum[i][j] + old)){
                        dp[i + 1][pos] = dp[i][j] + 1;
                        sum[i + 1][pos] = sum[i][j] + old;
                        prv[i + 1][pos] = j;
                    }
                }
            }
            int i = n, j = sz - 1;
            if(dp[i][j] == 1488){
                out.println(-1);
                return;
            }
            out.println(dp[i][j]);
            ArrayList<Integer> ans = new ArrayList<>();
            while(i > 0){
                if(prv[i][j] != j){
                    j = prv[i][j];
                    ans.add(i);
                }
                --i;
            }
            for(Integer x : ans){
                out.print(x);
                out.print(' ');
            }
        }
    }

    static class InputReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader (InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next () {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
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
    }
}