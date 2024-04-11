#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

int main(){
    int N; cin >> N;

    vector<int> a(N);
    rep(i, N) cin >> a[i];

    int MAX = 5000000;
    vector<pii> cnt(MAX+1, pii(-1, -1));

    vector<vector<int>> ids(MAX+1);
    vector<int> p;
    rep(i, N){
        ids[a[i]].eb(i);
        if(sz(ids[a[i]]) >= 2) continue;
        p.eb(i);
    }

    vector<int> x;
    rep(i, MAX+1){
        if(sz(ids[i]) >= 2) x.eb(i);
        if(sz(ids[i]) >= 4){
            cout << "YES\n";
            rep(j, 4){
                cout << ids[i][j]+1 << (j == 3? '\n' : ' ');
            }
            return 0;
        }
    }
    
    if(sz(x) >= 2){
        cout << "YES\n";
        cout << ids[x[0]][0]+1 << ' ' << ids[x[1]][0]+1 << ' ' << ids[x[0]][1]+1 << ' ' << ids[x[1]][1]+1 << '\n';
        return 0;
    }

    int n = sz(p);

    rep(i, n){
        rep(j, i){
            int tmp = a[p[i]]+a[p[j]];
            if(tmp%2 == 0 && sz(ids[tmp/2]) >= 2){
                cout << "YES\n";
                cout << p[i]+1 << ' ' << p[j]+1 << ' ' << ids[tmp/2][0]+1 << ' ' << ids[tmp/2][1]+1 << '\n';
                return 0;
            }
            if(cnt[tmp].first != -1){
                auto [k, l] = cnt[tmp];
                cout << "YES\n";
                cout << p[i]+1 << ' ' << p[j]+1 << ' ' << p[k]+1 << ' ' << p[l]+1 << '\n';
                return 0;
            }
            cnt[tmp] = pii(i, j);
        }
    }

    cout << "NO\n";
}