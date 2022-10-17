#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 5e5 + 10;
const int B = sqrt(N);
int p[N], sz[N], f[N], used[N], timer;
int p2[N], sz2[N], f2[N], used2[N], timer2;

void update0(int v) {
  if (used[v] < timer) {
    used[v] = timer;
    p[v] = v;
    sz[v] = 1;
    f[v] = 0;
  }
}

int find(int v) {
  update0(v);
  return p[v] == v ? v : find(p[v]);
}
 
int get_color(int v) {
  update0(v);
  return p[v] == v ? f[v] : (f[v] ^ get_color(p[v]));
}
 
bool merge(int a, int b) {
  update0(a);
  update0(b);
  int ac = find(a), bc = find(b);
  if (ac == bc) {
    if (get_color(a) == get_color(b)) {
      return false;
    }
    return true;
  }
  if (sz[ac] < sz[bc]) {
    swap(ac, bc);
    swap(a, b);
  }
  if (get_color(a) == get_color(b)) {
    f[bc] ^= 1;
  }
  p[bc] = ac;
  sz[ac] += sz[bc]; 
  return true;
}

void update(int v) {
  if (used2[v] < timer2) {
    update0(v);
    used2[v] = timer2;
    p2[v] = p[v];
    sz2[v] = sz[v];
    f2[v] = f[v];
  }
}

int find2(int v) {
  update(v);
  return p2[v] == v ? v : find2(p2[v]);
}
 
int get_color2(int v) {
  update(v);
  return p2[v] == v ? f2[v] : (f2[v] ^ get_color2(p2[v]));
}
 
bool merge2(int a, int b) {
  update(a);
  update(b);
  int ac = find2(a), bc = find2(b);
  if (ac == bc) {
    if (get_color2(a) == get_color2(b)) {
      return false;
    }
    return true;
  }
  if (sz2[ac] < sz2[bc]) {
    swap(ac, bc);
    swap(a, b);
  }
  if (get_color2(a) == get_color2(b)) {
    f2[bc] ^= 1;
  }
  p2[bc] = ac;
  sz2[ac] += sz2[bc]; 
  return true;
}

vector<int> have[N];
int group[N];
map<int, vector<pair<int, int>>> g[N];
bool ok[N];

mt19937 rnd(time(0));

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n = 5e5, m = 5e5, k = rnd() % n + 1;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> group[i];
    //group[i] = rnd() % k + 1;
    have[group[i]].pb(i);
  }  
  for (int i = 0; i < m; i++) {
    //int u = rnd() % n + 1, v = rnd() % n + 1;
    int u, v;
    cin >> u >> v;
    g[group[u]][group[v]].pb({u, v});
    if (group[u] != group[v]) {
      g[group[v]][group[u]].pb({v, u});  
    }
  }
  int good_groups = 0;
  for (int id = 1; id <= k; id++) {
    timer++;
    bool good = true;
    for (auto edge : g[id][id]) {
      if (!merge(edge.F, edge.S)) {
        good = false;
        break;
      }
    }
    if (good) {
      ok[id] = true;
      good_groups++;
    }
  }
  //cout << "OK1" << endl;
  ll ans1 = 0, ans2 = 0;
  for (int id = 1; id <= k; id++) {
    if (!ok[id]) {
      continue;
    }
    /*for (int i = 1; i <= n; i++) {
      p[i] = i;
      sz[i] = 1;
      f[i] = 0;
    }*/
    timer++;
    bool good = true;
    for (auto edge : g[id][id]) {
      if (!merge(edge.F, edge.S)) {
        good = false;
        break;
      }
    }
    int not_connected = good_groups - 1;
    for (auto it : g[id]) {
      int id2 = it.F;
      vector<pair<int, int>> edges = it.S;
      if (id2 == id || !ok[id2]) {
        continue;
      }
      not_connected--;
      bool s1 = (SZ(have[id]) > B), s2 = (SZ(have[id2]) > B);
      if (s1 && s2 && id2 < id) {
        continue;
      }
      if (!s1 && !s2 && id2 < id) {
        continue;
      }
      if (!s1 && s2) {
        continue;
      }
      timer2++;
      bool kek = true;
      for (auto itt : g[id2][id2]) {
        if (!merge2(itt.F, itt.S)) {
          kek = false;
          break;
        }
      }
      if (kek) {
        for (auto itt : edges) {
          if (!merge2(itt.F, itt.S)) {
            kek = false;
            break;
          }
        }
      }
      if (kek) {
        //cout << "OK " << id << ' ' << id2 << '\n';
        ans1++;
      }
    }
    ans2 += not_connected;
  }
  //cout << ans1 << ' ' << ans2 << '\n';
  assert(ans2 % 2 == 0);
  ll ans = ans1 + (ans2 / 2);
  cout << ans << '\n';
  cerr << "TIME:: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}