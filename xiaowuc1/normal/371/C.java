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
      String str = nextToken();
      int needB = 0;
      int needC = 0;
      int needS = 0;
      for(int i = 0; i < str.length(); i++) {
        if(str.charAt(i) == 'B') {
          needB++;
        }
        if(str.charAt(i) == 'C') {
          needC++;
        }
        if(str.charAt(i) == 'S') {
          needS++;
        }
      }
      int haveB = readInt();
      int haveS = readInt();
      int haveC = readInt();
      int priceB = readInt();
      int priceS = readInt();
      int priceC = readInt();
      long amt = readLong();
      long min = 0;
      long max = 2000000000000L;
      while(min != max) {
        long mid = (min+max)/2;
        if(min == mid) mid++;
        long bb = priceB * Math.max(0, mid * needB - haveB);
        long cc = priceC * Math.max(0, mid * needC - haveC);
        long ss = priceS * Math.max(0, mid * needS - haveS);
        if(bb+cc+ss<=amt) {
          min = mid;
        }
        else {
          max = mid-1;
        }
      }
      pw.println(min);
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