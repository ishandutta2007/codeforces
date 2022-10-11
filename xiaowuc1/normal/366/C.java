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
      int ratio = readInt();
      int[] x = new int[n];
      int[] y = new int[n];
      for(int i = 0; i < n; i++) {
        x[i] = readInt();
      }
      for(int i = 0; i < n; i++) {
        y[i] = readInt() * ratio;
      }
      int[] pos = new int[10001];
      int[] neg = new int[10001];
      Arrays.fill(pos, -1);
      Arrays.fill(neg, -1);
      pos[0] = 0;
      neg[0] = 0;
      int same = 0;
      for(int i = 0; i < n; i++) {
        if(x[i] == y[i]) {
          same += x[i];
        }
        else {
          int[] mod = x[i] >= y[i] ? pos : neg;
          int diff = Math.abs(x[i] - y[i]);
          for(int a = 10000; a >= diff; a--) {
            if(mod[a-diff] >= 0) {
              mod[a] = Math.max(mod[a], mod[a-diff] + x[i]);
            }
          }
        }
      }
      int ret = same == 0 ? -1 : same;
      for(int i = 1; i <= 10000; i++) {
        if(pos[i] >= 0 && neg[i] >= 0) {
          ret = Math.max(ret, same + pos[i] + neg[i]);
        }
      }
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