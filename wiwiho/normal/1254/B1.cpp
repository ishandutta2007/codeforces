//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

vector<int> prime;
vector<int> p;
void sieve(int n){
    prime.resize(n + 1, 1);
    for(int i = 2; i <= n; i++){
        if(prime[i] == 1){
            p.push_back(i);
            prime[i] = i;
        }
        for(int j : p){
            if((ll)i * j > n || j > prime[i]) break;
            prime[i * j] = j;
        }
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    sieve(1000000);

    vector<ll> a(n);
    for(int i = 0; i  < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) a[i] += a[i - 1];

    if(a[n - 1] == 1) return cout << "-1\n", 0;

    vector<ll> kk;
    ll tmp = a[n - 1];
    for(ll i : p){
        if(tmp % i) continue;
        kk.eb(i);
        while(tmp % i == 0) tmp /= i;
    }
    if(tmp > 1) kk.eb(tmp);

    ll ans = (1LL << 60);
    for(ll k : kk){
        ll now = 0;
        for(int i = 0; i < n - 1; i++){
            now += min(a[i] % k, k - a[i] % k);
        }
        ans = min(ans, now);
    }

    cout << ans << "\n";

    return 0;
}