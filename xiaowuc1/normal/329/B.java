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

  static int[] dx = new int[]{-1,1,0,0};
  static int[] dy = new int[]{0,0,-1,1};

  public static void main(String[] args) throws IOException {
    br = new BufferedReader(new InputStreamReader(System.in));
    pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    //int qq = 1;
    int qq = Integer.MAX_VALUE;
    //int qq = readInt();
    for(int casenum = 1; casenum <= qq; casenum++)  {
      int r = readInt();
      int c = readInt();
      char[][] grid = new char[r][c];
      int[][] dist = new int[r][c];
      for(int i = 0; i < r; i++) {
        grid[i] = nextToken().toCharArray();
        Arrays.fill(dist[i], 1 << 25);
      }
      LinkedList<State> q = new LinkedList<State>();
      for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
          if(grid[i][j] == 'E') {
            q.add(new State(i,j));
            dist[i][j] = 0;
          }
        }
      }
      int ourDist = -1;
      while(!q.isEmpty()) {
        State curr = q.removeFirst();
        if(grid[curr.x][curr.y] == 'S') {
          ourDist = dist[curr.x][curr.y];
          break;
        }
        for(int k = 0; k < dx.length; k++) {
          int nx = curr.x + dx[k];
          int ny = curr.y + dy[k];
          if(nx >= 0 && nx < r && ny >= 0 && ny < c && dist[nx][ny] > 1 + dist[curr.x][curr.y] && grid[nx][ny] != 'T') {
            dist[nx][ny] = 1 + dist[curr.x][curr.y];
            q.add(new State(nx, ny));
          }
        }
      }
      int ret = 0;
      for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
          if(dist[i][j] <= ourDist && Character.isDigit(grid[i][j])) {
            ret += grid[i][j] - '0';
          }
        }
      }
      pw.println(ret);
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