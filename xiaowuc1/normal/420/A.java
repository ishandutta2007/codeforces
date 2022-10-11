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

  static int[][] grid;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++) {
      String s = nextLine();
      String t = new StringBuilder(s).reverse().toString();
      if(!s.equals(t)) {
        pw.println("NO");
      }
      else {
        boolean bad = false;
        bad |= s.indexOf("B") != -1;
        bad |= s.indexOf("C") != -1;
        bad |= s.indexOf("D") != -1;
        bad |= s.indexOf("E") != -1;
        bad |= s.indexOf("F") != -1;
        bad |= s.indexOf("G") != -1;
        bad |= s.indexOf("J") != -1;
        bad |= s.indexOf("K") != -1;
        bad |= s.indexOf("L") != -1;
        bad |= s.indexOf("N") != -1;
        bad |= s.indexOf("P") != -1;
        bad |= s.indexOf("Q") != -1;
        bad |= s.indexOf("R") != -1;
        bad |= s.indexOf("S") != -1;
        bad |= s.indexOf("Z") != -1;
        if(bad) pw.println("NO");
        else pw.println("YES");
      }
    }
    pw.close();
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