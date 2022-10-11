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
      boolean[] row = new boolean[n];
      boolean[] col = new boolean[n];
      Arrays.fill(row, true);
      Arrays.fill(col, true);
      int m = readInt();
      while(m-- > 0) {
        int x = readInt()-1;
        int y = readInt()-1;
        row[x] = false;
        col[y] = false;
      }
      int ret = 0;
      if(n%2==1) {
        if(row[n/2] || col[n/2]) {
          ret++;
        }
      }
      for(int i = 1; i < n-1-i; i++) {
        int j = n-1-i;
        int bestMask = 0;
        // 0 is top i (1)
        // 1 is bottom i (2)
        // 2 is top j (4)
        // 3 is bottom j (8)
        // 4 is left i (16)
        // 5 is left j (32)
        // 6 is right i (64)
        // 7 is right j (128)
        for(int mask = 0; mask < 256; mask++) {
          if(Integer.bitCount(mask) <= Integer.bitCount(bestMask)) {
            continue;
          }
          if((mask&3)==3) continue;
          if((mask&12)==12) continue;
          if((mask&80)==80) continue;
          if((mask&160)==160) continue;
          if((mask&1)!=0 && (mask&16)!=0) continue;
          if((mask&1)!=0 && (mask&128)!=0) continue;
          if((mask&2)!=0 && (mask&32)!=0) continue;
          if((mask&2)!=0 && (mask&64)!=0) continue;
          if((mask&4)!=0 && (mask&64)!=0) continue;
          if((mask&4)!=0 && (mask&32)!=0) continue;
          if((mask&8)!=0 && (mask&128)!=0) continue;
          if((mask&8)!=0 && (mask&16)!=0) continue;
          if((mask&1)!=0 && !col[i]) continue;
          if((mask&2)!=0 && !col[i]) continue;
          if((mask&4)!=0 && !col[j]) continue;
          if((mask&8)!=0 && !col[j]) continue;
          if((mask&16)!=0 && !row[i]) continue;
          if((mask&32)!=0 && !row[j]) continue;
          if((mask&64)!=0 && !row[i]) continue;
          if((mask&128)!=0 && !row[j]) continue;
          bestMask = mask;
        }
        ret += Integer.bitCount(bestMask);
      }
      pw.println(ret);
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