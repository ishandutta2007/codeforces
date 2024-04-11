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

const ll MOD = 998244353;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    string s, t;
    cin >> s >> t;

    vector<int> r(t.size() + 1);
    r[t.size()] = s.size();
    int now = t.size() - 1;
    for(int i = s.size() - 1; i >= 0 && now >= 0; i--){
        if(s[i] == t[now]) r[now] = i, now--;
    }

    now = 0;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        ans = max(ans, r[now] - i);
        if(now < t.size() && s[i] == t[now]) now++;
    }

    cout << ans << '\n';

    return 0;
}