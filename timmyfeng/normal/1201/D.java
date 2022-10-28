import java.io.*;
import java.util.*;

public class Main {

  public static void main(String args[]) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);

    int n = in.nextInt();
    int m = in.nextInt();
    int k = in.nextInt();
    int q = in.nextInt();

    int[] left = new int[n];
    int[] right = new int[n];
    for (int i = 0; i < n; ++i) {
      left[i] = m;
      right[i] = -1;
    }

    for (int i = 0; i < k; ++i) {
      int r = in.nextInt() - 1;
      int c = in.nextInt() - 1;
      left[r] = Math.min(left[r], c);
      right[r] = Math.max(right[r], c);
    }

    boolean[] safe = new boolean[m];
    for (int i = 0; i < q; ++i) {
      safe[in.nextInt() - 1] = true;
    }

    int[] prv = new int[m];
    for (int i = 0, j = -1; i < m; ++i) {
      if (safe[i]) {
        j = i;
      }
      prv[i] = j;
    }

    int[] nxt = new int[m];
    for (int i = m - 1, j = m; i >= 0; --i) {
      if (safe[i]) {
        j = i;
      }
      nxt[i] = j;
    }

    Map<Integer, Long> cost = new HashMap<>();
    if (left[0] > right[0]) {
      cost.put(nxt[0], (long) nxt[0] - 1);
    } else {
      cost.put(0, -1L);
    }

    long ans = 0;
    for (int i = 0; i < n; ++i) {
      Map<Integer, Long> new_cost = new HashMap<>();
      if (left[i] > right[i]) {
        for (Map.Entry<Integer, Long> p : cost.entrySet()) {
          new_cost.put(p.getKey(), p.getValue() + 1);
        }
      } else {
        long l = Long.MAX_VALUE, r = Long.MAX_VALUE;
        for (Map.Entry<Integer, Long> p : cost.entrySet()) {
          int length = right[i] - left[i];
          l = Math.min(l, p.getValue() + 1 + Math.abs(right[i] - p.getKey()) + length);
          r = Math.min(r, p.getValue() + 1 + Math.abs(left[i] - p.getKey()) + length);
        }
        ans = Math.min(l, r);

        if (prv[right[i]] > -1) {
          new_cost.put(prv[right[i]], r + right[i] - prv[right[i]]);
          if (prv[left[i]] > -1) {
            new_cost.put(prv[left[i]], l + left[i] - prv[left[i]]);
          }
        }

        if (nxt[left[i]] < m) {
          new_cost.put(nxt[left[i]], l + nxt[left[i]] - left[i]);
          if (nxt[right[i]] < m) {
            new_cost.put(nxt[right[i]], r + nxt[right[i]] - right[i]);
          }
        }
      }
      cost = new_cost;
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