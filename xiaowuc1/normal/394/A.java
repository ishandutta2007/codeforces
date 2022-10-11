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
      String str = nextToken();
      int left = str.indexOf("+");
      int right = str.indexOf("=");
      int a = left;
      int b = right-left-1;
      int c = str.length() - right-1;
      if(a+b==c) {
        generate(a,b,c);
      }
      else if(c > 0 && (a+1)+b == (c-1)) {
        generate(a+1,b,c-1);
      }
      else if(a > 1 && (a-1)+b==c+1) {
        generate(a-1,b,c+1);
      }
      else if(b>1 && a+(b-1)==c+1) {
        generate(a,b-1,c+1);
      }
      else {
        pw.println("Impossible");
      }
    }
    pw.close();
  }

  public static void generate(int a, int b, int c) {
    while(a-- > 0) {
      pw.print("|");
    }
    pw.print("+");
    while(b-- > 0) {
      pw.print("|");
    }
    pw.print("=");
    while(c-- > 0) {
      pw.print("|");
    }
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