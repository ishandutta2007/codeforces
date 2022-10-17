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
     
    mt19937 rnd(239);
     
    int dist1[1010], dist2[1010];
    int A, B;
    pair<int, int> ask(vector<int> &a) {
      cout << "? " << SZ(a);
      for (auto it : a) {
        cout << ' ' << it;
      }
      cout << endl;
      /*pair<int, int> best = {1e9, 0};
      for (auto it : a) {
        best = min(best, make_pair(dist1[it] + dist2[it], it));
      }
      swap(best.F, best.S);*/ 
      pair<int, int> rez;
      cin >> rez.F >> rez.S;
      return rez;
    }
     
    const int N = 1010;
    vector<int> g[N];
    int h[N], pr[N], mx;
    bool sub[N][N];
     
    void dfs(int v, int p = 0, int curh = 0) {
      h[v] = curh;
      mx = max(mx, h[v]);
      pr[v] = p;
      sub[v][v] = true;
      for (auto u : g[v]) {
        if (u != p) {
          dfs(u, v, curh + 1);
          for (int i = 1; i <= 1000; i++) {
            if (sub[u][i]) {
              sub[v][i] = true;
            }
          }
        }
      }
    }
     
    bool cmp(int a, int b) {
      return h[a] > h[b];
    }
     
    signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      int T;
      cin >> T;
      while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
          g[i] = {};
          dist1[i] = dist2[i] = 1e9;
          for (int j = 1; j <= n; j++) {
            sub[i][j] = false;
          }
        }
        mx = 0;
        //cout << n << endl;
        for (int i = 2; i <= n; i++) {
          int u = i, v = rnd() % (i - 1) + 1;
          cin >> u >> v;
          g[u].pb(v);
          g[v].pb(u);
        }
        vector<int> cur;
        for (int i = 1; i <= n; i++) {
          cur.pb(i);
        }
        pair<int, int> kek = ask(cur);
        dfs(kek.F);
        int V1;
        if (mx >= n / 2) {
          int id = -1;
          for (auto it : g[kek.F]) {
            for (int i = 1; i <= n; i++) {
              if (sub[it][i] && h[i] >= n / 2) {
                id = it;
                break;
              }
            }
          }
          assert(id != -1);
          vector<int> have;
          for (int i = 1; i <= n; i++) {
            if (!sub[id][i]) {
              have.pb(i);
            }
          }
          sort(all(have), cmp);
          int r = SZ(have) - 1, l = -1;
          while (r - l > 1) {
            int mid = (l + r) / 2;
            vector<int> cur;
            for (int i = 0; i <= mid; i++) {
              cur.pb(have[i]);
            }
            if (ask(cur).S == kek.S) {
              r = mid;
            }
            else {
              l = mid;
            }
          }
          V1 = have[r];
        }
        else {
          int l = 0, r = mx + 1;
          pair<int, int> lst;
          while (r - l > 1) {
            int mid = (l + r) / 2;
            vector<int> cur;
            for (int i = 1; i <= n; i++) {
              if (h[i] >= mid) {
                cur.pb(i);
              }
            }
            pair<int, int> flex = ask(cur);
            if (flex.S == kek.S) {
              lst = flex;
              l = mid;
            }
            else {
              r = mid;
            }
          }
          assert(lst.S == kek.S);
          V1 = lst.F;
        }
        int ban = -1;
        if (kek.S - h[V1] <= h[V1]) {
          ban = V1;
          while (h[ban] != kek.S - h[V1]) {
            ban = pr[ban];
          }
        }
        vector<int> mda;
        for (int i = 1; i <= n; i++) {
          if (h[i] == kek.S - h[V1] && i != ban) {
            mda.pb(i);
          }
        }
        int V2;
        if (kek.S == h[V1]) {
          V2 = kek.F;
        }
        else {
          V2 = ask(mda).F;
        }
        cout << "! " << V1 << ' ' << V2 << endl;
        string suka;
        cin >> suka;
      }
    }