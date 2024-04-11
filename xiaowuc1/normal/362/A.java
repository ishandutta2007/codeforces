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

  static int[] dx = new int[]{-2,-2,2,2};
  static int[] dy = new int[]{-2,2,-2,2};

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    //int qq = Integer.MAX_VALUE;
    int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      char[][] grid = new char[8][8];
      for(int i = 0; i < grid.length; i++) {
        grid[i] = nextToken().toCharArray();
      }
      int x1 = -1;
      int y1 = -1;
      int x2 = -1;
      int y2 = -1;
      for(int i = 0; i < grid.length; i++) {
        for(int j = 0; j < grid[i].length; j++) {
          if(grid[i][j] == 'K') {
            if(x1 == -1) {
              x1 = i;
              y1 = j;
            }
            else {
              x2 = i;
              y2 = j;
            }
          }
        }
      }
      boolean[][][][] visited = new boolean[8][8][8][8];
      visited[x1][y1][x2][y2] = true;
      LinkedList<State> q = new LinkedList<State>();
      q.add(new State(x1,y1,x2,y2));
      while(!q.isEmpty()) {
        State curr = q.removeFirst();
        for(int a = 0; a < dx.length; a++) {
          for(int b = 0; b < dx.length; b++) {
            int nx1 = curr.x1 + dx[a];
            int ny1 = curr.y1 + dy[a];
            int nx2 = curr.x2 + dx[b];
            int ny2 = curr.y2 + dy[b];
            int min = Math.min(Math.min(nx1, nx2), Math.min(ny1, ny2));
            int max = Math.max(Math.max(nx1, nx2), Math.max(ny1, ny2));
            if(min >= 0 && min < 8 && max >= 0 && max < 8 && !visited[nx1][ny1][nx2][ny2]) {
              visited[nx1][ny1][nx2][ny2] = true;
              q.add(new State(nx1, ny1, nx2, ny2));
            }
          }
        }
      }
      boolean ret = false;
      for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
          if(visited[i][j][i][j] && grid[i][j] != '#') {
            ret = true;
          }
        }
      }
      pw.println(ret ? "YES" : "NO");
    }
    pw.close();
  }

  static class State {
    public int x1,y1,x2,y2;

    public State(int x1, int y1, int x2, int y2) {
      super();
      this.x1 = x1;
      this.y1 = y1;
      this.x2 = x2;
      this.y2 = y2;
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