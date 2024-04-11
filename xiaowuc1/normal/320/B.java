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
      l = new int[200];
      r = new int[200];
      int num = 0;
      while(n-- > 0) {
        int type = readInt();
        if(type == 2) {
          int a = readInt()-1;
          int b = readInt()-1;
          boolean[] visit = new boolean[num];
          visit[a] = true;
          LinkedList<Integer> q = new LinkedList<Integer>();
          q.add(a);
          while(!q.isEmpty()) {
            int curr = q.removeFirst();
            for(int i = 0; i < num; i++) {
              if(l[curr] > l[i] && l[curr] < r[i] && !visit[i]) {
                visit[i] = true;
                q.add(i);
              }
              if(r[curr] > l[i] && r[curr] < r[i] && !visit[i]) {
                visit[i] = true;
                q.add(i);
              }
            }
          }
          if(visit[b]) {
            pw.println("YES");
          }
          else {
            pw.println("NO");
          }
        }
        else {
          l[num] = readInt();
          r[num] = readInt();
          num++;
        }
      }
    }
    pw.close();
  }

  static int[] l,r;
  
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