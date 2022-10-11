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
    long[] fact = new long[1001];
    fact[0] = 1;
    final long MOD = 1000000007;
    for(int i = 1; i < fact.length; i++) {
      fact[i] = fact[i-1] * i;
      fact[i] %= MOD;
    }
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int n = readInt();
      int m = readInt();
      boolean[] go = new boolean[n];
      for(int i = 0; i < m; i++) {
        go[readInt()-1] = true;
      }
      ArrayList<State> list = new ArrayList<State>();
      for(int i = 0; i < n;) {
        if(go[i]) {
          i++;
          continue;
        }
        int j = i;
        while(j < go.length && !go[j]) {
          j++;
        }
        list.add(new State(i, j-1));
        i=j;
      }
      long ret = 1;
      for(State out: list) {
        boolean end = out.x == 0 || out.y == n-1;
        if(!end) {
          ret *= modpow(2, out.y - out.x, MOD);
          ret %= MOD;
        }
      }
      ret *= fact[n-m];
      ret %= MOD;
      for(State out: list) {
        ret *= inv(fact[out.y - out.x + 1], MOD);
        ret %= MOD;
      }
      pw.println(ret);
    }
    pw.close();
  }

  public static long inv(long b, long m) {
    return modpow(b, m-2, m);
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
  
  static class State {
    public int x,y;

    public State(int x, int y) {
      super();
      this.x = x;
      this.y = y;
    }
    
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