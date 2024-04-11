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
      int qqq = readInt();
      ArrayList<Object> list = new ArrayList<Object>();
      while(qqq-- > 0) {
        int type = readInt();
        if(type == 1) {
          list.add(readInt());
        }
        else {
          int length = readInt();
          int copy = readInt();
          while(list.size() <= 100000 && copy > 0) {
            for(int i = 0; i < length; i++) {
              list.add(list.get(i));
            }
            copy--;
          }
          if(copy > 0) {
            list.add(new State(length, copy));
          }
        }
      }
      qqq = readInt();
      int currentIndex = 0;
      long alreadyProcessed = 0;
      StringBuilder sb = new StringBuilder();
      while(qqq-- > 0) {
        long curr = readLong()-1;
        long largeValid = -1;
        while(true) {
          largeValid = alreadyProcessed;
          if(list.get(currentIndex) instanceof State) {
            State state = (State)list.get(currentIndex);
            largeValid += state.numTimes * state.prefixIndex - 1;
          }
          if(curr >= alreadyProcessed && curr <= largeValid) {
            break;
          }
          currentIndex++;
          alreadyProcessed = largeValid+1;
        }
        if(list.get(currentIndex) instanceof Integer) {
          sb.append(list.get(currentIndex) + " ");
        }
        else {
          int index = (int)(curr - alreadyProcessed);
          State state = (State)list.get(currentIndex);
          index %= state.prefixIndex;
          sb.append(list.get(index) + " ");
        }
      }
      pw.println(sb.toString().trim());
    }
    pw.close();
  }

  static class State {
    public int prefixIndex;
    public int numTimes;
    public State(int prefixIndex, int numTimes) {
      super();
      this.prefixIndex = prefixIndex;
      this.numTimes = numTimes;
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