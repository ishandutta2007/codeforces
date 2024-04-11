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
      int[][] grid = new int[n][m];
      for(int i = 0; i < n; i++) {
        String str = nextToken();
        for(int j = 0; j < m; j++) {
          if(str.charAt(j) == '0') {
            continue;
          }
          grid[i][j]++;
          if(j > 0) {
            grid[i][j] += grid[i][j-1];
          }
        }
      }
      int ret = 0;
      for(int i = 0; i < m; i++) {
        int[] count = new int[i+2];
        int totalNum = 0;
        for(int[] out: grid) {
          if(out[i] > 0) {
            count[out[i]]++;
            totalNum++;
          }
        }
        int curr = 0;
        for(int j = count.length-1; j >= 1; j--) {
          if(totalNum * (j) <= ret) break;
          curr += count[j];
          ret = Math.max(ret, curr * (j));
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