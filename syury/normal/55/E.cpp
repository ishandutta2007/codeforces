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
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

struct pt{
    ll x, y;
    pt operator + (const pt & p)const{
        return pt{x + p.x, y + p.y};
    }
    pt operator - (const pt & p)const{
        return pt{x - p.x, y - p.y};
    }
    ll cross(const pt & p)const{
        return x * p.y - y * p.x;
    }
    ll cross(const pt & a, const pt & b)const{
        return (a - *this).cross(b - *this);
    }
};

const int N = (int)1e5 + 5;

pt p[N];
int n;

inline int adv(int i, int d){
    i += d;
    return i >= n ? i - n : i;
}

inline ll sum_ints(ll k){
    return k * (k + 1)/2;
}

ll solve(pt q){
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(p[i].cross(p[adv(i, 1)], q) <= 0 || p[i].cross(p[adv(i, n - 1)], q) >= 0)
            return 0;
        int L = 1, R = n - 1;
        while(R - L > 1){
            int mid = (L + R)/2;
            if(p[i].cross(p[adv(i, mid)], q) > 0)
                L = mid;
            else
                R = mid;
        }
        ans += sum_ints(L - 1) + sum_ints(n - 2 - L);
    }
    return n * 1ll * (n - 1) * 1ll * (n - 2) / 6 - ans/2;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld%lld", &p[i].x, &p[i].y);
    }
    reverse(p, p + n);
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        pt query;
        scanf("%lld%lld", &query.x, &query.y);
        printf("%lld\n", solve(query));
    }
    return 0;
}