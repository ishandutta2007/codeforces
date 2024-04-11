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
      int[] list = new int[n];
      for(int i = 0; i < n; i++) {
        list[i] = readInt();
      }
      for(int a = 0; a < 100; a++) {
        int x = (int)(Math.random()*n);
        int y = (int)(Math.random()*n);
        int temp = list[x];
        list[x] = list[y];
        list[y] = temp;
      }
      Arrays.sort(list);
      if(list.length == 1) {
        pw.println(-1);
      }
      else if(list[0] == list[n-1]) {
        pw.println(1);
        pw.println(list[0]);
      }
      else if(n == 2) {
        if(list[0] % 2 == list[1] % 2) {
          pw.println(3);
          pw.print(2 * list[0] - list[1]);
          pw.print(" ");
          pw.print((list[0] + list[1])/2);
          pw.print(" ");
          pw.print(2 * list[1] - list[0]);
          pw.println();
        }
        else {
          pw.println(2);
          pw.print(2 * list[0] - list[1]);
          pw.print(" ");
          pw.print(2 * list[1] - list[0]);
          pw.println();
        }
      }
      else {
        int ret = solve(list);
        if(ret == -1) {
          pw.println(2);
          pw.print(2*list[0] - list[1]);
          pw.print(" ");
          pw.print(list[n-1] + list[1] - list[0]);
          pw.println();
        }
        else if(ret == 0) {
          pw.println(0);
        }
        else {
          pw.println(1);
          pw.println(ret);
        }
      }
    }
    pw.close();
  }

  public static int solve(int[] list) {
    TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
    for(int i = 1; i < list.length; i++) {
      int key = list[i] - list[i-1];
      Integer value = map.get(key);
      if(value == null) value = 0;
      map.put(key, ++value);
    }
    if(map.size() > 2) return 0;
    if(map.size() == 1) return -1;
    int low = map.firstKey();
    int high = map.lastKey();
    if(map.get(high) != 1) return 0;
    if(2*low != high) return 0;
    for(int i = 1; i < list.length; i++) {
      if(list[i] - list[i-1] == high) {
        return ((list[i] + list[i-1]))/2;
      }
    }
    throw new RuntimeException();
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