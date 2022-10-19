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
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

using vi = vector<int>;
using vll = vector<ll>;

#define vec(type, name, a, x) vector<type> name(a, x)
#define VEC(type, a, x) vector<type>(a, x)
#define vec2(type, name, a, b, x) vector<vector<type>> name(a, VEC(type, b, x))
#define VEC2(type, a, b, x) vector<vector<type>>(a, VEC(type, b, x))
#define vec3(type, name, a, b, c, x) vector<vector<vector<type>>> name(a, VEC2(type, b, c, x))
#define VEC3(type, a, b, c, x) vector<vector<vector<type>>>(a, VEC2(type, b, c, x))
#define vec4(type, name, a, b, c, d, x) vector<vector<vector<vector<type>>>> name(a, VEC3(type, b, c, d, x))
#define VEC4(type, a, b, c, d, x) vector<vector<vector<vector<type>>>>(a, VEC3(type, b, c, d, x))
#define vec5(type, name, a, b, c, d, e, x) vector<vector<vector<vector<vector<type>>>>> name(a, VEC4(type, b, c, d, e, x))
#define VEC5(type, a, b, c, d, e, x) vector<vector<vector<vector<vector<type>>>>>(a, VEC4(type, b, c, d, e, x))

template<typename T> void in(vector<T> &a) {rep(i, sz(a)) cin >> a[i];}

template<typename T> void out(const vector<T> &a) {for(auto &e: a) cout << e << ' '; cout << endl;}

template<typename T> void out2(const vector<T> &a) {for(auto &e: a) cout << e << '\n';}

template<typename T> void unique(vector<T> &a) {sort(all(a)), a.erase(unique(all(a)), a.end());}

vector<int> iota(int n){
    vector<int> ret(n);
    iota(all(ret), 0);
    return ret;
}

template<typename T> vector<int> iota(const vector<T> &a, bool greater = false){
    vector<int> ret = iota(sz(a));
    sort(all(ret), [&](int i, int j){
        return (a[i] < a[j])^greater;
    });
    return ret;
}

ll decompose(ll N, ll K){
    ll x = N/K, y = N%K;
    return x*x*(K-y)+(x+1)*(x+1)*y;
}

int main(){
    int N, K;
    cin >> N >> K;
    vec(ll, a, N, 0);
    in(a);
    priority_queue<pli, vector<pli>, greater<pli> > que;
    K -= N;
    ll ans = 0;
    rep(i, N){
        ans += a[i]*a[i];
        if(a[i] > 1) que.emplace(decompose(a[i], 2)-decompose(a[i], 1), i);
    }
    vec(int, cnt, N, 2);
    while(K--){
        ll p; int i;
        tie(p, i) = que.top(); que.pop();
        ans += p;
        if(cnt[i] == a[i]) continue;
        que.emplace(decompose(a[i], cnt[i]+1)-decompose(a[i], cnt[i]), i);
        cnt[i]++;
    }
    cout << ans << endl;
}