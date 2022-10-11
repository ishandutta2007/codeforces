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

  static String[] list; 
  
  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      StringBuilder sb = new StringBuilder();
      String str = nextToken();
      int zero = 0;
      boolean one = true;
      boolean six = true;
      boolean eight = true;
      boolean nine = true;
      int curr = 0;
      for(int i = 0; i < str.length(); i++) {
        if(str.charAt(i) == '1' && one) {
          one = false;
        }
        else if(str.charAt(i) == '6' && six) {
          six = false;
        } 
        else if(str.charAt(i) == '8' && eight) {
          eight = false;
        } 
        else if(str.charAt(i) == '9' && nine) {
          nine = false;
        } 
        else if(str.charAt(i) == '0') {
          zero++;
        }
        else {
          sb.append(str.charAt(i));
          curr *= 10;
          curr += sb.charAt(sb.length()-1) - '0';
          curr %= 7;
        }
      }
      Set<Integer> set = new HashSet<Integer>();
      set.add(1689);
      set.add(1698);
      set.add(1869);
      set.add(1896);
      set.add(1986);
      set.add(1968);
      
      set.add(6189);
      set.add(6198);
      set.add(6819);
      set.add(6196);
      set.add(6981);
      set.add(6918);
      
      set.add(8619);
      set.add(8691);
      set.add(8169);
      set.add(8196);
      set.add(8916);
      set.add(8961);
      
      set.add(9681);
      set.add(9618);
      set.add(9861);
      set.add(9816);
      set.add(9186);
      set.add(9168);
      
      for(int out: set) {
        if((curr*10000+out)%7==0) {
          sb.append(out);
          while(zero-- > 0) {
            sb.append(0);
          }
          pw.println(sb);
          exitImmediately();
        }
      }
      
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