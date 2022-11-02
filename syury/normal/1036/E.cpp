//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

struct pt{
    int x, y;
    pt(){}
    pt(int _x, int _y):x(_x), y(_y){}
    pt operator - (const pt & p)const{
        return pt(x - p.x, y - p.y);
    }
    ll cross(const pt & p)const{
        return x * 1ll * p.y - y * 1ll * p.x;
    }
    ll cross(const pt & p, const pt & q)const{
        return (p - *this).cross(q - *this);
    }
    bool operator < (const pt & p)const{
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
};

inline ll sgn(ll x){
    return x < 0 ? -1 : int(x > 0);
}

struct seg{
    pt a, b;
};

ll ans = 0;
int n;
seg s[1111];
pt in[(int)2e6 + 66];
int what[(int)2e6 + 66];
int sz = 0;

inline bool do_isect(seg s1, seg s2){
    return sgn(s1.a.cross(s1.b, s2.a)) != sgn(s1.a.cross(s1.b, s2.b)) && sgn(s2.a.cross(s2.b, s1.a)) != sgn(s2.a.cross(s2.b, s1.b));
}

pair<bool, pt> intersection(seg s1, seg s2){
    pt v = s1.b - s1.a, u = s2.b - s2.a;
    ll Q = v.cross(u);
    ll P = -(s1.a - s2.a).cross(u);
    if(P * v.x % Q == 0 && P * v.y % Q == 0)
        return {true, pt(s1.a.x + P * v.x / Q, s1.a.y + P * v.y / Q)};
    else
        return {false, pt(0, 0)};
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i].a.x >> s[i].a.y >> s[i].b.x >> s[i].b.y;
    }
    for(int i = 0; i < n; i++){
        ans += 1 + __gcd(abs(s[i].a.x - s[i].b.x), abs(s[i].a.y - s[i].b.y));
    }
    for(int i = 1; i <= n; i++)
        what[i * (i - 1)/2] = i;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(do_isect(s[i], s[j])){
                bool ok;
                pt inter;
                tie(ok, inter) = intersection(s[i], s[j]);
                if(ok)
                    in[sz++] = inter;
            }
        }
    }
    sort(in, in + sz);
    int i = 0;
    while(i < sz){
        int j = i;
        while(j < sz && in[i].x == in[j].x && in[i].y == in[j].y)
            ++j;
        assert(what[j - i] != 0);
        ans -= what[j - i] - 1;
        i = j;
    }
    cout << ans << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}