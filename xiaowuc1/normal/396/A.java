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

  static final long MOD = 1000000007;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    long[] fac = new long[100005];
    fac[0] = 1;
    for(int i = 1; i < fac.length; i++) {
      fac[i] = fac[i-1] * i;
      fac[i] %= MOD;
    }
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int n = readInt();
      Map<Integer, Integer> map = new HashMap<Integer, Integer>();
      for(int i = 0; i < n; i++) {
        int curr = readInt();
        for(int a = 2; a * a <= curr; a++) {
          int count = 0;
          while(curr%a==0) {
            curr /= a;
            count++;
          }
          if(count > 0) {
            Integer value = map.get(a);
            if(value == null) {
              value = 0;
            }
            value += count;
            map.put(a, value);
          }
        }
        if(curr > 1) {
          Integer value = map.get(curr);
          if(value == null) {
            value = 0;
          }
          map.put(curr, ++value);
        }
      }
      long ret = 1;
      for(int out: map.keySet()) {
        int amt = map.get(out);
        ret *= fac[amt + n-1];
        ret %= MOD;
        ret *= inv(fac[amt], MOD);
        ret %= MOD;
        ret *= inv(fac[n-1], MOD);
        ret %= MOD;
      }
      pw.println(ret);
    }
    pw.close();
  }

  public static long inv(long a, long m) {
    return modpow(a, m-2, m);
  }

  public static long modpow(long b, long e, long m) {
    long r = 1;
    while(e > 0) {
      if(e%2==1) {
        r *= b;
        r %= m;
      }
      b *= b;
      b %= m;
      e /= 2;
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