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
      int[] mask = new int[8];
      Arrays.fill(mask, -1);
      for(int i = 0; i < n; i++) {
        int curr = readInt();
        mask[get(curr)] = curr;
      }
      for(int a = 0; a < 8; a++) {
        if(mask[a] == -1) continue;
        for(int b = 0; b < a; b++) {
          if(mask[b] == -1 || (a&b)!=0) continue;
          for(int c = 0; c < b; c++) {
            if(mask[c] == -1 || (a&c)!=0 || (b&c)!=0) continue;
            for(int d = 0; d < c; d++) {
              if(mask[d] == -1 || (a&d)!=0 || (b&d)!=0 || (c&d)!=0) continue;
              pw.println(4);
              pw.println(mask[a] + " " + mask[b] + " " + mask[c] + " " + mask[d]);
              exitImmediately();
            }
          }
        }
      }
      for(int a = 0; a < 8; a++) {
        if(mask[a] == -1) continue;
        for(int b = 0; b < a; b++) {
          if(mask[b] == -1 || (a&b)!=0) continue;
          for(int c = 0; c < b; c++) {
            if(mask[c] == -1 || (a&c)!=0 || (b&c)!=0) continue;
            pw.println(3);
            pw.println(mask[a] + " " + mask[b] + " " + mask[c]);
            exitImmediately();
          }
        }
      }
      for(int a = 0; a < 8; a++) {
        if(mask[a] == -1) continue;
        for(int b = 0; b < a; b++) {
          if(mask[b] == -1 || (a&b)!=0) continue;
          pw.println(2);
          pw.println(mask[a] + " " + mask[b]);
          exitImmediately();
        }
      }
      for(int a = 0; a < 8; a++) {
        if(mask[a] == -1) continue;
        pw.println(1);
        pw.println(mask[a]);
        exitImmediately();
      }
    }
    pw.close();
  }

  public static int get(int s) {
    String ret = Integer.toString(s);
    while(ret.length() < 3) {
      ret = 0 + ret;
    }
    int mask = 0;
    for(int i = 0; i < 3; i++) {
      if(ret.charAt(i) != '0') {
        mask |= 1 << i;
      }
    }
    return mask;
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