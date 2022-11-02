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

const ll MX = (ll)5e18;

struct Basis{
    vector<ll> b;
    vector<ll> mask;
    void add(ll v, ll cmask){
        for(size_t i = 0; i < b.size(); i++){
            if(!v)
                break;
            int l = __builtin_clzll(v), r = __builtin_clzll(b[i]);
            if(l < r){
                mask.insert(mask.begin() + i, cmask);
                b.insert(b.begin() + i, v);
                return;
            }
            if(l == r){
                cmask ^= mask[i];
                v ^= b[i];
            }
        }
        if(v){
            b.push_back(v);
            mask.push_back(cmask);
        }
    }
    bool can(ll v){
        for(size_t i = 0; i < b.size(); i++){
            if(!v)
                break;
            int l = __builtin_clzll(v), r = __builtin_clzll(b[i]);
            if(l < r){
                return false;
            }
            if(l == r)
                v ^= b[i];
        }
        return !v;
    }
    ll restore(ll v){
        ll ans = 0;
        for(size_t i = 0; i < b.size(); i++){
            if(!v)
                break;
            int l = __builtin_clzll(v), r = __builtin_clzll(b[i]); 
            if(l == r){
                ans ^= mask[i];
                v ^= b[i];
            }
        }
        return ans;
    }
};

/*bool can(int x){
    int len = 32 - __builtin_clz(x);
    Basis b;
    for(ll i = 2*x; i < MX; i += 2*x){
        b.add(i>>(len-1));
        if(b.can(1))
            return true;
    }
    return false;
}*/

void solve(){
    ll x;
    cin >> x;
    vector<pair<ll, ll> > args;
    vector<char> ops;
    args.emplace_back(x, x);
    ops.push_back('^');
    while(x > 1){
        for(ull i = 2*x; i < (ull)MX; i *= 2){
            args.emplace_back(i/2, i/2);
            ops.push_back('+');
        }
        Basis b;
        vector<ll> base;
        int len = 64 - __builtin_clzll(x);
        for(ll i = 2*x; i < MX; i += 2*x){
            if(!b.can(i>>(len-1))){
                b.add(i>>(len-1), 1ll<<base.size());
                base.push_back(i);
            }
            if(b.can(1))
                break;
        }
        auto mask = b.restore(1);
        ll p = x;
        for(size_t i = 0; i < base.size(); i++){
            if(mask&(1ll<<i)){
                ll lol = base[i]/p;
                int bit = 0;
                ll got = 0;
                while(lol){
                    if(lol&1){
                        args.emplace_back(got, p*(1ll<<bit));
                        ops.push_back('+');
                        got += p*(1ll<<bit);
                    }
                    ++bit;
                    lol >>= 1;
                }
                args.emplace_back(x, base[i]);
                ops.push_back('^');
                x ^= base[i];
            }
        }
        assert(__builtin_clzll(x) > __builtin_clzll(p));
    }
    cout << args.size() << endl;
    for(size_t i = 0; i < args.size(); i++){
        cout << args[i].X << ' ' << ops[i] << ' ' << args[i].Y << '\n';
    }
}

signed main(){
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(9);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}