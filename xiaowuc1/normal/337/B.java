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
      long a = readInt();
      long b = readInt();
      long x = gcd(a,b);
      a/=x;
      b/=x;
      long c = readInt();
      long d = readInt();
      long y = gcd(c,d);
      c/=y;
      d/=y;
      if(1.0*a/c < 1.0*b/d) {
        long l = c;
        long r = a;
        a *= l;
        b *= l;
        c *= r;
        d *= r;
      }
      else {
        long l = d;
        long r = b;
        a *= l;
        b *= l;
        c *= r;
        d *= r;
      }
      long num = a*b - c*d;
      long dem = a*b;
      long g = gcd(dem, num);
      pw.println(num/g + "/" + dem/g);
    }
    pw.close();
  }

  public static long gcd(long a, long b) {
    if(a==0) return b;
    if(b==0) return a;
    return gcd(b, a%b);
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