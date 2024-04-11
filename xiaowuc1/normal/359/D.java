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
      int[] list = new int[n];
      Set<Integer>[] sets = new Set[n];
      for(int i = 0; i < n; i++) {
        list[i] = readInt();
        sets[i] = new HashSet<Integer>();
      }
      int maxSize = 0;
      ArrayList<Integer> ret = new ArrayList<Integer>();
      for(int i = 0; i < n; i++) {
        if(maxSize == 0) {
          ret.add(i+1);
        }
        int curr = list[i];
        int min = list[i];
        for(int j = i+1; j < n; j++) {
          curr = gcd(list[j], curr);
          min = Math.min(min, list[j]);
          if(!sets[j].add(curr)) break;
          if(curr == min) {
            int size = j-i;
            if(size > maxSize) {
              ret = new ArrayList<Integer>();
              maxSize = size;
            }
            if(size == maxSize){
              ret.add(i+1);
            }
          }
        }
      }
      pw.println(ret.size() + " " + maxSize);
      StringBuilder sb = new StringBuilder();
      for(int out: ret) {
        sb.append(out + " ");
      }
      pw.println(sb.toString().trim());
    }
    pw.close();
  }

  public static int gcd(int a, int b) {
    return a%b==0 ? b : gcd(b,a%b);
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