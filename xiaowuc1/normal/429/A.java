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
      int n = readInt();
      
      LinkedList<Integer>[] edges = new LinkedList[n];
      for(int i = 0; i < n; i++) {
        edges[i] = new LinkedList<Integer>();
      }

      for(int i = 1; i < n; i++) {
        int a = readInt()-1;
        int b = readInt()-1;
        edges[a].add(b);
        edges[b].add(a);
      }

      int[] have = new int[n];
      for(int i = 0; i < n; i++) {
        have[i] = readInt();
      }
      int[] goal = new int[n];
      for(int i = 0; i < n; i++) {
        goal[i] = readInt();
      }

      ArrayList<Integer> ret = new ArrayList<Integer>();

      int[] dist = new int[n];
      Arrays.fill(dist, 1 << 25);
      dist[0] = 0;
      LinkedList<State> q = new LinkedList<State>();
      q.add(new State(0, 0, 0));
      while(!q.isEmpty()) {
        State curr = q.removeFirst();
        int numFlips = 0;
        if(dist[curr.curr] % 2 == 0) numFlips = curr.even;
        else numFlips = curr.odd;
        boolean flipped = numFlips % 2 == 1;
        if(flipped != (have[curr.curr] != goal[curr.curr])) {
          if(dist[curr.curr] % 2 == 0) {
            curr.even++;
          }
          else {
            curr.odd++;
          }
          ret.add(curr.curr + 1);
        }
        for(int out: edges[curr.curr]) {
          if(dist[out] > 1 + dist[curr.curr]) {
            dist[out] = 1 + dist[curr.curr];
            q.add(new State(out, curr.odd, curr.even));
          }
        }
      }

      pw.println(ret.size());
      for(int out: ret) {
        pw.println(out);
      }

    }
    pw.close();
  }

  static class State {
    public int curr, odd, even;
    public State(int a, int b, int c) {
      curr = a;
      odd = b;
      even = c;
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