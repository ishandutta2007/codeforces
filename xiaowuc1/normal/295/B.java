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
      long[][] amt = new long[n][n];
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          amt[i][j] = readInt();
        }
      }
      int[] nums = new int[n];
      for(int i = 0; i < n; i++) {
        nums[i] = readInt()-1;
      }
      long[] ret = new long[n];
      for(int qqq = n-1; qqq >= 0; qqq--) {
        int k = nums[qqq];
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
            amt[i][j] = Math.min(amt[i][j], amt[i][k] + amt[k][j]);
          }
        }
        for(int a = qqq; a < n; a++) {
          for(int b = qqq; b < n; b++) {
            int i = nums[a];
            int j = nums[b];
            ret[qqq] += amt[i][j];
          }
        }
      }
      pw.print(ret[0]);
      for(int i = 1; i < n; i++) {
        pw.print(" " + ret[i]);
      }
      pw.println();
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