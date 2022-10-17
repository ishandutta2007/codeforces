#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int INF = 1e9 + 10; 
const int N = 2e5 + 10;
const int MX = 120;
int a[N], to[MX][MX], used[MX], ptr;
int p[MX], sz[MX];

bitset<120> have[MX], nl;

inline void init() {
  for (int i = 0; i < ptr; i++) {
    p[i] = i;
    sz[i] = 1;
    have[i] &= nl;
    have[i][i] = 1;
  }
}

int find(int v) {
  return p[v] == v ? v : p[v] = find(p[v]);
}

inline void merge(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) {
    return;
  }
  p[b] = a;
  sz[a] += sz[b];
  have[a] |= have[b];
  return;
}

inline void add(int X) {
  for (int i = 0; i < ptr; i++) {
    merge(i, to[i][X]);
  }
}

map<vector<int>, int> id;
vector<int> perm[MX];

int upd[MX], lol[MX];
map<vector<int>, int> was;
bitset<120> bt[MX];
mt19937 rnd(time(0));
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n = 2e5, k = 5;
  cin >> n >> k;
  vector<int> kek;
  for (int i = 1; i <= k; i++) {
    kek.pb(i);
  }
  do {
    id[kek] = ptr;
    perm[ptr] = kek;
    ptr++;
  } while (next_permutation(all(kek)));
  for (int i = 1; i <= n; i++) {
    vector<int> cur(k);
    for (auto &it : cur) {
      cin >> it;
    }
    /*for (int j = 1; j <= k; j++) {
      cur.pb(j);
    }*/
    //shuffle(all(cur), rnd);
    a[i] = id[cur];
    //cout << a[i] << '\n';
  }
  for (int i = 0; i < ptr; i++) {
    for (int j = 0; j < ptr; j++) {
      vector<int> f1 = perm[i], f2 = perm[j], f3(k);
      for (int t = 0; t < k; t++) {
        f3[t] = f1[f2[t] - 1];
      }
      to[i][j] = id[f3];
    }
  }
  for (int i = 0; i < ptr; i++) {
    vector<int> fuck = {0};
    int cur = to[0][i], iter = 0;
    while (cur) {
      bt[i][cur] = 1;
      fuck.pb(cur);
      cur = to[cur][i];
    }
    bt[i][0] = 1;
    sort(all(fuck));
    if (was.find(fuck) == was.end()) {
      was[fuck] = i;
    }    
    lol[i] = was[fuck];
  }
  vector<int> lst(ptr);
  set<pair<int, int>> st;
  for (int i = 0; i < ptr; i++) {
    st.insert({0, i});
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    st.erase({-lst[a[i]], a[i]});
    lst[a[i]] = i;
    st.insert({-lst[a[i]], a[i]});
    pair<int, int> prv = {INF, INF};
    init();
    int flex = 0;
    for (auto it : st) {
      if (it.F == 0) {
        break;
      }
      if (prv.F != INF) {
        ans += (prv.F + it.F) * 1ll * prv.S;
      }
      if (find(it.S) != find(0)) {
        add(it.S);
      }
      prv = {-it.F, sz[find(0)]};
      if (sz[find(0)] == ptr) {
        break;
      } 
      flex++;
    }
    ans += prv.F * 1ll * prv.S;
  }
  cout << ans << '\n';
}