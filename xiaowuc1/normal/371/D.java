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
      long[] cap = new long[n+1];
      long[] curr = new long[n+1];
      TreeSet<Integer> set = new TreeSet<Integer>();
      for(int i = 0; i < n; i++) {
        cap[i] = readInt();
        set.add(i);
      }
      set.add(n);
      cap[n] = Long.MAX_VALUE;
      int qqq = readInt();
      while(qqq-- > 0) {
        int type = readInt();
        if(type == 2) {
          pw.println(curr[readInt()-1]);
        }
        else {
          int index = readInt()-1;
          int val = readInt();
          while(val > 0) {
            long canAdd = cap[index] - curr[index];
            if(val <= canAdd) {
              curr[index] += val;
              val = 0;
            }
            else {
              curr[index] = cap[index];
              val -= canAdd;
              set.remove(index);
              index = set.higher(index);
            }
          }
        }
      }
    }
    pw.close();
  }

  static class SegmentTreeRangeUpdate {
    public long[] leaf;
    public long[] update;
    public int origSize;
    public SegmentTreeRangeUpdate(int[] list) {
      origSize = list.length;
      leaf = new long[4*list.length];
      update = new long[4*list.length];
      build(1,0,list.length-1,list);
    }
    public void build(int curr, int begin, int end, int[] list) {
      if(begin == end)
        leaf[curr] = list[begin];
      else  {
        int mid = (begin+end)/2;
        build(2 * curr, begin, mid, list);
        build(2 * curr + 1, mid+1, end, list);
        leaf[curr] = leaf[2*curr] + leaf[2*curr+1];
      }
    }
    public void update(int begin, int end, int val) {
      update(1,0,origSize-1,begin,end,val);
    }
    public void update(int curr,  int tBegin, int tEnd, int begin, int end, int val)  {
      if(tBegin >= begin && tEnd <= end)
        update[curr] = val;
      else  {
        int mid = (tBegin+tEnd)/2;
        if(mid >= begin && tBegin <= end)
          update(2*curr, tBegin, mid, begin, end, val);
        if(tEnd >= begin && mid+1 <= end)
          update(2*curr+1, mid+1, tEnd, begin, end, val);
      }
    }
    public long query(int begin, int end) {
      return query(1,0,origSize-1,begin,end);
    }
    public long query(int curr, int tBegin, int tEnd, int begin, int end) {
      if(tBegin >= begin && tEnd <= end)  {
        if(update[curr] != 0) {
          leaf[curr] = update[curr];
          if(2*curr < update.length){
            update[2*curr] = update[curr];
            update[2*curr+1] = update[curr];
          }
          update[curr] = 0;
        }
        return leaf[curr];
      }
      else  {
        leaf[curr] = update[curr];
        if(2*curr < update.length){
          update[2*curr] = update[curr];
          update[2*curr+1] = update[curr];
        }
        update[curr] = 0;
        int mid = (tBegin+tEnd)/2;
        long ret = 0;
        if(mid >= begin && tBegin <= end)
          ret = query(2*curr, tBegin, mid, begin, end);
        if(tEnd >= begin && mid+1 <= end)
          ret = query(2*curr+1, mid+1, tEnd, begin, end);
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