#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int _n=(n), i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

void init_io() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
}

void add_mul(vector<int> &a, int mul, const vector<int> &b) {
  int n = a.size();
  REP(i,n) a[i] = (a[i] + mul * b[i]) % 3;
}

bool solve(vector<vector<int>> &equations, vector<int> &solution) {
  int sx = solution.size();
  int sy = equations.size();

  int nexty=0;
  REP(x, sx) {
    {
      int y = nexty;
      while (y < sy && equations[y][x] == 0) ++y;
      if (y==sy) continue;
      swap(equations[y], equations[nexty]);
    }
    if (equations[nexty][x] == 2) {
      add_mul(equations[nexty], 1, equations[nexty]);
    }
    FOR(y,nexty+1,sy-1) {
      if (equations[y][x]==1) {
        add_mul(equations[y], 2, equations[nexty]);
      } else if (equations[y][x]==2) {
        add_mul(equations[y], 1, equations[nexty]);
      }
    }
    ++nexty;
  }

  solution.assign(sx, 0);
  FORD(y, sy-1, 0) {
    int x=0;
    while(x<sx && equations[y][x]==0) ++x;
    if (x==sx) {
      if(equations[y][sx]!=0) return false;
    } else {
      assert(equations[y][x]==1);
      int val = equations[y][sx];
      FOR(x1, x+1, sx-1) {
        val -= solution[x1] * equations[y][x1];
      }
      val = (val%3+3)%3;
      solution[x] = val;
    }
  }
  return true;
}

void solve_one() {
  int num_vertices, num_edges;
  cin >> num_vertices >> num_edges;

  vector<int> color(num_edges, -1);
  vector<int> variable_number(num_edges, -1);
  int num_variables = 0;
  vector<vector<int>> edge_number(num_vertices, vector<int>(num_vertices, -1));

  REP(i, num_edges) {
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    edge_number[a][b] = i;
    edge_number[b][a] = i;
    if (c!=-1) {
      color[i] = c-1;
    } else {
      variable_number[i] = num_variables++;
    }
  }

  vector<vector<int>> equations;
  REP(a, num_vertices) REP(b,a) REP(c,b) {
    int d = edge_number[a][b];
    int e = edge_number[a][c];
    int f = edge_number[b][c];
    if (d==-1 || e==-1 || f==-1) continue;
    vector<int> equation(num_variables+1, 0);
    for (int edge : {d, e, f}) {
      if (color[edge]!=-1) {
        equation[num_variables] = (equation[num_variables]-color[edge] + 3) % 3;
      } else {
        equation[variable_number[edge]] = 1;
      }
    }
    equations.push_back(equation);
  }

  vector<int> solution(num_variables, -1);
  if (solve(equations, solution)) {
    REP(edge, num_edges) {
      int c = color[edge] != -1 ? color[edge] : solution[variable_number[edge]];
      c += 1;
      cout << c << ' ';
    }
    cout << "\n";
  } else {
    cout << "-1\n";
  }
}

int main() {
  init_io();

  int ntc; cin >> ntc;
  REP(tc, ntc) {
    solve_one();
  }
}