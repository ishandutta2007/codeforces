import java.io.*;
import java.util.*;

public class Main {

  static void sort(int[] a) {
    List<Integer> b = new ArrayList<>();
    for (int i = 0; i < a.length; ++i) {
      b.add(a[i]);
    }
    Collections.sort(b);
    for (int i = 0; i < a.length; ++i) {
      a[i] = b.get(i);
    }
  }

  public static void main(String args[]) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);

    int n = in.nextInt();
    int k = in.nextInt();

    int[] a = new int[n];
    for (int i = 0; i < n; ++i) {
      a[i] = in.nextInt();
    }
    sort(a);

    int lo = a[n / 2], hi = a[n / 2] + k;
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      long sum = 0;
      for (int i = n / 2; i < n; ++i) {
        sum += Math.max(0, mid - a[i]);
      }
      if (sum <= k) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }

    out.println(lo);

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