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

const int N = (int)2e5 + 55;
const dbl eps = 1e-9;

struct pt{
    ll x, y;
    pt(){}
    pt(ll _x, ll _y):x(_x), y(_y){}
    pt operator + (const pt & p)const{
        return pt(x + p.x, y + p.y);
    }
    pt operator - (const pt & p)const{
        return pt(x - p.x, y - p.y);
    }
    ll cross(const pt & p)const{
        return x * p.y - y * p.x;
    }
    ll cross(const pt & p, const pt & q)const{
        return (p - *this).cross(q - *this);
    }
    ll dot(const pt & p)const{
        return x * p.x + y * p.y;
    }
};

struct item{
    pt pos;
    int id;
};

struct Line{
    pt p[2];
    Line(pt a, pt b){
        p[0] = a; p[1] = b;
    }
    pt& operator [] (size_t i){
        return p[i];
    }
};

int n, H;
pt tower;
pt p[N];
item it[N];
item hull[N];

pair<dbl, dbl> interLineLine(Line l1, Line l2){
    pt v = l1[1] - l1[0], u = l2[1] - l2[0];
    dbl s = u.cross(l1[0] - l2[0])/(dbl)v.cross(u);
    return {l1[0].x + v.x * s, l1[0].y + v.y * s};
}

void solve(){
    cin >> n >> H;
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
        it[i].pos = p[i];
        it[i].id = i;
    }
    tower = pt(p[n - 1].x, p[n - 1].y + H);
    sort(it, it + n, [&tower](const item & l, const item & r){
            ll c = tower.cross(l.pos, r.pos);
            if(c != 0)return c < 0;
            else return l.id > r.id;
            });
    int sz = 0;
    for(int i = 0; i < n; i++){
        while(sz > 0 && hull[sz - 1].id < it[i].id)
            --sz;
        hull[sz++] = it[i];
    }
    dbl ans = 0;
    for(int i = 0; i + 1 < sz; i++){
        Line l1(tower, hull[i].pos);
        Line l2(hull[i + 1].pos, p[hull[i + 1].id + 1]);
        if((l1[1] - l1[0]).cross(l2[1] - l2[0]) == 0){
            pt lol = l2[1] - l2[0];
            dbl x = lol.x, y = lol.y;
            ans += sqrt(x*x + y*y);
            continue;
        }
        auto isect = interLineLine(l1, l2);
        isect.X -= hull[i + 1].pos.x;
        isect.Y -= hull[i + 1].pos.y;
        ans += sqrt(max((dbl)0, isect.X * isect.X + isect.Y * isect.Y));
    }
    cout.precision(10);
    cout << fixed << ans << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}