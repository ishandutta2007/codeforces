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
      long amount = readLong();
      long start = readLong();
      long scale = readLong();
      long ret = 0;
      while(amount >= count(start)*scale) {
        long numAllowed = amount / (count(start) * scale);
        long above = above(start);
        long numsAvailable = above - start+1;
        if(numsAvailable <= numAllowed) {
          amount -= numsAvailable * count(start) * scale;
          ret += numsAvailable;
          start = above+1;
        }
        else {
          ret += numAllowed;
          amount = 0;
        }
      }
      pw.println(ret);
    }
    pw.close();
  }

  public static long above(long n) {
    int num = count(n);
    long ret = 0;
    while(num-- > 0) {
      ret *= 10;
      ret += 9;
    }
    return ret;
  }

  public static int count(long n) {
    return Long.toString(n).length();
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