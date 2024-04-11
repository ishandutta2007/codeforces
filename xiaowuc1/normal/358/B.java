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
      String[] list = new String[n];
      for(int i = 0; i < n; i++) {
        list[i] = nextToken();
      }
      String str = nextToken();
      if(str.lastIndexOf("3") == -1) {
        pw.println("no");
        exitImmediately();
      }
      str = str.substring(0, str.lastIndexOf("3"));
      if(str.lastIndexOf("<") == -1) {
        pw.println("no");
        exitImmediately();
      }
      str = str.substring(0, str.lastIndexOf("<"));
      for(String out: list) {
        if(str.indexOf("<") == -1) {
          pw.println("no");
          exitImmediately();
        }
        str = str.substring(1 + str.indexOf("<"));
        if(str.indexOf("3") == -1) {
          pw.println("no");
          exitImmediately();
        }
        str = str.substring(1 + str.indexOf("3"));
        for(int i = 0; i < out.length(); i++) {
          if(str.indexOf(out.charAt(i)) == -1) {
            pw.println("no");
            exitImmediately();
          }
          str = str.substring(1 + str.indexOf(out.charAt(i)));
        }
      }
      pw.println("yes");
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