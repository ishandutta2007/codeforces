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
      int n = readInt();
      int k = readInt();
      int[][] dp = new int[k][n+1];
      Arrays.fill(dp[0], 1);
      dp[0][0] = 0;
      int ret = 0;
      final int MOD = 1000000007;
      for(int i = 0; i < k-1; i++) {
        for(int j = 1; j <= n; j++) {
          for(int a = 1; a * j <= n; a++) {
            dp[i+1][a*j] += dp[i][j];
            if(dp[i+1][a*j] >= MOD) {
              dp[i+1][a*j] -= MOD;
            }
          }
        }
      }
      for(int out: dp[k-1]) {
        ret += out;
        if(ret >= MOD) {
          ret -= MOD;
        }
      }
      pw.println(ret);
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