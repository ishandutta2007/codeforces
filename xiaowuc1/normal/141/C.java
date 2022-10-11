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
        list[i] = new State(nextToken(), readInt());
      }
      Arrays.sort(list);
      for(int i = 0; i < n; i++) {
        if(list[i].count > i) {
          pw.println(-1);
          exitImmediately();
        }
      }
      ArrayList<State> ret = new ArrayList<State>();
      for(int i = 0; i < n; i++) {
        ret.add(ret.size() - list[i].count, list[i]);
      }
      int[] ans = new int[n];
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < ret.size(); j++) {
          if(list[i] == ret.get(j)) {
            ans[i] = j+1;
          }
        }
      }
      for(int i = 0; i < n; i++) {
        pw.println(list[i].name + " " + ans[i]);
      }
    }
    pw.close();
  }

  static class State implements Comparable<State> {
    public String name;
    public int count;
    public State(String name, int count) {
      super();
      this.name = name;
      this.count = count;
    }
    public int compareTo(State s) {
      return count - s.count;
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