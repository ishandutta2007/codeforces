import java.awt.Point;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);
    static int M, N, K;
    static char[][] map;
    static int[][] time;
    static HashMap<Character, Point> pos = new HashMap<Character, Point>();
    static int[] DR = new int[] { 1, 0, -1, 0 };
    static int[] DC = new int[] { 0, 1, 0, -1 };

    public static void main(String[] args) {
        M = sc.nextInt();
        N = sc.nextInt();
        K = sc.nextInt();
        map = new char[M][N];
        time = new int[M][N];
        for (int i = 0; i < M; ++i) {
            map[i] = sc.next().toCharArray();
            for (int j = 0; j < N; ++j) {
                if ('a' <= map[i][j] && map[i][j] <= 'z') {
                    pos.put(map[i][j], new Point(i, j));
                    time[i][j] = 1;
                } else if ('1' <= map[i][j] && map[i][j] <= '9') {
                    time[i][j] = map[i][j] - '0';
                }
            }
        }
        int rs = sc.nextInt() - 1;
        int cs = sc.nextInt() - 1;
        String path = sc.next();
        int rg = sc.nextInt() - 1;
        int cg = sc.nextInt() - 1;
        Path[][] paths = new Path[26][26];
        for (int i = 0; i < path.length() - 1; ++i) {
            int i1 = path.charAt(i) - 'a';
            int i2 = path.charAt(i + 1) - 'a';
            if (paths[i1][i2] == null) {
                paths[i1][i2] = getPath(pos.get(path.charAt(i)), pos.get(path.charAt(i + 1)));
                paths[i2][i1] = new Path();
                for (int j = 0; j < paths[i1][i2].pos.size(); ++j) {
                    paths[i2][i1].pos.add(paths[i1][i2].pos.get(paths[i1][i2].pos.size() - 1 - j));
                }
            }
        }
        Path[] ps = new Path[path.length() + 1];
        ps[0] = getPath(new Point(rs, cs), pos.get(path.charAt(0)));
        ps[ps.length - 1] = getPath(pos.get(path.charAt(path.length() - 1)), new Point(rg, cg));
        for (int i = 1; i < ps.length - 1; ++i) {
            int i1 = path.charAt(i - 1) - 'a';
            int i2 = path.charAt(i) - 'a';
            ps[i] = paths[i1][i2];
        }

        int t = 0;
        for (int i = 0; i < ps.length; ++i) {
            ArrayList<Point> p = ps[i].pos;
            for (int j = 0; j < p.size() - 1; ++j) {
                int x = p.get(j).x;
                int y = p.get(j).y;
                t += time[x][y];
                if (t == K) {
                    System.out.println((p.get(j + 1).x + 1) + " " + (p.get(j + 1).y + 1));
                    return;
                } else if (t > K) {
                    System.out.println((x + 1) + " " + (y + 1));
                    return;
                }
            }
        }
        System.out.println((rg + 1) + " " + (cg + 1));
    }

    static Path getPath(Point s, Point e) {
        boolean[][] used = new boolean[M][N];
        ArrayList<State> cur = new ArrayList<State>();
        cur.add(new State(e.x, e.y, 0, null));
        used[e.x][e.y] = true;
        while (!cur.isEmpty()) {
            ArrayList<State> next = new ArrayList<State>();
            for (State state : cur) {
                if (state.x == s.x && state.y == s.y) {
                    Path res = new Path();
                    while (state != null) {
                        res.pos.add(new Point(state.x, state.y));
                        state = state.prev;
                    }
                    return res;
                }
                for (int i = 0; i < 4; ++i) {
                    int nx = state.x + DR[i];
                    int ny = state.y + DC[i];
                    if (nx < 0 || M <= nx || ny < 0 || N <= ny || map[nx][ny] == '#') continue;
                    if (used[nx][ny]) continue;
                    used[nx][ny] = true;
                    next.add(new State(nx, ny, state.d + time[state.x][state.y], state));
                }
            }
            cur = next;
        }
        return null;
    }

    //  static Path getPath(Point s, Point e) {
    //      boolean[][] used = new boolean[M][N];
    //      PriorityQueue<State> q = new PriorityQueue<State>();
    //      q.add(new State(e.x, e.y, 0, null));
    //      used[e.x][e.y] = true;
    //      while (!q.isEmpty()) {
    //          State cur = q.poll();
    //          if (cur.x == s.x && cur.y == s.y) {
    //              Path res = new Path();
    //              while (cur != null) {
    //                  res.pos.add(new Point(cur.x, cur.y));
    //                  cur = cur.prev;
    //              }
    //              return res;
    //          }
    //          for (int i = 0; i < 4; ++i) {
    //              int nx = cur.x + DR[i];
    //              int ny = cur.y + DC[i];
    //              if (nx < 0 || M <= nx || ny < 0 || N <= ny || map[nx][ny] == '#') continue;
    //              if (used[nx][ny]) continue;
    //              used[nx][ny] = true;
    //              q.add(new State(nx, ny, cur.d + time[cur.x][cur.y], cur));
    //          }
    //      }
    //      return null;
    //  }

    static class State implements Comparable<State> {
        State prev;
        int x, y, d;

        State(int x, int y, int d, State prev) {
            this.x = x;
            this.y = y;
            this.d = d;
            this.prev = prev;
        }

        public int compareTo(State o) {
            return this.d - o.d;
        }
    }

    static class Path {
        ArrayList<Point> pos = new ArrayList<Point>();
    }

}