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

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++) {
      int n = readInt();
      int m = readInt();
      int[][] grid = new int[n][m];
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          grid[i][j] = readInt();
        }
      }
      int[][] dpDR = new int[n][m];
      int[][] dpUR = new int[n][m];
      int[][] dpDL = new int[n][m];
      int[][] dpUL = new int[n][m];

      dpDR[0][0] = grid[0][0];
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          if(i + 1 < n) {
            dpDR[i+1][j] = Math.max(dpDR[i+1][j], dpDR[i][j] + grid[i+1][j]);
          }
          if(j + 1 < m) {
            dpDR[i][j+1] = Math.max(dpDR[i][j+1], dpDR[i][j] + grid[i][j+1]);
          }
        }
      }


      dpUR[n-1][0] = grid[n-1][0];
      for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
          if(i > 0) {
            dpUR[i-1][j] = Math.max(dpUR[i-1][j], dpUR[i][j] + grid[i-1][j]);
          }
          if(j + 1 < m) {
            dpUR[i][j+1] = Math.max(dpUR[i][j+1], dpUR[i][j] + grid[i][j+1]);
          }
        }
      }


      dpDL[0][m-1] = grid[0][m-1];
      for(int i = 0; i < n; i++) {
        for(int j = m-1; j >= 0; j--) {
          if(i + 1 < n) {
            dpDL[i+1][j] = Math.max(dpDL[i+1][j], dpDL[i][j] + grid[i+1][j]);
          }
          if(j > 0) {
            dpDL[i][j-1] = Math.max(dpDL[i][j-1], dpDL[i][j] + grid[i][j-1]);
          }
        }
      }


      dpUL[n-1][m-1] = grid[n-1][m-1];
      for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
          if(i > 0) {
            dpUL[i-1][j] = Math.max(dpUL[i-1][j], dpUL[i][j] + grid[i-1][j]);
          }
          if(j > 0) {
            dpUL[i][j-1] = Math.max(dpUL[i][j-1], dpUL[i][j] + grid[i][j-1]);
          }
        }
      }

      int ret = 0;
      for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1; j++) {
          int curr = dpDR[i-1][j] + dpUR[i][j-1] + dpUL[i+1][j] + dpDL[i][j+1];
          curr = Math.max(curr, dpDR[i][j-1] + dpUR[i+1][j] + dpUL[i][j+1] + dpDL[i-1][j]);
          ret = Math.max(ret, curr);
        }
      }

      pw.println(ret);

    }
    pw.close();
  }

  public static int solve(ArrayList<Integer> list) {
    while(true) {
      boolean upd = false;
      for(int i = 0; i < list.size();) {
        int j = i+1;
        while(j < list.size() && list.get(i).intValue() == list.get(j).intValue()) {
          j++;
        }
        if(j-i >= 3) {
          for(int k = j-1; k >= i; k--) {
            list.remove(k);
          }
          upd = true;
        }
        else {
          i = j;
        }
      }
      if(!upd) break;
    }
    return list.size();
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