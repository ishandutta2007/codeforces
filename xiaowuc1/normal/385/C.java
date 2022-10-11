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
    boolean[] comp = new boolean[10000001];
    for(int i = 2; i * i < comp.length; i++) {
      if(!comp[i]) {
        for(int j = i*i; j < comp.length; j += i) {
          comp[j] = true;
        }
      }
    }
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int[] count = new int[10000001];
      int[] num = new int[10000001];
      int n = readInt();
      while(n-- > 0) {
        int curr = readInt();
        count[curr]++;
      }
      for(int i = 2; i < comp.length; i++) {
        if(!comp[i]) {
          for(int j = i; j < num.length; j+=i) {
            num[i] += count[j];
          }
        }
      }
      for(int a = 3; a < num.length; a++) {
        num[a] += num[a-1];
      }
      int qqq = readInt();
      while(qqq-- > 0) {
        int x = Math.min(num.length, readInt());
        int y = Math.min(num.length-1, readInt());
        pw.println(num[y] - num[x-1]);
      }
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