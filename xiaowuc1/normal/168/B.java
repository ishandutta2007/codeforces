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
    int qq = 1;
    //int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      ArrayList<String> list = new ArrayList<String>();
      while(true) {
        String s = br.readLine();
        if(s==null) break;
        if(!is(s)) {
          list.add(clean(s));
        }
        else {
          list.add(s);
        }
      }
      for(int i = 0; i < list.size(); ) {
        if(is(list.get(i))) {
          pw.println(list.get(i++));
        }
        else {
          StringBuilder sb = new StringBuilder();
          int j = i;
          for(j = i; j < list.size(); j++) {
            if(is(list.get(j))) {
              break;
            }
            sb.append(list.get(j));
          }
          i=j;
          pw.println(sb);
        }
      }
    }
    pw.close();
  }

  public static boolean is(String s) {
    for(int i = 0; i < s.length(); i++) {
      if(!Character.isWhitespace(s.charAt(i))) {
        return s.charAt(i) == '#';
      }
    }
    return false;
  }

  public static String clean(String s) {
    StringBuilder sb = new StringBuilder();
    for(int i = 0; i < s.length(); i++) {
      if(!Character.isWhitespace(s.charAt(i))) {
        sb.append(s.charAt(i));
      }
    }
    return sb.toString();
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