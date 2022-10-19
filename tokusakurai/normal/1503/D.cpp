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
vector<int> p;
vector<bool> u, used;

int solve(int K){
    if(K == 0) return 0;

    //cout << K << endl;

    int l = N-K, r = N+K-1, rem = K, ret = 0;

    vector<int> ls, rs;

    while(!(rem < K && l == N-rem && r == N+rem-1)){
        if(l < N-rem){
            used[l] = true, used[p[l]] = true;
            if(!u[l]) ret++;
            ls.eb(p[l]);
        }
        else{
            used[r] = true, used[p[r]] = true;
            if(!u[r]) ret++;
            rs.eb(p[r]);
        }

        rem--;
        while(l < 2*N && used[l]) l++;
        while(r >= 0 && used[r]) r--;

        if(rem == 0) break;
    }

    int ml = N+rem-1;
    reverse(all(ls));
    each(e, ls){
        if(e <= ml) return inf;
        else ml = e;
    }

    int mr = N-rem;
    reverse(all(rs));
    each(e, rs){
        if(e >= mr) return inf;
        else mr = e;
    }

    return min(ret, K-rem-ret)+solve(rem);
}

int main(){
    cin >> N;

    p.resize(2*N), u.assign(2*N, false);
    rep(i, N){
        int a, b; cin >> a >> b; a--, b--;
        p[a] = b, p[b] = a;
        u[a] = true;
    }

    used.assign(2*N, false);

    int ans = solve(N);
    cout << (ans >= inf? -1 : ans) << '\n';
}