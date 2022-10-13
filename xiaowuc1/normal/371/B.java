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
      int a = readInt();
      int b = readInt();
      Map<State, Integer> map = new HashMap<State, Integer>();
      LinkedList<State> q = new LinkedList<State>();
      q.add(new State(a,b));
      map.put(new State(a,b), 0);
      while(!q.isEmpty()) {
        State curr = q.removeFirst();
        if(curr.a%2==0) {
          State next = new State(curr.a * 1 / 2, curr.b);
          if(!map.containsKey(next)) {
            map.put(next, 1 + map.get(curr));
            q.add(next);
          }
        }
        if(curr.a%3==0) {
          State next = new State(curr.a * 1 / 3, curr.b);
          if(!map.containsKey(next)) {
            map.put(next, 1 + map.get(curr));
            q.add(next);
          }
        }
        if(curr.a%5==0) {
          State next = new State(curr.a * 1 / 5, curr.b);
          if(!map.containsKey(next)) {
            map.put(next, 1 + map.get(curr));
            q.add(next);
          }
        }
        if(curr.b%2==0) {
          State next = new State(curr.a, curr.b * 1 / 2);
          if(!map.containsKey(next)) {
            map.put(next, 1 + map.get(curr));
            q.add(next);
          }
        }
        if(curr.b%3==0) {
          State next = new State(curr.a, curr.b * 1 / 3);
          if(!map.containsKey(next)) {
            map.put(next, 1 + map.get(curr));
            q.add(next);
          }
        }
        if(curr.b%5==0) {
          State next = new State(curr.a, curr.b * 1 / 5);
          if(!map.containsKey(next)) {
            map.put(next, 1 + map.get(curr));
            q.add(next);
          }
        }
      }
      int ret = Integer.MAX_VALUE;
      for(State out: map.keySet()) {
        if(out.a == out.b) {
          ret = Math.min(ret, map.get(out));
        }
      }
      if(ret == Integer.MAX_VALUE) {
        ret = -1;
      }
      pw.println(ret);
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