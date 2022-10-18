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
#define iceil(a) ((int)ceil(a))
#define ifloor(a) ((int)floor(a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = (1LL << 60);

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<bool> c(26);
    for(int i = 0; i < k; i++){
        char t;
        cin >> t;
        c[t - 'a'] = true;
    }

    vector<ll> cnt(1);
    for(int i = 0; i < n; i++){
        if(!c[s[i] - 'a']) cnt.eb();
        else cnt.back()++;
    }

    ll ans = 0;
    for(ll i : cnt){
        ans += i * (i + 1) / 2;
    }
    //printv(cnt, cerr);
    cout << ans << "\n";

    return 0;
}