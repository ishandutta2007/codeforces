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
      int m = readInt();
      int s = readInt();
      int f = readInt();
      int[] time = new int[m];
      int[] l = new int[m];
      int[] r = new int[m];
      for(int i = 0; i < m; i++) {
        time[i] = readInt();
        l[i] = readInt();
        r[i] = readInt();
      }
      int timeIndex = 0;
      for(int qqq = 1; s != f; qqq++) {
        int next = s<f ? s+1 : s-1;
        if(timeIndex == time.length || time[timeIndex] != qqq) {
          if(s<f) {
            pw.print('R');
          }
          else {
            pw.print('L');
          }
          s = next;
        }
        else {
          boolean can = true;
          if(s >= l[timeIndex] && s <= r[timeIndex]){
            can = false;
          }
          if(next >= l[timeIndex] && next <= r[timeIndex]){
            can = false;
          }
          if(can) {
            if(s<f) {
              pw.print('R');
            }
            else {
              pw.print('L');
            }
            s = next;
          }
          else {
            pw.print('X');
          }
          timeIndex++;
        }
      }
    }
    pw.close();
  }

  public static int get(int s) {
    String ret = Integer.toString(s);
    while(ret.length() < 3) {
      ret = 0 + ret;
    }
    int mask = 0;
    for(int i = 0; i < 3; i++) {
      if(ret.charAt(i) != '0') {
        mask |= 1 << i;
      }
    }
    return mask;
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