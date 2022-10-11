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

  static int[][] grid;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int n = readInt();
      int[][] grid = new int[n][n];
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          grid[i][j] = readInt();
        }
      }
      int k = readInt();
      StringBuilder sb = new StringBuilder();
      while(k-- > 0) {
        int a = readInt();
        int b = readInt();
        a--;
        b--;
        int w = readInt();
        grid[a][b] = Math.min(grid[a][b], w);
        grid[b][a] = Math.min(grid[b][a], w);
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
            grid[i][j] = Math.min(grid[i][j], grid[i][a] + grid[a][b] + grid[b][j]);
            grid[i][j] = Math.min(grid[i][j], grid[i][b] + grid[b][a] + grid[a][j]);
          }
        }
        long ret = 0;
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < i; j++) {
            ret += grid[i][j];
          }
        }
        sb.append(ret + " ");
      }
      pw.println(sb.toString().trim());
    }
    pw.close();
  }

  public static int gcd(int a, int b) {
    return a%b==0 ? b : gcd(b,a%b);
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