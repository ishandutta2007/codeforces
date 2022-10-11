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
    outer: for(int casenum = 1; casenum <= qq; casenum++)  {
      String s = nextToken();
      int[] xs = new int[s.length()+1];
      int[] ys = new int[s.length()+1];
      int[] zs = new int[s.length()+1];
      for(int i = 0; i < s.length(); i++) {
        xs[i+1] = xs[i];
        ys[i+1] = ys[i];
        zs[i+1] = zs[i];
        if(s.charAt(i) == 'x') {
          xs[i+1]++;
        }
        if(s.charAt(i) == 'y') {
          ys[i+1]++;
        }
        if(s.charAt(i) == 'z') {
          zs[i+1]++;
        }
      }
      int qqq = readInt();
      while(qqq-- > 0) {
        int a = readInt()-1;
        int b = readInt();
        int[] list = new int[3];
        list[0] = xs[b] - xs[a];
        list[1] = ys[b] - ys[a];
        list[2] = zs[b] - zs[a];
        Arrays.sort(list);
        pw.println(b-a < 3 || list[2] - list[0] <= 1 ? "YES" : "NO");
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