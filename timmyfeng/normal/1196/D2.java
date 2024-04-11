import java.io.*;
import java.util.*;

public class Main {

  public static void main(String args[]) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);

    String target = "RGB";

    int t = in.nextInt();
    for (int tt = 0; tt < t; ++tt) {
      int n = in.nextInt();
      int l = in.nextInt();
      String s = in.next();

      int[][][] sum = new int[n + 1][3][3];
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
          for (int k = 0; k < 3; ++k) {
            sum[i + 1][j][k] = sum[i][j][k];
            if (s.charAt(i) == target.charAt(j) && i % 3 == k) {
              ++sum[i + 1][j][k];
            }
          }
        }
      }

      int ans = l;
      for (int i = 0; i + l - 1 < n; ++i) {
        for (int j = 0; j < 3; ++j) {
          int cost = l;
          for (int k = 0; k < 3; ++k) {
            cost -= sum[i + l][(k + j) % 3][k] - sum[i][(k + j) % 3][k];
          }
          ans = Math.min(ans, cost);
        }
      }

      out.println(ans);
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