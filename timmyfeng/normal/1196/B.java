import java.io.*;
import java.util.*;

public class Main {

  public static void main(String args[]) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);

    // parity of sum = parity of k
    // number of odd a >= k

    int t = in.nextInt();
    for (int i = 0; i < t; ++i) {
      int n = in.nextInt();
      int k = in.nextInt();
      int[] a = new int[n];

      int count = 0;

      for (int j = 0; j < n; ++j) {
        a[j] = in.nextInt();
        count += a[j] % 2;
      }

      if (count % 2 != k % 2 || count < k) {
        out.println("NO");
      } else {
        out.println("YES");
        boolean first = true;
        for (int j = 0; j < n && k > 1; ++j) {
          if (a[j] % 2 == 1) {
            if (first) {
              first = false;
            } else {
              out.print(j + " ");
              --k;
            }
          }
        }
        out.println(n);
      }
    }

    out.close();
  }

}

class InputReader {

  public BufferedReader reader;
  public StringTokenizer tokenizer;

  public InputReader(InputStream str) {
    reader = new BufferedReader(new InputStreamReader(str), 1 << 15);
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

  public long nextLong() {
    return Long.parseLong(next());
  }

}