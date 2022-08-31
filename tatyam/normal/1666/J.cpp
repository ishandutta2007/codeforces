#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4;
bool chmin(ll& a, ll b){ if(a <= b) return 0; a = b; return 1; }

void solve(){
    ll N;
    cin >> N;
    vector A(N, vector<ll>(N));
    for(auto& a : A) for(ll& i : a) cin >> i;
    A.emplace(A.begin(), N);
    for(auto& a : A) a.insert(a.begin(), 0);
    for(ll i = 0; i <= N; i++) for(ll j = 0; j < N; j++) A[i][j + 1] += A[i][j];
    for(ll i = 0; i < N; i++) for(ll j = 0; j <= N; j++) A[i + 1][j] += A[i][j];
    auto get = [&](ll x1, ll x2, ll y1, ll y2){
        return A[x2][y2] - A[x2][y1] - A[x1][y2] + A[x1][y1];
    };
    auto getlr = [&](ll l, ll r){
        return get(l, r, 0, l) + get(l, r, r, N);
    };
    vector dp(N + 1, vector<ll>(N + 1, INF));
    vector root(N + 1, vector<ll>(N + 1, -1));
    for(ll i = 0; i <= N; i++) dp[i][i] = 0;
    for(ll r = 1; r <= N; r++) for(ll l = r; l--; ){
        for(ll mid = l; mid < r; mid++){
            if(chmin(dp[l][r], dp[l][mid] + dp[mid + 1][r] + getlr(l, mid) + getlr(mid + 1, r))) root[l][r] = mid;
        }
    }
    vector<ll> ans(N);
    auto solve = [&](ll l, ll r, ll par, auto solve){
        if(l == r) return;
        const ll mid = root[l][r];
        ans[mid] = par + 1;
        solve(l, mid, mid, solve);
        solve(mid + 1, r, mid, solve);
    };
    solve(0, N, -1, solve);
//    cerr << dp[0][N] << endl;
    for(ll i = 0; i < N; i++) cout << ans[i] << " \n"[i + 1 == N];
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}