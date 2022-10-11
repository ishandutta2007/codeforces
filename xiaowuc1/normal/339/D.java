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
      int[] list = new int[1<<n];
      for(int i = 0; i < 1<<n; i++) {
        list[i] = readInt();
      }
      SegmentTree ret = new SegmentTree(list);
      while(m-- > 0) {
        int index = readInt();
        int val = readInt();
        ret.update(--index, val);
        pw.println(ret.getRoot());
      }
    }
    pw.close();
  }

  static class SegmentTree {
    int[] tree;
    boolean[] or;
    int size;
    public SegmentTree(int[] list) {
      tree = new int[4*list.length];
      or = new boolean[4*list.length];
      size = list.length;
      build(1,0,list.length-1,list);
    }
    public void build(int index, int l, int r, int[] list) {
      if(l == r) {
        tree[index] = list[l];
      }
      else {
        int m = (l+r)/2;
        build(2*index, l, m, list);
        build(2*index+1, m+1, r, list);
        or[index] = !or[2*index];
        if(or[index]) {
          tree[index] = tree[2*index] | tree[2*index+1];
        }
        else {
          tree[index] = tree[2*index] ^ tree[2*index+1];
        }
      }
    }
    public void update(int index, int val) {
      update(1, 0, size-1, index, val);
    }
    public void update(int index, int l, int r, int ii, int v) {
      if(ii < l || ii > r) return;
      if(l==r) {
        tree[index] = v;
        return;
      }
      else {
        int m = (l+r)/2;
        update(2*index, l, m, ii, v);
        update(2*index+1, m+1, r, ii, v);
        if(or[index]) {
          tree[index] = tree[2*index] | tree[2*index+1];
        }
        else {
          tree[index] = tree[2*index] ^ tree[2*index+1];
        }
      }
    }
    public int getRoot() {
      return tree[1];
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