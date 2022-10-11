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
      Map<Integer, ArrayList<Integer>> map = new TreeMap<Integer, ArrayList<Integer>>();
      for(int i = 0; i < n; i++) {
        int curr = readInt();
        if(!map.containsKey(curr)) {
          map.put(curr, new ArrayList<Integer>());
        }
        map.get(curr).add(i);
      }
      ArrayList<Integer> retA = new ArrayList<Integer>();
      ArrayList<Integer> retB = new ArrayList<Integer>();
      for(int out: map.keySet()) {
        ArrayList<Integer> go = map.get(out);
        if(go.size() == 1) {
          retA.add(out);
          retB.add(0);
        }
        else {
          Collections.sort(go);
          TreeSet<Integer> set = new TreeSet<Integer>();
          for(int i = 0; i < go.size()-1; i++) {
            set.add(go.get(i+1) - go.get(i));
          }
          if(set.size() == 1) {
            retA.add(out);
            retB.add(set.first());
          }
        }
      }
      pw.println(retA.size());
      for(int i = 0; i < retA.size(); i++) {
        pw.println(retA.get(i) + " " + retB.get(i));
      }
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