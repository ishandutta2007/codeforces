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
typedef long double dbl;
typedef pair<int, int> pii;

const dbl eps = 1e-9;
const dbl PI = acos(-1.0);

inline int sgn(dbl x){
    return x < -eps ? -1 : (x > eps ? 1 : 0);
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
    pt operator / (dbl d)const{
        return pt(x / d, y / d);
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
    dbl angle()const{
        return atan2(y, x);
    }
};

struct query{
    int tp;
    int x, y;
};

struct rotation{
    pt cen;
    dbl cs, si;
    pt apply(const pt & p)const{
        dbl x = p.x - cen.x, y = p.y - cen.y;
        return pt(cen.x + x * cs - y * si, cen.y + x * si + y * cs);
    }
};

const int N = (int)2e5 + 5;
const int BLOCK = 400;

int n, q;
int sum = 1;
pt p[N];
pt center;
rotation rot[BLOCK];
pt cenpos[BLOCK];

void process_queries(vector<query> qs){
    int sz = qs.size();
    for(size_t i = 0; i < qs.size(); i++){
        auto pos = p[qs[i].tp == 1 ? sum - qs[i].x : qs[i].x];
        for(size_t j = 0; j < i; j++){
            if(qs[j].tp == 1)
                pos = rot[j].apply(pos);
        }
        if(qs[i].tp == 1){
            dbl angle = -PI/2 - (center - pos).angle();
            rot[i] = rotation{pos, cos(angle), sin(angle)};
            center = rot[i].apply(center);
            sum = sum - qs[i].x + qs[i].y;
        }
        else{
            cout << fixed << pos.x << ' ' << pos.y << '\n';
        }
    }
    dbl A[2][2], c[2];
    A[0][0] = A[1][1] = 1; A[0][1] = A[1][0] = 0;
    c[0] = c[1] = 0;
    for(size_t j = 0; j < qs.size(); j++){
        if(qs[j].tp == 1){
            dbl B[2][2], d[2];
            B[0][0] = A[0][0] * rot[j].cs - A[1][0] * rot[j].si;
            B[0][1] = A[0][1] * rot[j].cs - A[1][1] * rot[j].si;
            B[1][0] = A[0][0] * rot[j].si + A[1][0] * rot[j].cs;
            B[1][1] = A[0][1] * rot[j].si + A[1][1] * rot[j].cs;
            d[0] = rot[j].cen.x + rot[j].cs * (c[0] - rot[j].cen.x) - rot[j].si * (c[1] - rot[j].cen.y);
            d[1] = rot[j].cen.y + rot[j].si * (c[0] - rot[j].cen.x) + rot[j].cs * (c[1] - rot[j].cen.y);
            memcpy(A, B, sizeof(A));
            memcpy(c, d, sizeof(c));
        }
    }
    for(int i = 0; i < n; i++){
        dbl x = A[0][0] * p[i].x + A[0][1] * p[i].y + c[0];
        dbl y = A[1][0] * p[i].x + A[1][1] * p[i].y + c[1];
        p[i] = pt(x, y);
    }
}

void solve(){
    cout.precision(12);
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        p[i] = pt(x, y);
    }
    dbl area = 0;
    for(int i = 0; i < n; i++)
        area += p[i].cross(p[(i+1)%n]);
    area = fabs(area);
    for(int i = 1; i + 1 < n; i++){
        pt curr = (p[i] + p[i + 1] + p[0]) / 3;
        center = center + curr * fabs(p[0].cross(p[i], p[i + 1]));
    }
    center = center / area;
    vector<query> qs;
    for(int i = 0; i < q; i++){
        if((int)qs.size() == BLOCK){
            process_queries(qs);
            qs = {};
        }
        query curr;
        cin >> curr.tp >> curr.x;
        if(curr.tp == 1)
            cin >> curr.y;
        --curr.x; --curr.y;
        qs.push_back(curr);
    }
    process_queries(qs);
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