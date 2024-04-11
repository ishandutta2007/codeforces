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
      int m = readInt();
      int p = readInt();
      int[] list = new int[n];
      for(int i = 0; i < n; i++) {
        list[i] = readInt();
      }
      Map<Integer, Integer> map = load(m);
      TreeSet<Integer> ret = new TreeSet<Integer>();
      for(int a = 0; a < p; a++) {
        int num = 0;
        int curr = a;
        Map<Integer, Integer> count = new HashMap<Integer, Integer>();
        Set<Integer> badKeys = new HashSet<Integer>();
        while(curr < n) {
          if(!count.containsKey(list[curr])) {
            count.put(list[curr], 0);
          }
          count.put(list[curr], 1 + count.get(list[curr]));
          if(num < m) {
            num++;
          }
          if(equal(map, count, list[curr])) {
            badKeys.remove(list[curr]);
          }
          else {
            badKeys.add(list[curr]);
          }
          if(curr >= m*1L*p) {
            int key = list[curr - m * p];
            if(count.get(key) == 1) {
              count.remove(key);
            }
            else {
              count.put(key, count.get(key) - 1);
            }
            if(equal(map, count, key)) {
              badKeys.remove(key);
            }
            else {
              badKeys.add(key);
            }
          }
          if(num == m && badKeys.isEmpty()) {
            ret.add(curr - (m-1)*p + 1);
          }
          curr += p;
        }
      }
      pw.println(ret.size());
      StringBuilder ans = new StringBuilder();
      for(int out: ret) {
        ans.append(out + " ");
      }
      pw.println(ans.toString().trim());
    }
    pw.close();
  }

  public static boolean equal(Map<Integer, Integer> a, Map<Integer, Integer> b, int key) {
    int valA = a.containsKey(key) ? a.get(key) : 0;
    int valB = b.containsKey(key) ? b.get(key) : 0;
    return valA == valB;
  }

  public static Map<Integer, Integer> load(int n) throws IOException {
    Map<Integer, Integer> ret = new HashMap<Integer, Integer>();
    while(n-- > 0) {
      int key = readInt();
      if(!ret.containsKey(key)) {
        ret.put(key, 0);
      }
      ret.put(key, ret.get(key)+1);
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