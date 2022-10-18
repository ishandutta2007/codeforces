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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define iceil(a) ((int)ceil((int)a))
#define ifloor(a) ((int)floor((int)a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

vector<pll> a;
int n;
ll s;

bool check(ll m){

    vector<ll> t;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i].S < m) sum += a[i].F;
        else t.eb(a[i].F);
    }

    if(t.size() < n / 2 + 1) return false;

    gsort(t);
    for(int i = n / 2 + 1; i < t.size(); i++) sum += t[i];
    for(int i = 0; i < n / 2 + 1; i++) sum += max(t[i], m);

    return sum <= s;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        cin >> n >> s;
        a.clear();
        a.resize(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].F >> a[i].S;
        }

        ll l = 1, r = 1000000000;
        while(l < r){
            ll m = ceil((l + r) / 2.0);
            if(check(m)){
                l = m;
            }
            else{
                r = m - 1;
            }
        }

        cout << l << "\n";

    }

    return 0;
}