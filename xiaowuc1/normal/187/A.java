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
      int[] list = new int[n];
      int[] goal = new int[n];
      for(int i = 0; i < n; i++) {
        list[i] = readInt();
      }
      for(int i = 0; i < n; i++) {
        goal[i] = readInt();
      }
      int first = 0;
      int listIndex = 0;
      while(first < n && list[listIndex] == goal[first]) {
        first++;
        listIndex++;
      }
      Set<Integer> bucket = new HashSet<Integer>();
      int ret = 0;
      for(int i = n-1; first < n; i--) {
        bucket.add(list[i]);
        ret++;
        while(first < n) {
          if(bucket.contains(goal[first])) {
            first++;
          }
          else if(goal[first] == list[listIndex]) {
            first++;
            listIndex++;
          }
          else {
            break;
          }
        }
      }
      pw.println(ret);
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