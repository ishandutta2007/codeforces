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

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5;
const int mod = 777777777;

int t[4*N][3][3];
int a[N];
bool ok[3][3];
int n, m;

void add(int & x, int y){
    x += y;
    x -= x >= mod ? mod : 0;
}

void merge(int l, int r, int to){
    memset(t[to], 0, sizeof(t[to]));
    F(l1, 0, 3)
        F(l2, 0, 3)
            F(l3, 0, 3)
                if(ok[l2][l3])
                    F(l4, 0, 3)
                        add(t[to][l1][l4], t[l][l1][l2] * 1ll * t[r][l3][l4] % mod);
                    
}

void build(int v, int l, int r){
    if(l == r){
        F(i, 0, 3)t[v][i][i] = 1;
        ret;
    }
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);
    merge(2*v, 2*v + 1, v);
}

void upd(int v, int l, int r, int pos, int val){
    if(l == r){
        a[l] = val;
        memset(t[v], 0, sizeof(t[v]));
        if(val)
            t[v][val - 1][val - 1] = 1;
        else
            F(i, 0, 3)t[v][i][i] = 1;
        ret;
    }
    int mid = (l + r)/2;
    if(pos <= mid)
        upd(2*v, l, mid, pos, val);
    else
        upd(2*v + 1, mid + 1, r, pos, val);
    merge(2*v, 2*v + 1, v);
}

int get_ans(){
    int res = 0;
    F(i, 0, 3)F(j, 0, 3)add(res, t[1][i][j]);
    ret res;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d", &n, &m);
    F(i, 0, 3)F(j, 0, 3){int x; scanf("%d", &x); ok[i][j] = x;}
    memset(a, 0, sizeof(a));
    build(1, 0, n - 1);
    F(i, 0, m){
        int pos, w;
        scanf("%d%d", &pos, &w);
        --pos;
        upd(1, 0, n - 1, pos, w);
        printf("%d\n", get_ans());
    }
    return 0;
}