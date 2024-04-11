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
      int l = readInt();
      int r = readInt();
      int ql = readInt();
      int qr = readInt();
      int[] list = new int[n];
      int[] prefix = new int[n+1];
      for(int i = 0; i < n; i++) {
        list[i] = readInt();
        prefix[i+1] = prefix[i] + list[i];
      }
      long ret = Long.MAX_VALUE;
      for(int i = 0; i <= n; i++) {
        long left = prefix[i] * 1L * l;
        long right = (prefix[n] - prefix[i]) * 1L * r;
        long extraLeft = Math.max(0, n-2*(n-i)-1) * 1L * ql;
        long extraRight = Math.max(0, n-2*i-1) * 1L * qr;
        ret = Math.min(ret, left + right + extraLeft + extraRight);
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