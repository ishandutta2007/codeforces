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
      int qqq = readInt();
      int[] a = new int[n];
      int[] b = new int[n];
      for(int i = 0; i < n; i++) {
        a[i] = readInt();
      }
      for(int i = 0; i < n; i++) {
        b[i] = readInt();
      }
      int[] list = new int[n];
      Arrays.fill(list, Integer.MIN_VALUE);
      SegmentTree tree = new SegmentTree(list);
      while(qqq-- > 0) {
        int type = readInt();
        if(type == 2) {
          int temp = readInt()-1;
          int index = tree.query(temp);
          if(index == Integer.MIN_VALUE) {
            pw.println(b[temp]);
          }
          else {
            pw.println(a[temp+index]);
          }
        }
        else {
          // copy a from aIndex to b from bIndex 
          int aIndex = readInt()-1;
          int bIndex = readInt()-1;
          int len = readInt();
          int diff = aIndex - bIndex;
          tree.update(bIndex, bIndex+len-1, diff);
        }
      }
    }
    pw.close();
  }

  static class SegmentTree {
    public int[] leaf;
    public int[] update;
    public int size;
    public SegmentTree(int[] list) {
      size = list.length;
      leaf = new int[4*size];
      update = new int[4*size];
      Arrays.fill(leaf, Integer.MIN_VALUE);
      Arrays.fill(update, Integer.MIN_VALUE);
      build(1, 0, list.length-1, list);
    }
    public void build(int index, int l, int r, int[] list) {
      if(l == r) {
        leaf[index] = list[l];
      }
      else {
        int m = (l+r)/2;
        build(2*index, l, m, list);
        build(2*index+1, m+1, r, list);
      }
    }
    public void update(int left, int right, int val) {
      update(1, 0, size-1, left, right, val);
    }
    public void update(int index, int leafL, int leafR, int left, int right, int val) {
      if(left > leafR) return;
      if(right < leafL) return;
      if(leafL == leafR) {
        leaf[index] = val;
        update[index] = Integer.MIN_VALUE;
        return;
      }
      if(leafL >= left && leafR <= right) {
        update[index] = val;
        return;
      }
      if(update[index] != Integer.MIN_VALUE) {
        update[2*index] = update[index];
        update[2*index+1] = update[index];
        update[index] = Integer.MIN_VALUE;
      }
      int m = (leafL+leafR)/2;
      update(2*index, leafL, m, left, right, val);
      update(2*index+1, m+1, leafR, left, right, val);
    }
    public int query(int index) {
      return query(1, 0, size-1, index);
    }
    public int query(int treeIndex, int l, int r, int index) {
      if(index < l || index > r) return Integer.MIN_VALUE;
      if(l == r) {
        if(update[treeIndex] != Integer.MIN_VALUE) {
          leaf[treeIndex] = update[treeIndex];
          update[treeIndex] = Integer.MIN_VALUE;
        }
        return leaf[treeIndex];
      }
      if(update[treeIndex] != Integer.MIN_VALUE) {
        update[2*treeIndex] = update[treeIndex];
        update[2*treeIndex+1] = update[treeIndex];
        update[treeIndex] = Integer.MIN_VALUE;
      }
      int m = (l+r)/2;
      return Math.max(query(2*treeIndex, l, m, index), query(2*treeIndex+1, m+1, r, index));
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