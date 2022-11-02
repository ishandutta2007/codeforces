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

const int N = (int)2e5 + 5;

int n;
pii a[N];

void solve(){
    scanf("%d", &n);
    F(i, 0, n){
        scanf("%d%d", &a[i].X, &a[i].Y);
    }
    sort(a, a + n);
    multiset<int> kek;
    ll ans = 0;
    int ptr = n - 1;
    int ex = 0;
    while(ptr >= 0){
        int j = ptr;
        while(j >= 0 && a[j].X == a[ptr].X)--j;
        ++j;
        E(i, j, ptr)
            kek.insert(a[i].Y);
        int must = a[j].X - ex - j;
        while(must > 0){
            ans += *kek.begin();
            kek.erase(kek.begin());
            --must; ++ex;
        }
        ptr = j - 1;
    }
    printf("%lld\n", ans);
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    scanf("%d", &T);
    while(T--)
        solve();
    return 0;
}