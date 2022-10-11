import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;

/*
br = new BufferedReader(new FileReader("input.txt"));
pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
br = new BufferedReader(new InputStreamReader(System.in));
pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class Main {
  private static BufferedReader br;
  private static StringTokenizer st;
  private static PrintWriter pw;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int n = readInt();
      int m = readInt();
      int[] x = new int[n];
      int[] y1 = new int[n];
      int[] y2 = new int[n];
      for(int i = 0; i < n; i++) {
        x[i] = readInt();
        y1[i] = readInt();
        y2[i] = readInt() + y1[i];
      }
      int ret = 0;
      while(m-- > 0) {
        int x1 = readInt();
        int y = readInt();
        int x2 = readInt() + x1;
        for(int i = 0; i < n; i++) {
          if(y >= y1[i] && y <= y2[i] && x[i] >= x1 && x[i] <= x2) {
            ret = Math.max(ret, Math.min(Math.min(x2 - x[i], x[i] - x1), Math.min(y2[i] - y, y-y1[i])));
          }
        }
      }
      pw.println(ret);
    }
    pw.close();
  }

  private static void exitImmediately() {
    pw.close();
    System.exit(0);
  }

  private static long readLong() throws IOException {
    return Long.parseLong(nextToken());
  }

  private static double readDouble() throws IOException {
    return Double.parseDouble(nextToken());
  }

  private static int readInt() throws IOException {
    return Integer.parseInt(nextToken());
  }

  private static String nextToken() throws IOException  {
    while(st == null || !st.hasMoreTokens())  {
      if(!br.ready()) {
        exitImmediately();
      }
      st = new StringTokenizer(br.readLine().trim());
    }
    return st.nextToken();
  }
}