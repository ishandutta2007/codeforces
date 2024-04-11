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
      int r = readInt();
      int c = readInt();
      grid = new int[r][c];
      for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
          grid[i][j] = readInt();
        }
      }
      pw.println(r / (1<<count(grid.length)));
    }
    pw.close();
  }

  public static int count(int maxR) {
    if(maxR % 2 == 1) return 0;
    for(int i = 0; i < maxR/2; i++) {
      for(int j = 0; j < grid[i].length; j++) {
        if(grid[i][j] != grid[maxR - 1 - i][j]) {
          return 0;
        }
      }
    }
    return 1 + count(maxR/2);
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