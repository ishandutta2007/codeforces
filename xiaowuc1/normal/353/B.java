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
      n *= 2;
      int[] list = new int[n];
      for(int i = 0; i < n; i++) {
        list[i] = readInt();
      }
      int[] ret = new int[n];
      int index = 1;
      for(int val = 10; val <= 99; val++) {
        int place = 0;
        for(int i = 0; i < n; i++) {
          if(list[i] == val) {
            ret[i] = index;
            if(++index == 3) index = 1;
            if(++place == 2) {
              break;
            }
          }
        }
      }
      for(int i = 0; i < n; i++) {
        if(ret[i] == 0) {
          ret[i] = index;
          if(++index == 3) index = 1;
        }
      }
      Set<Integer> set = new HashSet<Integer>();
      for(int i = 0; i < n; i++) {
        if(ret[i] == 1) {
          for(int j = 0; j < n; j++) {
            if(ret[j] == 2) {
              set.add(100 * list[i] + list[j]);
            }
          }
        }
      }
      pw.println(set.size());
      StringBuilder sb = new StringBuilder();
      for(int out: ret) {
        sb.append(out + " ");
      }
      pw.println(sb.toString().trim());
    }
    pw.close();
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