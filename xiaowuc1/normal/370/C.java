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

  static int[] dx = new int[]{-1,1,0,0};
  static int[] dy = new int[]{0,0,-1,1};

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int n = readInt();
      nextToken();
      int[] list = new int[n];
      for(int i = 0; i < n; i++) {
        list[i] = readInt();
      }
      Arrays.sort(list);
      int maxCount = 0;
      for(int i = 0; i < n;) {
        int j = i+1;
        while(j < n && list[i] == list[j]) {
          j++;
        }
        maxCount = Math.max(maxCount, j-i);
        i=j;
      }
      int ret = 0;
      for(int i = 0; i < n; i++) {
        if(list[i] != list[(i+maxCount)%list.length]) {
          ret++;
        }
      }
      pw.println(ret);
      for(int i = 0; i < n; i++) {
        pw.println(list[i] + " " + list[(i+maxCount)%list.length]);
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