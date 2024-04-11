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
      String s = nextToken();
      int n = s.length();
      boolean[][] pal = new boolean[s.length()][s.length()];
      for(int i = 0; i < s.length(); i++) {
        pal[i][i] = true;
        if(i+1 < s.length() && s.charAt(i) == s.charAt(i+1)) {
          pal[i][i+1] = true;
        }
      }
      for(int diff = 2; diff < n; diff++) {
        for(int i = 0; i + diff < n; i++) {
          pal[i][i+diff] = pal[i+1][i+diff-1] && s.charAt(i) == s.charAt(i+diff);
        }
      }
      int[][] dp = new int[n][n];
      for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
        if(i+1 < n && pal[i][i+1]) {
          dp[i][i+1] = 3;
        }
        else if(i+1 < n) {
          dp[i][i+1] = 2;
        }
      }
      for(int diff = 2; diff < n; diff++) {
        for(int i = 0; i + diff < n; i++) {
          dp[i][i+diff] = dp[i+1][i+diff] + dp[i][i+diff-1] - dp[i+1][i+diff-1];
          if(pal[i][i+diff]) {
            dp[i][i+diff]++;
          }
        }
      }
      int qqq = readInt();
      while(qqq-- > 0) {
        int a = readInt();
        int b = readInt();
        pw.println(dp[--a][--b]);
      }
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