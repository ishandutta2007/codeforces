import java.io.*;
import java.util.*;

public class Main {

  public static void main(String args[]) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);

    final int A = 100000;

    int t = in.nextInt();
    for (int i = 0; i < t; ++i) {
      int n = in.nextInt();

      int max_x = A;
      int min_x = -A;
      int max_y = A;
      int min_y = -A;

      for (int j = 0; j < n; ++j) {
        int x = in.nextInt();
        int y = in.nextInt();

        if (in.nextInt() == 0) {
          min_x = Math.max(min_x, x);
        }

        if (in.nextInt() == 0) {
          max_y = Math.min(max_y, y);
        }

        if (in.nextInt() == 0) {
          max_x = Math.min(max_x, x);
        }

        if (in.nextInt() == 0) {
          min_y = Math.max(min_y, y);
        }
      }

      if (min_x > max_x || min_y > max_y) {
        out.println(0);
      } else {
        out.println(1 + " " + max_x + " " + max_y);
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