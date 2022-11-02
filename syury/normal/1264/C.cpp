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

const int N = (int)2e5 + 5;
const int mod = 998244353;

inline int inv(int x){
    int res = 1;
    int pw = mod - 2;
    while(pw){
        if(pw&1)
            res = res * 1ll * x % mod;
        x = x * 1ll * x % mod;
        pw >>= 1;
    }
    return res;
}

const int i100 = inv(100);

int n, q;
int suff[N];
int mul[N];
int p[N], ip[N];
set<int> active;
ll ans = 0;

inline int get(int from, int to){
    int res = (suff[from] - suff[to]) * 1ll * mul[to] % mod;
    return res < 0 ? res + mod : res;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%d", p + i);
        p[i] = p[i] * 1ll * i100 % mod;
        ip[i] = inv(p[i]);
    }
    int imul = 1;
    mul[n] = 1;
    for(int i = n - 1; i >= 0; i--){
        mul[i] = mul[i + 1] * 1ll * p[i] % mod;
        imul = imul * 1ll * ip[i] % mod;
        suff[i] = imul + suff[i + 1];
        suff[i] %= mod;
    }
    active.insert(0);
    active.insert(n);
    ans = get(0, n);
    for(int i = 0; i < q; i++){
        int pos;
        scanf("%d", &pos);
        --pos;
        if(active.count(pos)){
            auto it = active.find(pos);
            auto lt = it;
            auto rt = it;
            --lt; ++rt;
            ans -= get(*lt, *it) + get(*it, *rt);
            ans += get(*lt, *rt);
            active.erase(it);
        }
        else{
            auto rt = active.lower_bound(pos);
            auto lt = rt;
            --lt;
            ans -= get(*lt, *rt);
            ans += get(*lt, pos) + get(pos, *rt);
            active.insert(pos);
        }
        ans %= mod;
        if(ans < 0)
            ans += mod;
        printf("%lld\n", ans);
    }
    return 0;
}