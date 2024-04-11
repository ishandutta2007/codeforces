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
      int canSwap = n;
      int total = 2*n-1;
      int[] list = new int[total];
      for(int i = 0; i < list.length; i++) {
        list[i] = readInt();
      }
      boolean[] canHavePoss = new boolean[total+1];
      int start = 0;
      for(int out: list) {
        if(out > 0) {
          start++;
        }
      }
      for(int i = 0; i < list.length; i++) {
        list[i] = Math.abs(list[i]);
      }
      LinkedList<Integer> q = new LinkedList<Integer>();
      q.add(start);
      canHavePoss[start] = true;
      while(!q.isEmpty()) {
        int curr = q.removeFirst();
        int negative = total - curr;
        for(int pos = 0; pos <= canSwap; pos++) {
          if(pos <= curr && (canSwap-pos) <= negative) {
            int next = curr - pos * 2 + canSwap;
            if(!canHavePoss[next]) {
              canHavePoss[next] = true;
              q.add(next);
            }
          }
        }
      }
      int max = total;
      while(!canHavePoss[max]) {
        max--;
      }
      Arrays.sort(list);
      int sum = 0;
      int bad = total - max;
      for(int out: list) {
        if(bad-- > 0) {
          sum -= out;
        }
        else {
          sum += out;
        }
      }
      pw.println(sum);
    }
    pw.close();
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