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
      int[] amt = new int[10];
      for(int i = 1; i < amt.length; i++) {
        amt[i] = readInt();
      }
      int[] dp = new int[n+1];
      for(int i = 0; i < n; i++) {
        for(int out: amt) {
          if(out == 0) continue;
          if(i+out <= n) {
            dp[i+out] = Math.max(dp[i+out], dp[i]+1);
          }
        }
      }
      if(dp[n] == 0) {
        pw.println(-1);
      }
      else {
        int num = n;
        while(dp[num] > 0) {
          for(int j = 9; j >= 1; j--) {
            if(num-amt[j] >= 0 && dp[num] == 1 + dp[num-amt[j]]) {
              pw.print(j);
              num -= amt[j];
              break;
            }
          }
        }
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