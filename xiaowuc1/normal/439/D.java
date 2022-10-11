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

  static int[] a, b;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++) {
      int n = readInt();
      int m = readInt();
      a = new int[n];
      for(int i = 0; i < n; i++) {
        a[i] = readInt();
      }
      b = new int[m];
      for(int i = 0; i < m; i++) {
        b[i] = readInt();
      }
      int l = 0;
      int r = 1000000000;
      while(r-l > 3) {
        int left = (int)((2L*l+r)/3);
        int right = (int)((2L*r+l)/3);
        if(solve(left) < solve(right)) {
          r = right;
        }
        else {
          l = left;
        }
      }
      long ret = Long.MAX_VALUE;
      for(int i = l; i <= r; i++) {
        ret = Math.min(ret, solve(i));
      }
      pw.println(ret);
    }
    pw.close();
  }

  public static long solve(int curr) {
    long ret = 0;
    for(int out: a) {
      ret += Math.max(0, curr - out);
    }
    for(int out: b) {
      ret += Math.max(0, out - curr);
    }
    return ret;
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