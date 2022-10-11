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

  static String[] list; 
  
  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int n = readInt();
      seen = new Set[n];
      for(int i = 0; i < n; i++) {
        seen[i] = new HashSet<Integer>();
      }
      list = new String[n];
      for(int i = 0; i < n; i++) {
        list[i] = nextToken();
      }
      pw.println(can(n-1) ? "YES" : "NO");
    }
    pw.close();
  }

  public static boolean can(int n) {
    if(n==0) {
      return true;
    }
    int hash = hash(n);
    if(!seen[n].add(hash)) return false;
    if(list[n].charAt(0) == list[n-1].charAt(0) || list[n].charAt(1) == list[n-1].charAt(1)) {
      String save = list[n-1];
      list[n-1] = list[n];
      if(can(n-1)) {
        return true;
      }
      list[n-1] = save;
    }
    if(n-3 >= 0 && (list[n].charAt(0) == list[n-3].charAt(0) || list[n].charAt(1) == list[n-3].charAt(1))) {
      String save = list[n-3];
      list[n-3] = list[n];
      if(can(n-1)) {
        return true;
      }
      list[n-3] = save;
    }
    return false;
  }
  
  static Set<Integer>[] seen;
  
  public static int hash(int n) {
    int ret = 0;
    for(int i = 0; i <= n; i++) {
      ret *= 3137;
      ret += list[i].hashCode();
    }
    return ret;
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