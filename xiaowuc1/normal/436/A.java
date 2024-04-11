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
      int startHeight = readInt();
      int[] type = new int[n];
      int[] h = new int[n];
      int[] m = new int[n];
      for(int i = 0; i < n; i++) {
        type[i] = readInt();
        h[i] = readInt();
        m[i] = readInt();
      }
      int ret = 0;
      for(int first = 0; first <= 1; first++) {
        int currHeight = startHeight;
        int currEat = first;
        int ans = 0;
        boolean[] used = new boolean[n];
        while(true) {
          boolean good = false;
          int cand = -1;
          for(int i = 0; i < n; i++) {
            if(used[i] || type[i] != currEat || h[i] > currHeight) continue;
            if(cand == -1 || m[i] >= m[cand]) {
              cand = i;
              good = true;
            }
          }
          if(!good) break;
          ans++;
          used[cand] = true;
          ret = Math.max(ret, ans);
          currHeight += m[cand];
          currEat ^= 1;
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