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
      int correct = readInt();
      int consecutive = readInt();
      int wrong = n - correct;
      long lastWrong = n+1;
      if(wrong > 0) {
        lastWrong = n - (consecutive - 1) - (wrong-1) * 1L * consecutive;
        lastWrong = Math.max(1, lastWrong);
      }
      long numDoubles = (lastWrong-1) / consecutive;
      long ret = 0;
      if(numDoubles > 0) {
        ret = 2 * (modpow(2, numDoubles, 1000000009)-1) * consecutive;
        ret %= 1000000009;
      }
      ret += Math.max(0, correct - numDoubles * consecutive);
      ret %= 1000000009;
      pw.println(ret);
    }
    pw.close();
  }

  public static long modpow(long b, long e, long m) {
    long r = 1;
    while(e > 0) {
      if(e%2==1) {
        r*=b;
        r%=m;
      }
      b*=b;
      b%=m;
      e/=2;
    }
    return r;
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