import java.io.*;
import java.util.*;

public class Main {

  public static void main(String args[]) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);

    // suppose that b < w
    // for a good component to exist,
    // w <= 3b + 1 must hold.

    int t = in.nextInt();
    for (int tt = 0; tt < t; ++tt) {
      int b = in.nextInt();
      int w = in.nextInt();
      int o = 1;

      if (w < b) {
        int tmp = b;
        b = w;
        w = tmp;
        o = 0;
      }

      if (w > 3 * b + 1) {
        out.println("NO");
      } else {
        out.println("YES");

        for (int i = 0; i < b; ++i) {
          out.println(2 + " " + (2 * i + 1 + o));
          out.println(2 + " " + (2 * i + 2 + o));
        }
        w -= b;

        for (int i = 0; i < b; ++i) {
          if (w > 0) {
            out.println(1 + " " + (2 * i + 2 + o));
            --w;
          }

          if (w > 0) {
            out.println(3 + " " + (2 * i + 2 + o));
            --w;
          }
        }

        if (w > 0) {
          out.println(2 + " " + (2 * b + 1 + o));
        }
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