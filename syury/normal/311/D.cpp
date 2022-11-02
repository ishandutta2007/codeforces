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

const int N = (int)1e5 + 55;
const int mod = 95542721;
const int ord = 48;

inline int add(int x, int y){
    x += y;
    return x >= mod ? x - mod : x;
}

int n, q;
int a[N];
int val[N][ord];
int t[4*N][ord];
int tag[4*N];
int tmp1[ord], tmp2[ord];

inline void push(int v){
    if(tag[v]){
        tag[v] %= ord;
        tag[2*v] += tag[v];
        tag[2*v + 1] += tag[v];
        for(int i = 0; i < ord; i++){
            int j = i + tag[v];
            j -= j >= ord ? ord : 0;
            tmp1[i] = t[2*v][j];
            tmp2[i] = t[2*v+1][j];
        }
        memcpy(t[2*v], tmp1, ord * sizeof(int));
        memcpy(t[2*v+1], tmp2, ord * sizeof(int));
        tag[v] = 0;
    }
}

inline void recalc(int v){
    for(int i = 0; i < ord; i++){
        t[v][i] = add(t[2*v][i], t[2*v+1][i]);
    }
}

void build(int v, int l, int r){
    if(l == r){
        memcpy(t[v], val[l], ord * sizeof(int));
        return;
    }
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);
    recalc(v);
}

void inc(int v, int l, int r, int ul, int ur){
    if(ul > ur)
        return;
    if(l == ul && r == ur){
        ++tag[v];
        for(int i = 0; i < ord; i++)
            tmp1[i] = t[v][i + 1 == ord ? 0 : (i + 1)];
        memcpy(t[v], tmp1, ord * sizeof(int));
        return;
    }
    push(v);
    int mid = (l + r)/2;
    inc(2*v, l, mid, ul, min(ur, mid));
    inc(2*v + 1, mid + 1, r, max(ul, mid + 1), ur);
    recalc(v);
}

int get(int v, int l, int r, int ul, int ur){
    if(ul > ur)
        return 0;
    if(l == ul && r == ur)
        return t[v][0];
    push(v);
    int mid = (l + r)/2;
    return add(get(2*v, l, mid, ul, min(ur, mid)), get(2*v + 1, mid + 1, r, max(ul, mid + 1), ur));
}

void solve(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
        val[i][0] = a[i]%mod;
        for(int j = 1; j < ord; j++)
            val[i][j] = val[i][j - 1] * 1ll * val[i][j - 1] % mod * val[i][j - 1] % mod;
    }
    build(1, 0, n - 1);
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int tp, l, r;
        scanf("%d%d%d", &tp, &l, &r);
        --l; --r;
        if(tp == 1)
            printf("%d\n", get(1, 0, n - 1, l, r));
        else
            inc(1, 0, n - 1, l, r);
    }
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