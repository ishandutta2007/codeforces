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

const dbl PI = acos(-1.0);
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
    pt rotate(dbl cs, dbl si)const{
        return pt(x * cs - y * si, x * si + y * cs);
    }
    pt rotate(dbl ang)const{
        return rotate(cos(ang), sin(ang));
    }
    pt getOrth()const{
        return pt(-y, x);
    }
    dbl length()const{
        return safe_sqrt(dot(*this));
    }
};

dbl angle(pt l, pt mid, pt r){
    return atan2(mid.cross(l, r), mid.dot(l, r));
}

pt interLineLine(pt a, pt v, pt c, pt u, bool& ok){
    if(fabs(v.cross(u)) < eps){
        ok = false;
        return pt(0, 0);
    }
    dbl s = u.cross(a - c)/v.cross(u);
    return a + v * s;
}

bool collinear(pt A, pt B, pt C){
    return fabs(A.cross(B, C)) < eps;
}

bool doInterSegs(pt a, pt b, pt c, pt d){
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) && sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

bool convex(pt A, pt B, pt C, pt D){
    if(collinear(A, B, C) || collinear(B, C, D) || collinear(C, D, A) || collinear(D, A, B))
        return false;
    pt p[4] = {A, B, C, D};
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            if(fabs(p[i].x - p[j].x) < eps && fabs(p[i].y - p[j].y) < eps)
                return false;
        }
    }
    if(doInterSegs(A, B, C, D) || doInterSegs(B, C, D, A))
        return false;
    int turnsign = sgn((B - A).cross(C - B));
    if(turnsign != sgn((C - B).cross(D - C)) || turnsign != sgn((D - C).cross(A - D)) || turnsign != sgn((A - D).cross(B - A)))
        return false;
    return true;
}

bool solve1(pt M1, pt M2, pt M3){
    if(fabs(M2.cross(M3, M1)) < eps)
        return false;
    pt mid1 = (M1 + M2) * 0.5;
    pt mid2 = (M2 + M3) * 0.5;
    pt orth1 = (M2 - M1).getOrth();
    pt orth2 = (M3 - M2).getOrth();
    dbl cosr, sinr;
    dbl lambda = (M1 - M2).length()/(M3 - M2).length();
    dbl t = (PI - fabs(angle(M1, M2, M3)));
    dbl A = lambda - cos(t);
    dbl B = -sin(t);
    if(fabs(A) < eps){
        sinr = 0;
        cosr = 1;
    } else if(fabs(B) < eps) {
        cosr = 0;
        sinr = 1;
    } else {
        dbl sq = 1/(1 + B*B/(A*A));
        sinr = safe_sqrt(sq);
        cosr = -B * sinr / A;
    }
    if(M2.cross(M3, M1) > eps){
        sinr = -sinr;
    }
    pt dir = (M3 - M2).rotate(cosr, sinr);
    bool ok = 1;
    pt pC = interLineLine(M2, dir, mid2, orth2, ok);
    if(!ok)return false;
    pt pB = interLineLine(M2, pt(0, 0) - dir, mid1, orth1, ok);
    if(!ok)return false;
    //cerr << (pB - M2).length() << ' ' << (pC - M2).length() << endl;
    pt pA = M1 * 2 - pB;
    pt pD = M3 * 2 - pC;
    //cerr << "trying " << fixed << ' ' << pA.x << ' ' << pA.y << ' ' << pB.x << ' ' << pB.y << ' ' << pC.x << ' ' << pC.y << ' ' << pD.x << ' ' << pD.y << '\n';
    if(!convex(pA, pB, pC, pD))
        return false;
    else{
        cout << "YES\n";
        cout << fixed << pA.x << ' ' << pA.y << ' ' << pB.x << ' ' << pB.y << ' ' << pC.x << ' ' << pC.y << ' ' << pD.x << ' ' << pD.y << '\n';
        return true;
    }
}

void solve(){
    pt M[3];
    for(int i = 0; i < 3; i++){
        int x, y;
        cin >> x >> y;
        M[i] = pt(x, y);
    }
    vector<int> p(3);
    iota(all(p), 0);
    do{
        if(solve1(M[p[0]], M[p[1]], M[p[2]]))
            return;
    }while(next_permutation(all(p)));
    cout << "NO\n";
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(9);
    int T=1;
    cin >> T;
    while(T--)
        solve();
    return 0;
}