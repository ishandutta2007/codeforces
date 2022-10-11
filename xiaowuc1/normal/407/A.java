import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;

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
    for(int casenum = 1; casenum <= qq; casenum++) {
      int a = readInt();
      int b = readInt();
      int minAdjust = Math.min(a, b);
      int maxAdjust = Math.max(a, b);
      int gcd = gcd(maxAdjust, minAdjust);
      int minScale = minAdjust / gcd;
      minAdjust /= gcd;
      maxAdjust /= gcd;
      for(a = 1; a < gcd; a++) {
        b = (int)Math.sqrt(gcd*gcd-a*a);
        while(a*a+b*b < gcd*gcd) {
          b++;
        }
        if(a*a + b*b == gcd*gcd) {
          pw.println("YES");
          pw.println("0 0");
          pw.println((a*minAdjust) + " " + (b*minAdjust));
          pw.println(((a*minScale) + -b * maxAdjust) + " " + ((b*minScale) + a * maxAdjust));
          exitImmediately();
        }
      }
      pw.println("NO");
    }
    pw.close();
  }

  public static int gcd(int a, int b) {
    return a%b == 0 ? b : gcd(b, a%b);
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

  private static String nextLine() throws IOException  {
    if(!br.ready()) {
      exitImmediately();
    }
    st = null;
    return br.readLine();
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