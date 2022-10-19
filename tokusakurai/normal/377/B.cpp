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
    int N, M; ll S; cin >> N >> M >> S;

    vector<pii> a(M), b(N);
    rep(i, M){
        int x; cin >> x;
        a[i] = pii(x, i);
    }
    rep(i, N){
        int x; cin >> x;
        b[i] = pii(x, i);
    }
    sort(rall(a)), sort(rall(b));

    vector<ll> c(N);
    rep(i, N) cin >> c[i];

    int l = 0, r = M+1; //(l,r]
    while(r-l > 1){
        int m = (l+r)/2;

        priority_queue<pli, vector<pli>, greater<pli>> que;
        int ptr = 0;
        ll K = 0;

        for(int i = 0; i < M; i += m){
            while(ptr < N && b[ptr].first >= a[i].first){
                int j = b[ptr++].second;
                que.emplace(c[j], j);
            }
            if(empty(que)){
                K = INF;
                break;
            }
            K += que.top().first; que.pop();
        }

        (K <= S? r : l) = m;
    }

    if(r == M+1) {cout << "NO\n"; return 0;}

    cout << "YES\n";

    priority_queue<pli, vector<pli>, greater<pli>> que;
    int ptr = 0;
    vector<int> ans(M);

    for(int i = 0; i < M; i += r){
        while(ptr < N && b[ptr].first >= a[i].first){
            int j = b[ptr++].second;
            que.emplace(c[j], j);
        }
        for(int j = 0; j < r; j++){
            if(i+j >= M) break;
            ans[a[i+j].second] = que.top().second;
        }
        que.pop();
    }

    rep(i, M) cout << ans[i]+1 << (i == M-1? '\n' : ' ');
}