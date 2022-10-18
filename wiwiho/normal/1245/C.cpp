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
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    vector<ll> dpu(100005);
    vector<ll> dpw(100005);
    dpu[1] = 1; dpw[1] = 1;
    for(int i = 2; i <= 100003; i++){
        dpu[i] = (dpu[i - 1] + dpw[i - 2]) % MOD;
        dpw[i] = (dpu[i - 1] + dpw[i - 2]) % MOD;
    }

    ll ans = 1;
    string s;
    cin >> s;
    s += ".";
    int cnt = 0;
    if(s[0] == 'm' || s[0] == 'w') return cout << "0\n", 0;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == 'm' || s[i] == 'w') return cout << "0\n", 0;
        if(s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n')){
            cnt = max(2, cnt + 1);
        }
        else if(cnt > 0){
            ans *= (dpu[cnt] + dpw[cnt - 1]) % MOD;
            ans %= MOD;
            cnt = 0;
        }
    }

    cout << ans << "\n";

    return 0;
}