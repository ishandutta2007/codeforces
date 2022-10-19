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

    vector<int> nxt(N, -1), cnt(N, 0);
    vector<pii> p;
    for(int i = 0; i < N;){
        int j = 0;
        while(i+j < N && a[i] == a[i+j]) j++;
        cnt[i] = j;
        if(j == 1) {i += j; continue;}
    
        p.eb(i, a[i]), i += j;
    }

    int n = sz(p);
    rep(i, n-1){
        nxt[p[i].first] = p[i+1].second;
    }

    int ans = 0, K = 0, tmp = -1;
    if(n > 0) tmp = p[0].second;

    for(int i = 0; i < N;){
        if(cnt[i] == 1){
            ans++;
            if(tmp == a[i]) K++;
            else K--, chmax(K, 0);
        }
        else{
            ans += 2-K;
            tmp = nxt[i], K = 0;
            if(a[i] == tmp) K = 2;
        }
        i += cnt[i];
    }

    cout << ans << '\n';
}