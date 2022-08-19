import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public BigInteger nextRandomBigInteger(BigInteger n) {
            Random rand = new Random();
            BigInteger result = new BigInteger(n.bitLength(), rand);
            while( result.compareTo(n) >= 0 ) {
                result = new BigInteger(n.bitLength(), rand);
            }
            return result;
        }
        
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            BigInteger n = new BigInteger(in.next());
            List<BigInteger> factors = new ArrayList<>();
            factors.add(n);
            int idle = 0;
            while (idle < 20) {
              idle++;
              BigInteger x = nextRandomBigInteger(n);
              BigInteger y = x.multiply(x).mod(n);
              out.println("sqrt " + y);
              out.flush();
              BigInteger z = new BigInteger(in.next());
              if (z.compareTo(x) != 0) {
                BigInteger d = z.subtract(x).abs();
                boolean changed = true;
                while (changed) {
                  changed = false;
                  for (int i = 0; i < factors.size(); i++) {
                    BigInteger f = factors.get(i);
                    BigInteger e = d.gcd(f);
                    if (e.compareTo(BigInteger.ONE) > 0 && e.compareTo(f) < 0) {
                      factors.set(i, e);
                      factors.add(f.divide(e));
                      changed = true;
                      idle = 0;
                      break;
                    }
                  }
                }
              }
            }
            out.print("! " + factors.size());
            for (BigInteger f : factors) {
              out.print(" " + f);
            }
            out.println();
            out.flush();
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
    }
}