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
      int zero = readInt();
      int one = readInt();
      if(one < zero-1) {
        pw.println(-1);
      }
      else if(one > 2 * zero + 2) {
        pw.println(-1);
      }
      else {
        int[] gaps = new int[zero+1];
        for(int i = 1; i < gaps.length-1; i++) {
          gaps[i]++;
          one--;
        }
        for(int i = 0; i < gaps.length; i++) {
          while(one > 0 && gaps[i] < 2) {
            gaps[i]++;
            one--;
          }
        }
        for(int i = 0; i < gaps.length - 1; i++) {
          while(gaps[i]-- > 0) {
            pw.print(1);
          }
          pw.print(0);
        }
        while(gaps[gaps.length-1]-- > 0) {
          pw.print(1);
        }
        pw.println();
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