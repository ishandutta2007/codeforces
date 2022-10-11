import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
  static BufferedReader br;
  static StringTokenizer st;
  static PrintWriter pw;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++) {
      int n = readInt();
      String[] s = new String[n];
      for(int i = 0; i < n; i++) {
        s[i] = nextLine();
      }
      int c = s[0].length();
      StringBuilder sb = new StringBuilder();
      for(int i = 0; i < c; i++) {
        Set<Character> set = new HashSet<Character>();
        for(String out: s) {
          if(out.charAt(i) != '?') {
            set.add(out.charAt(i));
          }
        }
        if(set.size() > 1) {
          sb.append('?');
        }
        else {
          if(set.size() == 0) {
            set.add('a');
          }
          for(char out2: set) {
            sb.append(out2);
          }
        }
      }
      pw.println(sb);
    }
    pw.close();
  }

  /*
  0 0 to 0 m-1
  1 0 to 0 m-2
  r-2 0 to 0 1
  r-1 0 to 0 0
  0 1 to 1 c-1
  0 2 to 2 c-1
  0 c-1 to c-1 
  */
  public static int[] rotate(int x, int y, int r, int c) {
    return new int[]{y, r-1-x};
  }

  public static void exitImmediately() {
    pw.close();
    System.exit(0);
  }

  public static int readInt() throws IOException {
    return Integer.parseInt(nextToken());
  }

  public static double readDouble() throws IOException {
    return Double.parseDouble(nextToken());
  }

  public static long readLong() throws IOException {
    return Long.parseLong(nextToken());
  }

  public static String nextLine() throws IOException {
    st = null;
    if(!br.ready()) {
      exitImmediately();
    }
    return br.readLine();
  }

  public static String nextToken() throws IOException {
    while(st == null || !st.hasMoreTokens()) {
      if(!br.ready()) {
        exitImmediately();
      }
      st = new StringTokenizer(br.readLine());
    }
    return st.nextToken();
  }
}