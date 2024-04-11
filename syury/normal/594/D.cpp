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

const int mod = (int)1e9 + 7;
const int N = (int)2e5 + 5;
const int A = (int)1e6 + 6;

int pw(ll x, int p){
    ll res = 1;
    while(p){
        if(p&1)
            res = res * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    ret res;
}

int lp[A];
int a[N];
int L[N], R[N];
int ans[N];
vector<int> occ[A];
vector<pii> mul[N];
vector<int> que[N];
int t[4*N];
int n, m;

void build(int v, int l, int r){
    t[v] = 1;
    if(l == r)
        ret;
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);
}

void upd(int v, int l, int r, int ul, int ur, int num){
    if(ul > ur)ret;
    if(l == ul && r == ur){
        t[v] = t[v] * 1ll * num % mod;
        ret;
    }
    int mid = (l + r)/2;
    upd(2*v, l, mid, ul, min(ur, mid), num);
    upd(2*v + 1, mid + 1, r, max(ul, mid + 1), ur, num);
}

int get(int v, int l, int r, int pos){
    if(l == r)
        ret t[v];
    int mid = (l + r)/2;
    if(pos <= mid)
        ret t[v] * 1ll * get(2*v, l, mid, pos) % mod;
    else
        ret t[v] * 1ll * get(2*v + 1, mid + 1, r, pos) % mod;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fill(lp, lp + A, -1);
    F(i, 2, A){
        if(lp[i] != -1)cont;
        lp[i] = i;
        for(ll j = i * 1ll * i; j < A; j += i){
            lp[j] = lp[j] == -1 ? i : lp[j];
        }
    }
    scanf("%d", &n);
    F(i, 0, n)
        scanf("%d", a + i);
    scanf("%d", &m);
    F(i, 0, m){
        scanf("%d%d", L + i, R + i);
        --L[i]; --R[i];
        que[L[i]].pb(i);
    }
    F(i, 0, n){
        int x = a[i];
        while(x > 1){
            occ[lp[x]].pb(i);
            x /= lp[x];
        }
    }
    F(i, 0, A){
        if(occ[i].empty())cont;
        int rev = pw(i - 1, mod - 2);
        int prv = -1;
        I(j, occ[i]){
            if(prv + 1 <= j){
                if(prv >= 0)mul[prv].pb({j, rev});
                mul[j].pb({j, i - 1});
            }
            if(prv >= 0)
                mul[prv].pb({j, i});
            prv = j;
        }
    }
    build(1, 0, n - 1);
    DF(i, n - 1, 0){
        I(q, mul[i]){
            upd(1, 0, n - 1, q.X, n - 1, q.Y);
        }
        I(q, que[i]){
            ans[q] = get(1, 0, n - 1, R[q]);
        }
    }
    F(i, 0, m)
        printf("%d\n", ans[i]);
    return 0;
}