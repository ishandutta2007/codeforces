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
      int[][] grid = new int[n][n];
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          grid[i][j] = readInt();
        }
      }
      for(int i = 0; i < n; i++) {
        StringBuilder sb = new StringBuilder();
        for(int j = 0; j < n; j++) {
          sb.append((grid[i][j] + grid[j][i]) / 2.0 + " ");
        }
        pw.println(sb.toString().trim());
      }
      for(int i = 0; i < n; i++) {
        StringBuilder sb = new StringBuilder();
        for(int j = 0; j < n; j++) {
          sb.append((grid[i][j] - grid[j][i]) / 2.0 + " ");
        }
        pw.println(sb.toString().trim());
      }
      
    }
    pw.close();
  }

  static class State {
    public int a,b;

    public State(int a, int b) {
      super();
      this.a = a;
      this.b = b;
    }

    @Override
    public int hashCode() {
      final int prime = 31;
      int result = 1;
      result = prime * result + a;
      result = prime * result + b;
      return result;
    }

    @Override
    public boolean equals(Object obj) {
      if (this == obj)
        return true;
      if (obj == null)
        return false;
      if (getClass() != obj.getClass())
        return false;
      State other = (State) obj;
      if (a != other.a)
        return false;
      if (b != other.b)
        return false;
      return true;
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