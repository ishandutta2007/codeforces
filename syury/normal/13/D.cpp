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
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = 1005;

struct pt{
    int x, y, c;
    inline pt operator - (const pt & p)const{
        return pt{x - p.x, y - p.y, c};
    }
    inline ll cross(const pt & p)const{
        return x * 1ll * p.y - y * 1ll * p.x;
    }
    inline int half()const{
        return int(y < 0 || (y == 0 && x < 0));
    }
    inline bool operator < (const pt & p)const{
        return half() == p.half() ? (cross(p) == 0 ? (c > p.c) : (cross(p) > 0)) : (half() < p.half());
    }
};

int ans = 0;
int n, m;
pt ap[N];
pt p[N];

inline int nxt(int i, int sz){
    return i + 1 != sz ? i + 1 : 0;
}

//#define TEST

void solve(){
#ifdef TEST
    n = m = 500;
#else
    cin >> n >> m;
#endif
    for(int i = 0; i < n; i++){
#ifdef TEST
        ap[i].x = rand()%1000000; ap[i].y = rand()%1000000;
#else
        cin >> ap[i].x >> ap[i].y;
#endif
        ap[i].c = 1;
    }
    for(int i = 0; i < m; i++){
#ifdef TEST
        ap[n+i].x = rand()%1000000; ap[n+i].y = rand()%1000000;
#else
        cin >> ap[n+i].x >> ap[n+i].y;
#endif
        ap[n+i].c = 0;
    }
    if(n <= 2){
        cout << "0\n";
        return;
    }
    int sz = n + m;
    for(int i = 0; i < sz; i++){
        if(!ap[i].c)
            continue;
        pt base = ap[i];
        int ptr = 0;
        for(int j = 0; j < sz; j++){
            if(j != i){
                p[ptr++] = ap[j] - base;
            }
        }
        sort(p, p + ptr);
        for(int j = 0; j < ptr; j++){
            if(!p[j].c)
                continue;
            pt cu = p[j];
            pt bound{cu.x, cu.y, -1};
            int k = nxt(j, ptr);
            while(k != j && cu.cross(p[k]) == 0)
                k = nxt(k, ptr);
            while(k != j && cu.cross(p[k]) >= 0){
                if(p[k].c == 0){
                    bound = (bound.c == -1 || (bound - cu).cross(p[k] - cu) > 0) ? p[k] : bound;
                }
                else{
                    /*if((bound - cu).cross(p[k] - cu) >= 0){
                        cerr << "FUC " << base.x << ' ' << base.y << ' ' << base.x + cu.x << ' ' << base.y + cu.y << endl;
                    }*/
                    ans += (bound - cu).cross(p[k] - cu) >= 0 ? 1 : 0;
                }
                k = nxt(k, ptr);
            }
        }
    }
    cout << ans/3 << endl;
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    T = 1;
    while(T--)
        solve();
    //cerr << fixed << clock()/(double)CLOCKS_PER_SEC << endl;
    return 0;
}