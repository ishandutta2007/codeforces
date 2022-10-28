import java.util.*;
import java.io.*;

public class Main {

  public static void main(String args[]) {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out);

    for (int t = in.nextInt(); t > 0; --t) {
      String s = in.next();
      for (int i = 0; i < s.length(); ++i) {
        if (i % 2 == 0) {
          out.print((s.charAt(i) == 'a') ? 'b' : 'a');
        } else {
          out.print((s.charAt(i) == 'z') ? 'y' : 'z');
        }
      }
      out.println();
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