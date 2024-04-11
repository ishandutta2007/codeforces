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
      int qqq = readInt();
      int[] ret = new int[n];
      Arrays.fill(ret, 1000000000);
      int[][] saved = new int[qqq][4];
      for(int i = 0; i < saved.length; i++) {
        saved[i][0] = readInt();
        saved[i][1] = readInt()-1;
        saved[i][2] = readInt()-1;
        saved[i][3] = readInt();
      }
      int[] inc = new int[n];
      for(int i = 0; i < saved.length; i++) {
        if(saved[i][0] == 1) {
          for(int a = saved[i][1]; a <= saved[i][2]; a++) {
            inc[a] += saved[i][3];
          }
        }
        else {
          for(int a = saved[i][1]; a <= saved[i][2]; a++) {
            ret[a] = Math.min(ret[a], saved[i][3] - inc[a]);
          }
        }
      }
      int[] simul = new int[n];
      for(int i = 0; i < n; i++) {
        simul[i] = ret[i];
      }
      for(int i = 0; i < saved.length; i++) {
        if(saved[i][0] == 1) {
          for(int a = saved[i][1]; a <= saved[i][2]; a++) {
            simul[a] += saved[i][3];
          }
        }
        else {
          int ans = Integer.MIN_VALUE;
          for(int a = saved[i][1]; a <= saved[i][2]; a++) {
            ans = Math.max(ans, simul[a]);
          }
          if(ans != saved[i][3]) {
            pw.println("NO");
            exitImmediately();
          }
        }
      }
      pw.println("YES");
      for(int i = 0; i < n; i++) {
        pw.print(ret[i]);
        if(i < n-1) {
          pw.print(" ");
        }
        else {
          pw.println();
        }
      }
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