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
  
  static int[] dx = new int[]{-1,1,0,0};
  static int[] dy = new int[]{0,0,-1,1};
  
  static char[][] grid;
  
  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int r = readInt();
      int c = readInt();
      int numX = readInt();
      grid = new char[r][c];
      int numTotal = 0;
      boolean[][] can = new boolean[r][c];
      LinkedList<State> q = new LinkedList<State>();
      for(int i = 0; i < r; i++) {
        grid[i] = nextToken().toCharArray();
        for(int j = 0; j < c; j++) {
          if(grid[i][j] == '.') {
            numTotal++;
            if(q.isEmpty()) {
              q.add(new State(i, j));
            }
          }
        }
      }
      int numSearch = numTotal - numX;
      while(!q.isEmpty() && numSearch > 0) {
        State curr = q.removeFirst();
        if(can[curr.x][curr.y]) continue;
        can[curr.x][curr.y] = true;
        numSearch--;
        for(int k = 0; k < dx.length; k++) {
          int nx = curr.x + dx[k];
          int ny = curr.y + dy[k];
          if(valid(nx,ny) && !can[nx][ny]) {
            q.add(new State(nx, ny));
          }
        }
      }
      for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
          if(grid[i][j] == '.' && !can[i][j]) {
            grid[i][j] = 'X';
          }
        }
      }
      for(char[] out: grid) {
        pw.println(new String(out));
      }
    }
    pw.close();
  }

  static class State {
    public int x,y;

    public State(int x, int y) {
      super();
      this.x = x;
      this.y = y;
    }
    
  }
  
  public static boolean valid(int x, int y) {
    return x >= 0 && x < grid.length && y >= 0 && y < grid[x].length && grid[x][y] == '.';
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