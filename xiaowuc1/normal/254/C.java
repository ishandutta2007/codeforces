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
    br = new BufferedReader(new FileReader("input.txt"));
    pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      char[] ret = nextToken().toCharArray();
      String b = nextToken();
      int n = b.length();
      int[] need = new int[26];
      int[] have = new int[26];
      for(int i = 0; i < n; i++) {
        need[b.charAt(i)-'A']++;
        have[ret[i]-'A']++;
      }
      int ans = 0;
      outer: for(int i = 0; i < n; i++) {
        for(int index = 0; index < 26; index++) {
          char go = (char)('A'+index);
          if(go < ret[i] && need[go-'A'] > have[go-'A'] && have[ret[i]-'A'] > need[ret[i]-'A']) {
            have[ret[i]-'A']--;
            need[go-'A']--;
            ret[i] = go;
            ans++;
            continue outer;
          }
          else if(go < ret[i]) {
            continue;
          }
          else if(go == ret[i]) {
            if(need[ret[i]-'A'] > 0) {
              have[ret[i]-'A']--;
              need[ret[i]-'A']--;
              continue outer;
            }
          }
          else if(need[go-'A'] > have[go-'A']) {
            have[ret[i]-'A']--;
            need[go-'A']--;
            ret[i] = go;
            ans++;
            continue outer;
          }
        }
      }
      pw.println(ans);
      pw.println(new String(ret));
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