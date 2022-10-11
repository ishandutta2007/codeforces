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
      grid = new int[n][3];
      for(int a = 0; a < 3; a++) {
        for(int i = 0; i < n; i++) {
          grid[i][a] = readInt();
        }
      }
      int[][] dp = new int[n][2];
      dp[0][0] = grid[0][0];
      dp[0][1] = grid[0][1];
      for(int i = 1; i < n; i++) {
        for(int j = 0; j < 2; j++) {
          // i before i-1
          dp[i][j] = dp[i-1][1] + grid[i][j];
          // i-1 before i
          dp[i][j] = Math.max(dp[i][j], dp[i-1][0] + grid[i][j+1]);
        }
      }
      pw.println(dp[n-1][0]);
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