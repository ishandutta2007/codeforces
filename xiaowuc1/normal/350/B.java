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
      int[] type = new int[n];
      for(int i = 0; i < n; i++) {
        type[i] = readInt();
      }
      int[] parent = new int[n];
      int[] numChild = new int[n];
      for(int i = 0; i < n; i++) {
        parent[i] = readInt()-1;
        if(parent[i] >= 0) {
          numChild[parent[i]]++;
        }
      }
      LinkedList<Integer> ret = new LinkedList<Integer>();
      for(int i = 0; i < n; i++) {
        if(type[i] == 0) continue;
        LinkedList<Integer> curr = new LinkedList<Integer>();
        curr.addFirst(i);
        int now = i;
        while(parent[now] >= 0 && type[parent[now]] == 0 && numChild[parent[now]] == 1) {
          curr.addFirst(parent[now]);
          now = parent[now];
        }
        if(curr.size() > ret.size()) {
          ret = curr;
        }
      }
      pw.println(ret.size());
      StringBuilder sb = new StringBuilder();
      for(int out: ret) {
        sb.append((1+out) + " ");
      }
      pw.println(sb.toString().trim());
    }
    pw.close();
  }

  public static String parse(long curr) {
    String ret = "";
    for(int i = 0; i < 4; i++) {
      ret = (curr&255) + ret;
      ret = "." + ret;
      curr >>= 8;
    }
    return ret.substring(1);
  }
  
  public static long parse(String str) {
    long ret = 0;
    StringTokenizer su = new StringTokenizer(str, ".");
    while(su.hasMoreTokens()) {
      ret <<= 8;
      ret |= Integer.parseInt(su.nextToken());
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