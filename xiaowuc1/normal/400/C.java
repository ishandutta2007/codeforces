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
      int n = readInt();
      int m = readInt();
      int x = readInt() % 4;
      int y = readInt() % 2;
      int z = readInt() % 4;
      z *= 3;
      z %= 4;
      int qqq = readInt();
      while(qqq-- > 0) {
        int saveN = n;
        int saveM = m;
        int currX = readInt()-1;
        int currY = readInt()-1;
        for(int i = 0; i < x; i++) {
          int[] rotate = rotate(currX, currY, n, m);
          currX = rotate[0];
          currY = rotate[1];
          int temp = m;
          m = n;
          n = temp;
        }
        if(y >= 1) {
          currY = m - 1 - currY;
        }
        for(int i = 0; i < z; i++) {
          int[] rotate = rotate(currX, currY, n, m);
          currX = rotate[0];
          currY = rotate[1];
          int temp = m;
          m = n;
          n = temp;
        }
        pw.println((currX+1) + " " + (currY+1));
        n = saveN;
        m = saveM;
      }
    }
    pw.close();
  }

  /*
  0 0 to 0 m-1
  1 0 to 0 m-2
  r-2 0 to 0 1
  r-1 0 to 0 0
  0 1 to 1 c-1
  0 2 to 2 c-1
  0 c-1 to c-1 
  */
  public static int[] rotate(int x, int y, int r, int c) {
    return new int[]{y, r-1-x};
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