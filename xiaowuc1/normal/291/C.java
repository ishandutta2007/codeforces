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
      long[] list = new long[n];
      for(int i = 0; i < n; i++) {
        list[i] = parse(nextToken());
      }
      for(int num = 31; num > 0; num--) {
        long curr = 0;
        for(int i = num; i <= 31; i++) {
          curr |= 1L << i;
        }
        Set<Long> set = new HashSet<Long>();
        for(long out: list) {
          set.add(out&curr);
        }
        if(set.size() == k) {
          pw.println(parse(curr));
          exitImmediately();
        }
      }
      pw.println(-1);
    }
    pw.close();
  }

  public static String parse(long curr) {
    String ret = "";
    for(int i = 0; i < 4; i++) {
      ret = (curr&255) + ret;
      ret = "." + ret;
      curr >>= 8;
    }
    return ret.substring(1);
  }
  
  public static long parse(String str) {
    long ret = 0;
    StringTokenizer su = new StringTokenizer(str, ".");
    while(su.hasMoreTokens()) {
      ret <<= 8;
      ret |= Integer.parseInt(su.nextToken());
    }
    return ret;
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