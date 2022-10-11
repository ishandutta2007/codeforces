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
      Map<Integer, Integer>[] maps = new Map[100005];
      ArrayList<Integer>[] submissionId = new ArrayList[100005];
      while(n-- > 0) {
        int num = readInt();
        int id = readInt();
        if(maps[id] == null) {
          maps[id] = new HashMap<Integer, Integer>();
          submissionId[id] = new ArrayList<Integer>();
        }
        if(num == submissionId[id].size()) {
          int submitID = maps[id].size();
          submissionId[id].add(submitID);
          maps[id].put(submitID, num);
        }
        else if(num > submissionId[id].size()) {
          pw.println("NO");
          exitImmediately();
        }
        else {
          int actualID = submissionId[id].get(num);
          if(maps[id].get(actualID) != num) {
            pw.println("NO");
            exitImmediately();
          }
        }
      }
      pw.println("YES");
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