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
    dbl x, y;
    pt(){}
    pt(dbl _x, dbl _y):x(_x), y(_y){}
    pt operator + (const pt & p)const{
        return pt(x + p.x, y + p.y);
    }
    pt operator - (const pt & p)const{
        return pt(x - p.x, y - p.y);
    }
    dbl dot(const pt & p)const{
        return x * p.x + y * p.y;
    }
    dbl dot(const pt & p, const pt & q)const{
        return (p - *this).cross(q - *this);
    }
    dbl cross(const pt & p)const{
        return x * p.y - y * p.x;
    }
    dbl cross(const pt & p, const pt & q)const{
        return (p - *this).cross(q - *this);
    }
};

const int N = 333;
const dbl eps = 1e-9;

dbl ans[N];
int y[N][N];
int n, k;

inline int sgn(dbl x){
    return x < -eps ? -1 : (x > eps ? 1 : 0);
}

dbl get_area(vector<pt> poly){
    dbl area = 0;
    for(size_t i = 0; i + 1 < poly.size(); i++){
        area += 0.5 * (poly[i].y + poly[i + 1].y) * (poly[i + 1].x - poly[i].x);
    }
    return area;
}

inline bool do_isect(pt A, pt B, pt C, pt D){
    if(sgn(A.cross(B, C)) == 0 && sgn(A.cross(B, D)) == 0)
        return false;
    int c1 = sgn(A.cross(B, C)), c2 = sgn(A.cross(B, D));
    if(c1 == 0 || c2 == 0 || c1 != c2){
        c1 = sgn(C.cross(D, A)), c2 = sgn(C.cross(D, B));
        if(c1 == 0 || c2 == 0 || c1 != c2)
            return 1;
        else
            return 0;
    }
    else return 0;
}

inline pt intersection(pt A, pt B, pt C, pt D){
    pt v = B - A, u = D - C;
    dbl s = -(A - C).cross(u)/v.cross(u);
    return pt(A.x + v.x * s, A.y + v.y * s);
}

void solve_strip(vector<int> L, vector<int> R){
    vector<pt> poly = {pt(0, 0), pt(1, 0)};
    for(int i = 0; i < n; i++){
        dbl area = get_area(poly);
        vector<pt> new_poly = {};
        int yl = L[i], yr = R[i];
        pt l(0, yl), r(1, yr);
        for(size_t j = 0; j + 1 < poly.size(); j++){
            if(do_isect(l, r, poly[j], poly[j + 1])){
                pt mid = intersection(l, r, poly[j], poly[j + 1]);
                if(l.cross(r, poly[j]) > eps)
                    new_poly.push_back(poly[j]);
                new_poly.push_back(mid);
            }
            else{
                if(l.cross(r, poly[j]) < eps)
                    continue;
                else
                    new_poly.push_back(poly[j]);
            }
        }
        if(l.cross(r, poly.back()) > eps)
            new_poly.push_back(poly.back());
        if(new_poly.empty() || new_poly[0].x > eps)
            new_poly.insert(new_poly.begin(), l);
        if(new_poly.back().x < 1 - eps)
            new_poly.push_back(r);
        ans[i] += get_area(new_poly) - area;
        poly = new_poly;
    }
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= k; j++)
            cin >> y[i][j];
    for(int j = 0; j < k; j++){
        vector<int> L(n), R(n);
        for(int i = 0; i < n; i++){
            L[i] = y[i][j];
            R[i] = y[i][j + 1];
        }
        solve_strip(L, R);
    }
    cout.precision(9);
    for(int i = 0; i < n; i++)
        cout << fixed << ans[i] << '\n';
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