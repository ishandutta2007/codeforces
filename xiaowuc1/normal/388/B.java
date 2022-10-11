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

  static int[][] grid;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    int qq = 1;
    //int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int n = readInt();
      ArrayList<Integer> list = new ArrayList<Integer>();
      ArrayList<Integer> count = new ArrayList<Integer>();
      ArrayList<Edge> ret = new ArrayList<Edge>();
      ret.add(new Edge(0, 2));
      ret.add(new Edge(0, 3));
      list.add(2);
      list.add(3);
      count.add(1);
      count.add(1);
      while(count.get(count.size()-1) != (1<<29)) {
        ArrayList<Integer> next = new ArrayList<Integer>();
        ArrayList<Integer> nextCount = new ArrayList<Integer>();
        for(int i = 0; i <= list.size(); i++) {
          next.add(list.get(list.size()-1) + (i+1));
          nextCount.add(1 << (Math.max(0, i-1)));
        }
        for(int i = 0; i < list.size(); i++) {
          ret.add(new Edge(list.get(i), next.get(i)));
          ret.add(new Edge(list.get(i), next.get(next.size()-1)));
        }
        list = next;
        count = nextCount;
      }
      int numV = list.get(list.size()-1)+1;
      pw.println(numV);
      boolean[][] grid = new boolean[numV][numV];
      for(int i = count.size()-1; i >= 0; i--) {
        if(count.get(i) <= n) {
          ret.add(new Edge(1, list.get(i)));
          n -= count.get(i);
        }
      }
      for(Edge out: ret) {
        grid[out.a][out.b] = true;
        grid[out.b][out.a] = true;
      }
      for(boolean[] out: grid) {
        for(boolean out2: out) {
          if(out2) {
            pw.print('Y');
          }
          else {
            pw.print('N');
          }
        }
        pw.println();
      }
    }
    pw.close();
  }

  static class Edge {
    public int a,b;

    public Edge(int a, int b) {
      super();
      this.a = a;
      this.b = b;
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