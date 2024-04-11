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
      long scale = readInt();
      int[] add = new int[n];
      for(int i = 1; i < n-1; i++) {
        add[i] = readInt();
      }
      int[] x = new int[n];
      int[] y = new int[n];
      for(int i = 0; i < n; i++) {
        x[i] = readInt();
        y[i] = readInt();
      }
      int[][] dist = new int[n][n];
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          dist[i][j] += Math.abs(x[i] - x[j]);
          dist[i][j] += Math.abs(y[i] - y[j]);
        }
      }
      long min = 0;
      long max = 1L << 60;
      while(min != max) {
        long mid = (min+max)/2;
        long[] amt = new long[n];
        Arrays.fill(amt, -1);
        amt[0] = mid;
        while(true) {
          boolean upd = false;
          for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
              if(i == j) continue;
              if(scale * dist[i][j] > amt[i]) continue;
              long next = amt[i] - scale * dist[i][j] + add[j];
              if(next > amt[j]) {
                amt[j] = next;
                upd = true;
              }
            }
          }
          if(!upd) break;
        }
        if(amt[n-1] >= 0) {
          max = mid;
        }
        else {
          min = mid+1;
        }
      }
      pw.println(min);
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