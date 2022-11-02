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
    pt getOrth()const{
        return pt(-y, x);
    }
    pt normalize()const{
        return *this * (1.0/sqrt(dot(*this)));
    }
    dbl length()const{
        return safe_sqrt(dot(*this));
    }
    dbl angle()const{
        return atan2(y, x);
    }
};

pt projPtLine(pt c, pt a, pt v){
    return a + v * (v.dot(c - a)/v.dot(v));
}

pt interLineLine(pt a, pt v, pt c, pt u){
    dbl s = u.cross(a - c)/v.cross(u);
    return a + v * s;
}

vector<pt> interLineCircle(pt a, pt v, pt c, dbl r){
    pt p = projPtLine(c, a, v);
    dbl d = (p - c).length();
    if(d > r + eps)
        return {};
    if(d > r - eps)
        return {p};
    dbl len = safe_sqrt(r*r - p.dot(c, c));
    v = v.normalize() * len;
    return {p - v, p + v};
}

pt getByAngle(pt c, dbl r, dbl ang){
    pt v(r * cos(ang), r * sin(ang));
    return v + c;
}

vector<pt> interCircleCircle(pt c1, dbl r1, pt c2, dbl r2){
    if(r1 + eps < r2){
        swap(c1, c2);
        swap(r1, r2);
    }
    pt v = c2 - c1;
    dbl d = v.length();
	dbl ang = v.angle();
	dbl longest = max(max(r1, r2), d);
	dbl per = r1 + r2 + d;
	if(2 * longest > per + eps)return {};
	if(abs(2 * longest - per) < 2 * eps)return {getByAngle(c1, r1, ang)};
	dbl cang = safe_acos((r1*r1 + d*d - r2*r2)/(2*r1*d));
	return {getByAngle(c1, r1, ang + cang), getByAngle(c1, r1, ang - cang)};
}

pt p[3];
dbl R[3];
bool isCircle[3];
pt v[3], mid[3];
dbl ap[3];

void solve(){
    for(int i = 0; i < 3; i++){
        cin >> p[i].x >> p[i].y >> R[i];
    }
    for(int i = 0; i < 3; i++){
        int l = (i + 1)%3;
        int r = 3 - i - l;
        if(fabs(R[l] - R[r]) < eps){
            mid[i] = (p[l] + p[r]) * 0.5;
            v[i] = (p[l] - p[r]).getOrth();
        } else {
            if(R[l] < R[r])swap(l, r);
            pt A = p[l] + (p[r] - p[l]) * (R[l]/(R[l] + R[r]));
            dbl len = sqrt(p[l].dot(p[r], p[r]))/(R[l]/R[r] - 1);
            pt B = p[r] + (p[r] - p[l]).normalize() * len;
            mid[i] = (A + B) * 0.5;
            ap[i] = sqrt(A.dot(B, B)) * 0.5;
            //cerr << i << ' '<<mid[i].x << ' ' << mid[i].y << ' ' << ap[i] << endl;
            isCircle[i] = true;
        }
    }
    vector<pt> cand;
    if(!isCircle[0] && !isCircle[1])
        cand = {interLineLine(mid[0], v[0], mid[1], v[1])};
    if(isCircle[0] && !isCircle[1])
        cand = interLineCircle(mid[1], v[1], mid[0], ap[0]);
    if(!isCircle[0] && isCircle[1])
        cand = interLineCircle(mid[0], v[0], mid[1], ap[1]);
    if(isCircle[0] && isCircle[1]){
        cand = interCircleCircle(mid[0], ap[0], mid[1], ap[1]);
    }
    /*for(auto c: cand)
        cerr << fixed << c.x << ' ' << c.y << endl;*/
    vector<pt> cand2;
    for(pt c: cand){
        dbl chk;
        if(isCircle[2])
            chk = sqrt(c.dot(mid[2], mid[2])) - ap[2];
        else
            chk = v[2].cross(c - mid[2]);
        if(fabs(chk) < eps)
            cand2.push_back(c);
    }
    cand = cand2;
    if(cand.empty())return;
    pt ans = cand[0];
    for(auto c: cand){
        dbl si1 = R[0]/sqrt(p[0].dot(c, c));
        dbl si2 = R[0]/sqrt(p[0].dot(ans, ans));
        if(si1 > si2)
            ans = c;
    }
    cout.precision(5);
    cout << fixed << ans.x << ' ' << ans.y << endl;
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
    //cin >> T;
    while(T--)
        solve();
    return 0;
}