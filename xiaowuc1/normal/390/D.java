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
      int r = readInt();
      int c = readInt();
      int k = readInt();
      ArrayList<ArrayList<State>> ret = new ArrayList<ArrayList<State>>();
      int ans = 0;
      for(int sum = 2; sum <= r+c && k > 0; sum++) {
        for(int j = 1; j <= c && k > 0; j++) {
          int i = sum-j;
          if(i >= 1 && i <= r) {
            k--;
            ArrayList<State> now = new ArrayList<State>();
            for(int a = 1; a <= i; a++) {
              now.add(new State(a, 1));
            }
            for(int b = 2; b <= j; b++) {
              now.add(new State(i, b));
            }
            ret.add(now);
            ans += now.size();
          }
        }
      }
      Collections.reverse(ret);
      pw.println(ans);
      for(ArrayList<State> temp: ret) {
        StringBuilder sb = new StringBuilder();
        for(State out: temp) {
          sb.append(out + " ");
        }
        pw.println(sb.toString().trim());
      }
    }
    pw.close();
  }

  static class State {
    public int x,y;

    public State(int x, int y) {
      super();
      this.x = x;
      this.y = y;
    }
    public String toString() {
      return String.format("(%d,%d)", x, y);
    }
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