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
    outer: for(int casenum = 1; casenum <= qq; casenum++)  {
      int k = readInt();
      int num = readInt();
      int n = readInt();
      int m = readInt();
      for(int maskOne = 0; maskOne < 4; maskOne++) {
        if(maskOne == 3 && n == 1) continue;
        for(int maskTwo = 0; maskTwo < 4; maskTwo++) {
          if(maskTwo == 3 && m == 1) continue;
          for(int numA = 0; numA <= getMax(n, maskOne); numA++) {
            for(int numB = 0; numB <= getMax(m, maskTwo); numB++) {
              long[] count = new long[k];
              int[] mask = new int[k];
              count[0] = numA;
              count[1] = numB;
              mask[0] = maskOne;
              mask[1] = maskTwo;
              for(int i = 2; i < k; i++) {
                /*
                 * x(n) = x(n-2) + x(n-1)
                 * Mask 0 means no A, not C
                 * Mask 1 means ends with A, no C
                 * Mask 2 means no A, starts with C
                 * Mask 3 means ends with A, starts with C
                 */
                count[i] = count[i-2] + count[i-1];
                if(mask[i-2]%2==1 && mask[i-1] >= 2) {
                  count[i]++;
                }
                mask[i] |= mask[i-2]&2;
                mask[i] |= mask[i-1]&1;
              }
              if(count[k-1] == num) {
                pw.println(gen(n, numA, maskOne));
                pw.println(gen(m, numB, maskTwo));
                continue outer;
              }
            }
          }
        }
      }
      pw.println("Happy new year!");
    }
    pw.close();
  }

  public static String gen(int length, int num, int mask) {
    char[] ret = new char[length];
    Arrays.fill(ret, 'Z');
    int start = 0;
    if((mask>=2)) {
      ret[start++] = 'C';
    }
    for(int i = start; num-- > 0; i+=2) {
      ret[i] = 'A';
      ret[i+1] = 'C';
    }
    if(mask%2==1) {
      ret[ret.length-1] = 'A';
    }
    return new String(ret);
  }
  
  /*
   * Mask 0 means no A, not C
   * Mask 1 means ends with A, no C
   * Mask 2 means no A, starts with C
   * Mask 3 means ends with A, starts with C
   */
  public static int getMax(int length, int mask) {
    switch(mask) {
    case 3:
      return (length-2)/2;
    case 2:
    case 1:
      return (length-1)/2;
    case 0:
      return length/2;
    default:
      throw new RuntimeException("NOOB");
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