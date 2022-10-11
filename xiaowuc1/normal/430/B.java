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
      nextToken();
      int color = readInt();
      int[] list = new int[n];
      for(int i = 0; i < n; i++) {
        list[i] = readInt();
      }
      int minSize = n;
      for(int i = 0; i <= n; i++) {
        ArrayList<Integer> go = new ArrayList<Integer>(n+1);
        for(int out: list) {
          go.add(out);
        }
        go.add(i, color);
        minSize = Math.min(minSize, solve(go));
      }
      pw.println((n) - minSize);
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