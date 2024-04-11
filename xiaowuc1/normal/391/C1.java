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
      int k = readInt();
      int[] p = new int[n];
      int[] e = new int[n];
      for(int i = 0; i < n; i++) {
        p[i] = readInt();
        e[i] = readInt();
      }
      int ret = Integer.MAX_VALUE;
      for(int mask = 0; mask < 1 << n; mask++) {
        int points = Integer.bitCount(mask);
        int loser = n;
        int effort = 0;
        for(int i = 0; i < n; i++) {
          if((mask&(1<<i)) != 0) {
            effort += e[i];
          }
          else {
            p[i]++;
          }
          if(points > p[i] || (points == p[i] && (mask&(1<<i)) != 0)) {
            loser--;
          }
          if((mask&(1<<i)) == 0) {
            p[i]--;
          }
        }
        if(loser < k) {
          ret = Math.min(ret, effort);
        }
      }
      if(ret == Integer.MAX_VALUE) {
        ret = -1;
      }
      pw.println(ret);
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