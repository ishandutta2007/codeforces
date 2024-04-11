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
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

struct pt{
    int id;
    int x, y, z;
};

struct pt2{
    int id;
    int x, y;
    bool operator < (const pt2 & p)const{
        if(x != p.x)ret x < p.x;
        else ret y < p.y;
    }
};

const int N = (int)1e5;

int n;
pt p[N];
pt tmp[N];
vector<int> extra;
vector<int> extra2;
vector<pii> seq;
pt2 d2[N];
int ids[N];
int ptr = 0;

void go(){
    extra2.clear();
    F(i, 0, ptr){
        d2[i] = pt2{tmp[i].id, tmp[i].y, tmp[i].z};
    }
    sort(d2, d2 + ptr);
    int old_y = (int)1e9;
    int sz = 0;
    F(i, 0, ptr){
        if(old_y != d2[i].x){
            for(int j = 0; j + 1 < sz; j += 2){
                seq.pb(mp(ids[j], ids[j + 1]));
            }
            if(sz&1)
                extra2.pb(ids[sz - 1]);
            sz = 0;
            old_y = d2[i].x;
        }
        ids[sz++] = d2[i].id;
    }
    for(int j = 0; j + 1 < sz; j += 2){
        seq.pb(mp(ids[j], ids[j + 1]));
    }
    if(sz&1)
        extra2.pb(ids[sz - 1]);
    for(int j = 0; j + 1 < (int)extra2.size(); j += 2){
        seq.pb(mp(extra2[j], extra2[j + 1]));
    }
    if(extra2.size()&1)
        extra.pb(extra2.back());
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    F(i, 0, n){
        p[i].id = i + 1;
        cin >> p[i].x >> p[i].y >> p[i].z;
    }
    sort(p, p + n, [](const pt & a, const pt & b){return a.x < b.x;});
    int old_x = (int)1e9;
    F(i, 0, n){
        if(old_x != p[i].x){
            go();
            ptr = 0;
            old_x = p[i].x;
        }
        tmp[ptr++] = p[i];
    }
    go();
    for(int i = 0; i + 1 < (int)extra.size(); i += 2){
        seq.pb(mp(extra[i], extra[i + 1]));
    }
    I(x, seq)
        cout << x.X << ' ' << x.Y << '\n';
    return 0;
}