//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
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

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

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

    ll x;
    cin >> x;
    ll tmp = x;

    if(x == 1){
        cout << "1 1\n";
        return 0;
    }

    sieve(2000000);

    vector<ll> d;
    for(int i : p){
        if(x % i) continue;
        ll cnt = 1;
        while(x % i == 0){
            cnt *= i;
            x /= i;
        }
        d.eb(cnt);
    }

    if(x > 1){
        d.eb(x);
    }

    //printv(d, cerr);

    int t = d.size();
    pll ans = mp(tmp, 1);
    for(ll i = 0; i < (1LL << t); i++){
        ll a = 1, b = 1;
        for(int j = 0; j < t; j++){
            if(i & (1LL << j)) a *= d[j];
            else b *= d[j];
        }
        if(max(a, b) < max(ans.F, ans.S)) ans = mp(a, b);
    }

    cout << ans.F << " " << ans.S << "\n";

    return 0;
}