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
      grid = new int[5][5];
      for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
          grid[i][j] = readInt();
        }
      }
      pw.println(dfs(new boolean[5], new int[5], 0));
    }
    pw.close();
  }

  public static int solve(int[] list) {
    int ret = 0;
    boolean[][] talk = new boolean[5][5];
    for(int i = 0; i < list.length; i++) {
      for(int j = i+1; j < list.length; j += 2) {
        int x = list[j-1];
        int y = list[j];
        ret += grid[x][y];
        ret += grid[y][x];
      }
    }
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
        if(talk[i][j]) {
          ret += grid[i][j];
        }
       }
    }
    return ret;
  }

  public static int dfs(boolean[] used, int[] list, int index) {
    if(index == 5) {
      return solve(list);
    }
    int ret = 0;
    for(int i = 0; i < used.length; i++) {
      if(!used[i]) {
        list[index] = i;
        used[i] = true;
        ret = Math.max(ret, dfs(used, list, index+1));
        used[i] = false;
      }
    }
    return ret;
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