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

void fail(){
    cout << "NO" << endl;
    exit(0);
}

const int C = (int)1e6 + 6;

bool inside(int x, int l, int r){
    if(l > r)swap(l, r);
    return l <= x && x <= r;
}

int si(ll x){return x < 0 ? -1 : 1;}

ll lt(ll P, ll Q){
    //x < P/Q
    if(P == 0)
        return -1;
    if(si(P) == si(Q)){
        return P%Q == 0 ? llabs(P)/llabs(Q) - 1 : (llabs(P)/llabs(Q));
    }
    else{
        return - (llabs(P)/llabs(Q)) - 1;
    }
}

ll gt(ll P, ll Q){
    //x > P/Q
    if(P == 0)
        return 1;
    if(si(P) == si(Q)){
        return llabs(P)/llabs(Q) + 1;
    }
    else{
        return P%Q == 0 ? -(llabs(P)/llabs(Q)) + 1 : -(llabs(P)/llabs(Q));
    }
}

void solve(){
    int n, dx1, dy1, dx2, dy2;
    cin >> n >> dx1 >> dy1 >> dx2 >> dy2;
    if(max(abs(dx1), abs(dx2)) == 0)
        fail();
    if(max(abs(dy1), abs(dy2)) == 0)
        fail();
    if(dx1 != 0 && dx2 != 0){
        if(dy2*1ll*dx1 == dy1*1ll*dx2)
            fail();
    }
    if(abs(dx1) + abs(dy1) == 0)fail();
    if(abs(dx2) + abs(dy2) == 0)fail();
    vector<pii> pts;
    for(int x = -2*C; x < 2*C + 1; x++){
        ll lo = -2*C, hi = 2*C;
        bool ok = 0;
        bool vert = 0;
        auto upd = [&x, &vert, &ok, &lo, &hi](ll A, ll B, ll c, ll x0, ll y0){
            if(B == 0){vert = 1; return;}
            ok = 1;
            assert(A * x0 + B * y0 + c != 0);
            bool sgn = A * x0 + B * y0 + c < 0;
            if(sgn){
                if(B < 0)
                    lo = max(lo, gt(-A * x - c, B));
                else
                    hi = min(hi, lt(-A * x - c, B));
            }
            else{
                if(B < 0)
                    hi = min(hi, lt(-A * x - c, B));
                else
                    lo = max(lo, gt(-A * x - c, B));
            }
        };
        if(inside(x, 0, dx1)){
            upd(dy1, -dx1, 0, dx2, dy2);
        }
        if(inside(x, 0, dx2)){
            upd(dy2, -dx2, 0, dx1, dy1);
        }
        if(inside(x, dx1, dx1 + dx2)){
            upd(dy2, -dx2, -dx1*1ll*dy2 + dy1*1ll*dx2, dx2, dy2);
        }
        if(inside(x, dx2, dx2 + dx1)){
            upd(dy1, -dx1, -dy1*1ll*dx2 + dy2*1ll*dx1, dx1, dy1);
        }
        //if(!vert && ok)cerr << x << ' ' << lo << ' ' << hi << endl;
        if(vert || !ok)continue;
        for(int y = lo; y <= hi; y++){
            //cerr << "adding " << x << ' ' << y << endl;
            pts.emplace_back(x, y);
            if(pts.size() > n)fail();
        }
    }
    int g = __gcd(abs(dx1), abs(dy1));
    int v = dx1/g, u = dy1/g;
    int cx = 0, cy = 0;
    while(cx != dx1 || cy != dy1){
        if(cx || cy)pts.emplace_back(cx, cy);
        cx += v; cy += u;
    }
    g = __gcd(abs(dx2), abs(dy2));
    v = dx2/g, u = dy2/g;
    cx = 0, cy = 0;
    while(cx != dx2 || cy != dy2){
        if(cx || cy)pts.emplace_back(cx, cy);
        cx += v; cy += u;
    }
    pts.emplace_back(0, 0);
    //cerr << pts.size() << endl;
    if(pts.size() != n)
        fail();
    cout << "YES\n";
    for(auto p: pts)
        cout << p.X << ' ' << p.Y << '\n';
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