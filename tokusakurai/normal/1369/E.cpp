#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N, M;
    cin >> N >> M;
    int A[N];
    rep(i, N) cin >> A[i];
    vector<int> v[N];
    pii p[M];
    int cnt[N];
    fill(cnt, cnt+N, 0);
    rep(i, M){
        int x, y; cin >> x >> y; x--, y--;
        p[i] = pii(x, y);
        v[x].pb(i), v[y].pb(i);
        cnt[x]++, cnt[y]++;
    }
    bool used1[N], used2[M];
    fill(used1, used1+N, false);
    fill(used2, used2+M, false);
    queue<int> que;
    vector<int> ans;
    rep(i, N){
        if(cnt[i] <= A[i]) que.push(i), used1[i] = true;
    }
    while(!que.empty()){
        int i = que.front();
        que.pop();
        for(auto &e: v[i]){
            if(used2[e]) continue;
            ans.pb(e);
            used2[e] = true;
            int x = p[e].first, y = p[e].second;
            cnt[x]--, cnt[y]--;
            if(!used1[x] && cnt[x] <= A[x]) que.push(x), used1[x] = true;
            if(!used1[y] && cnt[y] <= A[y]) que.push(y), used1[y] = true;
        }
    }
    rep(i, N){
        if(cnt[i] > 0) {cout << "DEAD" << endl; return 0;}
    }
    cout << "ALIVE" << endl;
    rep3(i, sz(ans)-1, 0) cout << ans[i]+1 << ' ';
    cout << endl;
}