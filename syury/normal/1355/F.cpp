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

vector<vector<int> > init_queries;

void calc_queries(){
    int keq = 17;
    int ptr = 2;
    int cnt = 0;
    while(keq){
        vector<int> q;
        ll mul = 1;
        while(1){
            bool ok = 1;
            for(int j = 2; j * j <= ptr; j++)
                if(ptr%j == 0){ok = 0; break;}
            if(!ok){++ptr; continue;}
            if(mul > ((ll)1e18) / ptr){break;}
            q.push_back(ptr);
            mul *= ptr++;
            ++cnt;
        }
        init_queries.push_back(q);
        --keq;
    }
}

ll WHAT, DIVS;

//#define TEST

ll ask(ll x){
#ifdef TEST
    return __gcd(x, WHAT);
#else
    cout << "? " << x << endl;
    ll ans;
    cin >> ans;
    return ans;
#endif
}

void answer(ll ans){
#ifdef TEST
    cerr << ans << ' ' << DIVS << endl;
    assert(llabs(ans - DIVS) <= 7 || (2*DIVS <= ans && ans <= 2*DIVS));
#else
    cout << "! " << ans << endl;
#endif
}

void solve(){
#ifdef TEST
    cin >> WHAT;
    DIVS = 1;
    ll kek = WHAT;
    for(ll x = 2; x * x <= WHAT; x++){
        int pw = 0;
        while(kek%x == 0){++pw; kek /= x;}
        DIVS *= 1 + pw;
    }
    if(kek > 1)DIVS *= 2;
#endif
    vector<int> primes;
    for(auto& v: init_queries){
        ll mul = 1;
        for(auto p: v)
            mul *= p;
        ll g = ask(mul);
        for(auto p: v)
            if(g%p == 0)
                primes.push_back(p);
    }
    ll ans = 1;
    for(size_t i = 0; i < primes.size(); i += 2){
        ll curr = 1;
        ll pw = 1;
        while(pw * primes[i] <= (ll)1e9)pw *= primes[i];
        curr *= pw;
        if(i + 1 < primes.size()){
            pw = 1;
            while(pw * primes[i + 1] <= (ll)1e9)pw *= primes[i + 1];
            curr *= pw;
        }
        ll g = ask(curr);
        int cp = 0;
        while(g%primes[i] == 0){g /= primes[i]; ++cp;}
        ans *= cp + 1;
        if(i + 1 < primes.size()){
            cp = 0;
            while(g%primes[i + 1] == 0){g /= primes[i + 1]; ++cp;}
            ans *= cp + 1;
        }
    }
    if(ans <= 2){
        answer(ans + 7);
    }
    else{
        answer(ans * 2);
    }
}


signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    calc_queries();
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}