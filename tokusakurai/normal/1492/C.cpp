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
    int N, M; cin >> N >> M;

    string S, T; cin >> S >> T;

    vector<vector<int>> ids(26);
    rep(i, N){
        int x = S[i]-'a';
        ids[x].eb(i);
    }

    vector<int> l(M+1);
    l[0] = 0;

    rep(i, M){
        int x = T[i]-'a';
        l[i+1] = *lower_bound(all(ids[x]), l[i])+1;
    }

    vector<int> r(M+1);
    r[M] = N;
    rep3(i, M-1, 0){
        int x = T[i]-'a';
        r[i] = *(--lower_bound(all(ids[x]), r[i+1]));
    }

    //rep(i, M+1) cout << l[i] << ' '; cout << '\n';
    //rep(i, M+1) cout << r[i] << ' '; cout << '\n';

    int ans = 0;

    rep2(i, 1, M-1){
        chmax(ans, r[i]-l[i]+1);
    }

    cout << ans << '\n';
}