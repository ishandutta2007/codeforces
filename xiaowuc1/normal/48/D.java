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
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int n = readInt();
      LinkedList<Integer>[] indices = new LinkedList[100001];
      for(int i = 0; i < indices.length; i++) {
        indices[i] = new LinkedList<Integer>();
      }
      for(int i = 0; i < n; i++) {
        indices[readInt()].add(i);
      }
      int[] ret = new int[n];
      int count = 1;
      int last = 100000;
      while(true) {
        int max = last;
        while(max >= 0 && indices[max].isEmpty()) {
          max--;
        }
        if(max < 0) break;
        last = max;
        for(int i = max; i >= 1; i--) {
          if(indices[i].isEmpty()) {
            pw.println(-1);
            exitImmediately();
          }
          ret[indices[i].removeFirst()] = count;
        }
        count++;
      }
      pw.println(--count);
      StringBuilder sb = new StringBuilder();
      for(int out: ret) {
        sb.append(out + " ");
      }
      pw.println(sb.toString().trim());
    }
    pw.close();
  }

  public static int gcd(int a, int b) {
    return a%b==0 ? b : gcd(b,a%b);
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