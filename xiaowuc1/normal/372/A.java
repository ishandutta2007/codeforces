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
      int[] list = new int[n];
      PriorityQueue<Integer> q = new PriorityQueue<Integer>();
      for(int i = 0; i < n; i++) {
        q.add(readInt());
      }
      for(int i = 0; i < n; i++) {
        list[i] = q.poll();
      }
      int min = 0;
      int max = n/2;
      while(min != max) {
        int mid = (min+max)/2;
        if(min == mid) {
          mid++;
        }
        boolean can = true;
        for(int i = 0; can && i < mid; i++) {
          if(list[i] * 2 > list[list.length-mid+i]) {
            can = false;
          }
        }
        if(can) {
          min = mid;
        }
        else {
          max = mid-1;
        }
      }
      pw.println(n - min);
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