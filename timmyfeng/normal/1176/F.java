import java.io.*;
import java.util.*;

public class Main {

  static long[][] points;

  static void update(int b, long[] a) {
    long max = 0, sum = 0;
    for (long i : a) {
      max = Math.max(max, i);
      sum += i;
    }

    for (int i = 0; i < 10; ++i) {
      boolean bonus = false;
      int j = i + a.length;
      if (j >= 10) {
        bonus = true;
        j -= 10;
      }
      points[b + 1][j] = Math.max(points[b + 1][j], points[b][i] + sum + (bonus ? max : 0));
    }
  }

  public static void main(String args[]) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);

    int n = in.nextInt();

    points = new long[n + 1][10];
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < 10; ++j) {
        points[i][j] = Long.MIN_VALUE;
      }
    }
    points[0][0] = 0;

    for (int i = 0; i < n; ++i) {
      List<Long>[] cards = new List[3 + 1];
      for (int j = 0; j <= 3; ++j) {
        cards[j] = new ArrayList<>();
      }

      int k = in.nextInt();
      for (int j = 0; j < k; ++j) {
        cards[in.nextInt()].add(in.nextLong());
      }

      for (int j = 0; j <= 3; ++j) {
        cards[j].sort(Collections.reverseOrder());
      }

      update(i, new long[0]);

      if (cards[1].size() >= 1) {
        update(i, new long[]{cards[1].get(0)});
      }

      if (cards[1].size() >= 2) {
        update(i, new long[]{cards[1].get(0), cards[1].get(1)});
      }

      if (cards[1].size() >= 3) {
        update(i, new long[]{cards[1].get(0), cards[1].get(1), cards[1].get(2)});
      }

      if (cards[1].size() >= 1 && cards[2].size() >= 1) {
        update(i, new long[]{cards[1].get(0), cards[2].get(0)});
      }

      if (cards[2].size() >= 1) {
        update(i, new long[]{cards[2].get(0)});
      }

      if (cards[3].size() >= 1) {
        update(i, new long[]{cards[3].get(0)});
      }
    }

    long ans = Long.MIN_VALUE;
    for (int i = 0; i < 10; ++i) {
      ans = Math.max(ans, points[n][i]);
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