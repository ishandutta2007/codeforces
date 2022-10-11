import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
  static BufferedReader br;
  static StringTokenizer st;
  static PrintWriter pw;

  static int[][] grid;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++) {
      int n = readInt();
      int[] list = new int[n];
      int gcd = 0;
      for(int i = 0; i < n; i++) {
        list[i] = readInt();
        gcd = gcd(gcd, list[i]);
      }
      int max = 0;
      for(int i = 0; i < n; i++) {
        max = Math.max(max, list[i] / gcd);
      }
      pw.println(max % 2 != n % 2 ? "Alice" : "Bob");
    }
    pw.close();
  }

  public static int gcd(int a, int b) {
    if(a == 0) return b;
    if(b == 0) return a;
    return gcd(b, a%b);
  }

  public static void exitImmediately() {
    pw.close();
    System.exit(0);
  }

  public static int readInt() throws IOException {
    return Integer.parseInt(nextToken());
  }

  public static double readDouble() throws IOException {
    return Double.parseDouble(nextToken());
  }

  public static long readLong() throws IOException {
    return Long.parseLong(nextToken());
  }

  public static String nextLine() throws IOException {
    st = null;
    if(!br.ready()) {
      exitImmediately();
    }
    return br.readLine();
  }

  public static String nextToken() throws IOException {
    while(st == null || !st.hasMoreTokens()) {
      if(!br.ready()) {
        exitImmediately();
      }
      st = new StringTokenizer(br.readLine());
    }
    return st.nextToken();
  }
}