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
    int qq = 1;
    //int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++) {
      double side = readDouble();
      double num = readDouble();
      int n = readInt();
      for(int i = 1; i <= n; i++) {
        double amt = num * i;
        long scale = (long)(amt / (4*side));
        amt -= scale * 4*side;
        while(amt >= 4*side) {
          amt -= 4*side;
        }
        if(amt <= side) {
          pw.println(amt + " " + 0);
        }
        else if(amt <= 2 * side) {
          pw.println(side + " " + (amt-side));
        }
        else if(amt <= 3 * side) {
          pw.println((3*side-amt) + " " + side);
        }
        else {
          pw.println(0 + " " + (4*side - amt));
        }
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