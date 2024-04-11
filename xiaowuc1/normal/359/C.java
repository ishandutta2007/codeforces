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
      int x = readInt();
      long pow = x;
      Set<Long> set = new HashSet<Long>();
      while(pow <= n) {
        set.add(pow);
        pow *= x;
      }
      long[] nums = new long[n];
      long sum = 0;
      for(int i = 0; i < n; i++) {
        nums[i] = readInt();
        sum += nums[i];
      }
      int num = 0;
      long extras = 0;
      for(int i = n-1; i >= 0;) {
        int j = i;
        while(j >= 0 && nums[j] == nums[i]) {
          j--;
          num++;
        }
        if(j == -1) {
          while(num%x == 0) {
            extras++;
            num /= x;
          }
        }
        else {
          long diff = nums[i] - nums[j];
          while(diff > 0) {
            if(num % x != 0) {
              break;
            }
            extras++;
            num /= x;
            diff--;
          }
          if(diff != 0) {
            break;
          }
        }
        i = j;
      }
      pw.println(modpow(x, Math.min(sum, sum - nums[n-1] + extras), 1000000007));
    }
    pw.close();
  }

  public static long modpow(long b, long e, long m) {
    long r = 1;
    while(e > 0) {
      if(e%2==1) {
        r*=b;
        r%=m;
      }
      b*=b;
      b%=m;
      e/=2;
    }
    return r;
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