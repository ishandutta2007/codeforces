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
     
    int n, m, ans;
    vector<vector<pair<int, int>>> a;
    vector<vector<int>> f;
    vector<int> good, cur_max;
    void rec(int id, int used) {
        if (id == min(n, m)) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += cur_max[i];
            }
            ans = max(ans, sum);
            return;
        }
        for (int i = 0; i < SZ(good); i++) {
            if (!((used >> i) & 1)) {
                vector<int> cur_max2 = cur_max;
                for (int shift = 0; shift < n; shift++) {
                    cur_max = cur_max2;
                    for (int j = 0; j < n; j++) {
                        cur_max[j] = max(cur_max[j], f[(j + shift) % n][good[i]]);
                    }
                    rec(id + 1, used | (1 << i));
                }
                cur_max = cur_max2;
            }
        }
    }
     
    signed main() {
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      cout.tie(0);
        int T;
        cin >> T;
        while (T--) {
            cin >> n >> m;
            a.resize(n);
            f.resize(n);
            for (int i =0 ; i < n; i++) {
                a[i].resize(m);
                f[i].resize(m);
            }
            good = {};
            cur_max.resize(n);
            for (int i = 0; i < n; i++) {
                cur_max[i] = 0;
            }
            ans = 0;
            vector<pair<int, int>> mx(m);
            for (int i = 0; i < m; i++) {
                mx[i] = {0, i};
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> a[i][j].F;
                    f[i][j] = a[i][j].F;
                    a[i][j].S = j;
                    mx[j].F = max(mx[j].F, f[i][j]);
                }
            }
            sort(mx.rbegin(), mx.rend());
            for (int i = 0; i < min(n, m); i++) {
                good.pb(mx[i].S);
            }
            rec(0, 0);
            cout << ans << '\n';
        }
    }