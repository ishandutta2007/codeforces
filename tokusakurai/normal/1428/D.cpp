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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vec(int, a, N, 0);
    in(a);
    int x = N-1;
    while(x >= 0 && a[x] == 0) x--;
    if(x < 0) {cout << 0 << endl; return 0;} 
    if(a[x] == 3) {cout << -1 << endl; return 0;}
    stack<int> que;
    vector<pii> p;
    rep3(i, N-1, 0){
        if(a[i] == 2){
            if(que.empty()) {cout << -1 << endl; return 0;}
            else p.eb(i, que.top()), que.pop();
        }
        if(a[i] == 1) que.push(i);
    }
    vi b;
    rep(i, N){
        if(a[i] == 3) b.pb(i);
    }
    vector<pii> ans;
    int ptr = 0;
    x = -1;
    for(auto &e: p){
        ans.eb(e.first, ptr), ans.eb(e.second, ptr);
        ptr++;
    }
    x = -1;
    while(!que.empty()){
        ans.eb(que.top(), ptr);
        chmax(x, que.top());
        que.pop();
        ptr++;
    }
    ptr = N-1;
    if(!b.empty()){
        if(sz(p) && p[0].first > b.back()) x = p[0].first;
        elif(x > b.back());
        else {cout << -1 << endl; return 0;}

        rep(i, sz(b)-1){
            ans.eb(b[i], ptr), ans.eb(b[i+1], ptr);
            ptr--;
        }
        ans.eb(b.back(), ptr);
        ans.eb(x, ptr);
    }

    cout << sz(ans) << endl;
    for(auto &e: ans){
        cout << N-e.second << ' ' << e.first+1 << '\n';
    }
}