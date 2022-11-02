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

const dbl eps = 1e-9;

inline int sgn(dbl x){
    return x < -eps ? -1 : (x > eps ? 1 : 0);
}

inline dbl safe_sqrt(dbl x){
    return x < 0 ? 0 : sqrt(x);
}

struct pt{
    dbl x, y;
    pt(){}
    pt(dbl _x, dbl _y):x(_x), y(_y){}
    pt operator + (const pt & p)const{
        return pt(x + p.x, y + p.y);
    }
    pt operator - (const pt & p)const{
        return pt(x - p.x, y - p.y);
    }
    dbl cross(const pt & p)const{
        return x * p.y - y * p.x;
    }
    dbl cross(const pt & p, const pt & q)const{
        return (p - *this).cross(q - *this);
    }
    dbl dot(const pt & p)const{
        return x * p.x + y * p.y;
    }
    dbl dot(const pt & p, const pt & q)const{
        return (p - *this).dot(q - *this);
    }
    dbl distTo(const pt & p)const{
        return safe_sqrt(dot(p, p));
    }
};

typedef vector<pt> poly;

inline pt readpt(){
    int x, y;
    cin >> x >> y;
    return pt(x, y);
}

inline bool hasPtSeg(pt a, pt b, pt c){
    return fabs(a.cross(b, c)) < eps && c.dot(a, b) < eps;
}

inline bool do_isect(pt a, pt b, pt c, pt d){
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) && sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

inline pt isect(pt a, pt b, pt c, pt d){
    pt v = b - a, u = d - c;
    dbl s = -(a - c).cross(u)/v.cross(u);
    pt ans = pt(a.x + s * v.x, a.y + s * v.y);
    assert(hasPtSeg(a, b, ans) && hasPtSeg(c, d, ans));
    return ans;
}

int n;
poly p;
pt S, T;

dbl perimeter(vector<pt> pts){
    dbl ans = 0;
    for(size_t i = 0; i < pts.size(); i++){
        auto j = i + 1 == pts.size() ? 0 : (i + 1);
        ans += pts[i].distTo(pts[j]);
    }
    return ans;
}

tuple<dbl, dbl, dbl> isect_poly(){
    vector<pt> p1, p2;
    for(int i = 0; i < n; i++){
        int j = i == n - 1 ? 0 : (i + 1);
        if(hasPtSeg(S, T, p[i]) && hasPtSeg(S, T, p[j])){
            return {0, 0, 0};
        }
        if(hasPtSeg(S, T, p[i])){
            p1.push_back(p[j]);
            continue;
        }
        if(hasPtSeg(S, T, p[j])){
            int k = j == n - 1 ? 0 : (j + 1);
            if(sgn(S.cross(T, p[i])) == sgn(S.cross(T, p[k])))
                return {0, 0, 0};
        }
        if(do_isect(S, T, p[i], p[j])){
            pt inter = isect(S, T, p[i], p[j]);
            p1.push_back(inter);
            p1.swap(p2);
            p1.push_back(inter);
            if(!hasPtSeg(S, T, p[j]))
                p1.push_back(p[j]);
        }
        else{
            p1.push_back(p[j]);
        }
    }
    dbl P1 = perimeter(p1), P2 = perimeter(p2), P = perimeter(p);
    return {0.5 * (P1 + P2 - P), P1, P2};
}

void solve(){
    S = readpt();
    T = readpt();
    cin >> n;
    p.resize(n);
    for(int i = 0; i < n; i++)
        p[i] = readpt();
    dbl str = S.distTo(T);
    dbl in, L, R;
    tie(in, L, R) = isect_poly();
    dbl ans = min(str + in, str - in + min(L, R) - in);
    cout.precision(9);
    cout << fixed << ans << endl;
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