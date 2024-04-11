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
      int m = readInt();
      int[] ret = new int[n];
      while(m-- > 0) {
        int a = readInt()-1;
        int b = readInt()-1;
        int c = readInt()-1;
        if(ret[a] == 1) {
          ret[b] = 2;
          ret[c] = 3;
        }
        else if(ret[a] == 2) {
          ret[b] = 1;
          ret[c] = 3;
        }
        else if(ret[a] == 3) {
          ret[b] = 1;
          ret[c] = 2;
        }
        else if(ret[b] == 1) {
          ret[a] = 2;
          ret[c] = 3;
        }
        else if(ret[b] == 2) {
          ret[a] = 1;
          ret[c] = 3;
        }
        else if(ret[b] == 3) {
          ret[a] = 1;
          ret[c] = 2;
        }
        else if(ret[c] == 1) {
          ret[a] = 2;
          ret[b] = 3;
        }
        else if(ret[c] == 2) {
          ret[a] = 1;
          ret[b] = 3;
        }
        else if(ret[c] == 3) {
          ret[a] = 1;
          ret[b] = 2;
        }
        else {
          ret[a] = 1;
          ret[b] = 2;
          ret[c] = 3;
        }
      }
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