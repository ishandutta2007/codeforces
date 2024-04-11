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
      int r = readInt();
      TreeSet<Integer> set = new TreeSet<Integer>();
      for(int i = 0; i < r; i++) {
        String s = nextLine();
        int candy = 0;
        int start = 0;
        for(int j = 0; j < s.length(); j++) {
          if(s.charAt(j) == 'G') {
            start = j;
          }
          if(s.charAt(j) == 'S') {
            candy = j;
          }
        }
        set.add(candy - start);
      }
      if(set.first() < 0) {
        pw.println(-1);
      }
      else {
        pw.println(set.size());
      }
    }
    pw.close();
  }

  static class State {
    public int x,y;
    public State(int a, int b) {
      x=a;
      y=b;
    }
    public String toString() {
      return " " + (x+1) + " " + (y+1);
    }
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