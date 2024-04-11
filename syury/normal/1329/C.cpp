//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
//#pragma GCC target("tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb emplace_back
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

const int N = 22;

int a[1<<N];
int n, g;
ll popped = 0;
ll sum = 0;

inline int f(int i){
    int old = a[i];
    if(2*i + 1 > (1<<n)-2){
        a[i] = 0; ret old;
    }
    if(a[2*i+1] == 0 && a[2*i + 2] == 0){
        a[i] = 0;
    }
    else{
        if(a[2*i+1] > a[2*i+2]){
            a[i] = f(2*i+1);
        }
        else
            a[i] = f(2*i + 2);
    }
    ret old;
}

vector<pii> rec(int v, int cg){
    if(cg == 1){
        int ch = n - (g - cg);
        vector<pii> kek((1<<ch)-2);
        F(i, 0, (1<<ch) - 2){
            int cu = f(v);
            popped += cu;
            kek[i] = mp(v, cu);
            //cout << kek[i].Y << ' ';
        }
        ret kek;
    }
    int l = 2*(v + 1) - 1, r = 2*(v + 1);
    auto L = rec(l, cg - 1);
    auto R = rec(r, cg - 1);
    vector<pii> ans(L.size() + R.size());
    size_t i = 0, j = 0;
    int ca = a[v];
    while(i < L.size() || j < R.size()){
        //cout << i << ' ' << j << endl;
        int left_top = (i == L.size() || L[i].X != l) ? a[l] : L[i].Y;
        int right_top = (j == R.size() || R[j].X != r) ? a[r] : R[j].Y;
        if(j < R.size() && right_top > left_top && R[j].X == r){
            popped -= R[j].Y;
            popped += ca;
            ans[i + j] = mp(v, ca);
            ca = R[j].Y;
            ++j;
            cont;
        }
        if(i < L.size() && left_top > right_top && L[i].X == l){
            popped -= L[i].Y;
            popped += ca;
            ans[i + j] = mp(v, ca);
            ca = L[i].Y;
            ++i;
            cont;
        }
        if(i < L.size()){
            ans[i + j] = L[i];
            ++i;
            cont;
        }
        ans[i + j] = R[j];
        ++j;
        cont;
    }
    a[v] = ca;
    ret ans;
}

void solve(){
    popped = 0;
    sum = 0;
    F(i, 0, (1<<n)-1)
        sum += a[i];
    auto seq = rec(0, g);
    printf("%lld\n", sum - popped);
    I(x, seq)printf("%d ", x.X + 1);
    printf("\n");
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
    while(T--){
        scanf("%d%d", &n, &g);
        F(i, 0, (1<<n)-1)
            scanf("%d", a + i);
        solve();
    }
    return 0;
}