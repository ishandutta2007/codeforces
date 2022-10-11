import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;

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
    for(int casenum = 1; casenum <= qq; casenum++) {
      boolean[] comp = new boolean[1001];
      comp[0] = comp[1] = true;
      for(int i = 2; i * i < comp.length; i++) {
        if(!comp[i]) {
          for(int j = i*i; j < comp.length; j += i) {
            comp[j] = true;
          }
        }
      }
      String s = nextLine();
      int[] count = new int[26];
      int maxCount = 0;
      for(int i = 0; i < s.length(); i++) {
        count[s.charAt(i) - 'a']++;
        maxCount = Math.max(maxCount, count[s.charAt(i) - 'a']);
      }
      boolean[] inThatSet = new boolean[s.length()+1];
      for(int i = 2; i <= s.length() / 2; i ++) {
        if(!comp[i]) {
          for(int j = i; j < inThatSet.length; j += i) {
            inThatSet[j] = true;
          }
        }
      }
      int need = 0;
      for(boolean out: inThatSet) {
        if(out) {
          need++;
        }
      }
      if(need > maxCount) {
        pw.println("NO");
      }
      else {
        int index = 0;
        while(count[index] != maxCount) {
          index++;
        }
        char[] ret = new char[s.length()];
        for(int i = 0; i < ret.length; i++) {
          if(inThatSet[i+1]) {
            count[index]--;
            ret[i] = (char)('a' + index);
          }
        }
        for(int i = 0; i < ret.length; i++) {
          if(ret[i] == 0) {
            for(int a = 0; a < 26; a++) {
              if(count[a] > 0) {
                count[a]--;
                ret[i] = (char)(a + 'a');
                break;
              }
            }
          }
          if(ret[i] == 0) {
            throw new RuntimeException("WHAT");
          }
        }
        pw.println("YES");
        pw.println(new String(ret));
      }
    }
    pw.close();
  }

  public static int gcd(int a, int b) {
    return a%b == 0 ? b : gcd(b, a%b);
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

  private static String nextLine() throws IOException  {
    if(!br.ready()) {
      exitImmediately();
    }
    st = null;
    return br.readLine();
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