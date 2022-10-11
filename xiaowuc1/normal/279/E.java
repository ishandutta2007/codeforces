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
      String str = nextToken();
      Stack<State> stack = new Stack<State>();
      for(int i = 0; i < str.length();) {
        if(str.charAt(i) == '0') {
          i++;
          continue;
        }
        int j = i+1;
        while(j < str.length() && str.charAt(j) == '1') {
          j++;
        }
        stack.push(new State(i,j-1));
        i=j;
      }
      int ret = 0;
      while(!stack.isEmpty()) {
        State curr = stack.pop();
        if(curr.a == curr.b) {
          ret++;
        }
        else {
          if(stack.isEmpty()) {
            ret += 2;
          }
          else {
            if(stack.peek().b + 2 == curr.a) {
              stack.peek().b++;
              ret++;
            }
            else {
              ret += 2;
            }
          }
        }
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