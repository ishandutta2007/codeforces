//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

inline ll intpow(ll x, int p, ll bnd){
    ll res = 1;
    while(p){
        if(p&1){
            if(res > bnd/x)
                return -1;
            res *= x;
        }
        if(p > 1){
            if(x > bnd/x)
                return -1;
            x *= x;
        }
        p >>= 1;
    }
    return res;
}

inline ll binsearch_root(int pw, ll bnd){
    ll L = 1, R = (ll)1e9 + 2;
    while(R - L > 1){
        ll mid = (L + R)/2;
        if(intpow(mid, pw, bnd) == -1)
            R = mid;
        else
            L = mid;
    }
    return L;
}

int mu[100];
ll maxpow[64];

ll solve(ll n){
    ull ans = 0;
    for(int pw = 2; pw <= 59; pw++){
        ll maxnum;
        if(pw > 2){
            while(intpow(maxpow[pw], pw, n) == -1)
                --maxpow[pw];
            maxnum = maxpow[pw];
        }
        else{
            maxnum = binsearch_root(2, n);
        }
        ans += mu[pw] * (maxnum - 1);
    }
    return (ll)(n - 1 - ans);
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 2; i <= 59; i++){
        int j = i;
        mu[i] = -1;
        for(int d = 2; d <= j; d++){
            if(j%d == 0){
                mu[i] *= -1;
                j /= d;
                if(j%d == 0){
                    mu[i] = 0;
                    break;
                }
            }
        }
    }
    for(int pw = 3; pw <= 59; pw++)
        maxpow[pw] = binsearch_root(pw, (ll)1e18);
    int T;
    scanf("%d", &T);
    //T = 1e5;
    vector<pair<ll, int> > avtor_zadachi_pidoras;
    for(int i = 0; i < T; i++){
        ll n;
        //n = (ll)1e18;
        scanf("%lld", &n);
        avtor_zadachi_pidoras.push_back(make_pair(n, i));
    }
    sort(all(avtor_zadachi_pidoras));
    reverse(all(avtor_zadachi_pidoras));
    vector<ll> ans(T);
    for(auto query: avtor_zadachi_pidoras){
        ans[query.Y] = solve(query.X);
    }
    for(int i = 0; i < T; i++)
        printf("%lld\n", ans[i]);
    return 0;
}