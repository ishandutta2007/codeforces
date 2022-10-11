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
      int start = readInt()-1;
      int[] list = new int[n];
      boolean[] isFollowed = new boolean[n];
      for(int i = 0; i < n; i++) {
        list[i] = readInt()-1;
        if(list[i] >= 0) {
          isFollowed[list[i]] = true;
        }
      }
      int actualInFront = -1;
      ArrayList<Integer> nums = new ArrayList<Integer>();
      for(int i = 0; i < n; i++) {
        if(isFollowed[i]) continue;
        ArrayList<Integer> count = new ArrayList<Integer>();
        int index = -1;
        int curr = i;
        while(curr >= 0) {
          if(curr == start) {
            index = count.size(); 
          }
          count.add(curr);
          curr = list[curr];
        }
        if(index >= 0) {
          actualInFront = count.size() - 1 - index;
        }
        else {
          nums.add(count.size());
        }
      }
      boolean[] dp = new boolean[n+1];
      dp[actualInFront] = true;
      for(int out: nums) {
        for(int i = n; i >= out; i--) {
          dp[i] |= dp[i-out];
        }
      }
      for(int i = 0; i <= n; i++) {
        if(dp[i]) {
          pw.println(i+1);
        }
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