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
      int goal = readInt();
      String s = nextToken();
      Map<Integer, Integer> map = new HashMap<Integer, Integer>();
      for(int i = 0; i < s.length(); i++) {
        int curr = 0;
        for(int j = i; j < s.length(); j++) {
          curr += s.charAt(j)-'0';
          Integer value = map.get(curr);
          if(value==null)value = 0;
          map.put(curr, ++value);
        }
      }
      long ret = 0;
      if(goal == 0 && map.containsKey(0)) {
        long amt = map.get(0);
        ret += amt * amt;
        for(int out: map.keySet()) {
          if(out > 0) {
            ret += 2 * amt * map.get(out);
          }
        }
      }
      else {
        for(int i = 1; i * i <= goal; i++) {
          if(goal%i!=0) continue;
          int a = i;
          int b = goal/i;
          if(map.containsKey(a) && map.containsKey(b)) {
            ret += map.get(a) * 1L * map.get(b);
            if(a != b) {
              ret += map.get(a) * 1L * map.get(b);
            }
          }
        }
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