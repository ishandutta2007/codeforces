import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in Actual solution is at the top
 *
 * @author Hieu Le
 */
public class Main {
  public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    TaskB solver = new TaskB();
    solver.solve(1, in, out);
    out.close();
  }

  static class TaskB {
    private static final int MAX = (int) 1e6;
    private static final int N = 2000;
    private List<Integer> primes;

    public TaskB() {
      primes = new ArrayList<>();
      boolean[] sieve = sieve(N);
      for (int i = 2; i <= N; ++i) if (sieve[i]) primes.add(i);
    }

    public static boolean[] sieve(int maxValue) {
      boolean[] isPrime = new boolean[maxValue + 1];
      Arrays.fill(isPrime, true);
      isPrime[0] = isPrime[1] = false;
      int limit = (int) Math.sqrt(maxValue);
      for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
          for (int j = i; i * j <= maxValue; ++j) isPrime[i * j] = false;
        }
      }
      return isPrime;
    }

    private int naive(int[] a) {
      int res = 0, cur = 0, k = -1;
      for (int i = 0; i < a.length; ++i) {
        cur += a[i];
        if (cur < 0) {
          cur = 0;
          k = i;
        }
        res = Math.max(res, (i - k) * cur);
      }
      return res;
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
      int k = in.nextInt();

      for (int b = 1; b <= MAX; ++b) {
        int sum = b + k;
        int min = sum / b;
        for (int n = min + 1; n <= Math.min(sum, N); ++n) {
          if (sum % n == 0) {
            int delta = sum / n;
            if (b > delta) {
              out.println(n);
              for (int i = 0; i < n - 2; ++i) out.print("0 ");
              int a = -(b - delta);
              out.printf("%d %d\n", a, b);
              int[] arr = new int[n];
              arr[n - 2] = a;
              arr[n - 1] = b;

              if (naive(arr) + k != sum) {
                throw new RuntimeException();
              }
              return;
            }
          }
        }
      }

      out.println(-1);
    }
  }

  static class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;
    private static final int BUFFER_SIZE = 32768;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), BUFFER_SIZE);
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

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}