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
    dbl length()const{
        return sqrt(this->dot(*this));
    }
    dbl angle()const{
        return atan2(y, x);
    }
};

inline pt getByAngle(dbl r, dbl ang){
    return pt(r * cos(ang), r * sin(ang));
}

struct Circle{
    pt c;
    dbl r;
};

const int N = (int)5e4 + 4;

int n, d;
Circle c[N];

inline dbl safe_acos(dbl x){
    return acos(clamp(x, (dbl)-1, (dbl)1));
}

vector<pt> interCircleCircle(Circle c1, Circle c2){
    //c1.c = 0
    dbl d = c2.c.length();
    dbl longest = max({c1.r, c2.r, d});
    dbl per = c1.r + c2.r + d;
    dbl ang = c2.c.angle();
    if(2 * longest > per + eps)
        return {};
    if(fabs(2 * longest - per) < 2 * eps)
        return {getByAngle(c1.r, ang)};
    dbl cang = safe_acos((c1.r*c1.r + d*d - c2.r*c2.r)/(2*c1.r*d));
    return {getByAngle(c1.r, ang - cang), getByAngle(c1.r, ang + cang)};
}

void solve(){
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        int x, y, r;
        cin >> x >> y >> r;
        c[i] = Circle{pt(x, y), r};
    }
    int bal = 0;
    vector<pair<dbl, int> > evt;
    for(int i = 0; i < n; i++){
        dbl mind = c[i].c.length() - c[i].r;
        dbl maxd = c[i].r + c[i].c.length();
        int l = 0, r = N/d;
        while(r - l > 1){
            int mid = (l + r)/2;
            int dist = d * mid;
            if(dist > mind - eps)
                r = mid;
            else
                l = mid;
        }
        for(int x = r * d; x < maxd + eps; x += d){
            Circle curr{pt(0, 0), x};
            auto isect = interCircleCircle(curr, c[i]);
            if(isect.empty())continue;
            dbl L, R;
            if(isect.size() == 1u)
                L = R = isect[0].angle();
            else{
                L = isect[0].angle();
                R = isect[1].angle();
            }
            L -= eps;
            R += eps;
            //cerr << "circle " << i << " added arc " << L << ' ' << R << endl;
            if(L < R){
                evt.emplace_back(L, 1);
                evt.emplace_back(R, -1);
            }
            else{
                evt.emplace_back(L, 1);
                evt.emplace_back(R, -1);
                ++bal;
            }
        }
    }
    sort(all(evt));
    size_t ptr = 0;
    int ans = bal;
    while(ptr < evt.size()){
        size_t ptr2 = ptr;
        while(ptr2 < evt.size() && evt[ptr2].X - evt[ptr].X < eps)
            ++ptr2;
        for(size_t i = ptr; i < ptr2; i++)
            bal += evt[i].Y;
        ans = max(ans, bal);
        ptr = ptr2;
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