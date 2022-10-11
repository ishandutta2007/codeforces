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
      long[][] grid = new long[n][2];
      for(int i = 0; i < n; i++) {
        int k = readInt();
        while(k-- > 0) {
          int num = readInt();
          int left = num >> 6;
          int right = num & 63;
          grid[i][left] |= 1L << right;
        }
      }
      for(int i = 0; i < n; i++) {
        boolean canWin = true;
        for(int j = 0; j < n; j++) {
          if(i==j) continue;
          boolean isSubset = true;
          for(int k = 0; k < 2; k++) {
            if((grid[j][k] & grid[i][k]) != grid[j][k]) {
              isSubset = false;
              break;
            }
          }
          if(isSubset) {
            canWin = false;
            break;
          }
        }
        pw.println(canWin ? "YES" : "NO");
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