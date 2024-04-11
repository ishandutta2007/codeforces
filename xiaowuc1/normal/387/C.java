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
      StringBuilder s = new StringBuilder(nextToken());
      int ret = 0;
      while(s.length() > 0) {
        int index = s.length()-1;
        int length = 1;
        while(s.charAt(index) == '0') {
          index--;
          length++;
        }
        int save = -1;
        int our = 0;
        for(int i = index-1; i >= 0; i--) {
          our++;
          if(s.charAt(i) == '0') continue;
          if(our > length) {
            save = i;
            break;
          }
          else if(our == length && s.charAt(i) >= s.charAt(index)) {
            save = i;
            break;
          }
        }
        if(save == -1) {
          ret++;
          break;
        }
        while(s.length() > index) {
          s.deleteCharAt(index);
        }
        ret++;
      }
      pw.println(ret);
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