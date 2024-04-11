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
      long[] prefix = new long[n+1];
      for(int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + (list[i] = readInt());
      }
      int[] highestIndex = new int[n];
      highestIndex[n-k] = n-k;
      for(int i = n-k-1; i >= 0; i--) {
        long curr = prefix[i+k] - prefix[i];
        long other = prefix[highestIndex[i+1]+k] - prefix[highestIndex[i+1]];
        if(curr >= other) {
          highestIndex[i] = i;
        }
        else {
          highestIndex[i] = highestIndex[i+1];
        }
      }
      long bestSum = prefix[2*k];
      int a = 0;
      int b = k;
      for(int i = 0; i <= n-2*k; i++) {
        long here = prefix[i+k] - prefix[i];
        long other = prefix[highestIndex[i+k]+k] - prefix[highestIndex[i+k]];
        if(here + other > bestSum) {
          bestSum = here+other;
          a = i;
          b = highestIndex[i+k];
        }
      }
      pw.println((a+1) + " " + (b+1));
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