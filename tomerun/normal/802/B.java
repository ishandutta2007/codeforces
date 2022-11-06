import java.io.*;
import java.util.ArrayList;
import java.util.TreeSet;

public class B {
  static FastScanner sc = new FastScanner(System.in);

  public static void main(String[] args) {
    int N = sc.nextInt();
    int K = sc.nextInt();
    int[] A = new int[N];
    ArrayList<ArrayList<Integer>> next = new ArrayList<>(N);
    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt() - 1;
      next.add(new ArrayList<>());
    }
    for (int i = N - 1; i >= 0; i--) {
      if (i < N - 1 && A[i] == A[i + 1]) continue;
      next.get(A[i]).add(i);
    }
    TreeSet<Long> q = new TreeSet<>((Long i1, Long i2) -> Long.compare(i1, i2));

    ArrayList<Integer> finished = new ArrayList<>();
    boolean[] contains = new boolean[N];
    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (i < N - 1 && A[i] == A[i + 1]) continue;
      ArrayList<Integer> list = next.get(A[i]);
      long v = ((long) list.get(list.size() - 1) << 32) | A[i];
      if (contains[A[i]]) {
        q.remove(v);
        list.remove(list.size() - 1);
      } else {
        ++ans;
        contains[A[i]] = true;
        list.remove(list.size() - 1);
        if (q.size() + finished.size() == K) {
          if (finished.isEmpty()) {
            long removed = q.pollLast();
            contains[(int) removed] = false;
          } else {
            contains[finished.get(finished.size() - 1)] = false;
            finished.remove(finished.size() - 1);
          }
        }
      }
      if (list.isEmpty()) {
        finished.add(A[i]);
      } else {
        q.add(((long) list.get(list.size() - 1) << 32) | A[i]);
      }
    }
    System.out.println(ans);
  }

  static class FastScanner {
    Reader input;

    FastScanner() {
      this(System.in);
    }

    FastScanner(InputStream stream) {
      this.input = new BufferedReader(new InputStreamReader(stream));
    }

    int nextInt() {
      return (int) nextLong();
    }

    long nextLong() {
      try {
        int sign = 1;
        int b = input.read();
        while ((b < '0' || '9' < b) && b != '-' && b != '+') {
          b = input.read();
        }
        if (b == '-') {
          sign = -1;
          b = input.read();
        } else if (b == '+') {
          b = input.read();
        }
        long ret = b - '0';
        while (true) {
          b = input.read();
          if (b < '0' || '9' < b) return ret * sign;
          ret *= 10;
          ret += b - '0';
        }
      } catch (IOException e) {
        e.printStackTrace();
        return -1;
      }
    }

    double nextDouble() {
      try {
        double sign = 1;
        int b = input.read();
        while ((b < '0' || '9' < b) && b != '-' && b != '+') {
          b = input.read();
        }
        if (b == '-') {
          sign = -1;
          b = input.read();
        } else if (b == '+') {
          b = input.read();
        }
        double ret = b - '0';
        while (true) {
          b = input.read();
          if (b < '0' || '9' < b) break;
          ret *= 10;
          ret += b - '0';
        }
        if (b != '.') return sign * ret;
        double div = 1;
        b = input.read();
        while ('0' <= b && b <= '9') {
          ret *= 10;
          ret += b - '0';
          div *= 10;
          b = input.read();
        }
        return sign * ret / div;
      } catch (IOException e) {
        e.printStackTrace();
        return Double.NaN;
      }
    }

    char nextChar() {
      try {
        int b = input.read();
        while (Character.isWhitespace(b)) {
          b = input.read();
        }
        return (char) b;
      } catch (IOException e) {
        e.printStackTrace();
        return 0;
      }
    }

    String nextStr() {
      try {
        StringBuilder sb = new StringBuilder();
        int b = input.read();
        while (Character.isWhitespace(b)) {
          b = input.read();
        }
        while (b != -1 && !Character.isWhitespace(b)) {
          sb.append((char) b);
          b = input.read();
        }
        return sb.toString();
      } catch (IOException e) {
        e.printStackTrace();
        return "";
      }
    }

  }

}