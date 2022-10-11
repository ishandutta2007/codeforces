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

  static int[] dp, val;

  static LinkedList<Integer>[] edges;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int n = readInt();
      dp = new int[n];
      val = new int[n];
      edges = new LinkedList[n];
      for(int i = 0; i < n; i++) {
        edges[i] = new LinkedList<Integer>();
      }
      for(int x = 1; x < n; x++) {
        int a = readInt()-1;
        int b = readInt()-1;
        int type = readInt();
        if(type == 2) {
          val[a] = 1;
          val[b] = 1;
        }
        edges[a].add(b);
        edges[b].add(a);
      }
      dp(0, -1);
      int ret = 0;
      StringBuilder sb = new StringBuilder();
      for(int i = 0; i < n; i++) {
        if(dp[i] == 1) {
          ret++;
          sb.append((i+1) + " ");
        }
      }
      pw.println(ret);
      pw.println(sb.toString().trim());
    }
    pw.close();
  }

  public static void dp(int curr, int parent) {
    for(int out: edges[curr]) {
      if(out != parent) {
        dp(out, curr);
        dp[curr] += dp[out];
      }
    }
    dp[curr] += val[curr];
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