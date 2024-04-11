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

  static boolean[][] grid;

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
      for(int qqq = 0; qqq < 100; qqq++) {
        int a = (int)(n*Math.random());
        int b = (int)(n*Math.random());
        int temp = list[a];
        list[a] = list[b];
        list[b] = temp;
      }
      Arrays.sort(list);
      boolean[] used = new boolean[n];
      int last = -1;
      ArrayList<Integer> ret = new ArrayList<Integer>();
      for(int i = 0; i < n; i++) {
        if(list[i] > last) {
          ret.add(list[i]);
          last = list[i];
          used[i] = true;
        }
      }
      for(int i = n-1; i >= 0; i--) {
        if(!used[i] && list[i] < last) {
          ret.add(list[i]);
          last = list[i];
        }
      }
      pw.println(ret.size());
      StringBuilder sb = new StringBuilder();
      for(int out: ret) {
        sb.append(out + " ");
      }
      pw.println(sb.toString().trim());
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