//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("tune=native")
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
typedef double dbl;
typedef pair<int, int> pii;

#ifdef LOCAL
const int N = 1111;
pii p[N];
int perm[N];
#endif

ll ask(int t, int i, int j, int k){
#ifdef LOCAL
    --i; --j; --k;
    i = perm[i]; j = perm[j]; k = perm[k];
    pii a = {p[j].X - p[i].X, p[j].Y - p[i].Y}, b = {p[k].X - p[i].X, p[k].Y - p[i].Y};
    ll cross = a.X * 1ll * b.Y - a.Y * 1ll * b.X;
    if(t == 1)
        ret llabs(cross);
    else
        ret cross < 0 ? -1 : 1;
#else
    printf("%d %d %d %d\n", t, i, j, k);
    fflush(stdout);
    ll res;
    scanf("%lld", &res);
    ret res;
#endif
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    scanf("%d", &n);
#ifdef LOCAL
    for(int i = 0; i < n; i++){
        scanf("%d%d", &p[i].X, &p[i].Y);
    }
    for(int i = 0; i < n; i++)
        scanf("%d", perm + i);
#endif
    int best = 1;
    F(i, 2, n){
        auto q = ask(2, 1, i+1, best+1);
        if(q > 0)best = i;
    }
    vector<int> cand;
    vector<ll> area;
    vector<int> sgn;
    F(i, 1, n){
        if(best == i)cont;
        auto q = ask(1, 1, best+1, i+1);
        cand.pb(i);
        area.pb(q);
    }
    int mx = -1;
    F(i, 0, (int)cand.size()){
        if(mx == -1 || area[mx] < area[i])
            mx = i;
    }
    vector<pair<ll, int> > plus, minus;
    F(i, 0, (int)cand.size()){
        if(mx == i)cont;
        auto q = ask(2, 1, cand[mx]+1, cand[i]+1);
        if(q > 0)plus.pb({area[i], cand[i]});
        if(q < 0)minus.pb({area[i], cand[i]});
    }
    sort(all(plus));
    sort(all(minus));
    vector<int> ans = {1, best + 1};
    I(v, minus)
        ans.pb(v.Y + 1);
    ans.pb(cand[mx] + 1);
    reverse(all(plus));
    I(v, plus)
        ans.pb(v.Y + 1);
    printf("0 ");
    I(v, ans)printf("%d ", v);
    fflush(stdout);
    return 0;
}