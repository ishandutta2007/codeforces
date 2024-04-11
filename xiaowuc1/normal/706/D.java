import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
  static BufferedReader br;
  static StringTokenizer st;
  static PrintWriter pw;

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++) {
      Trie t = new Trie();
      t.insert(0);
      int qqq = readInt();
      while(qqq-- > 0) {
        String op = nextToken();
        int n = readInt();
        if(op.equals("+")) t.insert(n);
        if(op.equals("-")) t.delete(n);
        if(op.equals("?")) pw.println(t.maxXor(n));
      }
    }
    pw.close();
  }

  static class Trie {
    Node root;
    public Trie() {
      root = new Node();
    }
    public void insert(int x) {
      root.update(x, 30, 1);
    }
    public void delete(int x) {
      root.update(x, 30, -1);
    }
    public int maxXor(int x) {
      return root.query(x, 30);
    }
  }

  static class Node {
    public Node[] child;
    public int numChild;
    public Node() {
      child = new Node[2];
      numChild = 0;
    }
    public void update(int x, int bitIndex, int update) {
      numChild += update;
      if(bitIndex < 0) return;
      int childIndex = ((x&(1<<bitIndex))) != 0 ? 1 : 0;
      if(child[childIndex] == null) {
        child[childIndex] = new Node();
      }
      child[childIndex].update(x, bitIndex-1, update);
    }
    public int query(int x, int bitIndex) {
      if(bitIndex < 0) return 0;
      int childIndex = ((x&(1<<bitIndex))) != 0 ? 0 : 1;
      if(child[childIndex] != null && child[childIndex].numChild > 0) {
        return (1 << bitIndex) | child[childIndex].query(x, bitIndex-1);
      }
      if(child[1-childIndex] == null) {
        return 0;
      }
      return child[1-childIndex].query(x, bitIndex-1);
    }
  }

  public static void exitImmediately() {
    pw.close();
    System.exit(0);
  }

  public static int readInt() throws IOException {
    return Integer.parseInt(nextToken());
  }

  public static double readDouble() throws IOException {
    return Double.parseDouble(nextToken());
  }

  public static long readLong() throws IOException {
    return Long.parseLong(nextToken());
  }

  public static String nextLine() throws IOException {
    st = null;
    if(!br.ready()) {
      exitImmediately();
    }
    return br.readLine();
  }

  public static String nextToken() throws IOException {
    while(st == null || !st.hasMoreTokens()) {
      if(!br.ready()) {
        exitImmediately();
      }
      st = new StringTokenizer(br.readLine());
    }
    return st.nextToken();
  }
}