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

int solve(vector<int> v){ //
    int n = sz(v);
    if(n <= 2) return n;
    vector<vector<int>> ids;
    for(int i = 0; i < n;){
        vector<int> tmp;
        int j = 0;
        if(v[i] == 0) tmp.eb(0), j = 1;
        else{
            while(i+j < n && __builtin_clz(v[i+j]) == __builtin_clz(v[i])){
                tmp.eb(v[i+j]), j++;
            }
        }
        ids.eb(tmp);
        i += j;
    }
    int ret = 0, m = sz(ids);
    rep(i, m){
        if(ids[i][0] != 0){
            int k = 31-__builtin_clz(ids[i][0]);
            each(e, ids[i]) e &= ~(1<<k);
        }
    }
    rep(i, m){
        if(i > 0) chmax(ret, solve(ids[i])+m-i);
        else chmax(ret, solve(ids[i])+m-1);
    }
    return ret;
}

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(all(a));

    cout << N-solve(a) << '\n';
}