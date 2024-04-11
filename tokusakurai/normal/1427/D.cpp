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
    rep(i, N) {cin >> a[i]; a[i]--;}

    vector<vector<int>> ans;

    rep(i, N-1){
        vector<int> tmp;
        int k = i/2;

        if(i%2 == 0){
            rep(j, k) tmp.eb(1);
            int l = 0;
            while(a[k+l] != k) l++;
            if(l > 0) tmp.eb(l);
            tmp.eb(N-i-l);
            rep(j, k) tmp.eb(1);
        }
        else{
            rep(j, k+1) tmp.eb(1);
            int l = 0;
            while(a[k+1+l] != N-1-k) l++;
            if(l > 0) tmp.eb(l);
            tmp.eb(N-i-l);
            rep(j, k) tmp.eb(1);
        }

        if(sz(tmp) >= 2) ans.eb(tmp);

        int ptr = 0;
        vector<int> b;
        for(auto &e: tmp){
            rep3(j, ptr+e-1, ptr) b.eb(a[j]);
            ptr += e;
        }
        reverse(all(b));

        swap(a, b);
    }

    if(a[0] != 0){
        vector<int> tmp;
        rep(i, N) tmp.eb(1);
        if(sz(tmp) >= 2) ans.eb(tmp);
    }

    cout << sz(ans) << '\n';
    each(e, ans){
        cout << sz(e);
        each(u, e) cout << ' ' << u;
        cout << '\n';
    }
}