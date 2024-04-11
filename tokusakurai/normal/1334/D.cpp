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

int N;
vector<int> ans;

vector<int> left(int id, int n){
    vector<int> tmp;
    rep(i, n){
        if(i%2 == 0) tmp.eb(id);
        else tmp.eb(id+1+i/2);
    }
    return tmp;
}

vector<int> right(int id, int n){
    vector<int> tmp;
    rep(i, n){
        if(i%2 == 0) tmp.eb(N-1-i/2);
        else tmp.eb(id);
    }
    reverse(all(tmp));
    return tmp;
}

vector<int> entire(int id){
    return left(id, 2*(N-id-1));
}

int main(){
    int T;
    cin >> T;
    while(T--){
        ans.clear();
        cin >> N;
        vector<ll> id;
        ll now = 0;
        rep(i, N){
            id.eb(now);
            now += 2*(N-i-1);
        }

        ll L, R;
        cin >> L >> R; L--;
        bool flag = false;
        if(R == 1LL*N*(N-1)+1) flag = true, R--; 
        int l = lower_bound(all(id), L)-begin(id), r = lower_bound(all(id), R)-begin(id);

        vector<int> memo;
        if(l > 0){
            memo = right(l-1, id[l]-L);
            each(e, memo) ans.eb(e);
        }
        rep2(i, l, r-2){
            memo = entire(i);
            each(e, memo) ans.eb(e);
        }
        if(r > 0){
            memo = left(r-1, R-id[r-1]);
            each(e, memo) ans.eb(e);
        }

        ans.resize(R-L);
        if(flag) ans.eb(0);
        each(e, ans) cout << e+1 << ' '; cout << '\n';
    }
}