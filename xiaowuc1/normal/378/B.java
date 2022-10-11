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
      int[] a = new int[n];
      int[] b = new int[n];
      for(int i = 0; i < n; i++) {
        a[i] = readInt();
        b[i] = readInt();
      }
      int x = 0;
      int y = 0;
      for(int qqq = 0; qqq < n; qqq++) {
        if(a[x] < b[y]) {
          x++;
        }
        else {
          y++;
        }
      }
      x = Math.max(x, n/2);
      for(int i = 0; i < n; i++) {
        if(i < x) {
          pw.print(1);
        }
        else {
          pw.print(0);
        }
      }
      pw.println();
      y = Math.max(y, n/2);
      for(int i = 0; i < n; i++) {
        if(i < y) {
          pw.print(1);
        }
        else {
          pw.print(0);
        }
      }
      pw.println();
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