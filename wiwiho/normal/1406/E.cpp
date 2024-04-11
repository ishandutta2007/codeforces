//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<int> p, prime;

void sieve(int n){
    p.resize(n + 1, 1);
    for(int i = 2; i <= n; i++){
        if(p[i] == 1){
            p[i] = i;
            prime.eb(i);
        }
        for(int j : prime){
            if((ll)i * j > n) break;
            p[i * j] = j;
            if(i % j == 0) break;
        }
    }
}

int qa(int a){
    cout << "A " << a << "\n" << flush;
    int ans;
    cin >> ans;
    return ans;
}

int qb(int b){
    cout << "B " << b << "\n" << flush;
    int ans;
    cin >> ans;
    return ans;
}

void qc(int c){
    cout << "C " << c << "\n" << flush;
}

ll fp(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int rt(int a, int s){
    ll now = 1;
    for(int i = 0; ; i++){
        now *= s;
        if(now > a) return i;
    }
}

int main(){
    StarBurstStream


    int n;
    cin >> n;
    sieve(n);

    set<int> s;
    for(int i = 1; i <= n; i++){
        s.insert(i);
    }

    vector<ll> ans;
    int i = 0;
    int m = prime.size();
    for(; i * 100 < m; i++){

        for(int j = i * 100; j < m && j < (i + 1) * 100; j++){
            qb(prime[j]);
            for(int k = 1; (ll) k * prime[j] <= n; k++){
                s.erase(k * prime[j]);
            }
        }

        int cnt = qa(1);
        if(cnt == s.size()) continue;

        for(int j = i * 100; j < m && j < (i + 1) * 100; j++){
            int c = qa(prime[j]);
            if(c) ans.eb(prime[j]);
        }

        break;
    }

    i++;
    for(int j = i * 100; j < m; j++){
        int cnt = 0;
        for(int k = 1; (ll) prime[j] * k <= n; k++){
            if(s.find(prime[j] * k) != s.end()){
                s.erase(prime[j] * k);
                cnt++;
            }
        }
        int t = qb(prime[j]);
        if(t != cnt) ans.eb(prime[j]);
    }

    ll a = 1;
    for(int i : ans){
        int l = 1, r = rt(n, i);
        while(l < r){
            int m = (l + r + 1) / 2;
            if(qa(fp(i, m))) l = m;
            else r = m - 1;
        }
        while(l--) a *= i;
    }

    qc(a);

    return 0;
}