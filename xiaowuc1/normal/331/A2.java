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
      long[] list = new long[n];
      long[] prefix = new long[n+1];
      HashMap<Long, Integer> map = new HashMap<Long, Integer>();
      for(int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + Math.max(0, list[i] = readInt());
        map.put(list[i], i);
      }
      long best = -(1L<<60);
      ArrayList<Integer> ans = new ArrayList<Integer>();
      for(int i = 0; i < n; i++) {
        long max = map.get(list[i]);
        if(max == i) continue;
        long curr = prefix[map.get(list[i]) + 1] - prefix[i];
        if(list[i] < 0) {
          curr += 2 * list[i];
        }
        if(curr > best) {
          best = curr;
          ans = new ArrayList<Integer>();
          for(int a = 0; a < n; a++) {
            if(a==i || a==max) continue;
            if(a < i || a > max || list[a] < 0) {
              ans.add(a);
            }
          }
        }
      }
      pw.println(best + " " + ans.size());
      StringBuilder sb = new StringBuilder();
      for(int out: ans) {
        sb.append(++out + " ");
      }
      pw.println(sb.toString().trim());
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