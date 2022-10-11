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

  public static void main(String[] args) throws IOException	{
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    int qq = 1;
    //int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)	{
      int n = readInt();
      edges = new LinkedList[n];
      for(int i = 0; i < n; i++) edges[i] = new LinkedList<>();
      for(int i = 1; i < n; i++) {
        int a = readInt()-1;
        int b = readInt()-1;
        edges[a].add(new Edge(b, i-1));
        edges[b].add(new Edge(a, i-1));
      }
      par = new int[n];
      depth = new int[n];
      edgeid = new int[n];
      Arrays.fill(edgeid, -1);
      ret = new int[n-1];
      dfs(0, -1);
      Arrays.fill(ret, 1);
      int m = readInt();
      int[] lhs = new int[m];
      int[] rhs = new int[m];
      int[] w = new int[m];
      for(int i = 0; i < m; i++) {
        lhs[i] = readInt()-1;
        rhs[i] = readInt()-1;
        w[i] = readInt();
        int a = lhs[i];
        int b = rhs[i];
        while(a != b) {
          if(depth[a] > depth[b]) {
            ret[edgeid[a]] = Math.max(ret[edgeid[a]], w[i]);
            a = par[a];
          }
          else if(depth[b] > depth[a]) {
            ret[edgeid[b]] = Math.max(ret[edgeid[b]], w[i]);
            b = par[b];
          }
          else {
            ret[edgeid[a]] = Math.max(ret[edgeid[a]], w[i]);
            a = par[a];
            ret[edgeid[b]] = Math.max(ret[edgeid[b]], w[i]);
            b = par[b];
          }
        }
      }
      boolean good = true;
      for(int i = 0; good && i < m; i++) {
        int minw = (int)1e6;
        int a = lhs[i];
        int b = rhs[i];
        while(a != b) {
          if(depth[a] > depth[b]) {
            minw = Math.min(minw, ret[edgeid[a]]);
            a = par[a];
          }
          else if(depth[b] > depth[a]) {
            minw = Math.min(minw, ret[edgeid[b]]);
            b = par[b];
          }
          else {
            minw = Math.min(minw, ret[edgeid[a]]);
            a = par[a];
            minw = Math.min(minw, ret[edgeid[b]]);
            b = par[b];
          }
        }
        good = minw == w[i];
      }
      if(!good) {
        pw.println(-1);
      }
      else {
        for(int i = 0; i < ret.length; i++) {
          if(i > 0) pw.print(" ");
          pw.print(ret[i]);
        }
        pw.println();
      }
    }
    pw.close();
  }

  static LinkedList<Edge>[] edges;
  static int[] ret;
  static int[] par;
  static int[] depth;
  static int[] edgeid;

  public static void dfs(int curr, int p) {
    for(Edge out: edges[curr]) {
      if(out.d == p) continue;
      par[out.d] = curr;
      depth[out.d] = 1 + depth[curr];
      edgeid[out.d] = out.i;
      dfs(out.d, curr);
    }
  }

  static class Edge {
    public int d, i;
    public Edge(int a, int b) {
      d=a;
      i=b;
    }
  }

  private static void exitImmediately()	{
    pw.close();
    System.exit(0);
  }

  private static long readLong() throws IOException	{
    return Long.parseLong(nextToken());
  }

  private static double readDouble() throws IOException	{
    return Double.parseDouble(nextToken());
  }

  private static int readInt() throws IOException	{
    return Integer.parseInt(nextToken());
  }

  private static String nextToken() throws IOException	{
    while(st == null || !st.hasMoreTokens())	{
      if(!br.ready())	{
        exitImmediately();
      }
      st = new StringTokenizer(br.readLine().trim());
    }
    return st.nextToken();
  }
}