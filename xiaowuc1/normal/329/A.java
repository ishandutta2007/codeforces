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
      boolean[][] matrix = new boolean[n][n];
      boolean[] row = new boolean[n];
      boolean[] col = new boolean[n];
      for(int i = 0; i < n; i++) {
        String s = nextToken();
        for(int j = 0; j < n; j++) {
          matrix[i][j] = s.charAt(j) == '.';
          row[i] |= matrix[i][j];
          col[j] |= matrix[i][j];
        }
      }
      if(!allTrue(row) && !allTrue(col)) {
        pw.println(-1);
      }
      else if(allTrue(row)) {
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
            if(matrix[i][j]) {
              pw.println((i+1) + " " + (j+1));
              break;
            }
          }
        }
      }
      else {
        for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
            if(matrix[j][i]) {
              pw.println((j+1) + " " + (i+1));
              break;
            }
          }
        }
      }
    }
    pw.close();
  }

  public static boolean allTrue(boolean[] list) {
    for(boolean out: list) {
      if(!out) {
        return false;
      }
    }
    return true;
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