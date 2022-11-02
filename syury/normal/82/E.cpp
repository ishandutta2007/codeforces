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

const int N = 555;

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
    pt operator * (dbl d)const{
        return pt(x * d, y * d);
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
};

struct trapezoid{
    pt up[2], down[2];
    trapezoid(pt a, pt b, pt c, pt d){
        up[0] = a;
        up[1] = b;
        down[0] = c;
        down[1] = d;
        if(up[0].x > up[1].x)
            swap(up[0], up[1]);
        if(down[0].x > down[1].x)
            swap(down[0], down[1]);
    }
};

int n, h, f;
int l[N], r[N];

pt interLineLine(pt a, pt b, pt c, pt d){
    pt v = b - a, u = d - c;
    dbl s = u.cross(a - c)/v.cross(u);
    return a + v * s;
}

vector<pt> interSegSeg(pt a, pt b, pt c, pt d){
    if(fabs((a - b).cross(c - d)) < eps)
        return {};
    pt cand = interLineLine(a, b, c, d);
    if(cand.dot(a, b) < eps && cand.dot(c, d) < eps)
        return {cand};
    else
        return {};
}

pair<pt, pt> get_pts(bool up, int y, int L, int R){
    int y0 = up ? f : -f;
    pt focus(0, y0);
    pt h0(0, y), h1(1, y);
    return {interLineLine(focus, pt(L, up ? h : -h), h0, h1), interLineLine(focus, pt(R, up ? h : -h), h0, h1)};
}

pair<dbl, dbl> interOnLine(dbl l1, dbl r1, dbl l2, dbl r2){
    return {max(l1, l2), min(r1, r2)};
}

dbl interTrapezoids(trapezoid t1, trapezoid t2, bool same){
    auto iup = interOnLine(t1.up[0].x, t1.up[1].x, t2.up[0].x, t2.up[1].x);
    auto idown = interOnLine(t1.down[0].x, t1.down[1].x, t2.down[0].x, t2.down[1].x);
    vector<pt> inter;
    if(iup.X < iup.Y - eps){
        inter.emplace_back(iup.X, h);
        inter.emplace_back(iup.Y, h);
    }
    else if(fabs(iup.X - iup.Y) < eps)
        inter.emplace_back((iup.X + iup.Y)/2, h);
    if(idown.X < idown.Y - eps){
        inter.emplace_back(idown.X, 0);
        inter.emplace_back(idown.Y, 0);
    }
    else if(fabs(idown.X - idown.Y) < eps)
        inter.emplace_back((idown.X + idown.Y)/2, 0);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            auto cand = interSegSeg(t1.up[i], t1.down[i], t2.up[j], t2.down[j]);
            for(auto p: cand)
                inter.push_back(p);
        }
    }
    if(inter.empty())
        return 0;
    sort(all(inter), [](pt a, pt b){
            return fabs(a.x - b.x) < eps ? a.y < b.y : a.x < b.x;
            });
    inter.erase(unique(all(inter), [](pt a, pt b){return fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps;}), inter.end());
    int pos = 0;
    for(int i = 1; i < (int)inter.size(); i++){
        if(inter[i].x < inter[pos].x - eps || (fabs(inter[i].x - inter[pos].x) < eps && inter[i].y < inter[pos].y))
            pos = i;
    }
    swap(inter[pos], inter[0]);
    pt base = inter[0];
    sort(inter.begin() + 1, inter.end(), [&base](pt a, pt b){return fabs(base.cross(a, b)) < eps ? base.dot(a, a) < base.dot(b, b) : base.cross(a, b) > 0;});
    int ptr = (int)inter.size() - 2;
    while(ptr > 0 && fabs(base.cross(inter[ptr], inter.back())) < eps)
        --ptr;
    reverse(inter.begin() + ptr + 1, inter.end());
    dbl ans = 0;
    for(int i = 1; i + 1 < (int)inter.size(); i++){
        ans += fabs(base.cross(inter[i], inter[i + 1]));
    }
    return ans;

}

void solve(){
    cin >> n >> h >> f;
    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
    }
    dbl inter = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            auto pts1 = get_pts(true, 0, l[i], r[i]);
            auto pts2 = get_pts(false, 0, l[j], r[j]);
            auto pts3 = get_pts(false, h, l[j], r[j]);
            inter += interTrapezoids(trapezoid(pt(l[i], h), pt(r[i], h), pts1.X, pts1.Y), trapezoid(pts3.X, pts3.Y, pts2.X, pts2.Y), i == j);
        }
    }
    dbl tot = 0;
    for(int i = 0; i < n; i++){
        pt focus(0, f);
        pt L, R;
        tie(L, R) = get_pts(true, -h, l[i], r[i]);
        tot += fabs(focus.cross(L, R)) - fabs(focus.cross(pt(l[i], h), pt(r[i], h)));
    }
    tot = tot - inter;
    cout.precision(10);
    cout << fixed << tot << endl;
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