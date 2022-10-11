import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
  static BufferedReader br;
  static StringTokenizer st;
  static PrintWriter pw;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++) {
      String s = nextToken();
      int eIndex = s.indexOf("e");
      String a = s.substring(0, eIndex);
      int b = Integer.parseInt(s.substring(eIndex+1));
      while(b-- > 0) {
        int dot = a.indexOf(".");
        if(dot == -1) {
          a += 0;
        }
        else {
          String newA = "";
          int start = 0;
          if(a.charAt(start) == '0') {
            start = 1;
          }
          newA += a.substring(start, dot);
          newA += a.charAt(dot+1);
          if(dot != a.length()-2) {
            newA += ".";
            newA += a.substring(dot+2);
          }
          a = newA;
        }
      }
      if(a.indexOf(".") >= 0) {
        while(a.charAt(a.length()-1) == '0') {
          a = a.substring(0, a.length()-1);
        }
        if(a.charAt(a.length()-1) == '.') {
          a = a.substring(0, a.length()-1);
        }
      }
      pw.println(a);
      pw.flush();
    }
    pw.close();
  }

  public static void exitImmediately() {
    pw.close();
    System.exit(0);
  }

  public static int readInt() throws IOException {
    return Integer.parseInt(nextToken());
  }

  public static double readDouble() throws IOException {
    return Double.parseDouble(nextToken());
  }

  public static long readLong() throws IOException {
    return Long.parseLong(nextToken());
  }

  public static String nextLine() throws IOException {
    st = null;
    if(!br.ready()) {
      exitImmediately();
    }
    return br.readLine();
  }

  public static String nextToken() throws IOException {
    while(st == null || !st.hasMoreTokens()) {
      if(!br.ready()) {
        exitImmediately();
      }
      st = new StringTokenizer(br.readLine());
    }
    return st.nextToken();
  }
}