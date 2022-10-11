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
      SegmentTree tree = new SegmentTree(new int[n]);
      for(int i = 0; i < n; i++) {
        int curr = readInt()-1;
        tree.update(curr, 1 + tree.query(0, curr));
      }
      pw.println(tree.query(0, n-1));
    }
    pw.close();
  }

  static class SegmentTree {
    public int[] leaf;
    public int origSize;
    public SegmentTree(int[] list)  {
      origSize = list.length;
      leaf = new int[4*list.length];
      build(1,0,list.length-1,list);
    }
    public void build(int curr, int begin, int end, int[] list) {
      if(begin == end)  {
        leaf[curr] = list[begin];
      }
      else  {
        int mid = (begin+end)/2;
        build(2 * curr, begin, mid, list);
        build(2 * curr + 1, mid+1, end, list);
        leaf[curr] = Math.max(leaf[2*curr], leaf[2*curr+1]);
      }
    }
    public void update(int index, int val)  {
      update(1,0,origSize-1,index,val);
    }
    public void update(int curr, int begin, int end, int index, int val)  {
      if(begin == end)  {
        leaf[curr] = val;
      }
      else  {
        int mid = (begin+end)/2;
        if(index <= mid)
          update(2 * curr, begin, mid, index, val);
        else
          update(2 * curr + 1, mid+1, end, index, val);
        leaf[curr] = Math.max(leaf[2*curr], leaf[2*curr+1]);
      }
    }
    public int query(int begin, int end)  {
      return query(1,0,origSize-1,begin,end);
    }
    public int query(int curr, int tBegin, int tEnd, int begin, int end)  {
      if(tBegin >= begin && tEnd <= end)  {
        return leaf[curr];
      }
      else  {
        int mid = (tBegin+tEnd)/2;
        int ret = 0;
        if(mid >= begin && tBegin <= end)
          ret = Math.max(ret, query(2*curr, tBegin, mid, begin, end));
        if(tEnd >= begin && mid+1 <= end)
          ret = Math.max(ret, query(2*curr+1, mid+1, tEnd, begin, end));
        return ret;
      }
    }
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