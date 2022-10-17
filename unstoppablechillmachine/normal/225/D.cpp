//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define F first
#define S second
#define pb push_back
//#define int ll
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

struct T {
  int i, j, side, mask;
  T() {};
  T(int ii, int jj, int s, int m) : i(ii), j(jj), side(s), mask(m) {};
};

vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};

T get(int len, vector<pair<int, int>> kek) {
  T res;
  res.i = kek[1].F;
  res.j = kek[1].S;
  for (int i = 0; i < 4; i++) {
    if (kek[2].F + delta[i].F == kek[1].F && kek[2].S + delta[i].S == kek[1].S) {
      res.side = i;
      break;
    }
  }
  res.mask = 0;
  int lst = res.side;
  //cout << res.side << endl;
  vector<int> musorka;
  for (int i = 3; i <= len; i++) {
    int curside;
    for (int j = 0; j < 4; j++) {
      if (kek[i].F + delta[j].F == kek[i - 1].F && kek[i].S + delta[j].S == kek[i - 1].S) {
        curside = j;
        break;
      }
    }
    int kk;
    if ((lst + 3) % 4 == curside) {
      kk = 2;
    }
    else {
      kk = (curside - lst + 4) % 4;
    }
    //cout << curside << ' ' << lst << ' ' << kk << endl;
    //res.mask = res.mask * 3 + kk;
    musorka.pb(kk);
    lst = curside;
  }
  reverse(all(musorka));
  for (auto it : musorka) {
    res.mask = res.mask * 3 + it;
  }
  return res;
}

int dist[15][15][4][2200];

void source() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> arr(n, vector<char>(m));
  int len = 0;
  vector<pair<int, int>> kek(10);
  pair<int, int> need;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == '@') {
        need = {i, j};
      }
      if (arr[i][j] >= '1' && arr[i][j] <= '9') {
        len = max(len, arr[i][j] - '0');
        kek[arr[i][j] - '0'] = {i, j};
      }
    }
  }
  int MX_VAL = 1;
  vector<int> pw(len + 1);
  pw[0] = MX_VAL;
  for (int i = 1; i <= len - 2; i++) {
    MX_VAL *= 3;
    pw[i] = MX_VAL;
  }
  T start = get(len, kek);
  queue<T> q;
  //vector<vector<vector<vector<int>>>> dist(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(MX_VAL, INF))));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        for (int mask = 0; mask < MX_VAL; mask++) {
          dist[i][j][k][mask] = INF;
        }
      }
    }
  }
  dist[start.i][start.j][start.side][start.mask] = 0;
  q.push(start);
  int timer = 0, ans = INF;
  vector<vector<int>> used(n, vector<int>(m));
  while (!q.empty()) {
    T cur = q.front();
    q.pop();
    timer++;
    if (make_pair(cur.i, cur.j) == need) {
      cout << dist[cur.i][cur.j][cur.side][cur.mask];
      exit(0);
    }
    used[cur.i][cur.j] = timer;
    used[cur.i - delta[cur.side].F][cur.j - delta[cur.side].S] = timer;
    pair<int, int> ff = {cur.i - delta[cur.side].F, cur.j - delta[cur.side].S};
    int curside = cur.side, msk = cur.mask;
    vector<int> change;
    change.pb(curside);
    for (int i = 0; i < len - 2; i++) {
      int add = msk % 3;
      msk /= 3;
      if (add == 2) {
        curside = (curside + 3) % 4;
      }
      else {
        curside = (curside + add) % 4;
      }
      change.pb(curside);
      ff.F -= delta[curside].F;
      ff.S -= delta[curside].S;
      used[ff.F][ff.S] = timer;
    }
    change.pop_back();
    int vl = 0;
    for (auto it : delta) {
      int toi = cur.i + it.F, toj = cur.j + it.S;
      if (toi >= 0 && toi < n && toj >= 0 && toj < m && arr[toi][toj] != '#') {
        if (used[toi][toj] < timer || ff == make_pair(toi, toj)) {
          int tomask = 0, cside = vl;
          for (int i = 0; i < len - 2; i++) {
            int kk;
            if ((cside + 3) % 4 == change[i]) {
              kk = 2;
            }
            else {
              kk = (change[i] - cside + 4) % 4;
            }
            tomask += kk * pw[i];
            cside = change[i];
          }
          if (dist[toi][toj][vl][tomask] == INF) {
            q.push(T(toi, toj, vl, tomask));
            dist[toi][toj][vl][tomask] = dist[cur.i][cur.j][cur.side][cur.mask] + 1;
          }
        }
      }
      vl++;
    }
  }
  cout << (ans == INF ? -1 : ans);
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output2.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopenpen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
#ifdef extraterrestrial_
  cerr << "\n\nTIME :: " << clock() * 1.0 / CLOCKS_PER_SEC;
#endif
  return 0;
}