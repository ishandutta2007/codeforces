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

  static int[][] grid;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int n = readInt();
      int[] list = new int[n];
      for(int i = 0; i < n; i++) {
        list[i] = readInt();
      }
      long ret = -(1L<<60);
      ArrayList<Integer> cut = new ArrayList<Integer>();
      for(int i = 0; i < n; i++) {
        for(int j = n-1; j > i; j--) {
          if(list[i] == list[j]) {
            long curr = 2 * list[i];
            for(int k = i+1; k < j; k++) {
              if(list[k] > 0) {
                curr += list[k];
              }
            }
            if(curr > ret) {
              ret = curr;
              cut = new ArrayList<Integer>();
              for(int k = 0; k < i; k++) {
                cut.add(k+1);
              }
              for(int k = i+1; k < j; k++) {
                if(list[k] < 0) {
                  cut.add(k+1);
                }
              }
              for(int k = j+1; k < n; k++) {
                cut.add(k+1);
              }
            }
          }
        }
      }
      pw.println(ret + " " + cut.size());
      StringBuilder sb = new StringBuilder();
      for(int out: cut) {
        sb.append(out + " ");
      }
      pw.println(sb.toString().trim());
    }
    pw.close();
  }

  public static int gcd(int a, int b) {
    return a%b==0 ? b : gcd(b,a%b);
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