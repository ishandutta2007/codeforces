#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll    

const int N = 2e5 + 10;
vector<pair<int, int>> g[N];
bool used[N];
pair<int, int> kek[N];
int cx;
vector<int> pl, mn, sub;
void check(int v) {
  sub.pb(v);
  used[v] = true;
  if (kek[v].F == 1) {
    pl.pb(kek[v].S);
  }
  else {
    mn.pb(kek[v].S);
  }
  for (auto u : g[v]) {
    if (!used[u.F]) {
      kek[u.F] = {-kek[v].F, u.S - kek[v].S};
      check(u.F);
    }
    else {
      pair<int, int> other_val = {-kek[v].F, u.S - kek[v].S};
      if (other_val == kek[u.F]) {
        continue;
      }
      if (other_val.F == kek[u.F].F) {
        cerr << v << ' ' << u.F << ' ' << kek[u.F].S << ' ' << other_val.S << '\n';
        cout << "NO\n";
        exit(0);
      }
      int ncx = -(other_val.S - kek[u.F].S) / (other_val.F - kek[u.F].F);
      if (cx != 1e18 && ncx != cx) {
        //cerr << cx << ' ' << ncx << '\n';
        cout << "NO\n";
        exit(0);
      } 
      cx = ncx;
    }
  }
}

int vl[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    c *= 2;
    g[u].pb({v, c});
    g[v].pb({u, c});
  }
  for (int v = 1; v <= n; v++) {
    if (!used[v]) {
      pl = {};
      mn = {};
      sub = {};
      cx = 1e18;
      kek[v] = {1, 0};
      check(v);
      if (cx != 1e18) {
        for (auto it : sub) {
          vl[it] = kek[it].F * cx + kek[it].S;
        }
        continue;
      }
      sort(all(pl));
      sort(all(mn));
      pair<int, int> best = {1e18, 1e18};
      vector<int> pref_pl(SZ(pl)), suf_pl(SZ(pl));
      if (!pl.empty()) {
        pref_pl[0] = pl[0];
        for (int i = 1; i < SZ(pl); i++) {
          pref_pl[i] = pref_pl[i - 1] + pl[i];
        }
        suf_pl.back() = pl.back();
        for (int i = SZ(pl) - 2; i >= 0; i--) {
          suf_pl[i] = suf_pl[i + 1] + pl[i];
        }
      }
      vector<int> pref_mn(SZ(mn)), suf_mn(SZ(mn));
      if (!mn.empty()) {
        pref_mn[0] = mn[0];
        for (int i = 1; i < SZ(mn); i++) {
          pref_mn[i] = pref_mn[i - 1] + mn[i];
        }
        suf_mn.back() = mn.back();
        for (int i = SZ(mn) - 2; i >= 0; i--) {
          suf_mn[i] = suf_mn[i + 1] + mn[i];
        } 
      }
      for (int i = 0; i < SZ(pl); i++) {
        int cs = 0;
        if (i) {
          cs += pl[i] * i - pref_pl[i - 1];
        }
        if (i + 1 < SZ(pl)) {
          cs += suf_pl[i + 1] - pl[i] * (SZ(pl) - i - 1);
        }
        if (!mn.empty()) {
          int ps = upper_bound(all(mn), -pl[i]) - mn.begin();
          if (ps) {
            cs += ps * (-pl[i]) - pref_mn[ps - 1];     
          }
          if (ps < SZ(mn)) {
            cs += (SZ(mn) - ps) * pl[i] + suf_mn[ps];
          }
        }
        best = min(best, make_pair(cs, -pl[i]));
      }
      /*for (auto it : pl) {
        int xx = -it;
        int cs = 0;
        for (auto it2 : sub) {
          cs += abs(xx * kek[it2].F + kek[it2].S);
        }
        best = min(best, make_pair(cs, -it));
      }*/
      for (int i = 0; i < SZ(mn); i++) {
        int cs = 0;
        if (i) {
          cs += mn[i] * i - pref_mn[i - 1];
        }
        if (i + 1 < SZ(mn)) {
          cs += suf_mn[i + 1] - mn[i] * (SZ(mn) - i - 1);
        }
        if (!pl.empty()) {
          int ps = upper_bound(all(pl), -mn[i]) - pl.begin();
          if (ps) {
            cs += ps * (-mn[i]) - pref_pl[ps - 1];
          }
          if (ps < SZ(pl)) {
            cs += (SZ(pl) - ps) * mn[i] + suf_pl[ps];
          }
        }
        best = min(best, make_pair(cs, mn[i]));
      }
      /*for (auto it : mn) {
        int xx = it;
        int cs = 0;
        for (auto it2 : sub) {
          cs += abs(xx * kek[it2].F + kek[it2].S);
        }
        best = min(best, make_pair(cs, it));
      }*/
      //cout << best.F << '\n';
      /*for (int i = 0; i < SZ(mn); i++) {
        int cs = 0;
        if (i) {

        }
        if (i < SZ(mn)) {

        }
        if (!pl.empty()) {

        }
      }*/
      for (auto it : sub) {
        vl[it] = kek[it].F * best.S + kek[it].S;
      }
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << fixed << setprecision(6) << (ld)vl[i] / 2.0 << ' ';
  }
  cout << '\n';
}