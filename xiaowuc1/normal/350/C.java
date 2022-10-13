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
      State[] list = new State[n];
      for(int i = 0; i < n; i++) {
        list[i] = new State(readInt(), readInt());
      }
      Arrays.sort(list);
      int[] x = new int[n];
      int[] y = new int[n];
      for(int i = 0; i < n; i++) { 
        x[i] = list[i].x;
        y[i] = list[i].y;
      }
      int ret = 0;
      for(int i = 0; i < n; i++) {
        if(x[i] != 0) {
          ret += 2;
        }
        if(y[i] != 0) {
          ret += 2;
        }
        ret += 2;
      }
      pw.println(ret);
      for(int i = 0; i < n; i++) {
        if(x[i] > 0) {
          pw.println(1 + " " + x[i] + " R");
        }
        else if(x[i] < 0) {
          pw.println(1 + " " + -x[i] + " L");
        }
        if(y[i] > 0) {
          pw.println(1 + " " + y[i] + " U");
        }
        else if(y[i] < 0) {
          pw.println(1 + " " + -y[i] + " D");
        }
        pw.println(2);
        if(x[i] > 0) {
          pw.println(1 + " " + x[i] + " L");
        }
        else if(x[i] < 0) {
          pw.println(1 + " " + -x[i] + " R");
        }
        if(y[i] > 0) {
          pw.println(1 + " " + y[i] + " D");
        }
        else if(y[i] < 0) {
          pw.println(1 + " " + -y[i] + " U");
        }
        pw.println(3);
      }
    }
    pw.close();
  }

  static class State implements Comparable<State> {
    public int x,y;

    public State(int x, int y) {
      super();
      this.x = x;
      this.y = y;
    }
    public int compareTo(State s) {
      int a = Math.abs(x) + Math.abs(y);
      int b = Math.abs(s.x) + Math.abs(s.y);
      if(a<b) return -1;
      if(a>b) return 1;
      return 0;
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