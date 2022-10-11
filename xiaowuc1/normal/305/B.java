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
      long num = readLong();
      long dem = readLong();
      int n = readInt();
      ArrayList<Long> list = new ArrayList<Long>();
      for(int i = 0; i < n; i++) {
        list.add(readLong());
      }
      boolean ret = match(num, dem, list);
      if(list.size() > 1 && list.get(list.size()-1) == 1) {
        list.add(list.remove(list.size()-1) + list.remove(list.size()-1));
        ret |= match(num, dem, list);
      }
      pw.println(ret ? "YES" : "NO");
    }
    pw.close();
  }

  public static boolean match(long num, long dem, ArrayList<Long> list) {
    for(int i = 0; i < list.size(); i++) {
      if(num / dem != list.get(i)) {
        return false;
      }
      num = num % dem;
      if(num == 0 && i != list.size()-1) return false;
      long temp = num;
      num = dem;
      dem = temp;
    }
    if(dem != 0) return false;
    return true;
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