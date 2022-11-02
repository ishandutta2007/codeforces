#pragma GCC optimize("Ofast,unroll-loops")
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
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)3e7;

int a, b, k;
bitset<N> s;
vector<int> primes;

inline bool is_prime(int x){
    for(int i = 2; i * i <= x; i++){
        if(x%i == 0)ret 0;
    }
    ret x > 1;
}

int solve(int r){
    if(k * 1ll * k > r)
        ret k <= r;
    r /= k;
    if(k <= 83){
        vector<int> p;
        I(x, primes)if(x < k)p.pb(x);
        int sz = p.size();
        int ans = 0;
        F(mask, 1, 1<<sz){
            ll mul = 1;
            F(i, 0, sz)if(mask&(1<<i)){mul *= p[i]; if(mul > r)brk;}
            if(mul > r)cont;
            int sgn = __builtin_popcount(mask)&1 ? 1 : -1;
            ans += r/mul * sgn;
        }
        ret r - ans;
    }
    else{
        s.reset();
        I(p, primes){
            if(p >= k)break;
            for(int x = p; x <= r; x += p)
                s[x] = 1;
        }
        return r - s.count();
    }
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> k;
    if(!is_prime(k)){cout << 0 << endl; ret 0;}
    F(i, 2, min(k, (int)1e5))
        if(is_prime(i))primes.pb(i);
    cout << solve(b) - solve(a - 1) << endl;
    return 0;
}