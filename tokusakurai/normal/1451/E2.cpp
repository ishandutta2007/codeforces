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

int query(string s, int i, int j){
    cout << s << ' ' << i+1 << ' ' << j+1 << endl;
    int x; cin >> x; return x;
}

int main(){
    int N;
    cin >> N;
    vector<int> id[N];
    rep2(i, 1, N-1){
        id[query("XOR", 0, i)].eb(i);
    }

    bool flag = false;
    vector<int> ans(N);
    if(!id[0].empty()){
        flag = true;
        int x = query("AND", 0, id[0][0]);
        ans[0] = x;
        flag = true;
    }
    if(!flag){
        rep(i, N){
            if(sz(id[i]) <= 1) continue;
            flag = true;
            int x = query("AND", id[i][0], id[i][1]);
            ans[0] = x^i;
            break;
        }
    }
    if(!flag){
        int x = query("AND", 0, id[1][0]), y = query("AND", 0, id[2][0]);
        if(y&1) x |= 1;
        ans[0] = x;
    }

    rep(i, N){
        each(e, id[i]) ans[e] = ans[0]^i;
    }

    cout << '!';
    rep(i, N) cout << ' ' << ans[i];
    cout << endl;
}