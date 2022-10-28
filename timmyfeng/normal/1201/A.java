import java.io.*;
import java.util.*;

public class Main {

  static final int A = 5;

  public static void main(String args[]) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);

    int n = in.nextInt();
    int m = in.nextInt();

    String[] s = new String[n];
    for (int i = 0; i < n; ++i) {
      s[i] = in.next();
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      int[] count = new int[A];
      int max = 0;
      for (int j = 0; j < n; ++j) {
        max = Math.max(max, ++count[s[j].charAt(i) - 'A']);
      }
      ans += max * in.nextInt();
    }

    out.println(ans);

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