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
      TreeSet<Integer> xs = new TreeSet<Integer>();
      TreeSet<Integer> ys = new TreeSet<Integer>();
      HashSet<State> set = new HashSet<State>();
      for(int i = 0; i < 8; i++) {
        int x = readInt();
        int y = readInt();
        set.add(new State(x, y));
      }
      for(State out: set) {
        xs.add(out.x);
        ys.add(out.y);
      }
      if(xs.size() != 3 || ys.size() != 3) {
        pw.println("ugly");
      }
      else {
        int[] xx = new int[3];
        int[] yy = new int[3];
        int index = 0;
        for(int out: xs) {
          xx[index++] = out;
        }
        index = 0;
        for(int out: ys) {
          yy[index++] = out;
        }
        boolean win = true;
        for(int i = 0; i < 3; i++) {
          for(int j = 0; j < 3; j++) {
            boolean should = i!=1 || j!=1;
            boolean is = set.contains(new State(xx[i], yy[j]));
            if(should != is) {
              win = false;
            }
          }
        }
        pw.println(win ? "respectable" : "ugly");
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

    @Override
    public int hashCode() {
      final int prime = 31;
      int result = 1;
      result = prime * result + x;
      result = prime * result + y;
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
      if (x != other.x)
        return false;
      if (y != other.y)
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