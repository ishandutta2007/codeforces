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

  static boolean[][] grid;
  
  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int n = readInt();
      grid = new boolean[n][n];
      for(int i = 0; i < n; i++) {
        String str = nextToken();
        for(int j = 0; j < n; j++) {
          grid[i][j] = str.charAt(j) == '#';
        }
      }
      boolean valid = true;
      for(int i = 0; valid && i < n; i++) {
        for(int j = 0; valid && j < n; j++) {
          if(!grid[i][j]) continue;
          if(!valid(i+1, j-1) || !valid(i+1, j) || !valid(i+1, j+1) || !valid(i+2, j)) {
            valid = false;
          }
          else {
            grid[i+1][j-1] = false;
            grid[i+1][j] = false;
            grid[i+1][j+1] = false;
            grid[i+2][j] = false;
          }
        }
      }
      pw.println(valid ? "YES" : "NO");
    }
    pw.close();
  }
  
  public static boolean valid(int x, int y) {
    return x >= 0 && x < grid.length && y >= 0 && y < grid[x].length && grid[x][y];
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