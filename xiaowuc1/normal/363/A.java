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
    String[] ret = new String[10];
    ret[0] = "O-|-OOOO";
    ret[1] = "O-|O-OOO";
    ret[2] = "O-|OO-OO";
    ret[3] = "O-|OOO-O";
    ret[4] = "O-|OOOO-";
    ret[5] = "-O|-OOOO";
    ret[6] = "-O|O-OOO";
    ret[7] = "-O|OO-OO";
    ret[8] = "-O|OOO-O";
    ret[9] = "-O|OOOO-";
    for(int casenum = 1; casenum <= qq; casenum++)  {
      String str = nextToken();
      for(int i = str.length()-1; i >= 0; i--) {
        pw.println(ret[str.charAt(i)-'0']);
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