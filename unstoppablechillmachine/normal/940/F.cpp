#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

const int N = 1e6 + 10;
int cc[N], have[N];

inline void add(int x) {
  if (cc[x] >= 0) have[cc[x]]--;
  cc[x]++;
  if (cc[x] >= 0) have[cc[x]]++;
}

inline void del(int x) {
  if (cc[x] >= 0) have[cc[x]]--;
  cc[x]--;
  if (cc[x] >= 0) have[cc[x]]++;
}

const int P = (int)pow(1e5, 2.0 / 3.0);

struct query {
  int t, l, r, ind;
  query() {};
  query(int _t, int _l, int _r, int _ind) : t(_t), l(_l), r(_r), ind(_ind) {};
};

bool cmp(query a, query b) {
  if (a.t / P != b.t / P) {
    return a.t / P < b.t / P;
  } 
  if (a.l / P != b.l / P) {
    return a.l / P < b.l / P;
  }
  return a.r < b.r;
}

void source() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), srt;
  for (auto &it : a) {
    cin >> it;
    srt.pb(it);
  }
  int timer = 0, cnt = 0;
  vector<pii> change;
  vector<query> q;
  for (int i = 0; i < m; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      q.emplace_back(timer, l, r, cnt);
      cnt++;
    }
    else {
      timer++;
      int pos, x;
      cin >> pos >> x;
      pos--;
      srt.pb(x);
      change.pb({pos, x});
    }
  }
  sort(all(srt));
  srt.resize(unique(all(srt)) - srt.begin());
  unordered_map<int, int> to;
  for (int i = 0; i < SZ(srt); i++) {
    to[srt[i]] = i + 1;
  }
  for (auto &it : a) {
    it = to[it];
  }
  for (auto &it : change) {
    it.S = to[it.S];
  }
  sort(all(q), cmp);
  vector<int> ans(cnt), arr = a;
  int curl = q[0].l, curr = q[0].l - 1, curt = 0;
  vector<pair<int, int>> roll_back;
  for (int i = 0; i < cnt; i++) {
    while (curt < q[i].t) {
      int ps = change[curt].F, vl = change[curt].S;
      if (ps >= curl && ps <= curr) {
        del(arr[ps]);
        add(vl);
      }
      roll_back.pb({ps, arr[ps]});
      arr[ps] = vl;
      curt++;
    }
    while (curt > q[i].t) {
      int ps = roll_back.back().F, vl = roll_back.back().S;
      curt--;
      roll_back.pop_back();
      if (ps >= curl && ps <= curr) {
        del(arr[ps]);
        add(vl);
      }
      arr[ps] = vl;
    }
    while (curr > q[i].r) {
      del(arr[curr--]);
    }
    while (curl < q[i].l) {
      del(arr[curl++]);
    }
    while (curr < q[i].r) {
      add(arr[++curr]);
    }
    while (curl > q[i].l) {
      add(arr[--curl]);
    }
    
    ans[q[i].ind] = 1;
    while (have[ans[q[i].ind]]) {
      ans[q[i].ind]++;
    }
  }
  for (int i = 0; i < cnt; i++) {
    cout << ans[i] << '\n';
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}