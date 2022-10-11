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

  static int[] dp;
  
  static int[] list;
  static int[] prefix;

  static String str;
  
  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int n = readInt();
      int k = readInt();
      int l = readInt();
      int r = readInt();
      int total = readInt();
      int most = readInt();
      int[] ret = new int[n];
      Arrays.fill(ret, total/n);
      int temp = (total/n)*n;
      for(int i = 0; i < n && temp < total; i++) {
        ret[i]++;
        temp++;
      }
      for(int i = 0; i < k; i++) {
        most -= ret[i];
      }
      int left = 0;
      int right = n-1;
      while(most-- > 0) {
        while(ret[left] == r) left++;
        while(ret[right] == l) right--;
        ret[left]++;
        ret[right]--;
      }
      StringBuilder sb = new StringBuilder();
      for(int out: ret) {
        sb.append(out + " ");
      }
      pw.println(sb.toString().trim());
    }
    pw.close();
  }

  public static int solve(int n) {
    if(n < 0) return 0;
    if(str.charAt(n) == '0') {
      dp[n] = solve(n-1);
      return dp[n];
    }
    dp[n] = Math.max(prefix[n], list[n] + solve(n-1));
    return dp[n];
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