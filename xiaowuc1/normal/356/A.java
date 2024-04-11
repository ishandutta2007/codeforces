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
      int k = readInt();
      int[] x = new int[k];
      int[] y = new int[k];
      int[] z = new int[k];
      for(int i = 0; i < k; i++) {
        x[i] = readInt()-1;
        y[i] = readInt()-1;
        z[i] = readInt()-1;
      }
      SegmentTree tree = new SegmentTree(new int[n]);
      for(int i = k-1; i >= 0; i--) {
        if(z[i] > x[i]) {
          tree.update(x[i], z[i]-1, z[i]+1);
        }
        if(z[i] < y[i]) {
          tree.update(z[i]+1, y[i], z[i]+1);
        }
      }
      StringBuilder sb = new StringBuilder();
      for(int i = 0; i < n; i++) {
        sb.append(tree.query(i) + " ");
      }
      pw.println(sb.toString().trim());
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
      Arrays.fill(leaf, -1);
      update = new int[4*size];
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
        update[index] = 0;
        return;
      }
      if(leafL >= left && leafR <= right) {
        update[index] = val;
        return;
      }
      if(update[index] != 0) {
        update[2*index] = update[index];
        update[2*index+1] = update[index];
        update[index] = 0;
      }
      int m = (leafL+leafR)/2;
      update(2*index, leafL, m, left, right, val);
      update(2*index+1, m+1, leafR, left, right, val);
    }
    public int query(int index) {
      return query(1, 0, size-1, index);
    }
    public int query(int treeIndex, int l, int r, int index) {
      if(index < l || index > r) return -1;
      if(l == r) {
        if(update[treeIndex] != 0) {
          leaf[treeIndex] = update[treeIndex];
          update[treeIndex] = 0;
        }
        return leaf[treeIndex];
      }
      if(update[treeIndex] != 0) {
        update[2*treeIndex] = update[treeIndex];
        update[2*treeIndex+1] = update[treeIndex];
        update[treeIndex] = 0;
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