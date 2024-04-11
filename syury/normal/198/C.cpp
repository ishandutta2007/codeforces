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
const dbl PI = acos(-1.0);
const int ITERS = 200;

inline dbl safe_sqrt(dbl x){
    return x < 0 ? 0 : sqrt(x);
}

inline dbl safe_acos(dbl x){
    return acos(clamp(x, (dbl)-1, (dbl)1));
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
    pt rotate(dbl phi)const{
        dbl c = cos(phi), s = sin(phi);
        return pt(c * x - s * y, s * x + c * y);
    }
    dbl angle()const{
        return atan2(y, x);
    }
};

int v, vp;
int r;
dbl pr;
dbl coeff;
pt P;
pt planet;
vector<pt> p1;

vector<pt> tangents(pt p){
    dbl ang = safe_acos(r/p.distTo(pt(0, 0)));
    dbl cang = p.angle();
    return {
        pt(r * cos(cang - ang), r * sin(cang - ang)),
        pt(r * cos(cang + ang), r * sin(cang + ang))
    };
}

dbl circleDist(pt p, pt q){
    dbl angle1 = p.angle(), angle2 = q.angle();
    dbl total = min(fabs(angle1 - angle2), 2*PI - fabs(angle1 - angle2));
    return total * r;
}

dbl distSegPt(pt A, pt B, pt C){
    if(A.dot(B, C) < -eps || B.dot(A, C) < -eps)
        return min(A.distTo(C), B.distTo(C));
    else
        return fabs(A.cross(B, C))/A.distTo(B);
}

bool can(dbl phi){
    dbl T = phi*coeff;
    pt pos = planet.rotate(phi);
    dbl D = distSegPt(P, pos, pt(0, 0));
    if(D > r - eps){
        return P.distTo(pos)/v <= T;
    }
    vector<pt> p2 = tangents(pos);
    for(auto fst: p1){
        for(auto snd: p2){
            dbl curr = P.distTo(fst) + pos.distTo(snd) + circleDist(fst, snd);
            if(curr/v <= T)
                return true;
        }
    }
    return false;
}

void solve(){
    cin >> planet.x >> planet.y >> vp;
    cin >> P.x >> P.y >> v >> r;
    pr = sqrt(planet.dot(planet));
    coeff = pr/vp;
    p1 = tangents(P);
    dbl L = 0, R = PI * (1<<16);
    for(int i = 0; i < ITERS; i++){
        dbl mid = (L + R) * 0.5;
        if(can(mid))
            R = mid;
        else
            L = mid;
    }
    cout.precision(9);
    cout << fixed << (L + R) * 0.5 * coeff << endl;
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