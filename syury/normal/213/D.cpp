//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

struct pt{
    dbl x, y;
    pt operator + (const pt & p)const{
        return pt{x + p.x, y + p.y};
    }
    pt operator - (const pt & p)const{
        return pt{x - p.x, y - p.y};
    }
    pt rotate(dbl ang)const{
        dbl ca = cos(ang), sa = sin(ang);
        return pt{x * ca - y * sa, x * sa + y * ca};
    }
    dbl dist(const pt & p)const{
        dbl dx = p.x - x, dy = p.y - y;
        return sqrt(dx*dx + dy*dy);
    }
};

const dbl PI = acos(-1.0);
const dbl ang36 = 36/180.0 * PI;
const dbl ang72 = 72/180.0 * PI;
const dbl DIAG = 20 * cos(ang36);

vector<pt> pts;

pt pt_by_ang(dbl r, dbl ang){
    return pt{r * cos(ang), r * sin(ang)};
}

vector<vector<int> > seq;

vector<pii> generate(int rem, dbl x, dbl y, dbl ang, int pI, int cI, bool inC, bool right){
    if(!rem)
        return {};
    pt p{x, y};
    pt A = p + pt_by_ang(DIAG, ang + ang36);
    pt B = A - pt_by_ang(DIAG, ang);
    pt C = p + pt_by_ang(10, ang);
    pt D = p + pt_by_ang(DIAG, ang + ang72);
    int bg = (int)pts.size();
    pts.push_back(A);
    pts.push_back(B);
    pts.push_back(D);
    vector<pii> kek;
    seq.push_back({pI + 1, cI + 1, bg + 1, bg + 3, bg + 2});
    if(!inC)
        kek = {
        make_pair(pI, bg),
        make_pair(bg, bg + 1),
        make_pair(bg + 1, cI),
        make_pair(cI, bg + 2)
    };
    else
        kek = {
            make_pair(cI, bg + 1),
            make_pair(bg + 1, bg),
            make_pair(bg, pI),
            make_pair(pI, bg + 2)
        };
    vector<pii> nxt;
    if(right)
        nxt = generate(rem - 1, D.x, D.y, ang - ang36, bg + 2, bg, 0, right^1);
    else
        nxt = generate(rem - 1, B.x, B.y, ang + ang36, bg + 1, bg + 2, 1, right^1);
    for(auto idx: nxt)
        kek.pb(idx);
    if(!inC)
        kek.pb(make_pair(bg + 2, pI));
    else
        kek.pb(make_pair(bg + 2, cI));
    return kek;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    pts.push_back(pt{-4899, -4999});
    pts.push_back(pt{-4899+10, -4999});
    auto ans = generate(n, -4899, -4999, 0, 0, 1, 0, 1);
    cout.precision(13);
    cout << pts.size() << endl;
    for(auto p: pts){
        cout << fixed << p.x << ' ' << p.y << '\n';
    }
    for(int i = 0; i < n; i++){
        for(auto x: seq[i])cout << x << ' ';
        cout << '\n';
    }
    cout << 1 << ' ';
    for(auto p: ans)
        cout << 1 + p.Y << ' ';
    cout << endl;
    return 0;
}