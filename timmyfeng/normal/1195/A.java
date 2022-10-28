import java.io.*;
import java.util.*;

public class Main {

  public static void main(String args[]) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);

    int n = in.nextInt();
    int k = in.nextInt();

    int pairs = 0;
    int[] c = new int[k + 1];
    for (int i = 0; i < n; ++i) {
      int a = in.nextInt();
      if (++c[a] % 2 == 0) {
        ++pairs;
      }
    }
    out.println(pairs * 2 + (n + 1) / 2 - pairs);

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