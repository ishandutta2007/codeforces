//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    string s, t;
    cin >> s >> t;

    int ans = 0;
    for(int i = 0; i < s.size(); i++){

        for(int j = i; j < s.size(); j++){

            int now = 0;
            for(int k = 0; k < s.size() && now < t.size(); k++){
                if(k >= i && k <= j) continue;
                //cerr << i << " " << j << " " << k << "\n";
                if(s[k] == t[now]) now++;
            }
            if(now == t.size()) ans = max(ans, j - i + 1);

        }
    }

    cout << ans << "\n";

    return 0;
}