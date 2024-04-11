#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, p, check1, l[1010][1010], r[1010][1010], c, d, vc, uffa;
string s;
bool visited[2000010];
char res[1010][1010];
vector<long long> adj[2000010];
queue<long long> q;

long long vl(long long a, long long b) {
  return 1010 * a + b;
}

pair<long long, long long> dc(long long a) {
  return {a / 1010, a % 1010};
}

void dfs(long long s, long long p, long long c) {
  if (visited[s]) {
    return;
  }
  visited[s] = true;
  vc++;
  if (s - p == 1) {
    res[dc(s).first][dc(s).second] = 'L';
  }
  if (s - p == -1) {
    res[dc(s).first][dc(s).second] = 'R';
  }
  if (s - p == 1010) {
    res[dc(s).first][dc(s).second] = 'U';
  }
  if (s - p == -1010) {
    res[dc(s).first][dc(s).second] = 'D';
  }
  if (c == 1 && l[dc(s).first][dc(s).second] == -1) {
    if (s - p == 1) {
      res[dc(p).first][dc(p).second] = 'R';
    }
    if (s - p == -1) {
      res[dc(p).first][dc(p).second] = 'L';
    }
    if (s - p == 1010) {
      res[dc(p).first][dc(p).second] = 'D';
    }
    if (s - p == -1010) {
      res[dc(p).first][dc(p).second] = 'U';
    }
  }
  if (adj[s].empty() && l[dc(s).first][dc(s).second] == -1 && c == 0) {
    uffa = 1;
  }
  for (auto u : adj[s]) {
    dfs(u, s, c + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  vc = 0;
  uffa = 0;

  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      res[i + 1][j + 1] = 'n';
      cin >> l[i + 1][j + 1] >> r[i + 1][j + 1];
      if ((l[i + 1][j + 1] == i + 1 && r[i + 1][j + 1] == j + 1) || l[i + 1][j + 1] == -1) {
        q.push(vl(i + 1, j + 1));
        res[i + 1][j + 1] = 'X';
      }
    }
  }

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i > 1) {
        if (l[i][j] == l[i - 1][j] && r[i][j] == r[i - 1][j]) {
          c = vl(i, j);
          d = vl(i - 1, j);
          adj[c].push_back(d);
          adj[d].push_back(c);
        }
      }
      if (i < n) {
        if (l[i][j] == l[i + 1][j] && r[i][j] == r[i + 1][j]) {
          c = vl(i, j);
          d = vl(i + 1, j);
          adj[c].push_back(d);
          adj[d].push_back(c);
        }
      }
      if (j > 1) {
        if (l[i][j] == l[i][j - 1] && r[i][j] == r[i][j - 1]) {
          c = vl(i, j);
          d = vl(i, j - 1);
          adj[c].push_back(d);
          adj[d].push_back(c);
        }
      }
      if (j < n) {
        if (l[i][j] == l[i][j + 1] && r[i][j] == r[i][j + 1]) {
          c = vl(i, j);
          d = vl(i, j + 1);
          adj[c].push_back(d);
          adj[d].push_back(c);
        }
      }
    }
  }

  while (!q.empty()) {
    //cout << q.front() << endl;
    dfs(q.front(), -10000, 0);
    q.pop();
  }

  if (vc != n * n || uffa == 1) {
    cout << "INVALID";
  } else {
    cout << "VALID" << endl;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        cout << res[i + 1][j + 1];
      }
      cout << endl;
    }
  }

  return 0;
}