import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.math.BigInteger;
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

        public static void solve(InputReader in, PrintWriter out) {
            int T = in.nextInt();
            while(T-- > 0){
                int n = in.nextInt();
                BigInteger nn = BigInteger.valueOf(n);
                BigInteger np = nn.nextProbablePrime();
                int m = n;
                while(!BigInteger.valueOf(m).isProbablePrime(30)){
                    --m;
                }
                BigInteger pp = BigInteger.valueOf(m);
                BigInteger P = np.multiply(pp);
                P = P.subtract(BigInteger.valueOf(2).multiply(pp.add(np)));
                P = P.add(BigInteger.valueOf(2*n + 2));
                BigInteger Q = np.multiply(pp);
                Q = Q.add(Q);
                BigInteger G = P.gcd(Q);
                P = P.divide(G);
                Q = Q.divide(G);
                out.print(P.toString());
                out.print('/');
                out.println(Q.toString());
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