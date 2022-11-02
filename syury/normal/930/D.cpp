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
typedef double dbl;
typedef pair<int, int> pii;

const int inf = (int)1e9;
const int N = (int)1e5 + 5;
const int C = (int)1e6;

struct pt{
    int x, y;
};

int n;
pt init[N];
pt p[N];
int lower[2][C];
int upper[2][C];

inline int count_points(int L, int R, int parity){
    if((L&1) != parity)++L;
    if((R&1) != parity)--R;
    return L <= R ? (R - L + 2)/2 : 0;
}

ll solvep(int parity){
    for(int x = 0; x < 2; x++){
        fill(lower[x], lower[x] + C, inf);
        fill(upper[x], upper[x] + C, -inf);
    }
    int sz = 0;
    for(int i = 0; i < n; i++){
        if(parity != ((init[i].x + init[i].y)&1))
            continue;
        p[sz].x = init[i].x + init[i].y;
        p[sz].y = init[i].x - init[i].y;
        //cout << p[sz].x << ' ' << p[sz].y << endl;
        lower[0][C/2 + p[sz].x + 1] = min(lower[0][C/2 + p[sz].x + 1], p[sz].y + 1);
        lower[1][C/2 + p[sz].x - 1] = min(lower[1][C/2 + p[sz].x - 1], p[sz].y + 1);
        upper[0][C/2 + p[sz].x + 1] = max(upper[0][C/2 + p[sz].x + 1], p[sz].y - 1);
        upper[1][C/2 + p[sz].x - 1] = max(upper[1][C/2 + p[sz].x - 1], p[sz].y - 1);
        ++sz;
    }
    ll ans = 0;
    for(int i = 1; i < C; i++){
        lower[0][i] = min(lower[0][i], lower[0][i - 1]);
        upper[0][i] = max(upper[0][i], upper[0][i - 1]);
    }
    for(int i = C - 2; i >= 0; i--){
        lower[1][i] = min(lower[1][i], lower[1][i + 1]);
        upper[1][i] = max(upper[1][i], upper[1][i + 1]);
    }
    for(int i = 0; i < C; i++){
        int L = max(lower[0][i], lower[1][i]);
        int R = min(upper[0][i], upper[1][i]);
        if(L <= R && ((i - C/2)&1) != parity){
            ans += count_points(L, R, parity^1);
        }
    }
    return ans;
}

void solve(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d%d", &init[i].x, &init[i].y);
    printf("%lld\n", solvep(0) + solvep(1));
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    solve();
    return 0;
}